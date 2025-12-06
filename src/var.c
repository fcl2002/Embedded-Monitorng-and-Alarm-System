#include "var.h"
#include "stateMachine.h"  // Para usar as constantes STATE_*

// Variáveis globais do sistema
static char state;
static char language;
static int alarme_tresh_max; // Holds the alarm threshold value
static int alarme_tresh_min;

// Estruturas de tempo
static struct {
    char hour;
    char minute;
    char second;
} current_time;

void varInit(void) {
    state = STATE_TEMPO;    // Estado inicial como TEMPO (horário)

    // Inicializa tempo atual: 12:00:00
    current_time.hour = 12;
    current_time.minute = 0;
    current_time.second = 0;

    // Initialize alarm threshold
    alarme_tresh_max = 100; // Default value

    alarme_tresh_min = 50;
    language = 0;       // Idioma inicial (Português)
}

char getState(void) {
    return state;
}

void setState(char newState) {
    state = newState;
}

// Funções para tempo atual
void getTimeString(char* timeStr) {
    // Formato: "HH:MM:SS"
    timeStr[0] = (current_time.hour / 10) + '0';
    timeStr[1] = (current_time.hour % 10) + '0';
    timeStr[2] = ':';
    timeStr[3] = (current_time.minute / 10) + '0';
    timeStr[4] = (current_time.minute % 10) + '0';
    timeStr[5] = ':';
    timeStr[6] = (current_time.second / 10) + '0';
    timeStr[7] = (current_time.second % 10) + '0';
    timeStr[8] = '\0';
}

void incrementTimeHour(void) {
    current_time.hour++;
    if (current_time.hour >= 60) current_time.hour = 0;
}

void decrementTimeHour(void) {
    if (current_time.hour <= 0) current_time.hour = 59;
    else current_time.hour--;
}

void incrementTimeMinute(void) {
    current_time.minute++;
    if (current_time.minute >= 60) current_time.minute = 0;
}

void decrementTimeMinute(void) {
    if (current_time.minute <= 0) current_time.minute = 59;
    else current_time.minute--;
}

void incrementTimeSecond(void) {
	current_time.second++;
    if (current_time.second >= 60) current_time.second = 0;
}

void decrementTimeSecond(void) {
    if (current_time.second <= 0) current_time.second = 59;
    else current_time.second--;
}


// --- New and corrected alarm threshold functions ---
int getAlarmeTreshMax(void) {
	return alarme_tresh_max;
}

void incrementAlarmeTreshMax(void) {
	alarme_tresh_max++;
}

void decrementAlarmeTreshMax(void) {
	alarme_tresh_max--;
}

int getAlarmeTreshMin(void) {
	return alarme_tresh_min;
}

void incrementAlarmeTreshMin(void) {
	alarme_tresh_min++;
}

void decrementAlarmeTreshMin(void) {
	alarme_tresh_min--;
}

char getLanguage(void) {
    return language;
}

void setLanguage(char newLanguage) {
    // Só tem 2 idiomas (0 e 1)
    // Usando resto para evitar colocar valor errado
    language = newLanguage % 2;
}
