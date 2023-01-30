#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    float amount = get_float("Dollar amount: ");
    int pennies = around(amount * 100);
    printf("Pennies: %i\n", pennies);
}

//try 4.2