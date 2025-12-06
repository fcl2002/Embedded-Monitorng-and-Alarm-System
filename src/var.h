/*
 * var.h
 *
 * Gerenciamento de variáveis globais do sistema
 * Adaptado para LPC11Uxx
 *
 * Grupo 06 - PBL02 - UNIFEI
 */

#ifndef VAR_H_
#define VAR_H_


/**
 * @brief Inicializa as variáveis do sistema com valores padrão
 */
void varInit(void);

/**
 * @brief Obtém o estado atual da máquina de estados
 * @return Estado atual
 */
char getState(void);

/**
 * @brief Define o estado atual da máquina de estados
 * @param newState Novo estado
 */
void setState(char newState);

/**
 * @brief Obtém o tempo atual como string formatada (HH:MM:SS)
 * @param timeStr Ponteiro para buffer de 9 caracteres
 */
void getTimeString(char* timeStr);

void incrementTimeHour(void);
void decrementTimeHour(void);

void incrementTimeSecond(void);
void decrementTimeSecond(void);
/**
 * @brief Incrementa os minutos do tempo atual
 */
void incrementTimeMinute(void);

/**
 * @brief Decrementa os minutos do tempo atual
 */
void decrementTimeMinute(void);

// --- New and corrected alarm threshold functions ---

/**
 * @brief Obtém o valor do limiar (threshold) do alarme
 * @return O valor do limiar
 */
int getAlarmeTreshMax(void);

/**
 * @brief Incrementa o limiar do alarme
 */
void incrementAlarmeTreshMax(void);

/**
 * @brief Decrementa o limiar do alarme
 */
void decrementAlarmeTreshMax(void);

int getAlarmeTreshMin(void);

/**
 * @brief Incrementa o limiar do alarme
 */
void incrementAlarmeTreshMin(void);

/**
 * @brief Decrementa o limiar do alarme
 */
void decrementAlarmeTreshMin(void);
/**
 * @brief Obtém o idioma selecionado
 * @return Idioma (0=Português, 1=Inglês)
 */
char getLanguage(void);

/**
 * @brief Define o idioma
 * @param newLanguage Novo idioma
 */
void setLanguage(char newLanguage);

#endif /* VAR_H_ */
