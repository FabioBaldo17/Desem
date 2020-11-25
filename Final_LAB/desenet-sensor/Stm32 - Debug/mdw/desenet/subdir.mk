################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/mdw/desenet/beacon.cpp \
../common/mdw/desenet/frame.cpp \
../common/mdw/desenet/networkinterfacedriver.cpp \
../common/mdw/desenet/networktimeprovider.cpp 

OBJS += \
./mdw/desenet/beacon.o \
./mdw/desenet/frame.o \
./mdw/desenet/networkinterfacedriver.o \
./mdw/desenet/networktimeprovider.o 

CPP_DEPS += \
./mdw/desenet/beacon.d \
./mdw/desenet/frame.d \
./mdw/desenet/networkinterfacedriver.d \
./mdw/desenet/networktimeprovider.d 


# Each subdirectory must supply rules for building sources it contributes
mdw/desenet/beacon.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet/beacon.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/frame.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet/frame.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/networkinterfacedriver.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet/networkinterfacedriver.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mdw/desenet/networktimeprovider.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet/networktimeprovider.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DTC_STM32 -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/cmsis -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/include/stm32f1-stdperiph -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/target -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/olimex-stm32f103-stk/board -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


