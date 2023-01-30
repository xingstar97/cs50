#include <stdio.h>
#include <cs50.h>

void swap(int** a, int** b){
    int* c = *a;
    *a = *b;
    *b = c;
}

int main(void){
    int a = 1;
    int b = 2;
    int *pa = &a;
    int *pb = &b;

    printf("a=%i\n", a);
    printf("b=%i\n", b);
    printf("&a=%p\n", &a);
    printf("&b=%p\n", &b);
    printf("pa=%p\n", pa);
    printf("pb=%p\n", pb);

    int * tp = pa;
    pa = pb;
    pb = tp;
    //swap(&pa, &pb);

    printf("a=%i\n", a);
    printf("b=%i\n", b);
    printf("&a=%p\n", &a);
    printf("&b=%p\n", &b);
    printf("pa=%p\n", pa);
    printf("pb=%p\n", pb);
    printf("*pa=%i\n", *pa);
    printf("*pb=%i\n", *pb);

}

