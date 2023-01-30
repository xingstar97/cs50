#include<stdio.h>

void meow(int n);
//declare the function which is defined later

int main(void)
{
       meow(3);
}

void meow(int n)
{
    for (int i= 0 ; i<n; i++)
    {
        printf("Meow\n");
    }
}
