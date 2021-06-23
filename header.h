#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INSTRLENGTH 15

typedef struct cellOperator {
	char operator[INSTRLENGTH];
	int precedence;
	struct cellOperator*next;
} operatorNode;

typedef struct cellOperand {
	int operand;
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
int evaluateAndExecute(dirtData**head, char*expression);
dirtData*insertDirtData(dirtData**head, dirtData*current, char*data, char type);
void displayDirtData(dirtData*head);
void stackPushOperand(operandNode**head, int data);
void stackPushOpCode(operatorNode**head, char*data, int number);
int stackPopOperand(operandNode**head);
char*stackPop(dirtData**head);
int executionUnit(dirtData**head, operandNode**headOp, operatorNode**headOpCode);
char topStackDataType(dirtData*head);
void displayStackOpCode(operatorNode*head);
char*topStackDataValue(operatorNode*head);
char*operandStackData(operandNode*head);
void executeInstruction(operandNode**head, operatorNode**headOp);
char*stackPopOpCode(operatorNode**head);
void opCodeAnalyzer(dirtData**head, operandNode**headOp, operatorNode**headOpCode);
void popAndDeleteOpCode(operatorNode**head);
int precedenceHierarchy(char*data);
char*topDirtDataStack(dirtData*head);
void deleteFromDirtData(dirtData**head);
void manage(dirtData**head, dirtData**pointer, char*part, int*partIndex, int*isALetter, int*isANumber);
