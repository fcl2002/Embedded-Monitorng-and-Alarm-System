/*
 * io.h
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */

#ifndef IO_H_
#define IO_H_

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

typedef enum{
    PIO0_0 =  (0 << 5) | 0,
    PIO0_1 =  (0 << 5) | 1,
    PIO0_2 =  (0 << 5) | 2,
    PIO0_3 =  (0 << 5) | 3,
    PIO0_4 =  (0 << 5) | 4,
    PIO0_5 =  (0 << 5) | 5,
    PIO0_6 =  (0 << 5) | 6,
    PIO0_7 =  (0 << 5) | 7,
    PIO0_8 =  (0 << 5) | 8,
    PIO0_9 =  (0 << 5) | 9,
    PIO0_10 = (0 << 5) | 10,
    PIO0_11 = (0 << 5) | 11,

    PIO1_0 =  (1 << 5) | 0,
    PIO1_1 =  (1 << 5) | 1,
    PIO1_2 =  (1 << 5) | 2,
    PIO1_3 =  (1 << 5) | 3,
    PIO1_4 =  (1 << 5) | 4,
    PIO1_5 =  (1 << 5) | 5,
    PIO1_6 =  (1 << 5) | 6,
    PIO1_7 =  (1 << 5) | 7,
    PIO1_8 =  (1 << 5) | 8,
    PIO1_9 =  (1 << 5) | 9,
    PIO1_10 = (1 << 5) | 10,
    PIO1_11 = (1 << 5) | 11,

    PIO2_0 =  (2 << 5) | 0,
    PIO2_1 =  (2 << 5) | 1,
    PIO2_2 =  (2 << 5) | 2,
    PIO2_3 =  (2 << 5) | 3,
    PIO2_4 =  (2 << 5) | 4,
    PIO2_5 =  (2 << 5) | 5,
    PIO2_6 =  (2 << 5) | 6,
    PIO2_7 =  (2 << 5) | 7,
    PIO2_8 =  (2 << 5) | 8,
    PIO2_9 =  (2 << 5) | 9,
    PIO2_10 = (2 << 5) | 10,
    PIO2_11 = (2 << 5) | 11,

    PIO3_0 =  (3 << 5) | 0,
    PIO3_1 =  (3 << 5) | 1,
    PIO3_2 =  (3 << 5) | 2,
    PIO3_3 =  (3 << 5) | 3,
    PIO3_4 =  (3 << 5) | 4,
    PIO3_5 =  (3 << 5) | 5,
} pin;

//Define LEDs
#define LED0 PIO2_9
#define LED1 PIO3_0
#define LED2 PIO2_0
#define LED3 PIO2_6

//Define Buttons
#define BUTTON_UP1      PIO2_8
#define BUTTON_RIGHT1   PIO2_1
#define BUTTON_DOWN1    PIO0_2
#define BUTTON_LEFT1    PIO1_8
#define BUTTON_CONFIRM1 PIO2_7


//Define i2c pins
#define I2C_SDA PIO0_5
#define I2C_SCL PIO0_4

//Function prototypes
void pinMode(pin p, int mode);
void digitalWrite(pin p, int value);
int digitalRead(pin p);
void digitalToggle(pin p);


#endif /* IO_H_ */
