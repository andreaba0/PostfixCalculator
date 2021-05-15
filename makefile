calculator: main.o functions.o alu.o
	gcc -o calculator.out main.o functions.o alu.o -lm

main.o: main.c header.h
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c

alu.o: alu.c header.h
	gcc -c alu.c
