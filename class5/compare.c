#include<cs50.h>
#include<stdio.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    //compare the address of the first char of s and t, always different
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
