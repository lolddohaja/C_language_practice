#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <locale.h>

#define SIZE 1024

#define WALL '#'
#define GOAL 'G'
#define PLAYER '@'
#define EMPTY ' '

#define WALL_PAIR 1
#define GOAL_PAIR 2
#define PLAYER_PAIR 3
#define EMPTY_PAIR 4

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
            if (*(map.map + (y * map.width) + x) == '#')
            {
                attron(COLOR_PAIR(WALL_PAIR));
            }
            else
            {
                if (*(map.map + (y * map.width) + x) == 'G')
                {
                    attron(COLOR_PAIR(GOAL_PAIR));
                }
                else
                {
                    attroff(COLOR_PAIR(GOAL_PAIR));
                    attroff(COLOR_PAIR(WALL_PAIR));
                }
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
void map_menu()
{
    int n = 0;
    while (1)
    {
        if (kbhit())
        {
            break;
        }
        if (n)
        {
            mvprintw(0, 0, "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???");
            mvprintw(1, 0, "???                                                               ???");
            mvprintw(2, 0, "???                         Select  Map                           ???");
            mvprintw(3, 0, "???                          1. level1                            ???");
            mvprintw(4, 0, "???                          2. level2                            ???");
            mvprintw(5, 0, "???                          3. level3                            ???");
            mvprintw(6, 0, "???                          4. level4                            ???");
            mvprintw(7, 0, "???                          5. level5                            ???");
            mvprintw(8, 0, "???                          6. level6                            ???");
            mvprintw(9, 0, "???                                                               ???");
            mvprintw(9, 0, "???                                                               ???");
            mvprintw(10, 0, "???                             key                               ???");
            mvprintw(11, 0, "???                           ???   : a                             ???");
            mvprintw(12, 0, "???                           ???   : w                             ???");
            mvprintw(13, 0, "???                           ???   : d                             ???");
            mvprintw(14, 0, "???                           ???   : s                             ???");
            mvprintw(15, 0, "???                     back to the menu: q                       ???");
            mvprintw(16, 0, "???                                                               ???");
            mvprintw(17, 0, "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???");
            usleep(150000);
            refresh();
            n = !n;
        }
        else if (!n)
        {
            refresh();
            mvprintw(0, 0, "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???");
            mvprintw(1, 0, "???                                                               ???");
            mvprintw(2, 0, "???                         Select  Map                           ???");
            mvprintw(3, 0, "???                          1. level1                            ???");
            mvprintw(4, 0, "???                          2. level2                            ???");
            mvprintw(5, 0, "???                          3. level3                            ???");
            mvprintw(6, 0, "???                          4. level4                            ???");
            mvprintw(7, 0, "???                          5. level5                            ???");
            mvprintw(8, 0, "???                          6. level6                            ???");
            mvprintw(9, 0, "???                                                               ???");
            mvprintw(9, 0, "???                                                               ???");
            mvprintw(10, 0, "???                             key                               ???");
            mvprintw(11, 0, "???                           ???   : a                             ???");
            mvprintw(12, 0, "???                           ???   : w                             ???");
            mvprintw(13, 0, "???                           ???   : d                             ???");
            mvprintw(14, 0, "???                           ???   : s                             ???");
            mvprintw(15, 0, "???                     back to the menu: q                       ???");
            mvprintw(16, 0, "???                                                               ???");
            mvprintw(17, 0, "??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ??? ???");
            usleep(150000);
            refresh();
            n = !n;
        }
    }
}

void finish_game()
{
    struct Map temp;
    loadMap(&temp,"clear.txt");
    mvprintw(0,0,"adasdasd");
    refresh();
    for (int y = 0; y < temp.height; y++)
    {
        for (int x = 0; x < temp.width; x++)
        {
            mvprintw(y, x, "%c", *(temp.map + (y * temp.width) + x));
        }
    }
    refresh();

    usleep(3000000);

    clear();
}

void start_game(struct Map current_map)
{
    int count = 0;
    int x1 = 1, y1 = current_map.height - 2;
    char ch = 0;
    do
    {

        attron(COLOR_PAIR(PLAYER_PAIR));
        mvaddch(y1, x1, PLAYER);
        attroff(COLOR_PAIR(PLAYER_PAIR));

        *(current_map.map + (y1 * current_map.width) + x1) = '@';

        printMap(current_map, count);

        while (kbhit())
        {
            ch = getchar();
        }
        if (ch)
        {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(y1, x1, EMPTY);
            *(current_map.map + (y1 * current_map.width) + x1) = ' ';
            attroff(COLOR_PAIR(EMPTY_PAIR));

            int next_x = x1 + get_dx(ch);
            int next_y = y1 + get_dy(ch);
            if (ch == 'q')
            {
                clear();
                break;
            }
            if (((get_dx(ch) == 1 || get_dx(ch) == -1) || (get_dy(ch) == 1 || get_dy(ch) == -1)) && (*(current_map.map + (next_y * current_map.width) + next_x)) != '#')
            {
                count++;
            }
            if (*(current_map.map + ((next_y + 1) * current_map.width) + next_x) == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (*(current_map.map + ((next_y - 1) * current_map.width) + next_x) == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (*(current_map.map + ((next_y)*current_map.width) + next_x + 1) == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }
            if (*(current_map.map + ((next_y)*current_map.width) + next_x - 1) == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }

            if (next_x > 0 && next_x < current_map.width - 1 && (*(current_map.map + (next_y * current_map.width) + next_x)) != '#')
            {
                x1 = next_x;
            }
            if (next_y > 0 && next_y < current_map.height - 1 && (*(current_map.map + (next_y * current_map.width) + next_x)) != '#')
            {
                y1 = next_y;
            }
            if ((*(current_map.map + (next_y * current_map.width) + next_x)) == 'G')
            {
                clear();
                finish_game();

                break;
            }
        }
        usleep(50 * 500);
    } while (1);
}

int main(void)
{
    setlocale(LC_ALL, "ko_KR.UTF-8");
    initscr();
    start_color();
    init_pair(WALL_PAIR, COLOR_YELLOW, COLOR_RED);
    init_pair(GOAL_PAIR, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(PLAYER_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(EMPTY_PAIR, COLOR_WHITE, COLOR_BLACK);

    struct Map map1;
    struct Map map2;
    struct Map map3;
    struct Map map4;
    struct Map map5;
    struct Map map6;

    loadMap(&map1, "map1.txt");
    loadMap(&map2, "map2.txt");
    loadMap(&map3, "map3.txt");
    loadMap(&map4, "map4.txt");
    loadMap(&map5, "map5.txt");
    loadMap(&map6, "map6.txt");

    int select;

    do
    {
        char input = 0;
        map_menu();

        while (kbhit())
        {
            input = getchar();
        }
        if (input == '1')
        {
            clear();
            start_game(map1);
        }
        else if (input == '2')
        {
            clear();
            start_game(map2);
        }
        else if (input == '3')
        {
            clear();
            start_game(map3);
        }
        else if (input == '4')
        {
            clear();
            start_game(map4);
        }
        else if (input == '5')
        {
            clear();
            start_game(map5);
        }
        else if (input == '6')
        {
            clear();
            start_game(map6);
        }
        else if (input == 'q')
        {
            clear();
            break;
        }
        else
        {
            map_menu();
        }

    } while (1);

    endwin();
    return 0;
}