/*
 * output.h
 *
 * Sistema de saída para máquina de estados
 * Gerencia a exibição no LCD
 * Adaptado para LPC11Uxx
 *
 * Grupo 06 - PBL02 - UNIFEI
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_


/**
 * @brief Inicializa o sistema de saída (LCD)
 */
void outputInit(void);

/**
 * @brief Imprime informações na tela baseado no estado e idioma
 * @param numTela Estado atual da máquina de estados
 * @param idioma Idioma selecionado (0=Português, 1=Inglês)
 */
void outputPrint(int numTela, int idioma);

#endif /* OUTPUT_H_ */
