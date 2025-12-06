/*
 * File:   stateMachine.h
 * Author: Avell
 *
 * Created on 18 de Junho de 2017, 22:17
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H


//estados da maquina de Estados
enum {
    STATE_ALARME_MAX, // Renomeado de STATE_ALARME
    STATE_TEMPO,
    STATE_IDIOMA,
    STATE_ALARME_MIN, // Novo estado para o valor mínimo
    STATE_FIM
};


void smInit(void);
void smLoop(void);


#endif	/* STATEMACHINE_H */
