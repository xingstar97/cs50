#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int number[] = {0,2,4,6,8,10,12};
    for (int i = 0; i<7; i++)
    {
        if(number[i] ==0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
    //print not found after the for loop, because we want to search all numbers
}