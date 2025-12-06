#include "adc.h"
#include "LPC11xx.h"
#include "bits.h"

// mudar

void adcInit(void) {
    // Habilita o clock para o bloco IOCON e ADC
    bitSet(LPC_SYSCON->SYSAHBCLKCTRL, 16); // IOCON (UM10398, 3.5.14)
    bitSet(LPC_SYSCON->SYSAHBCLKCTRL, 13); // ADC (UM10398, 3.5.14)

    LPC_SYSCON->PDRUNCFG      &= ~(1<<4);   // ativar o AD (UM10398,3.5.36)

    // configurar o pino PIO0_11 (AD0) como entrada analógica (UM10398, 7.4.29)
    // FUNC=2, MODE=0 e ADMODE=0
    LPC_IOCON->R_PIO0_11 = 0x02;

    // selecionar o canal AD0 e configurar seu clock para 4 MHz (UM10398, 25.5.1)
    // SEL=0, CLKDIV=11, BURST=0, CLKS=00
    LPC_ADC->CR = (1<<0) | (11<<8);
}

unsigned int adcRead(void){
    LPC_ADC->CR |= (1 << 24); // inicia conversão (bit START)

    while ((LPC_ADC->DR[0] & (1 << 31)) == 0); // espera fim (bit DONE)

    return (LPC_ADC->DR[0] >> 6) & 0x3FF; // extrai os 10 bits (resultado)
}
