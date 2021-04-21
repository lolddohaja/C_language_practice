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
void flipH(char *src, char *dest, int width, int height);
void flipV(char *src, char *dest, int width, int height);
void rotate9(char *src, char *dest, int width, int height);
void rotate18(char *src, char *dest, int width, int height);
void rotate27(char *src, char *dest, int width, int height);
void invertf(char *src, char *dest, int width, int height);

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
    char flip_h[HEIGHT][WIDTH];
    char flip_v[HEIGHT][WIDTH];
    char rotate_90[WIDTH][HEIGHT];
    char rotate_180[HEIGHT][WIDTH];
    char rotate_270[WIDTH][HEIGHT];
    char invert[HEIGHT][WIDTH];

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
        //왜 한글 안올라가냐 화나게
        case 1:
            printf("\n좌우 반전 \n");
            flipH(my_image.img, flip_h, my_image.width, my_image.height);
            printScreen((char *)flip_h, my_image.width, my_image.height);
            break;
        //?긽?븯諛섏쟾
        case 2:
            printf("\n상하 반전 \n");
            flipV(my_image.img, flip_v, my_image.width, my_image.height);
            printScreen((char *)flip_v,  my_image.width, my_image.height);
            break;
        //90?룄 ?룎由ш린
        case 3:
            printf("\n90도 돌리기 \n");
            rotate9(my_image.img, rotate_90, my_image.width, my_image.height);
            //printScreen((char *)rotate_90, my_image.height, my_image.width);
            break;
        //180?룄 ?룎由ш린
        case 4:
            printf("\n180도 돌리기\n");
            rotate18(my_image.img, rotate_180, my_image.width, my_image.height);
            printScreen((char *)rotate_180, my_image.width, my_image.height);
            break;
        //270?룄 ?룎由ш린
        case 5:
            printf("\n270도 돌리기\n");
            rotate27(my_image.img, rotate_270, my_image.width, my_image.height);
            //printScreen((char *)rotate_270, my_image.height, my_image.width);
            break;
        //?씤踰꾪듃
        case 6:
            printf("\n인버트 \n");
            invertf(my_image.img, invert, my_image.height, my_image.width);
            printScreen((char *)invert, my_image.width, my_image.height);
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
    if (width >= height){
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width - (width - height); x++)
            {
                *(dest + (x * height) + (height - 1 - y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)dest, width-(width-height) , height);
    }
    else if (height>width){
        for (int y = 0; y < height-(height-width); y++)
        {
            for (int x = 0; x < width; x++)
            {
                *(dest + (x * height) + (height - (height-width) - y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)dest, width , height-(height-width));   
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
    if(width>=height){
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width - (width - height); x++)
            {
                *(dest + ((height-1 - x) * height) + y) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)dest, width-(width-height) , height);
    }
    else if(height>width){
        for (int y = 0; y < height-(height-width); y++)
        {
            for (int x = 0; x < width; x++)
            {
                *(dest + (height - (height-width) - x) * height + y) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)dest, width , height-(height-width));
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