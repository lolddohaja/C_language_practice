#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024
#define WALL '#'
#define GOAL 'G'
#define PLAYER '@'
#define EMPTY ' '

#define WALL_PAIR     1
#define GOAL_PAIR     2
#define PLAYER_PAIR   3
#define EMPTY_PAIR    4

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

void printMap(struct Map map, int cnt)
{
    refresh();
    
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            if (*(map.map + (y * map.width) + x)=='#')
            {
                attron(COLOR_PAIR(WALL_PAIR));
            }
            else if (*(map.map + (y * map.width) + x)=!'#')
            {
                attroff(COLOR_PAIR(WALL_PAIR));
            }
            mvprintw(y, x, "%c", *(map.map + (y * map.width) + x));
            
        }
    }
    attron(COLOR_PAIR(EMPTY_PAIR));
    mvprintw(map.height, 0, "cnt: %d", cnt);
    attroff(COLOR_PAIR(EMPTY_PAIR));
    refresh();
}

int get_dx(char ch)
{
    if (ch == 'd')
    {
        return 1;
    }
    else if (ch == 'a')
    {
        return -1;
    }
    return 0;
}

int get_dy(char ch)
{
    if (ch == 's')
    {
        return 1;
    }
    else if (ch == 'w')
    {
        return -1;
    }
    return 0;
}
int map_menu()
{
    printf("--------Select Map---------");
    printf("----------level1-----------");
    printf("----------level2-----------");
    printf("----------level3-----------");
    printf("----------level4-----------");
    printf("----------level5-----------");
    printf("----------level6-----------");
    printf("----------level7-----------");
}


int main(void)
{
    initscr();
    start_color();
    init_pair(WALL_PAIR, COLOR_YELLOW, COLOR_RED);
    init_pair(GOAL_PAIR, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(PLAYER_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(EMPTY_PAIR, COLOR_WHITE, COLOR_BLACK);

    struct Map first_map;
    loadMap(&first_map, "map1.txt");

    int count = 0;
    int x1 = 1, y1 = first_map.height-2;
    int x2 = 40, y2 = 10;
    do
    {
        attron(COLOR_PAIR(PLAYER_PAIR));
        mvaddch(y1,x1, PLAYER);
        attroff(COLOR_PAIR(PLAYER_PAIR));
        
        *(first_map.map + (y1 * first_map.width) + x1) = '@';
        
        printMap(first_map, count);
        char ch = 0, ch_buf;
        while (kbhit())
        {
            ch = getchar();
        }
        if (ch)
        {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(y1, x1, EMPTY);
            *(first_map.map + (y1 * first_map.width) + x1) = ' ';
            attroff(COLOR_PAIR(EMPTY_PAIR));
            
            if (ch == 'q') break;

            int next_x = x1 + get_dx(ch);
            int next_y = y1 + get_dy(ch);
            
            if(next_x > 0 && next_x < first_map.width -1 && (*(first_map.map + (next_y * first_map.width) + next_x)) != '#')
            {
                x1 = next_x;
            }
            if(next_y > 0 && next_y < first_map.height -1 && (*(first_map.map + (next_y * first_map.width) + next_x)) != '#')
            {
                y1 = next_y;

            }
            if((*(first_map.map + (next_y * first_map.width) + next_x)) != '#')
            {
                count++;
            }
        }
        usleep(50 * 1000);
    } while (1);

    endwin();
    return 0;
}