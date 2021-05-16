#include "header.h"

int isLetter(char c) {
	if(c>='a'&&c<='z') return 1;
	if(c>='A'&&c<='Z') return 1;
	return 0;
}

int isNumber(char c) {
	if(c>='0'&&c<='9') return 1;
	if(c=='.') return 1;
	return 0;
}

int isOpCode(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
			return 1;
		default:
			return 0;
	}
}

void displayDirtData(dirtData*head) {
	for(int i=0;head!=NULL;i++) {
		printf("Value %6d: type: %c,  %s\n", i, head->type, head->data);
		head=head->next;
	}
}

dirtData*insertDirtData(dirtData**head, dirtData*current, char*data, char type) {
	if(*head==NULL) {
		*head=malloc(sizeof(dirtData));
		strcpy((*head)->data, data);
		(*head)->type=type;
		(*head)->next=NULL;
		return *head;
	}

	dirtData*node = malloc(sizeof(dirtData));
	strcpy(node->data, data);
	node->type=type;
	node->next=NULL;
	if(current==*head) (*head)->next=node;
	else current->next=node;
	return node;
}

evalRes*evaluateAndExecute(dirtData**head, char*expression) {
	evalRes*res = malloc(sizeof(evalRes));
	int isALetter=0;
	int isANumber=0;
	char part[20];
	char partIndex=0;
	dirtData*pointer=NULL;
	for(int i=0;i<strlen(expression)+1;i++) {
		if(i==strlen(expression)) {
				if(partIndex==0) break;
				if(isALetter) pointer=insertDirtData(head, pointer, part, 'o');
				if(isANumber) pointer = insertDirtData(head, pointer, part, 'n');
				break;
		}
		if(expression[i]==',') {
			if(isALetter) pointer=insertDirtData(head, pointer, part, 'o');
			if(isANumber) pointer=insertDirtData(head, pointer, part, 'n');
			partIndex=0;
			isALetter=0;
			isANumber=0;
			part[0]='\0';
		}
		if(isOpCode(expression[i])) {
			if(isALetter||isANumber) {
				part[partIndex]='\0';
				if(isALetter) pointer = insertDirtData(head, pointer, part, 'o');
				if(isANumber) pointer = insertDirtData(head, pointer, part, 'n');
				partIndex=0;
				isALetter=0;
				isANumber=0;
			}
			part[partIndex++]=expression[i];
			part[partIndex]='\0';
			partIndex=0;
			pointer = insertDirtData(head, pointer, part, 'o');
			part[0]='\0';
			continue;
		}
		if(isLetter(expression[i])) {
			if(isANumber) {
				part[partIndex]='\0';
				pointer = insertDirtData(head, pointer, part, 'n');
				partIndex=0;
				isANumber=0;
			}
			part[partIndex++]=expression[i];
			isALetter=1;
			continue;
		}
		if(isNumber(expression[i])) {
			if(isALetter) {
				part[partIndex]='\0';
				pointer = insertDirtData(head, pointer, part, 'o');
				partIndex=0;
				isALetter=0;
			}
			part[partIndex++]=expression[i];
			isANumber=1;
			continue;
		}
	}
	//displayDirtData(*head);
	return NULL;
}
