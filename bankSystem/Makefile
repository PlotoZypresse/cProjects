# Makefile for compiling bankSystem using LLVM's clang compiler

# Compiler settings
CC=clang
CFLAGS=-Wall -g -Iinclude -Wextra -Werror -pedantic-errors -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes

# Target executable name
TARGET=bankSystem

# Directories
SRCDIR=src
INCDIR=include
BINDIR=bin
BUILDDIR=build
TESTDIR=tests

# Source files
SRC=$(wildcard $(SRCDIR)/*.c)

# Object files (located in the build directory)
OBJ=$(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Default build target
all: $(BINDIR)/$(TARGET)

# Build target
$(BINDIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# To obtain object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony target for cleaning up
clean:
	rm -f $(BUILDDIR)/*.o $(BINDIR)/$(TARGET)

# Phony target to run the program
run: $(BINDIR)/$(TARGET)
	./$(BINDIR)/$(TARGET)

# Phony target for building and running tests
test:
	# Add commands to compile and run tests here if needed

# Include dependencies
-include $(OBJ:.o=.d)

# Generate dependencies
$(BUILDDIR)/%.d: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -M $< -MT $(@:.d=.o) -MF $@
