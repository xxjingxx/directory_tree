#include "tree.h"

#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 64

typedef struct node {
	TreeNode* tn;
	struct node* next;
} Node;

typedef struct queue {
	Node* head;
	Node* tail;
	int num_element;
} Queue;

Node* CreateNode(TreeNode* tn);

Queue* CreateQueue();

void Enqueue(Queue* q, TreeNode* tn);

TreeNode* Dequeue(Queue* q);

TreeNode* PeekQueue(Queue* q);

int EmptyQueue(Queue* q);

void PrintQueue(Queue* q);

void PrintNode(Node* n);

void DestroyNode(Node* n);

void DestroyQueue(Queue* q);


#endif
