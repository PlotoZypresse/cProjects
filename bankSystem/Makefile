
# Makefile for compiling bankSystem.c and bankAcc.c using LLVM's clang compiler

# Compiler settings - Change these if needed
CC=clang
CFLAGS=-Wall -g

# Target executable name
TARGET=bankSystem

# Source files
SRC=bankSystem.c bankAcc.c bankLL.c ui.c

# Build target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Phony target for cleaning up
clean:
	rm -f $(TARGET)

# Phony target to run the program
run: $(TARGET)
	./$(TARGET)
