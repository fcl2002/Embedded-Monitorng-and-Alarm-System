#include "buttons.h"
#include "event.h"
#include "bits.h"
static unsigned int key_ant;

void eventInit(void) {
	buttonsInit();
    key_ant = 0;
}

unsigned int eventRead(void) {
    int key;
    int ev = EV_NOEVENT;
    key = buttonsRead();
    if (key != key_ant) {
        if (bitTst(key, BUTTON_RIGHT1_ID)) {
            ev = EV_RIGHT;
        }

        if (bitTst(key, BUTTON_LEFT1_ID)) {
            ev = EV_LEFT;
        }

        if (bitTst(key, BUTTON_CONFIRM1_ID)) {
            ev = EV_ENTER;
        }
    }

    key_ant = key;
    return ev;
}
