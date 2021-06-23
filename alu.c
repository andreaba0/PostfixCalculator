#include "header.h"

int precedence(char*data) {
	if(data==NULL) return 0;
	if(isEqual(data, "+")) return 1;
	if(isEqual(data, "-")) return 1;
	if(isEqual(data, "*")) return 2;
	if(isEqual(data, "/")) return 2;
	if(isEqual(data, "%")) return 3;
	if(isEqual(data, "^")) return 4;
	if(isEqual(data, "pow")) return 4;
	if(isEqual(data, "sqrt")) return 4;
	if(isEqual(data, "log")) return 4;
	if(isEqual(data, "minus")) return 4;
	if(isEqual(data, "!")) return 5;
	return 0;
}

int alu(Node**head, Node**headOp) {
	char*operator=stackPopOperator(headOp);
	char res[WORDDIM];
	if(isEqual(operator, "+")) {
		float b = stackPopOperand(head);
		if(*head==NULL) return 401;
		float a = stackPopOperand(head);
		sprintf(res, "%f", a+b);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "-")) {
		float b = stackPopOperand(head);
		if(*head==NULL) return 401;
		float a = stackPopOperand(head);
		sprintf(res, "%f", a-b);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "*")) {
		float b = stackPopOperand(head);
		if(*head==NULL) return 401;
		float a = stackPopOperand(head);
		sprintf(res, "%f", a*b);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "/")) {
		float b = stackPopOperand(head);
		if(*head==NULL) return 401;
		float a = stackPopOperand(head);
		sprintf(res, "%f", a/b);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "sqrt")) {
		float a = stackPopOperand(head);
		sprintf(res, "%f", sqrt(a));
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "minus")) {
		float a = stackPopOperand(head);
		sprintf(res, "%f", a*(-1));
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "pow")||isEqual(operator, "^")) {
		int exp = stackPopOperand(head);
		if(*head==NULL) return 401;
		float base = stackPopOperand(head);
		int r=1;
		for(int i=0;i<exp;i++)
			r=r*base;
		sprintf(res, "%f", (float)r);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "%")) {
		int b = stackPopOperand(head);
		if(*head==NULL) return 401;
		int a = stackPopOperand(head);
		while(a-b>0) a=a-b;
		sprintf(res, "%d", a);
		stackPush(head, res);
		return 1;
	}
	if(isEqual(operator, "!")) {
		int a = stackPopOperand(head);
		int r=1;
		for(int i=0;i<a;i++)
			r=r*(i+1);
		sprintf(res, "%d", r);
		stackPush(head, res);
		return 1;
	}
	return 400;
}
