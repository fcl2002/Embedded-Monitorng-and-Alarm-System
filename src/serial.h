#ifndef SERIAL_H
#define SERIAL_H

void serialInit(void);
void serialSendChar(char c);
void serialSendString(const char *str);
int serialReadChar(void);
//int serialReadInt(void);
void serialSendInt(int value);

// FUNÇÕES PARA O RTC
void serialSendTime(void);
void serialSendDate(void);
void serialSendDateTime(void);

#endif // SERIAL_H