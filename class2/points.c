#include<cs50.h>
#include<stdio.h>

int main(void)
{
    const int mine = 2; 
    //const means I can not change the value of mine later, or I can use const MINE
    int points = get_int("how many points did you lose? ");
    
    if (points < mine)
    {
        printf("You lost fewer points than me.\n");
    }

    else if (points > mine)
    {
        printf("You lost more points than me.\n");
    }

    else
    {
        printf("You lost the same number of points as me.\n");
    }

}