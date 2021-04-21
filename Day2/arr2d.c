#include <stdio.h>
#define WIDTH 7
#define HEIGHT 6

void printScreen(char arr[][WIDTH], int height);
void printScreen2(char arr[][HEIGHT], int width);
void flipH(char src[][WIDTH], char dest[][WIDTH], int height);
void flipV(char src[][WIDTH], char dest[][WIDTH], int height);
void rotate9(char src[][WIDTH], char dest[][HEIGHT], int width);
void rotate18(char src[][WIDTH], char dest[][WIDTH], int height);
void rotate27(char src[][WIDTH], char dest[][HEIGHT], int width);
void invertf(char src[][WIDTH], char dest[][WIDTH], int height);

int main(void)
{
    int  n;

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
        printf("1.플립H, 2.플립V, 3.90도돌려, 4.180도돌려, 5.270도 돌려, 6.인버트 (0.종료): ");
        scanf("%d",&n);
        if(n==0) break;

        //print origin
        printf("\nOriginal \n");
        printScreen(origin, HEIGHT);


        switch (n)
        {
        //flipH
        case 1:{
           
            flipH(origin, flip_h, HEIGHT);
            printScreen(flip_h, HEIGHT);
        }
        break;
        //flipV
        case 2:{
            flipV(origin, flip_v, HEIGHT);
            printScreen(flip_v, HEIGHT);
     
        }
        break;
        //90도 돌리기
        case 3:{
            rotate9(origin, rotate_90, HEIGHT);
            printScreen2(rotate_90, WIDTH);
        }
        break;
        //180도 돌리기
        case 4:{
            rotate18(origin, rotate_180, HEIGHT);
            printScreen(rotate_180, HEIGHT);
        }
        break;
        //270도 돌리기
        case 5:{
            rotate27(origin, rotate_270, HEIGHT);
            printScreen2(rotate_270, HEIGHT);
        }
        break;
        //인버트
        case 6:{
            invertf(origin, invert, HEIGHT);
            printScreen(invert, HEIGHT);
        }
        break;
        default: break;
        }


    }
    // move x, y
    // zoom
    // function
    return 0;
}

void printScreen(char arr[][WIDTH], int height){
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            printf("%c", arr[y][x]);
        }
        printf("\n");
    }
}

void printScreen2(char arr[][HEIGHT], int width){
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            printf("%c", arr[i][j]);
        }


        printf("\n");
    }
}

void flipH(char src[][WIDTH], char dest[][WIDTH], int height){
    for (int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            dest[y][x] = src[y][(WIDTH-1)-x];
        }
    }
    printf("\nflip_h \n");
}

void flipV(char src[][WIDTH], char dest[][WIDTH], int height){
    for (int y = 0; y < HEIGHT; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            dest[y][x] = src[(HEIGHT-1)-y][x];
        }
    }
    printf("\nflip_h \n");
}

void rotate9(char src[][WIDTH], char dest[][HEIGHT], int width){

    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0 ; j < WIDTH ; j++)
        {
            dest[j][HEIGHT-1-i] = src[i][j];
        }
    }
    printf("\n90도 돌리기 \n");
}

void rotate18(char src[][WIDTH], char dest[][WIDTH], int height){
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            dest[i][j] = src[HEIGHT-1-i][WIDTH-1-j];
        }
    }
    printf("\nrotate 180\n");
}

void rotate27(char src[][WIDTH], char dest[][HEIGHT], int width){
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            dest[WIDTH-1-j][i] = src[i][j];
        }
    }
    printf("\nrotate 270\n");
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
    printf("\n인버트 \n");
}