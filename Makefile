all: main

main: main.c files.c files.h queue.c queue.h stack.c stack.h tree.c tree.h
	gcc -g main.c files.c queue.c stack.c tree.c -o dirtree

clean:
	rm -r dirtree 
