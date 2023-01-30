#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;
    //copy the address of char array, so they point to the same array
    //whem change t[0], it also changes s[0]

    t[0] = toupper(t[0]);

    printf("%s\n",s);
    printf("%s\n",s);
}