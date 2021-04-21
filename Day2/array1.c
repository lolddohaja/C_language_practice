#include <stdio.h>



int main(void){
    int arr[7];
    for(int i = 1; i<8; i++){
        printf("input integer %d:",i);
        scanf("%d", &arr[i-1]);
    }
    int max = arr[0];
    int min = arr[0];
    int sum = 0;

    for(int j = 0; j < sizeof(arr)/sizeof(int);j++)
    {
        if(arr[j]>max) max = arr[j];
        if(arr[j]<min) min = arr[j];
    }
    for(int j = 0; j < sizeof(arr)/sizeof(int);j++)
    {
        sum = arr[j]+sum;
    }
    printf("max:%d, min:%d, sum:%d\n", max, min, sum);
    return 0;
}

