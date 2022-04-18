.PHONY: all clean help

OBJ = main.o functions.o

GCCFLAGS = -m32 -o

NASMFLAGS = -f elf32 -o
	
all: build

build:
	gcc $(GCCFLAGS) -I. main.o main.c -c 
	nasm $(NASMFLAGS) functions.o functions.asm 
	gcc $(GCCFLAGS) program $(OBJ) -lm

clean:
	rm main.o
	rm functions.o
	rm program

test-integral: all
	./program -test-integral

test-root: build
	./program -test-root

solve: build
	./program -solve

help: build
	./program -help
