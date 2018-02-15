#include <stdio.h>
#include <limits.h>

int main(){
    int a = 5;
    long b = 6;
    long long c = 2;
    char d = 127;
    float e = 2.0;
    double f = 5.0;
    printf("int : %lu \n",sizeof(a));
    printf("long : %lu \n",sizeof(b));
    printf("long long : %lu \n",sizeof(c));
    printf("char : %lu \n",sizeof(d));
    printf("float : %lu \n",sizeof(e));
    printf("double : %lu \n",sizeof(f));

    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);

    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);
    return 0;
}