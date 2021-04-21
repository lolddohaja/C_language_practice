#include <stdio.h>

#define WIDTH 8
#define HEIGHT 6

struct imgSt{
    char *img;
    int width;
    int height;
};

void menu();
void printScreen(char *arr_p, int width, int height);
void flipH(char *src, int width, int height);
void flipV(char *src, int width, int height);
void rotate9(char *src, int width, int height);
void rotate18(char *src, int width, int height);
void rotate27(char *src, int width, int height);
void invertf(char *src, int width, int height);

int main()
{
    int n;
    //臾몄옄?뿴 ?뼱?젅?씠濡? ?몴?쁽 媛??뒫
    //援ъ“泥대줈 留뚮뱾?뼱?꽌 ?몴?쁽 媛??뒫 援ъ“泥? ?븞?뿉?꽌 width, height, img瑜? 留뚮뱾 ?닔 ?엳?떎
    //?씠誘몄??瑜? 珥덇린?솕 ?븯?뒗 ?븿?닔
    char origin[HEIGHT][WIDTH] = {
        "---*----",
        "---*----",
        "--***---",
        "-*-***--",
        "*--****-",
        "*--****-"};
    struct imgSt my_image;
    my_image.img = origin;
    my_image.width = WIDTH;
    my_image.height = HEIGHT;

    while (1)
    {
        menu();
        printf("선택하세요:");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n원본 \n");
        printScreen((char *)my_image.img, my_image.width, my_image.height);

        switch (n)
        {
        //좌우 반전
        case 1:
            printf("\n좌우 반전 \n");
            flipH(my_image.img, my_image.width, my_image.height);
            break;

        //상하 반전
        case 2:
            printf("\n상하 반전 \n");
            flipV(my_image.img, my_image.width, my_image.height);
            break;

        //90도 돌리기
        case 3:
            printf("\n90도 돌리기 \n");
            rotate9(my_image.img, my_image.width, my_image.height);
            break;

        //180?룄 ?룎由ш린
        case 4:
            printf("\n180도 돌리기\n");
            rotate18(my_image.img,my_image.width, my_image.height);
            break;
        //270?룄 ?룎由ш린
        case 5:
            printf("\n270도 돌리기\n");
            rotate27(my_image.img, my_image.width, my_image.height);
            break;
        //?씤踰꾪듃
        case 6:
            printf("\n인버트 \n");
            invertf(my_image.img, my_image.width,my_image.height);
            break;
        default:
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("--------골라보세요--------\n");
    printf("       1번 좌우 반전        \n");
    printf("       2번 상하 반전        \n");
    printf("       3번 90도 돌리기      \n");
    printf("      4번 180도 돌리기      \n");
    printf("      5번 270도 돌리기      \n");
    printf("         6번 인버트         \n");
    printf("         (0번 종료)        \n");
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

void flipH(char *src, int width, int height)
{
    char flip_h[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(*flip_h + (y * width) + x) = *(src + (y * width) + (width - 1) - x);
        }
    }
    printScreen((char *)flip_h, width, height);
}

void flipV(char *src, int width, int height)
{
    char flip_v[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(*flip_v + (y * width) + x) = *(src + (((height - 1) - y) * width) + x);
        }
    }
    printScreen((char *)flip_v,  width, height);
}

void rotate9(char *src,int width, int height)
{
    char rotate_90[width][height];
    if (width >= height){
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width - (width - height); x++)
            {
                *(*rotate_90 + (x * height) + (height - 1 - y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_90, width-(width-height) , height);
    }
    else if (height>width){
        for (int y = 0; y < height-(height-width); y++)
        {
            for (int x = 0; x < width; x++)
            {
                *(*rotate_90 + (x * height) + (height - (height-width) - y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_90, width , height-(height-width));   
    }
}

void rotate18(char *src, int width, int height)
{
    char rotate_180[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            *(*rotate_180 + (y * width) + x) = *(src + (((height - 1) - y) * width) + ((width - 1) - x));
        }
    }
    printScreen((char *)rotate_180, width, height);
}

void rotate27(char *src, int width, int height)
{
    char rotate_270[height][width];
    if(width>=height){
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width - (width - height); x++)
            {
                *(*rotate_270 + ((height-1 - x) * height) + y) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_270, width-(width-height) , height);
    }
    else if(height>width){
        for (int y = 0; y < height-(height-width); y++)
        {
            for (int x = 0; x < width; x++)
            {
                *(*rotate_270 + (height - (height-width) - x) * height + y) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_270, width , height-(height-width));
    }
}

void invertf(char *src, int width, int height)
{
    char invert[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (*(src + (y * width) + x) == '*')
            {
                *(*invert + (y * width) + x) = '-';
            }
            else
            {
                *(*invert + (y * width) + x) = '*';
            }
        }
    }
    printScreen((char *)invert, width, height);
}