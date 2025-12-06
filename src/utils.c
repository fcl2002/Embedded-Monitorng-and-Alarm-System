#include "utils.h"

void delay_ms(unsigned int ms){
    volatile unsigned int i;
    while(ms--){
        for(i=0; i<3000; i++);
    }
}

int strToInt(const char *str){
    int num = 0;
    while(*str >= '0' && *str <= '9'){
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

void intToStr(int value, char *str){
    int i = 0;
    int isNegative = 0;

    if(value == 0){
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if(value < 0){
        isNegative = 1;
        value = -value;
    }

    while(value > 0){
        str[i++] = (value % 10) + '0';
        value /= 10;
    }

    if(isNegative){
        str[i++] = '-';
    }

    str[i] = '\0';

    
    int start = 0;
    int end = i - 1;
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}