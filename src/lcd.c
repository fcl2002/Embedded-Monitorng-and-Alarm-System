#include "lcd.h"
#include "utils.h"
#include "bits.h"
#include "LPC11xx.h"
#include "system_LPC11xx.h"

static const pin lcdDataPins[4] = {LCD_D4, LCD_D5, LCD_D6, LCD_D7};

void delayMicro(int a){
    volatile int i;
    for(i=0; i<(a*2); i++);
}

void delayMili(int a){
    volatile int i;
    for(i=0; i<a; i++){
        delayMicro(1000);
    }
}

static void lcdPulseEnable(void){
    digitalWrite(LCD_E, HIGH);
    delayMicro(5);
    digitalWrite(LCD_E, LOW);
    delayMicro(5);
}

static void lcdSendNibble(unsigned char nibble){
    int i;
    for(i=0; i<4; i++){
        digitalWrite(lcdDataPins[i], (nibble >> i) & 1);
    }
    lcdPulseEnable();
}

static void lcdSendByte(unsigned char value, int rs){
    digitalWrite(LCD_RS, rs);
    lcdSendNibble(value >> 4);
    lcdSendNibble(value & 0x0F);

}

void lcdCommand(unsigned char cmd){
    lcdSendByte(cmd, LOW);
    delayMili(2);
}

void lcdChar(unsigned char ch){
    lcdSendByte(ch, HIGH);
}

void lcdString(const char *str){
    while(*str){
        lcdChar(*str++);
    }
}

void lcdClear(void){
    lcdCommand(0x01); 
    delayMili(2);
}

void lcdHome(void){
    lcdCommand(0x02); 
    delayMili(2);
}

void lcdSetCursor(unsigned char row, unsigned char col){
    const unsigned char rowOffsets[] = {0x00, 0x40, 0x14, 0x54};
    lcdCommand(0x80 | (rowOffsets[row] + col));
}

void lcdInit(void){
    int i;

    pinMode(LCD_RS, OUTPUT);
    pinMode(LCD_E, OUTPUT);

    LPC_IOCON->R_PIO1_0 = 0x81;
    LPC_IOCON->R_PIO1_1 = 0x81;
    LPC_IOCON->R_PIO1_2 = 0x81;

    for(i=0; i<4; i++){
        pinMode(lcdDataPins[i], OUTPUT);
    }

    LPC_IOCON->R_PIO1_0 = 0x81;
    LPC_IOCON->R_PIO1_1 = 0x81;
    LPC_IOCON->R_PIO1_2 = 0x81;
    LPC_IOCON->R_PIO0_11 = 0x81; // DB4

    delayMili(15);

    lcdSendNibble(0x03);
    delayMili(5);

    lcdSendNibble(0x03);
    delayMicro(160);

    lcdSendNibble(0x03);
    delayMicro(160);

    lcdSendNibble(0x02);
    delayMili(10);

    lcdCommand(0x28); // 4-bit mode, 2 lines, 5x8 dots
    lcdCommand(0x0C); // Display on, cursor off, blink off
    lcdCommand(0x06); // Increment cursor, no shift
    lcdClear();
}

void lcdNumber(int num){
    char buffer[10];
    intToStr(num, buffer);
    lcdString(buffer);
}

