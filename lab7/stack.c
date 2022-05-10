// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include "../main.h"

/* СТЕК */
/* От английского stack (стопка) */
/* Односвязный список, организованный по принципе LIFO */
/* LIFO - Last In First Out (первым вошел - последним вышел) */
/* Пример стека: стопка книг, тарелок и т.п. */
/* Чтобы достать книгу из середины, нужно сначала убрать все книги выше неё */


typedef struct stack_tag {
	void* a;
	void* b;
	struct stack_tag* next;
} stack;

/* функция вставки элемента в стек */
stack* PUSH(stack* S, void* first_num, void* second_num, int size) {
	stack* n = ((stack*)malloc(sizeof(stack)+2*size));
	n -> a = n + 1;
	memcpy(n -> a,first_num,size);
	n -> b = n + 1 + size;
	memcpy(n -> b,second_num,size);
	n -> next = S;
	return n;
}

/* Функция удаления элемента из стека */
stack* POP(stack* S, void* first_num, void* second_num, int size) {
	stack* n = S;
	S = S -> next;
	memcpy(first_num,n -> a,size); // for(i=0;i<SIZE;i++) data[i] = n -> data[i]
	memcpy(second_num,n -> b,size);
	free(n);
	return S;
}

/* Функция, проверяющая пуст ли стек */
int EMPTY(stack* S) {
	return !S;
}

/* Функция печати стека */
void print_stack(stack* head) {
	stack* n = head;
	while (!EMPTY(n)) {
		printf("%d %d\n",*((int*)n->a),*((int*)n->b));
		n = n -> next;
	}
}