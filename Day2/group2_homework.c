#include <stdio.h>

#define WIDTH 7
#define HEIGHT 6

void MENUFUNC(void)
{
    printf("--------menu-------\n");
    printf("   1 : original    \n");
    printf("   2 : 상하반전     \n");
    printf("   3 : 좌우반전     \n");
    printf("   4 : 90도(R) 돌리기\n");
    printf("   5 : 180도(R) 돌리기\n");
    printf("   6 : 확대          \n");
//    printf("   7 : 이동         \n");
    printf("   0 : 메뉴         \n");
    printf("   8 : 종료         \n");
    printf("--------------------\n");
}
/******************************************/ // menu function

void PRINTFUNC(char ORIGN[HEIGHT][WIDTH])
{
    for(int i = 0; i<HEIGHT; i++)
            {
                for(int j = 0; j<WIDTH; j++)
                {
                    printf("%c", ORIGN[i][j]);
                }
                printf("\n");
            }
            printf("\n");
}
/****************************************/ //print function

void REVERSEFUNC(char ORIGN[HEIGHT][WIDTH])
{
    char rever[HEIGHT][WIDTH];
    int k=0;

    for(int i=HEIGHT-1; i>=0; i--)
    {
        for(int j=0; j<WIDTH; j++)
        {

            rever[k][j]=ORIGN[i][j];
        }
        k++;
    }
    PRINTFUNC(rever);
}
/********************************************/ //상하반전

void LREVERSEFUNC(char ORIGN[HEIGHT][WIDTH])
{
    char lrever[HEIGHT][WIDTH];
    int k=0;

    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=WIDTH-1; j>=0; j--)
        {

            lrever[i][k]=ORIGN[i][j];
            k++;
        }
        k=0;
    }
    PRINTFUNC(lrever);
}
/********************************************/ //좌우반전

void SPINFUNC(char ORIGN[HEIGHT][WIDTH])
{
    char spin[WIDTH][HEIGHT];
    int k=0, l =0;

    for(int i=HEIGHT-1; i>=0; i--)
    {
        for(int j=0; j<WIDTH; j++)
        {
            spin[k][l]=ORIGN[i][j];
            k++;
        }
        k=0;
        l++;
    }

    for(int i = 0; i<WIDTH-(WIDTH - HEIGHT); i++)  
        {
            for(int j = 0; j<HEIGHT; j++)
            {
                printf("%c", spin[i][j]);
            }
            printf("\n");
        }
        printf("\n");
}
/********************************************/ //오른쪽으로 90도회전

void ASPIN(char ORIGN[HEIGHT][WIDTH])
{
    char aspin[HEIGHT][WIDTH];
    int k=0, l=0;

    for(int i=HEIGHT-1; i>=0; i--)
    {
        for(int j=WIDTH-1; j>=0; j--)
        {
            aspin[k][l]=ORIGN[i][j];
            l++;
        }
        l=0;
        k++;
    }
    PRINTFUNC(aspin);
}
/********************************************/ //오른쪽으로 180도 회전

int EXPANSIONFUNC(char ORIGN[HEIGHT][WIDTH], int EXINPUT)
{
    int HE = HEIGHT * EXINPUT;
    int WI = WIDTH * EXINPUT;
    char aspin[HE][WI];
    int height =0, width =0;

    printf("%d %d %d",HE,WI,EXINPUT);

    for(int i = 0; i<HE; i++)
    {
        if((i!=0)&&((i%EXINPUT)==0)) height++;
        for(int j=0; j<WI; j++)
        {
            aspin[i][j]=ORIGN[height][width];
            if((j!=0)&&((j%EXINPUT)==0)) width++;
        }
        printf("\n");
        width=0;
    }

    for(int i = 0; i<HE; i++)
            {
                for(int j = 0; j<WI; j++)
                {
                    printf("%c", aspin[i][j]);
                }
                printf("\n");
            }
            printf("\n");

}
/********************************************/ //확대

/*
int MOVINGXY(char ORIGN[HEIGHT][WIDTH], int X, int Y)
{
    char movingarray[HEIGHT][WIDTH];
    int HE, WI;
    int flagx = 0, flagy = 0;

    for(int i=0; i<HEIGHT; i++)
    {
        if((flagx == 0)&&(HE==HEIGHT))
        {
            HE=0;
            flagx = 1;
        }
        else if(flagx == 0)  HE = Y+i;
        else if(flagx == 1) HE++;

        for(int j=0; j<WIDTH; j++)
        {
            if((flagy == 0)&&(WI>WIDTH))
            {
                WI=0;
                flagy = 1;
            }
            else if(flagy == 0) WI = X+j;
            else if(flagy == 1) WI++;

            movingarray[HE][WI]=ORIGN[i][j];
        }
        flagy = 0;
        WI =0;
    }

    PRINTFUNC(movingarray);
}
*/
/********************************************/ //축 이동

int main(void)
{
    char orign[HEIGHT][WIDTH] = {
                                {'.','.','.','*','.','.','.'},
                                {'.','.','*','*','*','.','.'},
                                {'.','.','*','#','*','*','.'},
                                {'.','.','*','#','*','.','.'},
                                {'.','.','*','*','.','@','.'},
                                {'.','&','*','.','.','.','.'},
                                };

    int input = 0;

    MENUFUNC();

    while(input != 8)
    {
        printf("input number = ");
        scanf("%d",&input);
        printf("\n");

        if(input == 1)
        {
            PRINTFUNC(orign);
            input = 0;
        } //print original

        else if(input == 2)
        {
            REVERSEFUNC(orign);
        }
        else if(input == 3)
        {
            LREVERSEFUNC(orign);
        }
        else if(input == 4)
        {
            SPINFUNC(orign);
        }
        else if(input == 8)
        {
            printf("bye bye \n\n");
        }
        else if(input == 5)
        {
            ASPIN(orign);
        }
        else if(input == 6)
        {
            int sizeinput=0;
            printf("enter array size : ");
            scanf("%d",&sizeinput);
            printf("\n");
            EXPANSIONFUNC(orign, sizeinput);
        }
/*        else if(input == 7)
        {
            int xinput=0, yinput = 0;
            printf("enter x y : ");
            scanf("%d %d",&xinput, &yinput);
            printf("\n");
            MOVINGXY(orign, xinput, yinput);
        }*/
        else if(input == 0)
        {
            MENUFUNC();
        }
    }
    return 0;
}