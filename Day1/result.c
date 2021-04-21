#include <stdio.h>

int main(void)
{
    float a , b = 0;
    char op;
    
    printf("Input two real numbers: ");
    scanf("%f %f", &a, &b);
    printf("choose operator +,-,*,/ : ");
    scanf(" %c", &op);
    if (op == '+')
    {
        printf("%f %c %f = %f\n", a, op, b, a+b);
    }
    else if (op == '-')
    {
        printf("%f %c %f = %f\n", a, op, b, a-b);
    }
    else if (op == '*')
    {
        printf("%f %c %f = %f\n", a, op, b, a*b);
    }
    else if (op == '/' && b != 0)
    {
        printf("%f %c %f = %f\n", a, op, b, a/b);
    }
    else{printf("Your input is wrong!!\n");}

    return 0;
}