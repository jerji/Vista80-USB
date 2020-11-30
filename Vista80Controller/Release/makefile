################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include usbdrv/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(M_DEPS)),)
-include $(M_DEPS)
endif
ifneq ($(strip $(CP_DEPS)),)
-include $(CP_DEPS)
endif
ifneq ($(strip $(MI_DEPS)),)
-include $(MI_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(M_UPPER_DEPS)),)
-include $(M_UPPER_DEPS)
endif
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(MII_DEPS)),)
-include $(MII_DEPS)
endif
ifneq ($(strip $(MM_DEPS)),)
-include $(MM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
FLASH_IMAGE += \
Vista80Controller.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Vista80Controller.elf secondary-outputs

# Tool invocations
Vista80Controller.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,Vista80Controller.map,--cref -mrelax -Wl,--gc-sections -mmcu=attiny4313 -o "Vista80Controller.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Vista80Controller.hex: Vista80Controller.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Vista80Controller.elf  "Vista80Controller.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Vista80Controller.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny4313 Vista80Controller.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Vista80Controller.elf
	@echo 'Invoking: AVRDude'
	/usr/bin/avrdude -pt4313 -cusbasp -u -Uflash:w:Vista80Controller.hex:a -Ulfuse:w:0xee:m -Uhfuse:w:0xd9:m -Uefuse:w:0xff:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(M_DEPS)$(CP_DEPS)$(MI_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(M_UPPER_DEPS)$(I_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(MII_DEPS)$(MM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) Vista80Controller.elf
	-@echo ' '

secondary-outputs: $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
