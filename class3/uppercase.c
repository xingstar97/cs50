#include <stdio.h>
#include <cs50.h>
#include<string.h>

int main(void)
{
    string s = get_string("Former: ");
    printf("After: ");

    for (int i=0, n=strlen(s); i<n; i++)
    if(s[i]>'a'&&s[i]<'z')
    {
        printf("%c", s[i]-32);
    }
    else
    {
        printf("%c",s[i]);
    }
    printf("\n");
}

//if(islower(s[i])) if is lowercase return non zero value, if not return 0
//printf("%c",toupper(s[i]))