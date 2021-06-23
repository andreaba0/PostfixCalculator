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
		case '%':
		case '!':
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
	dirtData*temp=malloc(sizeof(dirtData));
	if(temp==NULL) return NULL;
	strcpy(temp->data, data);
	temp->type=type;
	temp->next=NULL;

	if(*head==NULL) *head=temp;
	else current->next=temp;
	return temp;
}

int isCorrect(char type, char c) {
	if(type=='l'&&(isLetter(c)||isOpCode(c)))
		return 1;
	if(type=='n'&&isNumber(c))
		return 1;
	return 0;
}

void examinate(char type, int*index, char*part, char*exp) {
	int j=0;
	while(*index<strlen(exp)&&isCorrect(type, exp[*index]))
		part[j++]=exp[(*index)++];
	part[j]='\0';
}

int evaluateAndExecute(dirtData**head, char*exp) {
	dirtData*tail=NULL;
	int i=0;
	char part[WORDDIM];
	while(i<strlen(exp)) {
		if(exp[i]==',') {
			i++;
			continue;
		}
		if(isNumber(exp[i])) {
			examinate('n', &i, part, exp);
			tail=insertDirtData(head, tail, part, 'n');
			if(part[0]=='.') return 102;
			continue;
		}
		if(isLetter(exp[i])) {
			examinate('l', &i, part, exp);
			tail=insertDirtData(head, tail, part, 'o');
			continue;
		}
		if(isOpCode(exp[i])) {
			examinate('l', &i, part, exp);
			tail=insertDirtData(head, tail, part, 'o');
			continue;
		}

		/*if(isNumber(exp[i])) {
			while(i<strlen(exp)&&isNumber(exp[i]))
				part[j++]=exp[i++];
			part[j]='\0';
			tail=insertDirtData(head, tail, part, 'n');
			if(part[0]=='.') return 102;
			continue;
		}
		if(isLetter(exp[i])) {
			while(i<strlen(exp)&&isLetter(exp[i]))
				part[j++]=exp[i++];
			part[j]='\0';
			tail=insertDirtData(head, tail, part, 'o');
			continue;
		}
		if(isOpCode(exp[i])) {
			while(i<strlen(exp)&&isOpCode(exp[i]))
				part[j++]=exp[i++];
			part[j]='\0';
			tail=insertDirtData(head, tail, part, 'o');
			continue;
		}*/
		return 100;
	}
	return 0;
}
