#include <stdio.h> 
int main() {
    int input =1 , i = 1, j = 1;
    while (1) {
        printf( "input number(If you finish this program, you input 0):");
        scanf( "%d", & input);
        if (input == 0){
            break;
        }
        if (input < 1 || input > 9) {
            printf( "Your wrong\n");
        }
        else {
            for(j = 2; j <= input ; j++){
                i = 1;
                printf("%d단\n",j);
                while (i <= 9) {
                    printf( "%d * %d = %d\n", j, i, input * i);
                    i = i + 1;
                }}
        }
    }
    // while (i <= 9) {
    //     printf("%d * %d = %d\n", input, i, input * i);
    //     i = i + 1;
    // }
    return 0;
}
