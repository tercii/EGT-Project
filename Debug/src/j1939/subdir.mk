################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/j1939/DM1Handler.cpp \
../src/j1939/J1939PGNParser.cpp \
../src/j1939/J1939Stack.cpp \
../src/j1939/J1939Transport.cpp 

CPP_DEPS += \
./src/j1939/DM1Handler.d \
./src/j1939/J1939PGNParser.d \
./src/j1939/J1939Stack.d \
./src/j1939/J1939Transport.d 

OBJS += \
./src/j1939/DM1Handler.o \
./src/j1939/J1939PGNParser.o \
./src/j1939/J1939Stack.o \
./src/j1939/J1939Transport.o 


# Each subdirectory must supply rules for building sources it contributes
src/j1939/%.o: ../src/j1939/%.cpp src/j1939/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-buildroot-linux-gnueabi-g++ -O0 -g3 -Wall -c -fmessage-length=0 `pkg-config libegt --cflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-j1939

clean-src-2f-j1939:
	-$(RM) ./src/j1939/DM1Handler.d ./src/j1939/DM1Handler.o ./src/j1939/J1939PGNParser.d ./src/j1939/J1939PGNParser.o ./src/j1939/J1939Stack.d ./src/j1939/J1939Stack.o ./src/j1939/J1939Transport.d ./src/j1939/J1939Transport.o

.PHONY: clean-src-2f-j1939

