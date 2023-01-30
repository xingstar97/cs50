#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string names[] = {"Tom","Tim","Andy"};
    for (int i = 0; i<3; i++)
    if (strcmp(names[i], "Tom")==0)
    // or if (!strcmp(names[i],"Tom"))
    {
        printf("Found\n");
        return 0;
    }
    printf("Not found\n");
    return 1;
}