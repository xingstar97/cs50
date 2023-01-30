#include<stdio.h>
#include<cs50.h>

void draw(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height <=0);
    draw (height);
}

void draw(int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j=0; j <(n-i-1); j++)
        {
            printf(" ");
        }
        for (int k=0; k<=i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l=0; l<=i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}