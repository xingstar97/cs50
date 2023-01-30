#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    for(n = get_int("width: ");
    n <1;
    n = get_int("width: "))
    {
    }

    for (int i = 0; i<n; i++)
    {
        printf("?");
    }
    printf("\n");
}

