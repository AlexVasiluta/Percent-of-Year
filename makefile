CC=gcc
CFLAGS=-Wall -O2
time: main.c
	$(CC) -o time main.c $(CFLAGS)
