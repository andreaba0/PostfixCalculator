void stackPushOperand(Node**head, char*data) {
    Node*temp=malloc(sizeof(Node));
    if(temp==NULL) return;
    strcpy(temp->data, data);
    temp->next=*head;
    *head=temp;
}