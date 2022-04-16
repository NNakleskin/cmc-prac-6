install:
	sudo apt install nasm
	sudo apt install gcc

start:
	nasm -f elf32 functions.asm -o functions.o
	gcc -m32 macro.o functions.o -o functions
	./functions

