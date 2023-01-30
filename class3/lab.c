#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int compute(char n);
int main(void)
{
    string s1 = get_string("Player1: ");
    string s2 = get_string("Player2: ");
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int sum1=0;
    int sum2=0;
   
    for (int i =0; i<n1; i++)
    {
        if (islower(s1[i]))
        {
            s1[i]=toupper(s1[i]);
        }
        else
        {
            s1[i]=s1[i];
        }
        sum1 = compute(s1[i])+sum1;
    }

     for (int j =0; j<n2; j++)
    {
         if (islower(s2[j]))
        {
            s2[j]=toupper(s2[j]);
        }
        else
        {
            s2[j] = s2[j];
        }
        sum2 = compute(s2[j])+sum2;
    }
    printf("sum1=%i,sum2 =%i",sum1,sum2);

    if (sum1>sum2)
    {
        printf("Player1 wins\n");
    }
    else if (sum1 == sum2)
    {
        printf("Tie\n");
    }
    else
    {
        printf("Player 2 wins\n");
    }
}

int compute(char n)
{
    int point[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int letter[128];

    for(int i = 'A'; i <= 'Z'; i++)
    {
        letter[i] = point[i-'A'];
    }

    if (isupper(n)==0)
    {
        return 0;
    }
    return letter[n];

}