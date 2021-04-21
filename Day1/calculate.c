#include <stdio.h>
#include <math.h>

float expression(float num);

int main(void){
    float num;
    printf("Enter value for x : ");
    scanf("%f", &num);
    printf("Polynomial value: %.2f\n", expression(num));
}

float expression(float num){
    float result;
    result = (3*pow(num,5))+(2*pow(num,4))-(5*pow(num,3))-(pow(num,2))+(7*num)-6;
    return result;
}