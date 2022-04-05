#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>

#include "queue.h"
#include "tree.h"
#include "stack.h"
#include "files.h"

TreeNode* FileTree(char* path) {
	// trim input path
	if (path[strlen(path)-1] == '/') {
		path[strlen(path)-1] = '\0';
	}
	struct stat s;
	struct dirent **namelist;
	char* rootPath = " ";
	TreeNode* root = CreateTreeNode(rootPath, path, 0);
	Queue* q = CreateQueue();
	Enqueue(q, root);

  while (!EmptyQueue(q)) {
    TreeNode* cur = Dequeue(q);
    int kLen = strlen(cur->path) + strlen(cur->name) + 3;
    char curPath[kLen];
    if (cur->level == 0) {
      strcpy(curPath, cur->name);
    } else {
      snprintf(curPath, kLen, "%s/%s", cur->path, cur->name);
    }
    int num_files;
    num_files = scandir(curPath, &namelist, 0, alphasort);
    if (num_files < 0) {
      perror("scandir");
      printf("dir: %s\n", path);
      return NULL;
    } else {
      int i = 0;
      while (i < num_files) {
        // Ignore dotfiles, such as .emacs
        if (namelist[i]->d_name[0] == '.') {
          free(namelist[i]);
          i++;
          continue;
        }
        char *directory;
        int length = strlen(curPath) + strlen(namelist[i]->d_name);
        directory = (char*) malloc(((length + 3)*sizeof(char)));
        if (directory == NULL) {
          printf("Couldn't malloc for filecrawler.directory\n");
          return NULL;
        }
        // Copy the path and file name into the "directory" string
        snprintf(directory, length + 3, "%s/%s", curPath, namelist[i]->d_name);

        // Use stat() to get info about the given directory (or file)
        if (0 == stat(directory, &s)) {
          // Tells us if the given directory/file is a directory or not
          if (S_ISDIR(s.st_mode)) {
            // Here's where you put the new TreeNode into the queue for
            // further processing
            TreeNode* dirNode = CreateTreeNode(curPath,
                                               namelist[i]->d_name,
                                               cur->level+1);
            AddChild(cur, dirNode, cur->level+1);
            Enqueue(q, dirNode);
          } else {
            TreeNode* kidNode = CreateTreeNode(curPath,
                                               namelist[i]->d_name,
                                               cur->level+1);
            AddChild(cur, kidNode, cur->level+1);
          }
        } else {
          printf("no stat; %s\n", directory);
        }
        free(namelist[i]);
        i++;
        free(directory);
      }
    }
    free(namelist);
  }
  DestroyQueue(q);
  return root;
}
