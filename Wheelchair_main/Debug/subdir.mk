################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CAN_Thread.cpp \
../ControllDistance.cpp \
../ControllHeading.cpp \
../Distance_Thread.cpp \
../Heading_Thread.cpp \
../IMU.cpp \
../Mode1.cpp \
../Mode2.cpp \
../Mode3.cpp \
../ModeCompassCalibrate.cpp \
../ModePIDTuning.cpp \
../ModeSensorDeback.cpp \
../PIDcontroller.cpp \
../SD_Thread.cpp \
../SRF02.cpp \
../Ultrasonic.cpp \
../Ultrasonic_Front.cpp \
../main.cpp 

OBJS += \
./CAN_Thread.o \
./ControllDistance.o \
./ControllHeading.o \
./Distance_Thread.o \
./Heading_Thread.o \
./IMU.o \
./Mode1.o \
./Mode2.o \
./Mode3.o \
./ModeCompassCalibrate.o \
./ModePIDTuning.o \
./ModeSensorDeback.o \
./PIDcontroller.o \
./SD_Thread.o \
./SRF02.o \
./Ultrasonic.o \
./Ultrasonic_Front.o \
./main.o 

CPP_DEPS += \
./CAN_Thread.d \
./ControllDistance.d \
./ControllHeading.d \
./Distance_Thread.d \
./Heading_Thread.d \
./IMU.d \
./Mode1.d \
./Mode2.d \
./Mode3.d \
./ModeCompassCalibrate.d \
./ModePIDTuning.d \
./ModeSensorDeback.d \
./PIDcontroller.d \
./SD_Thread.d \
./SRF02.d \
./Ultrasonic.d \
./Ultrasonic_Front.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -D__NEWLIB__ -D__CODE_RED -DCPP_USE_HEAP -D__CORTEX_M3 -DTOOLCHAIN_GCC -DMBED_BUILD_TIMESTAMP=1450540452.17 -DARM_MATH_CM3 -DTARGET_CORTEX_M -DTARGET_LPC176X -DTARGET_NXP -DTARGET_MBED_LPC1768 -DTARGET_LPC1768 -DTARGET_M3 -DTOOLCHAIN_GCC_CR -D__MBED__=1 -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/LSM9DS0" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos/rtos" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos/rtx" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos/rtx/TARGET_CORTEX_M" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed-rtos/rtx/TARGET_CORTEX_M/TARGET_M3/TOOLCHAIN_GCC" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/SDFileSystem" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/SDFileSystem/FATFileSystem" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/SDFileSystem/FATFileSystem/ChaN" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/ACM1602NI" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed/TARGET_LPC1768" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed/TARGET_LPC1768/TARGET_NXP" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed/TARGET_LPC1768/TARGET_NXP/TARGET_LPC176X/TARGET_MBED_LPC1768" -I"/Users/mori/LPCXpresso/workspace/Wheelchair_main/mbed/TARGET_LPC1768/TOOLCHAIN_GCC_CR" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


