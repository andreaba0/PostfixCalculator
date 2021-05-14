calculator: main.o functions.o
	gcc -o calculator.out main.o functions.o

main.o: main.c header.h
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c
