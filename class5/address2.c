#include<stdio.h>

int main(void)
{
    //string s ="Hi!";
    char *s ="Hi";
    char *p = &s[0];
    printf("%p\n", p);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]); 
    printf("%s\n",s);
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
}

//typedef char *string: define a char * type and call it string