################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c 

OBJS += \
./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o 

C_DEPS += \
./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.o Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.su Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.cyclo: ../Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/%.c Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -DSTM32F411xE -c -I../Inc -I/home/last_knight/Documents/STM32-BareMetal_Workspace/chip_headers/CMSIS/Device/ST/STM32F4xx/Include -I/home/last_knight/Documents/STM32-BareMetal_Workspace/chip_headers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates

clean-Inc-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates:
	-$(RM) ./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.cyclo ./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.d ./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.o ./Inc/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.su

.PHONY: clean-Inc-2f-CMSIS-2f-Device-2f-ST-2f-STM32F4xx-2f-Source-2f-Templates

