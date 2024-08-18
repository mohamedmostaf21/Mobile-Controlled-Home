################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/PWM/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Siren/subdir.mk
-include HAL/Servo/subdir.mk
-include HAL/SEVEN_SEGMENT/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Bluetooth_Module/subdir.mk
-include APP/Initialization/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVR_DRIVERS.lss \

FLASH_IMAGE += \
AVR_DRIVERS.hex \

EEPROM_IMAGE += \
AVR_DRIVERS.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_DRIVERS.elf secondary-outputs

# Tool invocations
AVR_DRIVERS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_DRIVERS.map -mmcu=atmega32 -o "AVR_DRIVERS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_DRIVERS.lss: AVR_DRIVERS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_DRIVERS.elf  >"AVR_DRIVERS.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_DRIVERS.hex: AVR_DRIVERS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_DRIVERS.elf  "AVR_DRIVERS.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVR_DRIVERS.eep: AVR_DRIVERS.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVR_DRIVERS.elf  "AVR_DRIVERS.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_DRIVERS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_DRIVERS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_DRIVERS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
