install:
	sudo apt install nasm
	sudo apt install gcc

start:
	nasm -f elf32 f3.asm -o f3.o
	gcc -m32 macro.o f3.o -o f3
	./f3