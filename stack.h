#include "tree.h"

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 64

typedef struct stack {
  TreeNode* stack[STACK_SIZE];
  int head;
} Stack;

Stack* CreateStack();

void PushStack(Stack* s, TreeNode* tn);

TreeNode* PopStack(Stack* s);

TreeNode* PeekStack(Stack* s);

int EmptyStack(Stack* s);

void PrintStack(Stack* s);

void DestroyStack(Stack* s);

#endif
