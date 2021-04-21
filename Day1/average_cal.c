#include <stdio.h>

int main(void){
    int n = 0;
    float result = 0, sum = 0, count = 0;
    for(int i=1; n>=0; i++){    
        printf("input real number(minus to quit):");
        scanf("%d", &n);
        if(n<0){
            break;
        }
        else{
            sum += n;
            count += 1;
        }
        }
    result = sum/count;
    printf("average: %.2f\n",result);

    return 0;
}