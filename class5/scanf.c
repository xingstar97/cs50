#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // int x;
    // printf("x: ");
    // scanf("%i", &x);
    // printf("x is %i", x);

    char *s = malloc(4);
    //WRONG: char *s;
    printf("s: ");
    scanf("%s", s);
    //s is an address
    printf("s is %s", s);

}