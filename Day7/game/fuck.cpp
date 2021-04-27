#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

struct Map
{
    vector<string> map;
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

void start_game(struct Map current_map)
{
    int count = 0;
    int x1 = 1, y1 = current_map.height - 2;
    char ch = 0;
    do
    {

        // attron(COLOR_PAIR(PLAYER_PAIR));
        // mvaddch(y1, x1, PLAYER);
        // attroff(COLOR_PAIR(PLAYER_PAIR));

        current_map.map[y1][x1] = '@'; // <--- string

        // printMap(current_map, count);

        while (kbhit())
        {
            ch = getchar();
        }
        if (ch)
        {
            // attron(COLOR_PAIR(EMPTY_PAIR));
            // mvaddch(y1, x1, EMPTY);
            current_map.map[y1][x1] = ' ';
            // attroff(COLOR_PAIR(EMPTY_PAIR));

            int next_x = x1 + get_dx(ch);
            int next_y = y1 + get_dy(ch);
            if (ch == 'q')
            {
                clear();
                break;
            }
            if (((get_dx(ch) == 1 || get_dx(ch) == -1) || (get_dy(ch) == 1 || get_dy(ch) == -1)) && current_map.map[next_y][next_x] != '#')
            {   
                count++;
            }
            if (current_map.map[next_y+1][next_x] == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (current_map.map[next_y-1][next_x] == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (current_map.map[next_y][next_x+1] == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }
            if (current_map.map[next_y][next_x-1] == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }

            if (next_x > 0 && next_x < current_map.width - 1 && current_map.map[next_y][next_x] != '#')
            {
                x1 = next_x;
            }
            if (next_y > 0 && next_y < current_map.height - 1 && current_map.map[next_y][next_x] != '#')
            {
                y1 = next_y;
            }
            if (current_map.map[next_y][next_x] == 'G')
            {
                clear();
                // finish_game();

                break;
            }
        }
        usleep(50 * 500);
    } while (1);
}

int main(void)
{
    initscr();
    struct Map map1;
    map1.height = 7;
    map1.width = 38;
    map1.map.push_back("=======================================");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=                                     =");
    map1.map.push_back("=======================================");

    int count = 0;
    int x1 = 1, y1 = map1.height - 2;
    char ch = 0;
    do
    {

        // attron(COLOR_PAIR(PLAYER_PAIR));
        // mvaddch(y1, x1, PLAYER);
        // attroff(COLOR_PAIR(PLAYER_PAIR));

        map1.map[y1][x1] = '@'; // <--- string
            refresh();
    for (int y = 0; y < map1.height+1; y++)
    {
        for (int x = 0; x < map1.width+1; x++)
        {
            mvprintw(y, x, "%c", map1.map[y][x]);
        }
    }
    refresh();
        // printMap(current_map, count);

        while (kbhit())
        {
            ch = getchar();
        }
        if (ch)
        {
            // attron(COLOR_PAIR(EMPTY_PAIR));
            // mvaddch(y1, x1, EMPTY);
            map1.map[y1][x1] = ' ';
            // attroff(COLOR_PAIR(EMPTY_PAIR));

            int next_x = x1 + get_dx(ch);
            int next_y = y1 + get_dy(ch);
            if (ch == 'q')
            {
                clear();
                break;
            }
            if (((get_dx(ch) == 1 || get_dx(ch) == -1) || (get_dy(ch) == 1 || get_dy(ch) == -1)) && map1.map[next_y][next_x] != '#')
            {   
                count++;
            }
            if (map1.map[next_y+1][next_x] == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (map1.map[next_y-1][next_x] == ' ' && (ch == 'a' || ch == 'd'))
            {
                ch = 0;
            }
            if (map1.map[next_y][next_x+1] == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }
            if (map1.map[next_y][next_x-1] == ' ' && (ch == 'w' || ch == 's'))
            {
                ch = 0;
            }

            if (next_x > 0 && next_x < map1.width - 1 && map1.map[next_y][next_x] != '#')
            {
                x1 = next_x;
            }
            if (next_y > 0 && next_y < map1.height - 1 && map1.map[next_y][next_x] != '#')
            {
                y1 = next_y;
            }
            if (map1.map[next_y][next_x] == 'G')
            {
                clear();
                // finish_game();

                break;
            }
        }
        usleep(50 * 500);
    } while (1);

}