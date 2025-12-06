/*
 * output.c
 */

#include "output.h"
#include "lcd.h"
#include "stateMachine.h"
#include "var.h"

#define NUM_IDIOMAS 2

// Mensagens com 16 caracteres para cada estado
// [estado][idioma] - 0=Português, 1=Inglês
static char * msgs[STATE_FIM][NUM_IDIOMAS] = {
    {"Limiar Maximo: ", "Max Threshold: "},  // STATE_ALARME_MAX
    {"Alterar tempo  ", "Change time    "},  // STATE_TEMPO
    {"Alterar idioma ", "Change language"},  // STATE_IDIOMA
    {"Limiar Minimo: ", "Min Threshold: "}   // STATE_ALARME_MIN
};

void outputInit(void) {
    lcdInit();
    lcdClear();
}

void outputPrint(int numTela, int idioma) {
    lcdSetCursor(0, 0);
    lcdString(msgs[numTela][idioma]);

    if (numTela == STATE_TEMPO) {
        lcdSetCursor(1, 0);
        char timeStr[9];
        getTimeString(timeStr);
        lcdString(timeStr);
    }
    else if (numTela == STATE_ALARME_MAX) {
        lcdSetCursor(1, 0);
        lcdNumber(getAlarmeTreshMax());
        lcdString("                ");
    }
    else if (numTela == STATE_ALARME_MIN) {
        lcdSetCursor(1, 0);
        lcdNumber(getAlarmeTreshMin());
        lcdString("                ");
    }
    else if (numTela == STATE_IDIOMA) {
        lcdSetCursor(1, 0);
        if (getLanguage() == 0) {
            lcdString("Portugues       ");
        } else {
            lcdString("English         ");
        }
    }
}
