CC = gcc

all: P0

P0: P0.c
	gcc -std=c99 -o P0 P0.c

clean:
	$(RM) P0 outP0.inorder outP0.postorder outP0.preorder
