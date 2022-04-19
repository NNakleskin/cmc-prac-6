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

test-integral: all
	./pr -test-integral

test-root: build
	./pr -test-root

solve: build
	./pr -solve

help: build
	./pr -help
