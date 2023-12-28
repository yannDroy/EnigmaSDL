CC = gcc
CFLAGS = -g -Wall -I.\SDL2\include -L.\SDL2\lib
LDFLAGS = -lm -lmingw32 -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf

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
