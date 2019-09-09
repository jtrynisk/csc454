################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Animal.cpp \
../src/Creature.cpp \
../src/NPC.cpp \
../src/PC.cpp \
../src/Project1.cpp \
../src/Room.cpp \
../src/main.cpp 

OBJS += \
./src/Animal.o \
./src/Creature.o \
./src/NPC.o \
./src/PC.o \
./src/Project1.o \
./src/Room.o \
./src/main.o 

CPP_DEPS += \
./src/Animal.d \
./src/Creature.d \
./src/NPC.d \
./src/PC.d \
./src/Project1.d \
./src/Room.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


