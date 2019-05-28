/**
   Modestas Jucevicius PS II grupe I pogrupis VU MIF
   2018-02-20
*/
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int valueType; // define the type of value you'll push into stack

struct StackListElement {
	valueType val;
	struct StackListElement *next;
};

struct StackStruct {
	struct StackListElement *top;
	int currentSize;
};

typedef struct StackStruct * Stack;  // dynamic size stack type

Stack stackCreate(); // creates an empty dynamic size stack
/** Example:
 Stack stack = stackCreate();
*/
int stackIsEmpty(Stack stack); // checks if dynamic size stack is empty, returns 1 if true, else returns 0
/** Example:
 if(stackIsEmpty(stack)){
	do something
 }
*/
int stackPush(Stack stack, valueType val); // pushes a value onto the dynamic sized stack, return 1 if out of memory, else returns 0
/** Example:
 int i = 4;
 char n = 'i';
 stackPush(stack, &i, sizeof(i));
 stackPush(stack, &n, sizeof(n));
*/
int stackPop(Stack stack, valueType *val); // pops a value from the  dynamic sized stack, returns 1 if empty, else returns 0
/** Example:
 int i;
 stackPop(stack, &i);
*/
int stackPeek(Stack stack, valueType *val); // checks the top value of the dynamic sized stack; returns 1 if stack is empty, else retuns 0
/** Example:
 int i;
 stackPeek(stack, &i);
*/
void stackFree(Stack stack); // deletes dynamic sized stack and frees it's memory
/** Example:
 stackFree(stack);
*/


#endif
