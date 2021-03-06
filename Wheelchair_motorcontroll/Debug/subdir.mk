################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CAN_thread.cpp \
../Deback_thread.cpp \
../PID.cpp \
../V_Control.cpp \
../Velocity_thread.cpp \
../main.cpp \
../motordriver.cpp \
../read_velocity.cpp 

OBJS += \
./CAN_thread.o \
./Deback_thread.o \
./PID.o \
./V_Control.o \
./Velocity_thread.o \
./main.o \
./motordriver.o \
./read_velocity.o 

CPP_DEPS += \
./CAN_thread.d \
./Deback_thread.d \
./PID.d \
./V_Control.d \
./Velocity_thread.d \
./main.d \
./motordriver.d \
./read_velocity.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__CODE_RED -DCPP_USE_HEAP -D__CORTEX_M3 -DTOOLCHAIN_GCC -DARM_MATH_CM3 -DTARGET_CORTEX_M -DTARGET_LPC176X -DTARGET_NXP -DTARGET_MBED_LPC1768 -DMBED_BUILD_TIMESTAMP=1447578655.39 -DTARGET_LPC1768 -DTARGET_M3 -DTOOLCHAIN_GCC_CR -D__MBED__=1 -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/ACM1602NI" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/QEI" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos/rtos" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos/rtx" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos/rtx/TARGET_CORTEX_M" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3/TOOLCHAIN_GCC" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/SDFileSystem" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/SDFileSystem/FATFileSystem" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/SDFileSystem/FATFileSystem/ChaN" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed/TARGET_LPC1768" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed/TARGET_LPC1768/TARGET_NXP" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_motorcontroll/mbed/TARGET_LPC1768/TOOLCHAIN_GCC_CR" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


