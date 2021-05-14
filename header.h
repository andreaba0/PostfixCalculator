#include <stdio.h>
#include <stdlib.h>

typedef struct cellOperator {
	char operator[12];
	int precedence;
	struct cellOperator*next;
} operatorNode;

typedef struct cellOperand {
	char operand[10];
	struct cellOperand*next;
} operandNode;
