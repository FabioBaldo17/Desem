################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/platform/linux-meshsim/board/display/simpledisplay.cpp 

OBJS += \
./platform/linux-meshsim/board/display/simpledisplay.o 

CPP_DEPS += \
./platform/linux-meshsim/board/display/simpledisplay.d 


# Each subdirectory must supply rules for building sources it contributes
platform/linux-meshsim/board/display/simpledisplay.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/display/simpledisplay.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


