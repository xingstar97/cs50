#include<stdio.h>
#include<cs50.h>
#include<string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Tom";
    people[0].number = "123-456-7890";

    people[1].name = "Tim";
    people[1].number = "213-456-7890";

    for (int i =0; i<2; i++)
    {
        if (strcmp(people[i].name, "Tom")==0)
        {
            printf("Found, %s\n", people[i].number);
            return 0;
        }
    
    }
    printf("Not found\n");
    return 1;
}