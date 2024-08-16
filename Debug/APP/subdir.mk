################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/App.c \
../APP/TestADC.c \
../APP/Test_Bluetooth.c \
../APP/Test_Servo.c \
../APP/Test_Siren.c \
../APP/Test_UART.c 

OBJS += \
./APP/App.o \
./APP/TestADC.o \
./APP/Test_Bluetooth.o \
./APP/Test_Servo.o \
./APP/Test_Siren.o \
./APP/Test_UART.o 

C_DEPS += \
./APP/App.d \
./APP/TestADC.d \
./APP/Test_Bluetooth.d \
./APP/Test_Servo.d \
./APP/Test_Siren.d \
./APP/Test_UART.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


