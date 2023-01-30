#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string names[] = {"Tom","Tim"};
    string numbers[] = {"123-456-7890","213-456-7890"};

    for (int i =0; i <2; i++)
    if (strcmp(names[i],"Tim")==0)
    {
        printf("Found, %s\n",numbers[i]);
        return 0;
        //return means end
    }
    printf("Not found\n");
    return 1;
    
}