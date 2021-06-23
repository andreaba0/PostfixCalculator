#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INSTRLENGTH 15
#define WORDDIM 12

struct elem1 {
	char data[WORDDIM];
	struct elem1 *next;
};
struct elem2 {
	char data[WORDDIM];
	char type;
	struct elem2 *next;
};
typedef struct elem1 Node;
typedef struct elem2 DirtNode;

int isLetter(char c);
int isOpCode(char c);
int isNumber(char c);
int isCorrect(char type, char c);
void examinate(char type, int*index, char*part, char*exp);
int evaluate(DirtNode**head, char*expression);
DirtNode*insertDirtNode(DirtNode**head, DirtNode*current, char*data, char type);
void displayDirtNode(DirtNode*head);
char*topOfStack(Node*head);
void stackPush(Node**head, char*data);
float stackPopOperand(Node**head);
char*stackPopOperator(Node**head);
DirtNode*listPop(DirtNode**head);
int controlUnit(DirtNode**head, Node**stackOperand, Node**stackOperator);
int operandAnalyzer(char*operator, Node**stackOperand, Node**stackOperator);
int alu(Node**stackOperand, Node**stackOperator);
int precedence(char*operator);
int isEqual(char*one, char*two);
void printStack(Node*head);
void printStack(Node*head);
int countStackElement(Node*head);

