#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "queue.h"
#include "tree.h"

Queue* CreateQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	q->num_element = 0;
	return q;
}

Node* CreateNode(TreeNode* tn) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->tn = tn;
	n->next = NULL;
	return n;
}

void Enqueue(Queue* q, TreeNode* tn) {
	Node* n = CreateNode(tn);
	if (q->head == NULL) {
		q->head = n;
	} else {
		q->tail->next = n;
	}
	q->tail = n;
}

TreeNode* Dequeue(Queue* q) {
	assert(q);
	assert(!EmptyQueue(q));
	TreeNode* ret = PeekQueue(q);
	q->head->tn = NULL;
	Node* n = q->head;
	q->head = n->next;
	free(n);
	return ret;
}

TreeNode* PeekQueue(Queue* q) {
	assert(q);
	assert(!EmptyQueue(q));
	TreeNode* ret = q->head->tn;
	return ret;
}

int EmptyQueue(Queue* q) {
	return q->head == NULL;
}

void PrintQueue(Queue* q) {
	assert(q);
	if (EmptyQueue(q)) {
		printf("Queue is empty.\n");
		return;
	}
	printf("queue head[");
	Node* cur;
	for (cur = q->head; cur != NULL; cur = cur->next) {
		PrintNode(cur);
		printf(" -> ");
	}
	printf("]tail\n");
	return;
}

void PrintNode(Node* n) {
	if (n == NULL) {
		printf("(null)\n");
		return;
	}
	PrintTreeNode(n->tn);
}

void DestroyQueue(Queue* q) {
	assert(q);
	Node* cur = q->head;
	while (cur) {
		Node* next = cur->next;
		DestroyNode(cur);
		cur = next;
	}
	free(q);
}

void DestroyNode(Node* n) {
	if (n) {
		DestroyTreeNode(n->tn);
		free(n);
	}
}

