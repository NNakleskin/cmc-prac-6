all:
	gcc -m32 -I. -o main.o main.c -c    
	nasm -f elf32 -o functions.o functions.asm 
	gcc -o program main.o functions.o -m32

clean:
	rm main.o
	rm program
	rm functions.o