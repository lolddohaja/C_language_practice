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
        printf("?„ ?ƒ?•˜?„¸?š”:");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n?›ë³? \n");
        printScreen((char *)my_image.img, my_image.width, my_image.height);

        switch (n)
        {
        //ì¢Œìš°ë°˜ì „
        case 1:
            printf("\nì¢Œìš°ë°˜ì „ \n");
            flipH(my_image.img, flip_h, my_image.width, my_image.height);
            printScreen((char *)flip_h, my_image.width, my_image.height);
            break;
        //?ƒ?•˜ë°˜ì „
        case 2:
            printf("\n?ƒ?•˜ë°˜ì „ \n");
            flipV(my_image.img, flip_v, my_image.width, my_image.height);
            printScreen((char *)flip_v,  my_image.width, my_image.height);
            break;
        //90?„ ?Œë¦¬ê¸°
        case 3:
            printf("\n90?„ ?Œë¦¬ê¸° \n");
            rotate9(my_image.img, rotate_90, my_image.width, my_image.height);
            printScreen((char *)rotate_90, my_image.height, my_image.width);
            break;
        //180?„ ?Œë¦¬ê¸°
        case 4:
            printf("\n180?„ ?Œë¦¬ê¸°\n");
            rotate18(my_image.img, rotate_180, my_image.width, my_image.height);
            printScreen((char *)rotate_180, my_image.width, my_image.height);
            break;
        //270?„ ?Œë¦¬ê¸°
        case 5:
            printf("\n270?„ ?Œë¦¬ê¸°\n");
            rotate27(my_image.img, rotate_270, my_image.width, my_image.height);
            printScreen((char *)rotate_270, my_image.height, my_image.width);
            break;
        //?¸ë²„íŠ¸
        case 6:
            printf("\n?¸ë²„íŠ¸ \n");
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
    printf("-------ê³¨ë¼ë³´ì„¸?š”-------\n");
    printf("       1ë²? ?”Œë¦½H        \n");
    printf("       2ë²? ?”Œë¦½V        \n");
    printf("      3ë²? 90?„?Œ? ¤      \n");
    printf("      4ë²? 180?„?Œ? ¤     \n");
    printf("      5ë²? 270?„?Œ? ¤     \n");
    printf("       6ë²? ?¸ë²„íŠ¸       \n");
    printf("       (0ë²? ì¢…ë£Œ)       \n");
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

    for (int y = 0; y < width; y++)
    {
        for (int x = 0; x < height - (width - height); x++)
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