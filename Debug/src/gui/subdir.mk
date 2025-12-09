################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gui/DashboardView.cpp 

CPP_DEPS += \
./src/gui/DashboardView.d 

OBJS += \
./src/gui/DashboardView.o 


# Each subdirectory must supply rules for building sources it contributes
src/gui/%.o: ../src/gui/%.cpp src/gui/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-buildroot-linux-gnueabi-g++ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config libegt --cflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-gui

clean-src-2f-gui:
	-$(RM) ./src/gui/DashboardView.d ./src/gui/DashboardView.o

.PHONY: clean-src-2f-gui

