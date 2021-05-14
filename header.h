#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellOperator {
	char operator[12];
	int precedence;
	struct cellOperator*next;
} operatorNode;

typedef struct cellOperand {
	char operand[10];
	struct cellOperand*next;
} operandNode;


int isLetter(char c);
int isOperand(char c);
int isNumber(char c);
