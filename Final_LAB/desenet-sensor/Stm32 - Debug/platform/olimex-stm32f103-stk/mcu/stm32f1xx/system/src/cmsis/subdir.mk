################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/system_stm32f10x.c \
../common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/vectors_stm32f10x.c 

OBJS += \
./platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/system_stm32f10x.o \
./platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/vectors_stm32f10x.o 

C_DEPS += \
./platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/system_stm32f10x.d \
./platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/vectors_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/system_stm32f10x.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/system_stm32f10x.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/interfaces -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/vectors_stm32f10x.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/vectors_stm32f10x.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/interfaces -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


