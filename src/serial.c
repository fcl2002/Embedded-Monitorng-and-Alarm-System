#include "serial.h"
#include "utils.h"
#include "LPC11xx.h"
#include "rtc.h"

// CONFIGURA UART PARA BAUDRATE 9600, 8 BITS, 1 STOP BIT, SEM PARIDADE
void serialInit(void){
   // Configurar os pinos RX E TX
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); // habilita o clock para o bloco IOCON (UM10398, 3.5.14)
	LPC_IOCON->PIO1_6 = 0x1; // configurar o pino UART RXD (UM10398, 7.4.40)
	LPC_IOCON->PIO1_7 = 0X1; // configurar o pino UART TXD (UM10398, 7.4.41)

	// Configurar a UART
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12); // habilita o clock para o bloco UART (UM10398, 3.5.14)
	LPC_SYSCON->UARTCLKDIV = 4; // Divisor do UART_PCLK-> 48MHz/4 = 12MHz (UM10398, 3.5.16)
	LPC_UART->LCR = 0x83; // WLS = 0x3 (8 bit length) | SBS = 0 (1 stop bit) | PE = 0 (Disabled Parity) | DLAB = 1 (UM10398, 13.5.7)


	// DLest = PCLK/(16 x BR) = 12 MHz / (16 x 9600) = 78,125 (NOT INTEGER) -> FRest = 1.5 -> DLest = Int(PCLK/(16 x BR x FR est)) = Int( 12MHz / (16 x 9600 x 1.5)) = 52
	// FRest = PCLK/(16 x BR x DLest) = 12MHz / (16 x 9600 x 52) = 1,502 -> DivAddVal = 1 | MulVal = 2
	// UARTbaudrate = PCLK / 16 x (256 x U0DLM + U0DLL) x (1 + DivAddVal / MulVal) -> U0DLM = 0 -> U0DLL = 52 -> UARTbaudrate = 9615
	LPC_UART->DLM = 0x0; // DLM=0 (UM10398, 13.5.3)
	LPC_UART->DLL = 0x34; // DLL=52 (UM10398, 13.5.3)
	LPC_UART->FDR = 0x21; // DIVADDVAL = 1, MULVAL = 2 ((UM10398, 13.5.15)
	LPC_UART->FCR |= 0x07; // habiltiar o FIFO e clear TX e RX of FIFO (UM10398, 13.5.6)

	LPC_UART->LCR = 0x03; // WLS = 0x3 (8 bit length) | SBS = 0 (1 stop bit) | PE = 0 (Disabled Parity) | DLAB = 0 (UM10398, 13.5.7)
	LPC_UART->TER = 0x80; // (13.5.16)
}

void serialSendChar(char c){
    while((LPC_UART->LSR & ( 1 << 6 )) == 0); // bit TEMT (UM10398, 13.5.9)
    LPC_UART->THR = c;
}

void serialSendString(const char *str){
    while(*str){
        serialSendChar(*str++);
    }
}

// RETORNA -1 SE NÃO LER NADA
int serialReadChar(void){
    if(LPC_UART->LSR & (1 << 0)){ // U0RBR = 1 -> contains valid data (13.5.9)
        return LPC_UART->RBR; // obter o dado recebido (UM10398, 13.5.1)
    }
    return -1;
}

// int serialReadInt(void){
//     char buffer[10];
//     int i = 0;
//     int c;

//     while(1){
//         c = serialReadChar();
//         if(c == -1) continue;

//         if(c == '\n' || c == '\r'){
//             buffer[i] = '\0';
//             break;
//         }

//         if(i < 9 && (c >= '0' && c <= '9')){
//               buffer[i++] = c;
//         }
//     }
//     return strToInt(buffer);
// }

void serialSendInt(int value){
	char buffer[6];
	int i = 0;

	if(value == 0){
		serialSendChar('0');
		return;
	}
	if(value < 0){
		serialSendChar('-');
		value = -value;
	}

	while(value > 0 && i < sizeof(buffer)){
		buffer[i++] = '0' + (value % 10);
		value /= 10;
	}

	while(i--){
		serialSendChar(buffer[i]);
	}
}

static void serialSend2Digit(int value) {
    if (value < 10) {
        serialSendChar('0');
    }
    serialSendInt(value);
}

void serialSendTime(void) {
    serialSend2Digit(mcpGetHours());
    serialSendChar(':');
    serialSend2Digit(mcpGetMinutes());
    serialSendChar(':');
    serialSend2Digit(mcpGetSeconds());
    serialSendChar(' ');
    serialSendChar(' ');
}

void serialSendDate(void) {
    serialSend2Digit(mcpGetDay());
    serialSendChar('/');
    serialSend2Digit(mcpGetMonth());
    serialSendChar('/');
    serialSend2Digit(mcpGetYear());
}

void serialSendDateTime(void) {
    serialSendTime();
    serialSendString("  ");
    serialSendDate();
}
