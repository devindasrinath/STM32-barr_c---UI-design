################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External\ Drivers/TIMER/crdcs_pq_timer.c 

OBJS += \
./External\ Drivers/TIMER/crdcs_pq_timer.o 

C_DEPS += \
./External\ Drivers/TIMER/crdcs_pq_timer.d 


# Each subdirectory must supply rules for building sources it contributes
External\ Drivers/TIMER/crdcs_pq_timer.o: ../External\ Drivers/TIMER/crdcs_pq_timer.c External\ Drivers/TIMER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"External Drivers/TIMER/crdcs_pq_timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-External-20-Drivers-2f-TIMER

clean-External-20-Drivers-2f-TIMER:
	-$(RM) ./External\ Drivers/TIMER/crdcs_pq_timer.d ./External\ Drivers/TIMER/crdcs_pq_timer.o

.PHONY: clean-External-20-Drivers-2f-TIMER

