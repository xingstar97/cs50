#include<stdio.h>
#include<cs50.h>

void draw(int n);
int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
        return; 
        //the return value of this function is void, so not return a value, just return
    }

    draw (n-1);
    for (int i =0; i<n; i++)
    //n-1 to n: need to draw another row
    {
        printf("#");
    }
    printf("\n");
}