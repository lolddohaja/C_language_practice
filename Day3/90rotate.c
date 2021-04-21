#include <stdio.h>

#define WIDTH 8
#define HEIGHT 6

void rotate9(char *src, char *dest, int width, int height);
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
    printScreen((char *)my_image.img, my_image.width, my_image.height);
    printf("90도 돌리기 \n");
    char rotate_90[WIDTH][HEIGHT];
    rotate9(my_image.img, rotate_90, my_image.width, my_image.height);
    printScreen((char *)rotate_90, my_image.height, my_image.width);
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

void rotate9(char *src, char *dest, int width, int height)
{
    if (width > height)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width - (width - height); x++)
            {
                //dest[x][HEIGHT - 1 - y] = src[y][x];
                *(dest + (x * width) + (width-(width - height) - y)) = *(src + (y * width) + x);
            }
        }
    }
    // else if(height > width)
    // {
    //     for (int y = 0; y < height; y++)
    //     {
    //         for (int x = 0; x < width - (width - height); x++)
    //         {
    //             *(dest + (x * height) + (width - y)) = *(src + (y * width) + x);
    //         }
    //     }
    // }
}

