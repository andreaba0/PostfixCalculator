#include "header.h"

int precedence(char*data) {
	if(data==NULL) return 0;
	if(!strcmp(data, "+")) return 1;
	if(!strcmp(data, "-")) return 1;
	if(!strcmp(data, "*")) return 2;
	if(!strcmp(data, "/")) return 2;
	if(!strcmp(data, "%")) return 3;
	if(!strcmp(data, "^")) return 4;
	if(!strcmp(data, "pow")) return 4;
	if(!strcmp(data, "sqrt")) return 4;
	if(!strcmp(data, "log")) return 4;
	if(!strcmp(data, "minus")) return 4;
	if(!strcmp(data, "!")) return 5;
	return 0;
}

void alu(Node**head, Node**headOp) {
	char*operator=stackPopOperator(headOp);
	char res[WORDDIM];
	if(!strcmp(operator, "+")) {
		float b = stackPopOperand(head);
		float a = stackPopOperand(head);
		sprintf(res, "%f", a+b);
		stackPush(head, res);
	}
	if(!strcmp(operator, "-")) {
		float b = stackPopOperand(head);
		float a = stackPopOperand(head);
		sprintf(res, "%f", a-b);
		stackPush(head, res);
	}
	if(!strcmp(operator, "*")) {
		float b = stackPopOperand(head);
		float a = stackPopOperand(head);
		sprintf(res, "%f", a*b);
		stackPush(head, res);
	}
	if(!strcmp(operator, "/")) {
		float b = stackPopOperand(head);
		float a = stackPopOperand(head);
		sprintf(res, "%f", a/b);
		stackPush(head, res);
	}
	if(!strcmp(operator, "sqrt")) {
		float a = stackPopOperand(head);
		sprintf(res, "%f", sqrt(a));
		stackPush(head, res);
	}
	if(!strcmp(operator, "minus")) {
		float a = stackPopOperand(head);
		sprintf(res, "%f", a*(-1));
		stackPush(head, res);
	}
	if(!strcmp(operator, "pow")||!strcmp(operator, "^")) {
		int exp = stackPopOperand(head);
		float base = stackPopOperand(head);
		int r=1;
		for(int i=0;i<exp;i++)
			r=r*base;
		sprintf(res, "%f", (float)r);
		stackPush(head, res);
	}
	if(!strcmp(operator, "%")) {
		int b = stackPopOperand(head);
		int a = stackPopOperand(head);
		while(a-b>0) a=a-b;
		sprintf(res, "%d", a);
		stackPush(head, res);
	}
	if(!strcmp(operator, "!")) {
		int a = stackPopOperand(head);
		int r=1;
		for(int i=0;i<a;i++)
			r=r*(i+1);
		sprintf(res, "%d", r);
		stackPush(head, res);
	}
}
