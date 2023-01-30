#include<stdio.h>

void meow(void);
//declare the function which is defined later

int main(void)
{
    for (int i= 0 ; i<3; i++)
    //use ; intead of , to separate them

    {
        meow();
    }
}

void meow(void)
{
    printf("Meow\n");
}
