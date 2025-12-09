################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/app/AppModel.cpp \
../src/app/EventBus.cpp \
../src/app/StateMachine.cpp 

CPP_DEPS += \
./src/app/AppModel.d \
./src/app/EventBus.d \
./src/app/StateMachine.d 

OBJS += \
./src/app/AppModel.o \
./src/app/EventBus.o \
./src/app/StateMachine.o 


# Each subdirectory must supply rules for building sources it contributes
src/app/%.o: ../src/app/%.cpp src/app/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-buildroot-linux-gnueabi-g++ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config libegt --cflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-app

clean-src-2f-app:
	-$(RM) ./src/app/AppModel.d ./src/app/AppModel.o ./src/app/EventBus.d ./src/app/EventBus.o ./src/app/StateMachine.d ./src/app/StateMachine.o

.PHONY: clean-src-2f-app

