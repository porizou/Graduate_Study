################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed/TARGET_LPC1768/TOOLCHAIN_GCC_CR/subdir.mk
-include mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3/TOOLCHAIN_GCC/subdir.mk
-include mbed-rtos/rtx/TARGET_CORTEX_M/subdir.mk
-include mbed-rtos/rtos/subdir.mk
-include SDFileSystem/FATFileSystem/ChaN/subdir.mk
-include SDFileSystem/FATFileSystem/subdir.mk
-include SDFileSystem/subdir.mk
-include QEI/subdir.mk
-include ACM1602NI/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Wheelchair_motorcontrol.axf

# Tool invocations
Wheelchair_motorcontrol.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/ACM1602NI" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/QEI" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos/rtos" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos/rtx" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos/rtx/TARGET_CORTEX_M" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3/TOOLCHAIN_GCC" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/SDFileSystem" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/SDFileSystem/FATFileSystem" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/SDFileSystem/FATFileSystem/ChaN" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768/TARGET_NXP" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768" -L"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768/TOOLCHAIN_GCC_CR" -Xlinker -Map="Wheelchair_motorcontrol.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontrol/mbed/TARGET_LPC1768/TOOLCHAIN_GCC_CR/LPC1768.ld" -o "Wheelchair_motorcontrol.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) Wheelchair_motorcontrol.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Wheelchair_motorcontrol.axf"; arm-none-eabi-objcopy -O binary "Wheelchair_motorcontrol.axf" "Wheelchair_motorcontrol.bin" ; # checksum -p LPC1768 -d "Wheelchair_motorcontrol.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
