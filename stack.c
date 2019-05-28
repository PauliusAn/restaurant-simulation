#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack stackCreate(){
    Stack stack = (Stack) malloc (sizeof(struct StackStruct));
    stack->currentSize = 0;
    stack->top = NULL;
    return stack;
}

int stackIsEmpty(Stack stack){
    return stack->currentSize == 0;
}
int stackPush(Stack stack, valueType val){
    struct StackListElement *stackElement = (struct StackListElement *) malloc(sizeof(struct StackListElement));
    if(stackElement == NULL){
        return 1;
    }
    stackElement->val = val;
    stackElement->next = stack->top;
    stack->currentSize++;
    stack->top = stackElement;
    return 0;
}
int stackPop(Stack stack, valueType *val){
    if(stack->currentSize>0){
        struct StackListElement *stackElement = stack->top;
        stack->currentSize--;
        stack->top = stackElement->next;
        *val = stackElement->val;
        free(stackElement);
        return 0;
    } else {
        return 1;
    }

}
void stackFree(Stack stack){
    while(stack->currentSize !=0){
        struct StackListElement *stackElement = stack->top;
        stack->top = stackElement->next;
        free(stackElement);
        stack->currentSize--;
    }
    free(stack);
}

int stackPeek(Stack stack, valueType *val){
    if(stack->currentSize>0){
        *val = stack->top->val;
        return 0;
    } else {
        return 1;
    }
}
