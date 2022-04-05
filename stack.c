#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

Stack* CreateStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	int i;
	for (i = 0; i < STACK_SIZE; i++) {
		s->stack[i] = NULL;
	}
	s->head = 0;
	return s;
}

void PushStack(Stack* s, TreeNode* tn) {
	if (s->head < STACK_SIZE) {
		s->stack[s->head] = tn;
		s->head++;
	}
}

TreeNode* PopStack(Stack* s) {
	if (!EmptyStack(s)) {
		TreeNode* ret = PeekStack(s);
		s->stack[s->head-1] = NULL;
		s->head--;
		return ret;
	}
	return NULL;
}

TreeNode* PeekStack(Stack* s) {
	return s->stack[s->head-1];
}

int EmptyStack(Stack* s) {
	return s->head == 0;
}

void PrintStack(Stack* s) {
	if (s == NULL) {
		printf("Stack doesn't exist.\n");
		return;
	}
	if (s->head == 0) {
		printf("Stack is empty.\n");
		return;
	}
	printf("stack[");
	int i;
	for (i = 0; i < s->head; i++) {
		PrintTreeNode(s->stack[i]);
		printf(", ");
	}
	printf("]\n");
	return;
}

void DestroyStack(Stack* s) {
	assert(s);
	int i;
	for (i = 0; i < STACK_SIZE; i++) {
		if (s->stack[i]) {
			DestroyTreeNode(s->stack[i]);
		}
	}
	free(s);
}

