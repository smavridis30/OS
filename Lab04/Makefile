# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = example1.c example2.c example3.c example4.c example5.c

# Object files
OBJECTS = example1 example2 example3 example4 example5

# Default target
all: $(OBJECTS)

# Targets for each file
example1: example1.c
	$(CC) $(CFLAGS) example1.c -o example1

example2: example2.c
	$(CC) $(CFLAGS) example2.c -o example2

example3: example3.c
	$(CC) $(CFLAGS) example3.c -o example3

example4: example4.c
	$(CC) $(CFLAGS) example4.c -o example4

example5: example5.c
	$(CC) $(CFLAGS) example5.c -o example5 

# Clean target to remove compiled files
clean:
	rm -f $(OBJECTS)
