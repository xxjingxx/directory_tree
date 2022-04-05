#ifndef TREE_H
#define TREE_H

typedef struct treeNode TreeNode;

struct treeNode {
	char* name;
	char* path;
	int level;
	TreeNode* children;
	TreeNode* siblings;
};

void DestroyTree(TreeNode* root);

TreeNode* CreateTreeNode(char* path, char* name, int level);

void DestroyTreeNode(TreeNode* treeNode);

void DestroyTree(TreeNode* root);

void AddChild(TreeNode* root, TreeNode* child, int level);

void PrintTree(TreeNode* root);

void PrintTreeNode(TreeNode* treeNode);

#endif
