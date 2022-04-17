all:
	gcc -m32 -I. -o main.o main.c -c
	gcc -m32 -I. -o risunctions.o rifunctions.h -c  
	gcc -m32 -I. -o minmax.o minmax.h -c  
	nasm -f elf32 -o functions.o functions.asm 
	gcc -m32 -o program main.o functions.o rifunctions.o

clean:
	rm main.o
	rm program
	rm functions.o
	rm rifunctions.o
	rm minmax.o