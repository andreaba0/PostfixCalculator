#include "header.h"

int isLetter(char c) {
	if(c>='a'&&c<='z') return 1;
	if(c>='A'&&c<='Z') return 1;
	return 0;
}

int isNumber(char c) {
	if(c>='0'&&c<='9') return 1;
	return 0;
}

int isOperand(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}
