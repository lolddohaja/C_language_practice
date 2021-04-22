#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024

struct Map
{
    char *map;
    int width;
    int height;
};

int kbhit(void)
{
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= (~(ICANON | ECHO));

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void loadMap(struct Map *selectMap, char *mapName)
{

    FILE *fp = fopen(mapName, "r");

    char buf[SIZE];
    char *origin = malloc(SIZE);

    int cnt = 0;
    int width = 0;
    int height = 0;
    char *line;

    while (1)
    {

        line = fgets(buf, SIZE, fp);
        if (line == NULL)
            break;
        line = strtok(line, "\n");

        for (int i = 0; i < strlen(line); i++)
        {
            *(origin + (cnt * strlen(line)) + i) = *(line + i);
        }
        width = (int)strlen(line);
        cnt++;
    }

    selectMap->map = origin;
    selectMap->width = width;
    selectMap->height = cnt;
}

void printMap(struct Map map)
{
    refresh();
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            mvprintw(y, x, "%c", *(map.map + (y * map.width) + x));
        }
    }
    refresh();
}

int main(void)
{
    initscr();

    struct Map first_map;
    loadMap(&first_map, "map1.txt");

    int cnt = 0;
    int x1 = 10, y1 = 8;
    int x2 = 40, y2 = 10;
    do
    {
        *(first_map.map + (y1 * first_map.width) + x1) = '@';
        printMap(first_map);
        char ch = 0, ch_buf;
        while (kbhit())
        {
            ch = getchar();
        }
        if (ch)
        {
        }
    } while (1);

    return 0;
}