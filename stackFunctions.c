#include "header.h"

void stackPush(Node**head, char*data) {
    Node*temp=malloc(sizeof(Node));
    if(temp==NULL) return;
    strcpy(temp->data, data);
    temp->next=*head;
    *head=temp;
}

float stackPopOperand(Node**head) {
    Node*temp=*head;
    *head=(*head)->next;
    float res = atof(temp->data);
    free(temp);
    return res;
}

char*stackPopOperator(Node**head) {
    Node*temp=*head;
    *head=(*head)->next;
    char*res=malloc(WORDDIM*sizeof(char));
    strcpy(res, temp->data);
    free(temp);
    return res;
}

DirtNode*listPop(DirtNode**head) {
    DirtNode*temp=*head;
    *head=(*head)->next;
    return temp;
}

char*topOfStack(Node*head) {
    if(head==NULL) return "";
    char*res=malloc(WORDDIM*sizeof(char));
    //static char res[WORDDIM];
    strcpy(res, (head)->data);
    return res;
}

int countStackElement(Node*head) {
    int res=0;
    while(head!=NULL) {
        res+=1;
        head=head->next;
    }
    return res;
}