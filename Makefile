.PHONY: all clean

OBJ = main.o functions.o

GCCFLAGS = -m32 -o

NASMFLAGS = -f elf32 -o

all: main.o functions.o
	gcc $(GCCFLAGS) pr $(OBJ) -lm

main.o: main.c
	gcc $(GCCFLAGS) main.o main.c -c

functions.o: functions.asm
	nasm $(NASMFLAGS) functions.o functions.asm 

build_all: 
	gcc $(GCCFLAGS) main.o main.c -c
	nasm $(NASMFLAGS) functions.o functions.asm 
	gcc $(GCCFLAGS) pr $(OBJ) -lm

clean:
	rm $(OBJ) pr
