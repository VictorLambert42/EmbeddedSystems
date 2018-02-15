#include <stdio.h>
#include <math.h>

int main(){
    int a = 0;
    a = 3;
    a = a << 8;
    a = a | 6;
    a = a << 8;
    a = a | 0xeb;
    a = a << 8;
    a = a | 0b00111111;

    printf("a = %d\n",a);
    return 0;
}