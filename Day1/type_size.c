#include <stdio.h>

int main(void)
{
    printf("char: %ld, short: %ld, int: %ld, long: %ld, long long :%ld\n",
    sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
    printf("char = %ld\n", sizeof(char)) ;
    printf("integer = %ld\n", sizeof(int)) ;
    printf("float = %ld\n", sizeof(float)) ;
    printf("double = %ld\n", sizeof(double)) ;
    printf("integer = %ld\n", sizeof(4)) ;
    printf("double = %ld\n", sizeof(4.0)) ;
    return 0;
}