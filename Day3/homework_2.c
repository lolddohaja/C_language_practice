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
    //ë¬¸ì?—´ ?–´? ˆ?´ë¡? ?‘œ?˜„ ê°??Š¥
    //êµ¬ì¡°ì²´ë¡œ ë§Œë“¤?–´?„œ ?‘œ?˜„ ê°??Š¥ êµ¬ì¡°ì²? ?•ˆ?—?„œ width, height, imgë¥? ë§Œë“¤ ?ˆ˜ ?ˆ?‹¤
    //?´ë¯¸ì??ë¥? ì´ˆê¸°?™” ?•˜?Š” ?•¨?ˆ˜
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
        printf("¼±ÅÃÇÏ¼¼¿ä:");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n¿øº» \n");
        printScreen((char *)my_image.img, my_image.width, my_image.height);

        switch (n)
        {
        //ì¢Œìš°ë°˜ì „
        case 1:
            printf("\nÁÂ¿ì ¹İÀü \n");
            flipH(my_image.img, flip_h, my_image.width, my_image.height);
            printScreen((char *)flip_h, my_image.width, my_image.height);
            break;
        //?ƒ?•˜ë°˜ì „
        case 2:
            printf("\n»óÇÏ ¹İÀü \n");
            flipV(my_image.img, flip_v, my_image.width, my_image.height);
            printScreen((char *)flip_v,  my_image.width, my_image.height);
            break;
        //90?„ ?Œë¦¬ê¸°
        case 3:
            printf("\n90µµ µ¹¸®±â \n");
            rotate9(my_image.img, rotate_90, my_image.width, my_image.height);
            //printScreen((char *)rotate_90, my_image.height, my_image.width);
            break;
        //180?„ ?Œë¦¬ê¸°
        case 4:
            printf("\n180µµ µ¹¸®±â\n");
            rotate18(my_image.img, rotate_180, my_image.width, my_image.height);
            printScreen((char *)rotate_180, my_image.width, my_image.height);
            break;
        //270?„ ?Œë¦¬ê¸°
        case 5:
            printf("\n270µµ µ¹¸®±â\n");
            rotate27(my_image.img, rotate_270, my_image.width, my_image.height);
            //printScreen((char *)rotate_270, my_image.height, my_image.width);
            break;
        //?¸ë²„íŠ¸
        case 6:
            printf("\nÀÎ¹öÆ® \n");
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
    printf("--------°ñ¶óº¸¼¼¿ä--------\n");
    printf("       1¹ø ÁÂ¿ì ¹İÀü        \n");
    printf("       2¹ø »óÇÏ ¹İÀü        \n");
    printf("       3¹ø 90µµ µ¹¸®±â      \n");
    printf("      4¹ø 180µµ µ¹¸®±â      \n");
    printf("      5¹ø 270µµ µ¹¸®±â      \n");
    printf("         6¹ø ÀÎ¹öÆ®         \n");
    printf("         (0¹ø Á¾·á)        \n");
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