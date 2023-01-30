#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n = get_int("n: ");
    int r = n%2;

    if (r == 0)
    {
        printf("n is even./n");

    }
    else
    {
        printf("n is odd./n");
    }
}