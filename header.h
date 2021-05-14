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

typedef struct evalRes {
	char mex[100];
	double res;
} evalRes;

typedef struct dirtData {
	char data[100];
	struct dirtData*next;
} dirtData;

int isLetter(char c);
int isOperand(char c);
int isNumber(char c);
evalRes*evaluateAndExecute(dirtData**head, char*expression);
dirtData*insertDirtData(dirtData**head, dirtData*current, char*data);
void displayDirtData(dirtData*head);
