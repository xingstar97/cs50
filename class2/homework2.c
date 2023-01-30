#include<stdio.h>
#include<cs50.h>

long power(int n);

int main(void)
{

    long number;
    do
    {
        number = get_long("Card number: ");
    }
    while (number<0);

    int num[16];
    for (int n=15;n>=0;n--)
    {
        num[n] = number/(power(n));
        printf("n = %i, int = %i\n",n, num[n]);
        number = number - num[n]*power(n);
    }

    string bank;

    if (num[14]==3&&num[13]==4||num[13]==7)
    {
        bank = "American Express";
    }
    else if (num[15]==5&&num[14]==1||num[14]==2||num[14]==3||num[14]==4||num[14]==5)
    {
        bank = "MasterCard";
    }
    else if (num[15]==4||num[12]==4)
    {
        bank = "Visa";
    }

    for (int n =1; n<=15; n=n+2)
    {
        num[n]=2*num[n];
        num[n] = num[n]/10 + num[n]%10;
        printf("%i\n", num[n]);
    }
   
   int summary =0;
   for (int n = 0; n<16; n++)
   {
    summary = summary +num[n];
   }
   printf("%i\n",summary);

   if(summary%10 ==0)
   {
    printf("%s\n",bank);
   }
   else
    {
        printf("Invalid\n");
    }   
    
}

long power(int n)
{
    long outcome = 1;
    for (int i=1;i<=n;i++)
    {
        outcome = 10*outcome;
    }
    return outcome;
}