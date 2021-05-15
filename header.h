#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSTRLENGTH 15

typedef struct cellOperator {
	char operator[INSTRLENGTH];
	int precedence;
	struct cellOperator*next;
} operatorNode;

typedef struct cellOperand {
	char operand[INSTRLENGTH];
	struct cellOperand*next;
} operandNode;

typedef struct evalRes {
	char mex[INSTRLENGTH];
	double res;
} evalRes;

typedef struct dirtData {
	char data[INSTRLENGTH];
	char type;
	struct dirtData*next;
} dirtData;

int isLetter(char c);
int isOpCode(char c);
int isNumber(char c);
evalRes*evaluateAndExecute(dirtData**head, char*expression);
dirtData*insertDirtData(dirtData**head, dirtData*current, char*data, char type);
void displayDirtData(dirtData*head);
void stackPushOperand(operandNode**head);
void stackPushOpCode(operatorNode**head);
operandNode*stackPopOpCode();
operatorNode*stackPopOperand();
