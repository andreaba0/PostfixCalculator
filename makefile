calculator: main.o functions.o alu.o processor.o stackFunctions.o
	gcc -o calculator.out main.o functions.o alu.o processor.o stackFunctions.o -lm

main.o: main.c header.h
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c

alu.o: alu.c header.h
	gcc -c alu.c

processor.o: processor.c header.h
	gcc -c processor.c

stackFunctions.o: stackFunctions.c header.h
	gcc -c stackFunctions.c
