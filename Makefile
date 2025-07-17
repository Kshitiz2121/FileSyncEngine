# Compiler
CC = gcc

# Executable name
TARGET = file_sync_engine.exe

# Source files
SRCS = main.c file_reader.c version_tracker.c diff_engine.c merge_engine.c

# Object files
OBJS = $(SRCS:.c=.o)

# Flags
CFLAGS = -Wall -Wextra -std=c11

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up build artifacts
clean:
	del /f /q $(TARGET) *.o merged_output.txt 2>nul || echo Cleaned.

.PHONY: all run clean
