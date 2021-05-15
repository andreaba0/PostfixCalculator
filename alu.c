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

void displayStackOpCode(operatorNode*head) {
	printf("Operatori\n");
	while(head!=NULL) {
		printf("%s\n", head->operator);
		head=head->next;
	}
}

char*topStackDataType(dirtData*head) {
	static char temp[2];
	temp[0]=head->type;
	temp[1]='\0';
	return temp;
}

void stackPushOperand(operandNode**head, char*data) {
	operandNode*new=malloc(sizeof(operandNode));
	if(new==NULL) return;
	strcpy(new->operand, data);
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

evalRes*executionUnit(dirtData**head, operandNode**headOp, operatorNode**headOpCode) {
	char*current=NULL;
	dirtData*index=*head;
	char*temp;
	while(*head!=NULL) {
		temp=topStackDataType(*head);
		current = stackPop(head);
		if(!strncmp(temp, "o", 2)) {
			stackPushOpCode(headOpCode, current, 0);
		}
		else {
			stackPushOperand(headOp, current);
		}
		//if(current->type=='n') stackPushOperand(headOp, current->data);
	}
	return NULL;
}
