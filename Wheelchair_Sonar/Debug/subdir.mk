################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Ping.cpp \
../main.cpp 

OBJS += \
./Ping.o \
./main.o 

CPP_DEPS += \
./Ping.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__CODE_RED -DCPP_USE_HEAP -D__CORTEX_M0 -DTARGET_LPC1114 -DTOOLCHAIN_GCC -DTARGET_CORTEX_M -DARM_MATH_CM0 -DTARGET_NXP -DTOOLCHAIN_GCC_CR -DTARGET_M0 -DTARGET_LPC11XX -DMBED_BUILD_TIMESTAMP=1451194533.25 -D__MBED__=1 -DTARGET_LPC11XX_11CXX -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed/TARGET_LPC1114" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed/TARGET_LPC1114/TARGET_NXP" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed/TARGET_LPC1114/TARGET_NXP/TARGET_LPC11XX_11CXX" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed/TARGET_LPC1114/TARGET_NXP/TARGET_LPC11XX_11CXX/TARGET_LPC11XX" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_Sonar/mbed/TARGET_LPC1114/TOOLCHAIN_GCC_CR" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m0 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


