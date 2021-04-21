#include <stdio.h>

float avr3(int num1, int num2, int num3){
    float avr;
    avr = (num1+num2+num3)/3.0;
    return avr;
}
int main(){
    int a, b, c; 
    float avr;
    printf("input 3 integers: ");
    scanf("%d%d%d",&a,&b,&c);

    printf("numbers %d, %d, %d are average %.2f\n", a, b, c, avr3(a,b,c));
    
    return 0;
}