.PHONY: all clean help

OBJ = main.o functions.o

GCCFLAGS = -m32 -o

NASMFLAGS = -f elf32 -o

all: 
	gcc $(GCCFLAGS) main.o main.c -c
	nasm $(NASMFLAGS) functions.o functions.asm 
	gcc $(GCCFLAGS) pr $(OBJ) -lm

clean:
	rm main.o
	rm functions.o
	rm pr
