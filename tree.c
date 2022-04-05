#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tree.h"
#include "stack.h"
#include "queue.h"

TreeNode* CreateTreeNode(char* path, char* name, int level) {
	TreeNode* t = (TreeNode*)malloc(sizeof(TreeNode));
	char* t_name = (char*)malloc(sizeof(char*) * strlen(name)+1);
	char* t_path = (char*)malloc(sizeof(char*) * strlen(path)+1);
	snprintf(t_name, strlen(name)+1,"%s", name);
	snprintf(t_path, strlen(path)+1,"%s", path);
	t->name = t_name;
	t->path = t_path;
	t->level = level;
	t->children = NULL;
	t->siblings = NULL;
	return t;
}

void DestroyTreeNode(TreeNode* treeNode) {
	if (treeNode == NULL) return;
	free(treeNode->path);
	free(treeNode->name);
	free(treeNode);
}

void DestroyTree(TreeNode* root) {
	if (!root) {
		return;
	}
	DestroyTree(root->siblings);
	DestroyTree(root->children);
	free(root->path);
	free(root->name);
	free(root);
}

void AddChild(TreeNode* root, TreeNode* child, int level) {
	child->level = root->level+1;
	if (root->children == NULL) {
		root->children = child;
		return;
	}
	TreeNode* cur = root->children;
	while (cur->siblings) {
		cur = cur->siblings;
	}
	cur->siblings = child;
}

void PrintTree(TreeNode* root) {
	printf("\e[34m---Printing tree---\n");
	Stack* s = CreateStack();
	PushStack(s, root);
	printf("\n");
	while (!EmptyStack(s)) {
		TreeNode* cur = PopStack(s);
		if (cur->children) {
			TreeNode* kid = cur->children;
			while (kid) {
				TreeNode* sib = kid->siblings;
				PushStack(s, kid);
				kid = sib;
			}
		}
		int i = cur->level;
		while (i > 1) {
			printf("\e[92m%lc   ", 0x2502);
			i--;
		}
		printf("\e[92m%lc%lc", 0x251C, 0x2500);
		PrintTreeNode(cur);
		printf("\e[0m\n");
	}
	printf("\n\e[34m---End---\e[0m\n");
	DestroyStack(s);
}

void PrintTreeNode(TreeNode* treeNode) {
	printf("\e[95m%s", treeNode->name);
}

