CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lSDL -lSDL_image -lSDL_ttf -lm

Enigma:	display.o machine.o main.o
	$(CC) $(CFLAGS) display.o machine.o main.o -o Enigma $(LDFLAGS)

main.o : main.c const.h
	$(CC) $(CFLAGS) main.c -c

display.o : display.c display.h
	$(CC) $(CFLAGS) display.c -c

machine.o : machine.c machine.h
	$(CC) $(CFLAGS) machine.c -c

clean:
	rm -f *.o Enigma
