#include <stdio.h>
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int input_num;
    printf("Input number: ");
    scanf("%d", &input_num);
    printf("%d\n", fib(input_num));
    return 0;
}