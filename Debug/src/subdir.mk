################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/buttons.c \
../src/cr_startup_lpc11xx.c \
../src/crp.c \
../src/event.c \
../src/i2c.c \
../src/io.c \
../src/lcd.c \
../src/leds.c \
../src/main.c \
../src/output.c \
../src/rtc.c \
../src/serial.c \
../src/stateMachine.c \
../src/system_LPC11xx.c \
../src/utils.c \
../src/var.c 

C_DEPS += \
./src/adc.d \
./src/buttons.d \
./src/cr_startup_lpc11xx.d \
./src/crp.d \
./src/event.d \
./src/i2c.d \
./src/io.d \
./src/lcd.d \
./src/leds.d \
./src/main.d \
./src/output.d \
./src/rtc.d \
./src/serial.d \
./src/stateMachine.d \
./src/system_LPC11xx.d \
./src/utils.d \
./src/var.d 

OBJS += \
./src/adc.o \
./src/buttons.o \
./src/cr_startup_lpc11xx.o \
./src/crp.o \
./src/event.o \
./src/i2c.o \
./src/io.o \
./src/lcd.o \
./src/leds.o \
./src/main.o \
./src/output.o \
./src/rtc.o \
./src/serial.o \
./src/stateMachine.o \
./src/system_LPC11xx.o \
./src/utils.o \
./src/var.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11XX__ -D__REDLIB__ -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/adc.d ./src/adc.o ./src/buttons.d ./src/buttons.o ./src/cr_startup_lpc11xx.d ./src/cr_startup_lpc11xx.o ./src/crp.d ./src/crp.o ./src/event.d ./src/event.o ./src/i2c.d ./src/i2c.o ./src/io.d ./src/io.o ./src/lcd.d ./src/lcd.o ./src/leds.d ./src/leds.o ./src/main.d ./src/main.o ./src/output.d ./src/output.o ./src/rtc.d ./src/rtc.o ./src/serial.d ./src/serial.o ./src/stateMachine.d ./src/stateMachine.o ./src/system_LPC11xx.d ./src/system_LPC11xx.o ./src/utils.d ./src/utils.o ./src/var.d ./src/var.o

.PHONY: clean-src

