#include<stdio.h>

void swap (int *a, int *b);
int main(void)
{
    int x = 1;
    int y = 2;

    swap (&x, &y);


    {
        int temp = x;
        x = y;
        y = temp;
    }
    //copy the address instead of the value of x and y
//    swap (x, y);
    printf("x is %i, y is %i \n", x, y);
}

// void swap (int a, int b)
// {
//     int temp = a;
//     a =b;
//     b=temp;
// }

void swap (int *a, int *b)
//int *a and int *b are address
{
    int temp = *a;
    // copy the value of a to temp
    *a = *b;
    *b = temp;
}