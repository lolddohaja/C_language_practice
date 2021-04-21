#include <stdio.h>
#define WIDTH 8
#define HEIGHT 6
int main(void){
    char rotate_90[WIDTH][HEIGHT];
    char origin[HEIGHT][WIDTH] = {
        "---*----",
        "---*----",
        "--***---",
        "-*-***--",
        "*--****-",
        "*--****-"};
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%x  ",&origin[y][x]);
            *(*rotate_90 + (x * HEIGHT) +  (HEIGHT-1-y)) = *(origin + (y * HEIGHT) + x);

        }
        printf("\n");
    }
    for (int y = 0; y < WIDTH; y++)
    {
        for (int x = 0; x < HEIGHT; x++)
        {
            printf("%x ", &rotate_90[y][x]);
        }
        printf("\n");
    }
                
}