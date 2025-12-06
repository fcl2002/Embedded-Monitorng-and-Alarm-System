/*
 * buttons.c
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */

#include "buttons.h"
#include "io.h"
#include "bits.h"

#define DEBOUNCE_COUNT 5

static unsigned int buttons = 0;
static unsigned int buttonsOld = 0;

static const pin btnPins[5] = {BUTTON_UP1, BUTTON_RIGHT1, BUTTON_DOWN1, BUTTON_LEFT1, BUTTON_CONFIRM1};

void buttonsInit(void){
    pinMode(BUTTON_UP1, INPUT);
    pinMode(BUTTON_RIGHT1, INPUT);
    pinMode(BUTTON_DOWN1, INPUT);
    pinMode(BUTTON_LEFT1, INPUT);
    pinMode(BUTTON_CONFIRM1, INPUT);
}

unsigned int buttonsRead(void){
    return buttons;
}

void buttonsDebounce(void){
    int i;
    static unsigned int tempo;
    static unsigned int newRead;
    static unsigned int stableRead;

    newRead = 0;

    for(i=0; i<5; i++){
        if(digitalRead(btnPins[i]) == LOW){
            bitSet(newRead, i);
        }
    }

    if(stableRead == newRead){
        if(tempo > 0) tempo--;
    }else{
        tempo = DEBOUNCE_COUNT;
        stableRead = newRead;
    }

    if(tempo == 0){
        buttons = stableRead & ~buttonsOld;
        buttonsOld = stableRead;
    }
}





