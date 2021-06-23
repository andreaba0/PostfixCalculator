#include "header.h"

int controlUnit(DirtNode**head, Node**stackOperand, Node**stackOperator) {
    while(*head!=NULL) {
        DirtNode*elem=listPop(head);
        if(elem->type=='n') 
            stackPush(stackOperand, elem->data);
        else 
            operandAnalyzer(elem->data, stackOperand, stackOperator);
        free(elem);
    }
    while(*stackOperator!=NULL)
         alu(stackOperand, stackOperator);
}

int isEqual(char*one, char*two) {
    if(!strcmp(one, two)) return 1;
    return 0;
}

int operandAnalyzer(char*operator, Node**stackOperand, Node**stackOperator) {
    if(*stackOperator==NULL) {
        stackPush(stackOperator, operator);
        return 1;
    }
    if(isEqual(topOfStack(stackOperator), "(")) {
        stackPush(stackOperator, operator);
        return 1;
    }
    if(isEqual(topOfStack(stackOperator), ")")) {
        while(*stackOperand!=NULL&&strcmp(topOfStack(stackOperator), ")")) {
            alu(stackOperand, stackOperator);
        }
        if(*stackOperator==NULL) return 200;
        if(!isEqual(topOfStack(stackOperator), ")")) return 201;
        char*trash = stackPopOperator(stackOperator);
        free(trash);
        return 1;
    }
    while(*stackOperator!=NULL&&precedence(topOfStack(stackOperator))>=precedence(operator))
        alu(stackOperand, stackOperator);
    stackPush(stackOperator, operator);
}