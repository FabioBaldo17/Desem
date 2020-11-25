################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/platform/linux-meshsim/board/board.cpp \
../common/platform/linux-meshsim/board/joystick.cpp \
../common/platform/linux-meshsim/board/ledcontroller.cpp \
../common/platform/linux-meshsim/board/meshsimboard.cpp \
../common/platform/linux-meshsim/board/trace.cpp 

OBJS += \
./platform/linux-meshsim/board/board.o \
./platform/linux-meshsim/board/joystick.o \
./platform/linux-meshsim/board/ledcontroller.o \
./platform/linux-meshsim/board/meshsimboard.o \
./platform/linux-meshsim/board/trace.o 

CPP_DEPS += \
./platform/linux-meshsim/board/board.d \
./platform/linux-meshsim/board/joystick.d \
./platform/linux-meshsim/board/ledcontroller.d \
./platform/linux-meshsim/board/meshsimboard.d \
./platform/linux-meshsim/board/trace.d 


# Each subdirectory must supply rules for building sources it contributes
platform/linux-meshsim/board/board.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/board.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/linux-meshsim/board/joystick.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/joystick.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/linux-meshsim/board/ledcontroller.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/ledcontroller.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/linux-meshsim/board/meshsimboard.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/meshsimboard.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/linux-meshsim/board/trace.o: /home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board/trace.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DDEBUG -DTC_MESHSIM -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/app -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/xf -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/mdw/desenet -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/platform-common/board -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/mcu -I/home/fabio/Documents/GitHub/Desem/Final_LAB/desenet-sensor/common/platform/linux-meshsim/board -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


