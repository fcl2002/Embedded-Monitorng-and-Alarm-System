/*
 * io.c
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */


#include "bits.h"
#include "io.h"
#include "LPC11xx.h"

static LPC_GPIO_TypeDef *getPort(uint8_t port_num){
    switch(port_num){
        case 0: return LPC_GPIO0;
        case 1: return LPC_GPIO1;
        case 2: return LPC_GPIO2;
        case 3: return LPC_GPIO3;
        default: return 0; // Invalid port number
    }
}

void pinMode(pin p, int mode){
    uint8_t port = p >> 5;
    uint8_t pin = p & 0x1F; // Extract the lower 5 bits to get the pin number

    LPC_GPIO_TypeDef *gpio = getPort(port);
    if(!gpio) return; // Invalid port number

    if(mode == OUTPUT){
        bitSet(gpio->DIR, pin);
    }else if(mode == INPUT){
        bitClr(gpio->DIR, pin);
    }
}

void digitalWrite(pin p, int value){
    uint8_t port = p >> 5;
    uint8_t pin = p & 0x1F; // Extract the lower 5 bits to get the pin number

    LPC_GPIO_TypeDef *gpio = getPort(port);
    if(!gpio) return; // Invalid port number

    if(value == HIGH){
        bitSet(gpio->DATA, pin);
    }else if(value == LOW){
        bitClr(gpio->DATA, pin);
    }
}

int digitalRead(pin p){
    uint8_t port = p >> 5;
    uint8_t pin = p & 0x1F; // Extract the lower 5 bits to get the pin number

    LPC_GPIO_TypeDef *gpio = getPort(port);
    if(!gpio) return -1; // Invalid port number

    return bitTst(gpio->DATA, pin) ? HIGH : LOW;
}

void digitalToggle(pin p){
    uint8_t port = p >> 5;
    uint8_t pin = p & 0x1F; // Extract the lower 5 bits to get the pin number

    LPC_GPIO_TypeDef *gpio = getPort(port);
    if(!gpio) return; // Invalid port number

    bitTgl(gpio->DATA, pin);
}

