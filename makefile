# Compiler and assembler variables
CC = gcc
ASM = nasm

# Compiler and assembler flags
CFLAGS = -g -Wall -masm=intel
ASMFLAGS = -g -f elf64

# Source files
CFILES = main.c cFunctions.c
ASMFILES = caesar.asm

# Object files
OBJECTS = main.o cFunctions.o caesar.o

# Output executable
EXEC = proj4

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble assembly files
%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Phony targets
.PHONY: all clean
