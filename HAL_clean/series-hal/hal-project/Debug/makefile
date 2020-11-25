################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/subdir.mk
-include platform/platform-common/board/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/stm32f1-stdperiph/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/newlib/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/diag/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cortexm/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/system/src/cmsis/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/hal/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/stm32f1xx/critical/subdir.mk
-include platform/olimex-stm32f103-stk/mcu/subdir.mk
-include platform/olimex-stm32f103-stk/board/shared-spi/subdir.mk
-include platform/olimex-stm32f103-stk/board/display/subdir.mk
-include platform/olimex-stm32f103-stk/board/subdir.mk
-include platform/olimex-stm32f103-stk/subdir.mk
-include mdw/gui/subdir.mk
-include app/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
hal-project.hex \

SECONDARY_SIZE += \
hal-project.siz \


# All Target
all: hal-project.elf secondary-outputs

# Tool invocations
hal-project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Wall -Wextra  -g3 -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"/home/fabio/Documents/GitHub/Desem/HAL_clean/series-hal/hal-project/../common/platform/olimex-stm32f103-stk/mcu/stm32f1xx/ldscripts" -Wl,-Map,"hal-project.map" --specs=nano.specs -o "hal-project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

hal-project.hex: hal-project.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "hal-project.elf"  "hal-project.hex"
	@echo 'Finished building: $@'
	@echo ' '

hal-project.siz: hal-project.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "hal-project.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) hal-project.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
