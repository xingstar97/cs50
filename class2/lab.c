#include<stdio.h>
#include<cs50.h>

int main(void)
{
    
    int start_size;
    int end_size;

    do
    {
        start_size = get_int("Start size: ");
        end_size = get_int("End_size: ");
    }
    while (start_size <= 0 || end_size < start_size);

    int n=0;
    int new_size = start_size;
    //declare variables outside the loop

    while (new_size < end_size)

    {
        new_size = new_size*(1+(float)1/3-(float)1/4);
        n++;
    } 

    printf("years: %i\n", n);
    return 0;
    
}