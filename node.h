#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_STRINGS 180

struct node {
    char *value[NUM_STRINGS];
    int num;            
    struct node *p_left;
    struct node *p_right;
    int len;
};

struct node *new_node(int x);
void insert(int key, struct node **leaf);
struct node* search(struct node *root, int x);
struct node* buildTree(char** inputArray, int length);
void printPostorder( struct node *root, int level, FILE* outfile);
void printPreorder(struct node *root, int level, FILE* outfile);
void printInorder(struct node *root, int level, FILE* outfile);
int main (int argc, const char *argv[]);
