#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int main(void)
{

    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n==NULL)
    {
        free(list);
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    list ->left = n;

    n = malloc(sizeof(node));
    if (n==NULL)
    {
        free (list->left);
        free(list);
        return 3;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    list ->right = n;

    printf("%i\n", list->left->number);
    printf("%i\n", list->number);
    printf("%i\n", list->right->number);

    free(list->left);
    free(list->right);
    free(list);  
}