# Compiler and common flags
CC = g++
CFLAGS = -Iinclude -Wall -Werror -Wextra -Wpedantic

# Directories and source files
SRC := $(wildcard ./source/*.cpp)
BUILD = build
TARGET = main

# Libraries
LDFLAGS = -Llibraries -lraylib -lm -ldl -lpthread -lGL -lX11

# Default target
all: $(BUILD)/$(TARGET)

# Create the build directory if it doesn't exist
$(BUILD):
	mkdir -p $(BUILD)

# Build target for app
$(BUILD)/$(TARGET): $(SRC) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Run the program after building
run: $(BUILD)/$(TARGET)
	cd $(BUILD) && ./$(TARGET)

# Clean the build directory
clean:
	rm -rf $(BUILD)

.PHONY: all run clean
