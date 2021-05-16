#include "header.h"

char*stackPop(dirtData**head) {
	if(*head==NULL) return NULL;
	static char temp[INSTRLENGTH];
	dirtData*node=*head;
	strcpy(temp, node->data);
	(*head)=(*head)->next;
	free(node);
	return temp;
}

int stackPopOperand(operandNode**head) {
	if((*head)==NULL) return 0;
	operandNode*temp=*head;
	*head=temp->next;
	int data;
	data = temp->operand;
	free(temp);
	return data;
}

char*stackPopOpCode(operatorNode**head) {
	if((*head)==NULL) return "";
	operatorNode*temp=*head;
	*head=(*head)->next;
	static char data[INSTRLENGTH];
	strcpy(data, temp->operator);
	free(temp);
	return data;
}

int precedenceHierarchy(char*data) {
	if(data==NULL) return 0;
	if(!strcmp(data, "+")) return 1;
	if(!strcmp(data, "-")) return 1;
	if(!strcmp(data, "*")) return 2;
	if(!strcmp(data, "/")) return 2;
	if(!strcmp(data, "^")) return 3;
	if(!strcmp(data, "pow")) return 3;
	if(!strcmp(data, "sqrt")) return 3;
	if(!strcmp(data, "log")) return 3;
	if(!strcmp(data, "minus")) return 3;
	return 0;
}

void displayStackOpCode(operatorNode*head) {
	while(head!=NULL) {
		printf("%s\n", head->operator);
		head=head->next;
	}
}

char topStackDataType(dirtData*head) {
	return head->type;
}

char*topStackDataValue(operatorNode*head) {
	if(head==NULL) return NULL;
	static char data[INSTRLENGTH];
	strcpy(data, head->operator);
	return data;
}

void stackPushOperand(operandNode**head, int data) {
	operandNode*new=malloc(sizeof(operandNode));
	if(new==NULL) return;
	new->operand= data;
	new->next=(*head);
	(*head)=new;
}

void stackPushOpCode(operatorNode**head, char*data, int number) {
	operatorNode*new=malloc(sizeof(operatorNode));
	if(new==NULL) return;
	strcpy(new->operator, data);
	new->precedence=number;
	new->next=*head;
	(*head)=new;
}

char*topDirtDataStack(dirtData*head) {
	static char temp[INSTRLENGTH];
	strcpy(temp, head->data);
	return temp;
}

void deleteFromDirtData(dirtData**head) {
	dirtData*temp=*head;
	*head=(*head)->next;
	free(temp);
}

void executeInstruction(operandNode**head, operatorNode**headOp) {
	char*operator=stackPopOpCode(headOp);
	if(!strcmp(operator, "+")) {
		int b = stackPopOperand(head);
		int a = stackPopOperand(head);
		stackPushOperand(head, a+b);
	}
	if(!strcmp(operator, "-")) {
		int b = stackPopOperand(head);
		int a = stackPopOperand(head);
		stackPushOperand(head, a-b);
	}
	if(!strcmp(operator, "*")) {
		int b = stackPopOperand(head);
		int a = stackPopOperand(head);
		stackPushOperand(head, a*b);
	}
	if(!strcmp(operator, "/")) {
		int b = stackPopOperand(head);
		int a = stackPopOperand(head);
		stackPushOperand(head, a/b);
	}
	if(!strcmp(operator, "sqrt")) {
		int a = stackPopOperand(head);
		stackPushOperand(head, sqrt(a));
	}
	if(!strcmp(operator, "minus")) {
		int a = stackPopOperand(head);
		stackPushOperand(head, a*(-1));
	}
	if(!strcmp(operator, "pow")||!strcmp(operator, "^")) {
		int exp = stackPopOperand(head);
		int base = stackPopOperand(head);
		int res=1;
		for(int i=0;i<exp;i++)
			res=res*base;
		stackPushOperand(head, res);
	}
}

void popAndDeleteOpCode(operatorNode**head) {
	operatorNode*temp=*head;
	(*head)=(*head)->next;
	free(temp);
}

void opCodeAnalyzer(dirtData**head, operandNode**headOp, operatorNode**headOpCode) {
	char*opCode=stackPop(head);
	if(!strcmp(opCode, "(")) {
		stackPushOpCode(headOpCode, opCode, 0);
		return;
	}
	if(*headOpCode==NULL) {
		stackPushOpCode(headOpCode, opCode, precedenceHierarchy(opCode));
		return;
	}
	if(!strcmp(opCode, ")")) {
		while(headOpCode!=NULL) {
			if(!strcmp((*headOpCode)->operator, "(")) {
				popAndDeleteOpCode(headOpCode);
				break;
			}
			executeInstruction(headOp, headOpCode);
		}
		return;
	}
	char*currentOpCodeStack=topStackDataValue(*headOpCode);
	while(*headOpCode!=NULL&&precedenceHierarchy(currentOpCodeStack)>precedenceHierarchy(opCode)) {
		executeInstruction(headOp, headOpCode);
	}
	stackPushOpCode(headOpCode, opCode, precedenceHierarchy(opCode));
}

evalRes*executionUnit(dirtData**head, operandNode**headOp, operatorNode**headOpCode) {
	char temp;
	char*dirtData;
	int i=0;
	while(*head!=NULL&&i<20) {
		i++;
		temp=topStackDataType(*head);
		dirtData=topDirtDataStack(*head);
		if(temp=='o') {
			opCodeAnalyzer(head, headOp, headOpCode);
		}
		if(temp=='n') {
			stackPushOperand(headOp, atoi(dirtData));
			deleteFromDirtData(head);
		}
		//if(current->type=='n') stackPushOperand(headOp, current->data);
	}
	while(*headOpCode!=NULL) executeInstruction(headOp, headOpCode);
	printf("Risultato: %d\n", (*headOp)->operand);
	return NULL;
}
