/*
 * buttons.h
 *
 *  Created on: 7 de mai. de 2025
 *      Author: Fernando
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#define BUTTON_UP1_ID      0
#define BUTTON_RIGHT1_ID   1
#define BUTTON_DOWN1_ID    2
#define BUTTON_LEFT1_ID    3
#define BUTTON_CONFIRM1_ID 4

void buttonsInit(void);
void buttonsDebounce(void);
unsigned int buttonsRead(void);

#endif /* BUTTONS_H_ */
