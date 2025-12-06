#include "var.h"
#include "stateMachine.h"
#include "event.h"
#include "output.h"
#include "lcd.h"
#include "buttons.h"
#include "utils.h" // Adicionado para delay_ms

void smInit(void) {
    varInit(); // É importante chamar varInit() para inicializar os valores
    setState(STATE_TEMPO);
    outputPrint(getState(), getLanguage()); // Mostra a tela inicial
}

void smLoop(void) {
    unsigned char evento;

    //máquina de estados
    evento = eventRead();

    switch (getState()) {
        case STATE_TEMPO:
        	// Execução de atividade no estado TEMPO
			if (evento == EV_RIGHT) {
				incrementTimeMinute();
			}
			if (evento == EV_LEFT) {
				decrementTimeMinute();
			}

			// Debug: Se for UP ou DOWN, mostra informação rapidamente
			if (evento == EV_UP) {
				lcdClear();
				lcdSetCursor(0, 0);
				lcdString("ESTADO: TEMPO   ");
				lcdSetCursor(1, 0);
				lcdString("TOP             ");
				delay_ms(150);
				outputPrint(getState(), getLanguage());
				return;
			}
			if (evento == EV_DOWN) {
				lcdClear(); // Corrigido: adicionado ()
				lcdSetCursor(0, 0);
				lcdString("ESTADO: TEMPO   ");
				lcdSetCursor(1, 0);
				lcdString("DOWN            ");
				delay_ms(150);
				outputPrint(getState(), getLanguage());
				return;
			}

			// Gestão da máquina de estado
			if (evento == EV_ENTER) {
				setState(STATE_IDIOMA);
			}
			break;

        case STATE_IDIOMA:
        	// Execução de atividade no estado IDIOMA
			if (evento == EV_RIGHT || evento == EV_LEFT) {
				setLanguage(getLanguage() + 1);
			}

			// Debug: Se for UP ou DOWN, mostra informação rapidamente
			if (evento == EV_UP) {
				lcdClear();
				lcdSetCursor(0, 0);
				lcdString("ESTADO: IDIOMA  ");
				lcdSetCursor(1, 0);
				lcdString("TOP             ");
				delay_ms(150);
				outputPrint(getState(), getLanguage());
				return;
			}
			if (evento == EV_DOWN) {
				lcdClear();
				lcdSetCursor(0, 0);
				lcdString("ESTADO: IDIOMA  ");
				lcdSetCursor(1, 0);
				lcdString("DOWN            ");
				delay_ms(150);
				outputPrint(getState(), getLanguage());
				return;
			}

			// Gestão da máquina de estado
			if (evento == EV_ENTER) {
				setState(STATE_ALARME_MIN); // Transição para o novo estado ALARME_MIN
			}
			break;

        case STATE_ALARME_MIN: // NOVO ESTADO PARA O LIMIAR MÍNIMO
                if (evento == EV_RIGHT) {
                	incrementAlarmeTreshMin(); // Chama a função do Mínimo
                }
                if (evento == EV_LEFT) {
                    decrementAlarmeTreshMin(); // Chama a função do Mínimo
                }

                // Bloco de debug copiado e ajustado
                if (evento == EV_UP) {
                    lcdClear();
                    lcdSetCursor(0, 0);
                    lcdString("ESTADO: ALARME MIN");
                    lcdSetCursor(1, 0);
                    lcdString("TOP             ");
                    delay_ms(150);
                    outputPrint(getState(), getLanguage());
                    return;
                }
                if (evento == EV_DOWN) {
                    lcdClear();
                    lcdSetCursor(0, 0);
                    lcdString("ESTADO: ALARME MIN");
                    lcdSetCursor(1, 0);
                    lcdString("DOWN            ");
                    delay_ms(150);
                    outputPrint(getState(), getLanguage());
                    return;
                }

                // Gestão da máquina de estado
                if (evento == EV_ENTER) {
                    setState(STATE_ALARME_MAX); // Transição para o estado ALARME_MAX
                }
                break;


    	case STATE_ALARME_MAX: // ESTADO ATUALIZADO PARA O LIMIAR MÁXIMO
                if (evento == EV_RIGHT) {
                	incrementAlarmeTreshMax(); // Chama a função do Máximo
                }
                if (evento == EV_LEFT) {
                    decrementAlarmeTreshMax(); // Chama a função do Máximo
                }

                // Bloco de debug ajustado
                if (evento == EV_UP) {
                    lcdClear();
                    lcdSetCursor(0, 0);
                    lcdString("ESTADO: ALARME MAX");
                    lcdSetCursor(1, 0);
                    lcdString("TOP             ");
                    delay_ms(150);
                    outputPrint(getState(), getLanguage());
                    return;
                }
                if (evento == EV_DOWN) {
                    lcdClear();
                    lcdSetCursor(0, 0);
                    lcdString("ESTADO: ALARME MAX");
                    lcdSetCursor(1, 0);
                    lcdString("DOWN            ");
                    delay_ms(150);
                    outputPrint(getState(), getLanguage());
                    return;
                }

                // Gestão da máquina de estado
                if (evento == EV_ENTER) {
                    setState(STATE_TEMPO); // Volta para o início do ciclo
                }
                break;


		default:
			// Estado inválido - volta para o estado inicial
			setState(STATE_TEMPO);
			break;

    }
    outputPrint(getState(), getLanguage());
}
