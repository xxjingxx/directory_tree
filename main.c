#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "tree.h"
#include "stack.h"
#include "queue.h"
#include "files.h"


int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	if (argc < 2) {
		printf("Usage: ./main path/of/a/directory.\n");
		return -1;
	}

	TreeNode* root = FileTree(argv[1]);
	PrintTree(root);
	DestroyTree(root);
	return 0;
}
