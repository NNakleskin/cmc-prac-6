all:
	gcc -m32 -I. -o main.o main.c -c 
	nasm -f elf32 -o functions.o functions.asm 
	gcc -m32 -lm -o program main.o functions.o

clean:
	rm main.o
	rm functions.o
	rm program

run:
	gcc -m32 -I. -o main.o main.c -c 
	nasm -f elf32 -o functions.o functions.asm 
	gcc -m32 -lm -o program main.o functions.o
	./program
