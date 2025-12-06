#ifndef LCD_H
#define LCD_H

#include "io.h"

#define LCD_RS PIO1_1
#define LCD_E  PIO1_0

#define LCD_D4 PIO0_11
#define LCD_D5 PIO2_11
#define LCD_D6 PIO1_10
#define LCD_D7 PIO0_9

void lcdInit(void);
void lcdCommand(unsigned char cmd);
void lcdChar(unsigned char ch);
void lcdString(const char *str);
void lcdSetCursor(unsigned char row, unsigned char col);
void lcdNumber(int num);
void lcdClear(void);
void lcdHome(void);



#endif // LCD_H
