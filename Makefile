.PHONY: all clean help

OBJ = main.o functions.o

GCCFLAGS = -m32 -o
	
all: build

build:
	gcc $(GCCFLAGS) -I. main.o main.c -c 
	nasm -f elf32 -o functions.o functions.asm 
	gcc $(GCCFLAGS) program $(OBJ) -lm

clean:
	rm main.o
	rm functions.o
	rm program

run: all
	./program

help:
    @awk '/^#/{c=substr($$0,3);next}c&&/^[[:alpha:]][[:alnum:]_-]+:/{print substr($$1,1,index($$1,":")),c}1{c=0}' $(MAKEFILE_LIST) | column -s: -t