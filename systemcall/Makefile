CC = gcc
CFLAGS = -Wall -g

# Object files
OBJS = program.o syscall_lib.o syscall.o intr.o kernel.o global.o

# Executable name
TARGET = program

# Compile and link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	rm $(OBJS)

# Compile source files into object files
program.o: program.c syscall_lib.h
	$(CC) $(CFLAGS) -c program.c

syscall_lib.o: syscall_lib.c syscall_lib.h syscall.h
	$(CC) $(CFLAGS) -c syscall_lib.c

syscall.o: syscall.c syscall.h intr.h
	$(CC) $(CFLAGS) -c syscall.c

intr.o: intr.c intr.h kernel.h global.h privileged.h
	$(CC) $(CFLAGS) -c intr.c

kernel.o: kernel.c kernel.h
	$(CC) $(CFLAGS) -c kernel.c

global.o : global.c
	$(CC) $(CFLAGS) -c global.c

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
