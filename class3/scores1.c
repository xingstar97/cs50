#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int scores[3];
    //scores[0] = get_int("score1: ");
    //scores[1] = get_int("score2: ");
    //scores[2] = get_int("score3: ");

    for(int i=0; i<3; i++)
    {
        scores[i] = get_int("score: ");
    }


    printf("Average score: %f\n", (scores[0]+scores[1]+scores[2])/3.0);
}