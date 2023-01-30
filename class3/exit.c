#include<stdio.h>
#include<cs50.h>

int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Missing command-line arguments\n");
        return 1;
        // return 1 (or any non zero value) from main means there is something wrong
    }
    printf("Hello, %s\n", argv[1]);
    return 0;
    //return 0 from main means nothing wrong
}