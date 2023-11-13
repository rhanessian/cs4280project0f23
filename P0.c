//Rebecca Hanessian
//CS 4280
//P0

#include "node.h"
#include "tree.c"

int main (int argc, const char *argv[]){
    int counter = 0;
    FILE *input;
    int i;
    char *word[NUM_STRINGS];
    if ( argc > 2 )
    {
        printf( "usage: %s filename", argv[0] );
        return -1;
    }
    else if (argc == 1){
        printf("Begin inputting strings (end with empty string):");
        input = stdin;
    }
    else
    {
        char tempstring[128];
    sprintf(tempstring, "%s.f23", argv[1]);
        FILE *file = fopen( tempstring, "r" );

        if ( file == 0 )
        {
            printf( "File could not be opened.\n" );
            return -1;
        }
        input = file;
    }
    size_t malloc_size = 500;
    for (i = 0; i < NUM_STRINGS; i++) {
        word[i] = malloc(malloc_size * sizeof(char));
        fgets(word[i], malloc_size, input);
        if (word[i][0] == '\n' || word[i][0] == 0)
            break;
        int len = strlen(word[i]);
        if (len == 0)
            break;
        word[i][len-1] = 0;
        counter++;
    }
    
    struct node* tree = buildTree(word, counter);
    FILE* pre = fopen("outP0.preorder","w");
    FILE* inord = fopen("outP0.inorder","w");
    FILE* post = fopen("outP0.postorder","w");
    printf("Preorder \n");
    printPreorder(tree, 0, pre);
    printf("Inorder \n");
    printInorder(tree, 0, inord);
    printf("Postorder \n");
    printPostorder(tree, 0, post);
    fclose(pre);
    fclose(inord);
    fclose(post);
    
    
    
    word[i] = NULL;
    if (input != stdin)
        fclose(input);
    return 0;

}
