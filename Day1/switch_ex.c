#include <stdio.h>

int main(void)
{
    int input;
    printf("11~99 사이의 값을 입력하시오: ");
    scanf("%d", &input);

    if (input < 11 || input > 99)
    {
        printf("입력값은 11 ~ 99 사이의 값이어야 합니다.\n");
        return 0;
    }

    switch (input/10)
    {
        case 2:
            printf("이");
            break;
        case 3:
            printf("삼");
            break;
        case 4:
            printf("사");
            break;
        case 5:
            printf("오");
            break;
        case 6:
            printf("육");
            break;
        case 7:
            printf("칠");
            break;
        case 8:
            printf("팔");
            break;
        case 9:
            printf("구");
            break;
        default:
            break;
    }
    printf("십");
    
    switch (input-(input/10)*10)
    {
        case 2:
            printf("이\n");
            break;
        case 3:
            printf("삼\n");
            break;
        case 4:
            printf("사\n");
            break;
        case 5:
            printf("오\n");
            break;
        case 6:
            printf("육\n");
            break;
        case 7:
            printf("칠\n");
            break;
        case 8:
            printf("팔\n");
            break;
        case 9:
            printf("구\n");
            break;
        default:
            break;
    }
}