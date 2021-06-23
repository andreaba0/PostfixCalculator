#include "header.h"

void printStack(Node*head) {
    printf("Stack value:\n");
    while(head!=NULL) {
        printf("%s\n", head->data);
        head=head->next;
    }
    printf("End of stack\n");
}

void displayDirtNode(DirtNode*head) {
	for(int i=0;head!=NULL;i++) {
		printf("Value %6d: type: %c,  %s\n", i, head->type, head->data);
		head=head->next;
	}
}