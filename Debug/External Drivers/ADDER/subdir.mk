################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External\ Drivers/ADDER/crdcs_pq_adder.c 

OBJS += \
./External\ Drivers/ADDER/crdcs_pq_adder.o 

C_DEPS += \
./External\ Drivers/ADDER/crdcs_pq_adder.d 


# Each subdirectory must supply rules for building sources it contributes
External\ Drivers/ADDER/crdcs_pq_adder.o: ../External\ Drivers/ADDER/crdcs_pq_adder.c External\ Drivers/ADDER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"External Drivers/ADDER/crdcs_pq_adder.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-External-20-Drivers-2f-ADDER

clean-External-20-Drivers-2f-ADDER:
	-$(RM) ./External\ Drivers/ADDER/crdcs_pq_adder.d ./External\ Drivers/ADDER/crdcs_pq_adder.o

.PHONY: clean-External-20-Drivers-2f-ADDER

