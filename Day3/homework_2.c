#include <stdio.h>

#define WIDTH 7
#define HEIGHT 6

struct imgSt{
    char *img;
    int width;
    int height;
};

void menu();
void printScreen(char *arr_p, int width, int height);
void flipH(char *src, char *dest, int width, int height);
void flipV(char *src, char *dest, int width, int height);
void rotate9(char *src, char *dest, int width, int height);
void rotate18(char *src, char *dest, int width, int height);
void rotate27(char *src, char *dest, int width, int height);
void invertf(char *src, char *dest, int width, int height);

int main(void)
{
    int n;
    //문자열 어레이로 표현 가능
    //구조체로 만들어서 표현 가능 구조체 안에서 width, height, img를 만들 수 있다
    //이미지를 초기화 하는 함수
    char origin[HEIGHT][WIDTH] = {
        "---*---",
        "---*---",
        "--***--",
        "-*-***-",
        "*--****",
        "*--****"};

    char flip_h[HEIGHT][WIDTH];
    char flip_v[HEIGHT][WIDTH];
    char rotate_90[WIDTH][HEIGHT];
    char rotate_180[HEIGHT][WIDTH];
    char rotate_270[WIDTH][HEIGHT];
    char invert[HEIGHT][WIDTH];

    while (1)
    {
        menu();
        printf("선택하세요:");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n원본 \n");
        printScreen((char *)origin, WIDTH, HEIGHT);

        switch (n)
        {
        //좌우반전
        case 1:
            printf("\n좌우반전 \n");
            flipH(origin, flip_h, WIDTH, HEIGHT);
            printScreen((char *)flip_h, WIDTH, HEIGHT);
            break;
        //상하반전
        case 2:
            printf("\n상하반전 \n");
            flipV(origin, flip_v, WIDTH, HEIGHT);
            printScreen((char *)flip_v, WIDTH, HEIGHT);
            break;
        //90도 돌리기
        case 3:
            printf("\n90도 돌리기 \n");
            rotate9(origin, rotate_90, WIDTH, HEIGHT);
            printScreen((char *)rotate_90, HEIGHT, WIDTH);
            break;
        //180도 돌리기
        case 4:
            printf("\n180도 돌리기\n");
            rotate18(origin, rotate_180, WIDTH, HEIGHT);
            printScreen((char *)rotate_180, WIDTH, HEIGHT);
            break;
        //270도 돌리기
        case 5:
            printf("\n270도 돌리기\n");
            rotate27(origin, rotate_270, WIDTH, HEIGHT);
            printScreen((char *)rotate_270, HEIGHT, WIDTH);
            break;
        //인버트
        case 6:
            printf("\n인버트 \n");
            invertf(origin, invert, HEIGHT, WIDTH);
            printScreen((char *)invert, WIDTH, HEIGHT);
            break;
        default:
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("-------골라보세요-------\n");
    printf("       1번 플립H        \n");
    printf("       2번 플립V        \n");
    printf("      3번 90도돌려      \n");
    printf("      4번 180도돌려     \n");
    printf("      5번 270도돌려     \n");
    printf("       6번 인버트       \n");
    printf("       (0번 종료)       \n");
}

void printScreen(char *arr_p, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            printf("%c", *(arr_p + (y * width) + x));
        }
        printf("\n");
    }
    printf("\n");
}

void flipH(char *src, char *dest, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(dest + (y * width) + x) = *(src + (y * width) + (width - 1) - x);
        }
    }
}

void flipV(char *src, char *dest, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(dest + (y * width) + x) = *(src + (((height - 1) - y) * width) + x);
        }
    }
}

void rotate9(char *src, char *dest, int width, int height)
{

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width - (width - height); x++)
        {
            *(dest + (x * height) + (width - 2 - y)) = *(src + (y * width) + x);
        }
    }
}

void rotate18(char *src, char *dest, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(dest + (y * width) + x) = *(src + (((height - 1) - y) * width) + ((width - 1) - x));
        }
    }
}

void rotate27(char *src, char *dest, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width - (width - height); x++)
        {
            *(dest + ((height - x) * height) + (y)) = *(src + (y * width) + x);
        }
    }
}

void invertf(char *src, char *dest, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (*(src + (y * width) + x) == '*')
            {
                *(dest + (y * width) + x) = '-';
            }
            else
            {
                *(dest + (y * width) + x) = '*';
            }
        }
    }
}