#include "header.h"

int controlUnit(DirtNode**head, Node**stackOperand, Node**stackOperator) {
    int ok;
    while(*head!=NULL) {
        DirtNode*elem=listPop(head);
        if(elem->type=='n') 
            stackPush(stackOperand, elem->data);
        else {
            ok=operandAnalyzer(elem->data, stackOperand, stackOperator);
            if(ok!=1) return ok;
        }
        free(elem);
    }
    if(*stackOperand==NULL) return 200;
    while(*stackOperator!=NULL) {
         ok=alu(stackOperand, stackOperator);
         if(ok!=1) return ok;
    }
    if(countStackElement(*stackOperand)!=1) return 201;
    return 1;
}

int isEqual(char*one, char*two) {
    if(!strcmp(one, two)) return 1;
    return 0;
}

int operandAnalyzer(char*operator, Node**stackOperand, Node**stackOperator) {
    int ok;
    if(*stackOperator==NULL) {
        stackPush(stackOperator, operator);
        return 1;
    }
    if(isEqual(operator, "(")) {
        stackPush(stackOperator, operator);
        return 1;
    }
    if(isEqual(operator, ")")) {
        while(*stackOperand!=NULL&&strcmp(topOfStack(*stackOperator), "(")) {
            ok=alu(stackOperand, stackOperator);
            if(ok!=1) return ok;
        }
        if(*stackOperator==NULL) return 300;
        if(!isEqual(topOfStack(*stackOperator), "(")) return 301;
        char*trash = stackPopOperator(stackOperator);
        free(trash);
        return 1;
    }
    while(*stackOperator!=NULL&&precedence(topOfStack(*stackOperator))>=precedence(operator)) {
        ok=alu(stackOperand, stackOperator);
        if(ok!=1) return ok;
    }
    stackPush(stackOperator, operator);
    return 1;
}