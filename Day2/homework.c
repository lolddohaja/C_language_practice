#include <stdio.h>

#define WIDTH 7
#define HEIGHT 6

void menu(void);
void printScreen(char *arr_p, int width, int height);
void flipH(char *src, char *dest, int width, int height);
void flipV(char src[][WIDTH], char dest[][WIDTH], int height);
void rotate9(char src[][WIDTH], char dest[][HEIGHT], int width);
void rotate18(char src[][WIDTH], char dest[][WIDTH], int height);
void rotate27(char src[][WIDTH], char dest[][HEIGHT], int width);
void invertf(char src[][WIDTH], char dest[][WIDTH], int height);

int main(void)
{
    int  n;
    //문자열 어레이로 표현 가능 
    //구조체로 만들어서 표현 가능
    char origin[HEIGHT][WIDTH] = {
        {'-','-','-','*','-','-','-'},
        {'-','-','-','*','-','-','-'},
        {'-','-','*','*','*','-','-'},
        {'-','*','-','*','*','*','-'},
        {'*','-','-','*','*','*','*'},
        {'*','-','-','*','*','*','*'}
    };
    char flip_h[HEIGHT][WIDTH];
    char flip_v[HEIGHT][WIDTH];
    char rotate_90[WIDTH][HEIGHT];
    char rotate_180[HEIGHT][WIDTH];
    char rotate_270[WIDTH][HEIGHT];
    char invert[HEIGHT][WIDTH];

    while(1){
        menu();
        printf("선택하세요:");
        scanf("%d",&n);
        if(n==0) break;
        //print origin
        printf("\nOriginal \n");
        printScreen((char *)origin, WIDTH, HEIGHT);
        switch (n)
        {
        //flipH
        case 1:
            flipH(origin, flip_h, WIDTH,HEIGHT);
            printScreen((char *)flip_h, WIDTH, HEIGHT);
            printf("\nflip_h \n");
            break;
        //flipV
        case 2:
            flipV(origin, flip_v, HEIGHT);
            printScreen((char *)flip_v, WIDTH, HEIGHT);
            printf("\nflip_v \n");
            break;
        //90도 돌리기
        case 3:
            rotate9(origin, rotate_90, HEIGHT);
            printScreen((char *)rotate_90, HEIGHT, WIDTH);
            printf("\n90도 돌리기 \n");
            break;
        //180도 돌리기
        case 4:
            rotate18(origin, rotate_180, HEIGHT);
            printScreen((char *)rotate_180, WIDTH, HEIGHT);
            printf("\nrotate 180\n");
            break;
        //270도 돌리기
        case 5:
            rotate27(origin, rotate_270, HEIGHT);
            printScreen((char *)rotate_270, HEIGHT, WIDTH);
            printf("\nrotate 270\n");
            break;
        //인버트
        case 6:
            invertf(origin, invert, HEIGHT);
            printScreen((char *)invert, WIDTH, HEIGHT);
            printf("\n인버트 \n");
            break;
        default: break;
        }
    }
    // move x, y
    // zoom
    // function
    return 0;
}

void menu(void){
    printf("-------골라보세요-------");
    printf("       1번 플립H        ");
    printf("       2번 플립V        ");
    printf("      3번 90도돌려      ");
    printf("      4번 180도돌려     ");
    printf("      5번 270도돌려     ");
    printf("       6번 인버트       ");
    printf("       (0번 종료)       ");
}

void printScreen(char *arr_p, int width, int height){
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            printf("%c", *(arr_p + (y*width) + x) );
        }
        printf("\n");
    }
}

void flipH(char *src, char *dest, int width, int height){
    for (int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            dest[y][x] = src[y][(WIDTH-1)-x];
        }
    }
    
}

void flipV(char src[][WIDTH], char dest[][WIDTH], int height){
    for (int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            dest[y][x] = src[(HEIGHT-1)-y][x];
        }
    }
    
}

void rotate9(char src[][WIDTH], char dest[][HEIGHT], int width){

    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0 ; j < WIDTH ; j++)
        {
            dest[j][HEIGHT-1-i] = src[i][j];
        }
    }
    
}

void rotate18(char src[][WIDTH], char dest[][WIDTH], int height){
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            dest[i][j] = src[HEIGHT-1-i][WIDTH-1-j];
        }
    }
    
}

void rotate27(char src[][WIDTH], char dest[][HEIGHT], int width){
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            dest[WIDTH-1-j][i] = src[i][j];
        }
    }
    
}

void invertf(char src[][WIDTH], char dest[][WIDTH], int height){

    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(src[i][j] == '*'){
                dest[i][j] = '-';
            }else{
                dest[i][j] = '*';
            }
        }
    }
}