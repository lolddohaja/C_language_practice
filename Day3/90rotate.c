#include <stdio.h>

#define WIDTH 9
#define HEIGHT 8

void rotate9(char *src, int width, int height);
void printScreen(char *arr_p, int width, int height);

struct imgSt
{
    char *img;
    int width;
    int height;
};

int main()
{
    char origin[HEIGHT][WIDTH] = {
        "---*----*",
        "---*----*",
        "--***---*",
        "-*-***--*",
        "*--***--*",
        "*--***--*",
        "****----*",
        "****----*"};
    struct imgSt my_image;
    my_image.img = origin;
    my_image.width = WIDTH;
    my_image.height = HEIGHT;
    printScreen((char *)my_image.img, my_image.width, my_image.height);
    printf("90도 회전하기 \n");
    
    rotate9(my_image.img, my_image.width, my_image.height);
    
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

void rotate9(char *src, int width, int height)
{
    char rotate_90[width][height];
    if (width >= height)
    {
        for (int y = 0 ; y < height; y++ )
        {
            for (int x = 0; x <width-(width-height) ; x++)
            {
                *(*rotate_90 + (x * height) +(height-1-y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_90, width-(width-height) , height);
    }
    else if (height > width){
        for (int y = 0; y < height-(height-width); y++)
        {
            for (int x = 0; x < width; x++)
            {
                *(*rotate_90 + (x * width) + (height - (height-width) - y)) = *(src + (y * width) + x);
            }
        }
        printScreen((char *)rotate_90, width , height-(height-width));   
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
    printScreen((char *)dest, width-(width-height) , height);
}