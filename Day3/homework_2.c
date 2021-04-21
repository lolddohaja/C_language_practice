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
    //λ¬Έμ?΄ ?΄? ?΄λ‘? ?? κ°??₯
    //κ΅¬μ‘°μ²΄λ‘ λ§λ€?΄? ?? κ°??₯ κ΅¬μ‘°μ²? ??? width, height, imgλ₯? λ§λ€ ? ??€
    //?΄λ―Έμ??λ₯? μ΄κΈ°? ?? ?¨?
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
        printf("? ???Έ?:");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("\n?λ³? \n");
        printScreen((char *)my_image.img, my_image.width, my_image.height);

        switch (n)
        {
        //μ’μ°λ°μ 
        case 1:
            printf("\nμ’μ°λ°μ  \n");
            flipH(my_image.img, flip_h, my_image.width, my_image.height);
            printScreen((char *)flip_h, my_image.width, my_image.height);
            break;
        //??λ°μ 
        case 2:
            printf("\n??λ°μ  \n");
            flipV(my_image.img, flip_v, my_image.width, my_image.height);
            printScreen((char *)flip_v,  my_image.width, my_image.height);
            break;
        //90? ?λ¦¬κΈ°
        case 3:
            printf("\n90? ?λ¦¬κΈ° \n");
            rotate9(my_image.img, rotate_90, my_image.width, my_image.height);
            printScreen((char *)rotate_90, my_image.height, my_image.width);
            break;
        //180? ?λ¦¬κΈ°
        case 4:
            printf("\n180? ?λ¦¬κΈ°\n");
            rotate18(my_image.img, rotate_180, my_image.width, my_image.height);
            printScreen((char *)rotate_180, my_image.width, my_image.height);
            break;
        //270? ?λ¦¬κΈ°
        case 5:
            printf("\n270? ?λ¦¬κΈ°\n");
            rotate27(my_image.img, rotate_270, my_image.width, my_image.height);
            printScreen((char *)rotate_270, my_image.height, my_image.width);
            break;
        //?Έλ²νΈ
        case 6:
            printf("\n?Έλ²νΈ \n");
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
    printf("-------κ³¨λΌλ³΄μΈ?-------\n");
    printf("       1λ²? ?λ¦½H        \n");
    printf("       2λ²? ?λ¦½V        \n");
    printf("      3λ²? 90??? €      \n");
    printf("      4λ²? 180??? €     \n");
    printf("      5λ²? 270??? €     \n");
    printf("       6λ²? ?Έλ²νΈ       \n");
    printf("       (0λ²? μ’λ£)       \n");
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