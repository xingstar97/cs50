#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("size: ");
    }
    while(n<1);

    //for each row
    for (int i = 0; i<n; i++)
    {
        //for each column
        for (int j =0; j<n; j++)
        {
            printf("#");
        }
        printf("\n");

    }
    printf("\n");
}
