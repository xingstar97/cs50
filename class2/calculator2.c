#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: "); 
    float z = x/y;
    printf("%.50f\n",z);
}

//floating point imprecision


int main(void)
{
    int x = get_float("x: ");
    int y = get_float("y: "); 
    float z = x/(float)y;
    //change y from integer to float
    printf("%.50f\n",z);
}
//try x = 2 and y =3; try x = 4 and y = 3