CC=gcc
CFLAGS=-Wall

all: monitor

monitor: main.o cpu.o memory.o process.o
	$(CC) -o monitor main.o cpu.o memory.o process.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

cpu.o: cpu.c
	$(CC) $(CFLAGS) -c cpu.c

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c

process.o: process.c
	$(CC) $(CFLAGS) -c process.c

clean:
	rm -f *.o monitor