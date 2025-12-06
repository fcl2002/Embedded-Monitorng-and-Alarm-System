/*
 * leds.h
 *
 *  Created on: 25 de jun. de 2025
 *      Author: Fernando
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "io.h"

void ledsInit(void);
void ledsOnAll(void);
void ledsOffAll(void);
void ledsToggle(pin led);
void ledsToggleAll(void);
void ledsSet(pin led, int value);
void ledsShow(void);

#endif /* LEDS_H_ */
