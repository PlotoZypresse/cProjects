
# Makefile for compiling bankSystem.c using LLVM's clang compiler

# Compiler settings - Change these if needed
CC=clang
CFLAGS=-Wall -g

# Target executable name
TARGET=bankSystem

# Build target
$(TARGET): bankSystem.c
	$(CC) $(CFLAGS) bankSystem.c -o $(TARGET)

# Phony target for cleaning up
clean:
	rm -f $(TARGET)

#Phony target to run the program
run: $(TARGET)
	./$(TARGET)
