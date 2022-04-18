.PHONY: all clean install uninstall

OBJ = main.o functions.o

GCCFLAGS = -m32 -o -lm
	
all: build

build:
	gcc -m32 -I. -o main.o main.c -c 
	nasm -f elf32 -o functions.o functions.asm 
	gcc $(GCCFLAGS) program $(OBJ)

clean:
	rm main.o
	rm functions.o
	rm program

run: all
	./program
