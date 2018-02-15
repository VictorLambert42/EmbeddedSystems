#include <stdio.h>

int main(){
    int a = 5;
    int* b = &a;

    *b = 6;
    printf("The value of a is %d\n",a);
    printf("The address of a is %p\n",&a);
    printf("%lu\n",sizeof(a));
    printf("%lu\n",sizeof(&a));
    return 0;
}