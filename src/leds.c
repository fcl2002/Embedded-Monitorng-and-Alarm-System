/*
 * leds.c
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */

#include "leds.h"
#include "utils.h"

void ledsInit(void){
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

    ledsOffAll();
}

void ledsOnAll(void){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
}

void ledsOffAll(void){
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
}

void ledsToggle(pin led){
    digitalToggle(led);
}

void ledsToggleAll(void){
    digitalToggle(LED0);
    digitalToggle(LED1);
    digitalToggle(LED2);
    digitalToggle(LED3);
}

void ledsSet(pin led, int value){
    digitalWrite(led, value);
}

void ledsShow(void){
    int i;
    for (i = 0; i < 2; i++){
        ledsOffAll();
        delay_ms(100);
        ledsOnAll();
        delay_ms(100);
    }

    ledsOffAll();
    delay_ms(100);

    ledsSet(LED0, HIGH);
    delay_ms(150);
    ledsSet(LED1, HIGH);
    delay_ms(150);
    ledsSet(LED2, HIGH);
    delay_ms(150);
    ledsSet(LED3, HIGH);
    delay_ms(150);

    for (int i = 0; i < 6; i++) {
        ledsToggle(LED0);
        ledsToggle(LED1);
        ledsToggle(LED2);
        ledsToggle(LED3);
        delay_ms(100);
    }

    ledsOffAll();
}


