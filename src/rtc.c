#include "rtc.h"

#include "i2c.h"
#include "serial.h"

unsigned char bcdToDec(unsigned char bcd){
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

unsigned char decToBcd(unsigned char dec){
    return ((dec / 10) << 4) | (dec % 10);
}

void mcp7940Init(void){

    unsigned char sec = i2cReadReg(MCP7940_ADDR, MCP_REG_SECONDS);

    if(!(sec & 0x80)){

        sec |= 0x80;
        i2cWriteReg(MCP7940_ADDR, MCP_REG_SECONDS, sec);

    }
}

unsigned char mcpReadReg(unsigned char reg){
    return i2cReadReg(MCP7940_ADDR, reg);
}

void mcpWriteReg(unsigned char reg, unsigned char value){
    i2cWriteReg(MCP7940_ADDR, reg, value);
}

unsigned char mcpReadSram(unsigned char addr) {
    if (addr < 0x20 || addr > 0x5F) return 0;
    return i2cReadReg(MCP7940_ADDR, addr);
}

void mcpWriteSram(unsigned char addr, unsigned char data) {
    if (addr < 0x20 || addr > 0x5F) return;
    i2cWriteReg(MCP7940_ADDR, addr, data);
}
