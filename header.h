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
void stackPushOperand(operandNode**head, char*data);
void stackPushOpCode(operatorNode**head, char*data, int number);
operandNode*stackPopOpCode();
operatorNode*stackPopOperand();
char*stackPop(dirtData**head);
evalRes*executionUnit(dirtData**head, operandNode**headOp, operatorNode**headOpCode);
char*topStackDataType(dirtData*head);
void displayStackOpCode(operatorNode*head);
