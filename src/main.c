/*
 * Copyright 2022 NXP
 */

#ifdef __USE_CMSIS
#include "LPC11xx.h"
#endif

#include "LPC11xx.h"
#include "system_LPC11xx.h"
#include "buttons.h"
#include "i2c.h"
#include "leds.h"
#include "serial.h"
#include "rtc.h"
#include "stateMachine.h"
#include "event.h"
#include "output.h"
#include "var.h"

#define SERIAL_BUFFER_SIZE 10

/**
 * @brief Converte uma string de dígitos para um inteiro.
 */
static int stringToInt(const char *str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main(void) {
	SystemInit();
	ledsInit();
	serialInit();
	i2cInit();
	lcdInit();
    eventInit();
	smInit(); // Isso já chama varInit() e a primeira impressão na tela

	int caracter;
    char serialBuffer[SERIAL_BUFFER_SIZE];
    int bufferIndex = 0;

	mcpSetSeconds(0);
	mcpSetMinutes(55);
	mcpSetHours(16);
	mcpSetWeekday(4);  // Ex: quinta-feira
	mcpSetDay(4);
	mcpSetMonth(7);
	mcpSetYear(25);    // 2025

    while(1) {
    	buttonsDebounce(); // Processa os botões para a máquina de estados
    	smLoop();          // Executa a lógica da máquina de estados e atualiza a tela

    	caracter = serialReadChar();
    	ledsOffAll();
    	if (caracter != -1) {
            // Se o caractere é um dígito, adiciona ao buffer
            if (caracter >= '0' && caracter <= '9') {
                if (bufferIndex < SERIAL_BUFFER_SIZE - 1) { // Previne overflow
                    serialBuffer[bufferIndex++] = caracter;
                }
            }
            // Se for Enter/Newline, processa o número
            else if (caracter == '\n' || caracter == '\r') {
                if (bufferIndex > 0) {
                    serialBuffer[bufferIndex] = '\0'; // Finaliza a string
                    int receivedValue = stringToInt(serialBuffer);

                    // --- LÓGICA DE COMPARAÇÃO ATUALIZADA PARA MIN/MAX ---
                    int min = getAlarmeTreshMin();
                    int max = getAlarmeTreshMax();

                    // Dispara a mensagem se o valor estiver FORA do intervalo [min, max]
                    if (receivedValue < min) {
                        serialSendString("\nWARNING - Value ");
                        serialSendInt(receivedValue);
                        serialSendString(" is outside the range [");
                        serialSendInt(min);
                        serialSendString(", ");
                        serialSendInt(max);
                        serialSendString("]");

						serialSendChar('\n');
						serialSendDateTime();
						serialSendChar('\n');
                        ledsToggle(LED0);

                    }
                    if ( receivedValue > max) {
                        serialSendString("\nWARNING - Value ");
                        serialSendInt(receivedValue);
                        serialSendString(" is outside the range [");
                        serialSendInt(min);
                        serialSendString(", ");
                        serialSendInt(max);
                        serialSendString("]");

						serialSendChar('\n');
						serialSendDateTime();
						serialSendChar('\n');
                        ledsToggle(LED1);
                    }
                }
                // Reseta o buffer para o próximo número
                bufferIndex = 0;
            }
    	}
    }
    return 0 ;
}
