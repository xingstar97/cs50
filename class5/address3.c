#include<stdio.h>

int main(void)
{
    int number[] = {1,2,3,4,5};
    printf("%i\n", *number);
    printf("%i\n", *(number+1));//int is 4 bytes, we only add 1 in the pointer (pointer arithmetic)
    printf("%i\n", *(number+2));
    printf("%i\n", *(number+3));
}