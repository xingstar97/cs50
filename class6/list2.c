#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    //int list[3]; in stack memory
    int *list = malloc(3*sizeof(int)); //in heap memory
    //dynamically allocate an array of 3
    if (list == NULL)
    {
        return 1;
    }

    list[0]=1;
    list[1]=2;
    list[2]=3;

    int *tmp = realloc(list, 4*sizeof(int));
    //realloc free the old memory
    if (tmp == NULL)
    {
        return 1;
    }
    
    tmp [3]=4;
    list =tmp;
    for (int i =0; i <4; i++)
    {
        printf("%i\n",list[i]);
    }
    free (list);
}