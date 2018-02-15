#include <stdio.h>
#include <stdlib.h>

void arithm(int* sum, int* sub, int* mult, int* divi, int a, int b){
    *sum = a + b;
    *sub = a - b;
    *mult = a * b;
    *divi = a / b;
}

int main(){
    int a = 5;
    int* b = &a;
    *b = 6;
    printf("The value of a is %d\n",a);
    printf("The address of a is %p\n",&a);
    printf("Size of a : %lu\n",sizeof(a));
    printf("Size of b : %lu\n",sizeof(&a));
    int* c = NULL;
    c = malloc(8 * sizeof(int));
    c[1] = 5;
    printf("Value at the 2nd place of c : %d\n",c[1]);
    long unsigned int total_size = 0;
    for(int i=0; i<8; i++){
        total_size += sizeof(c[i]);
    }
    printf("Size of c : %lu = 8 * sizeof(int) = 8 * 4\n",total_size);
    int sum, sub, mult, divi;
    arithm(&sum, &sub, &mult, &divi, 5, 5);
    printf("sum : %d\nsubstraction : %d\nmultiplication : %d\ndivision : %d\n",sum, sub, mult, divi);
    return 0;
}