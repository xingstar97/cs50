#include<cs50.h>
#include<stdio.h>

int main(int argc, string argv[])

//int argc: the length of the input
//string argv[]: input, an array of string

{
    if (argc==2)

    {
        printf("hello, %s\n", argv[1]);
    //argv[0]: the first thing humans typed
    //try argv[2]
    }
    else

    {
        printf("Hello, world\n");
    }
}