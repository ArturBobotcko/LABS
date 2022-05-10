#ifndef STACK_H
#define STACK_H

typedef struct stack_tag stack;

stack* PUSH(stack* S, void* first_num, void* second_num, int size);
stack* POP(stack* S, void* first_num, void* second_num, int size);
int EMPTY(stack* S);
void print_stack(stack* head);

#endif