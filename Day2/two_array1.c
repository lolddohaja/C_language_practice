#include <stdio.h>

int main(){
    int a[3][4], i, j, sum[4];

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j){
            a[i][j] += 1;
            sum[i] += a[i][j];
        }
    }
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 4; ++j){
            printf("")
            scanf("%d", &a[i][j]);
        }
    }
    printf("-------------");
    for(j = 0; j<4;++j){
        printf("%d ",sum[i]);
    }
}
