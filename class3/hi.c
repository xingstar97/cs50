#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //char c1 = 'H';
    //char c2 = 'I';
    //char c3 = '!';
    //printf("%c%c%c\n", c1,c2,c3);
    //try printf("%i%i%i\n", c1,c2,c3);
    //try printf("%i%i%i\n", (int)c1,(int)c2,(int)c3);

    string s = "HI!";
    //printf("%s\n", s);
    printf("%i %i %i\n", s[0],s[1],s[2]);
    //a string is an array
    // there is a \0 (called NUL) at the end of the string to indicate the end of the stirng
     printf("%i %i %i %i\n", s[0],s[1],s[2], s[3]);
}
