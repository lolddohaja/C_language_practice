#include <stdio.h>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

#define M_WIDTH 48
#define M_HEIGHT 12

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (B) ? (a) : (b))

void print_map(char map[M_HEIGHT][M_WIDTH], int cnt);
void init_map(char map[M_HEIGHT][M_WIDTH]);

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

int main()
{
    initscr();

    char map[M_HEIGHT][M_WIDTH];
    int cnt = 0;
    int x1 = 10, y1 = 8;
    int x2 = 40, y2 = 2;

    init_map(map);
    do
    {
        map[y1][x1] = '@';
        map[y2][x2] = 'Q';
        print_map(map, cnt);
        char ch = 0, ch_buf;

        while (kbhit())
        {
            ch = getchar();
        }

        if (ch)
        {
            map[y1][x1] = ' ';

            if (ch == 'q')
            {
                break;
            }
            int next_x = x1 + get_dx(ch);
            int next_y = y1 + get_dy(ch);
            if (next_x > 0 && next_x < M_WIDTH - 1)
            {
                x1 = next_x;
            }
            if (next_y > 0 && next_y < M_HEIGHT - 1)
            {
                y1 = next_y;
            }
        }

        cnt++;
        usleep(50 * 1000);
    } while (1);

    endwin();

    return 0;
}

void init_map(char map[M_HEIGHT][M_WIDTH])
{
    for (int y = 0; y < M_HEIGHT; y++)
    {
        for (int x = 0; x < M_WIDTH; x++)
        {
            if (y == 0 || x == 0 || y == M_HEIGHT - 1 || x == M_WIDTH - 1)
            {
                map[y][x] = '#';
            }
            else
            {
                map[y][x] = ' ';
            }
        }
    }
}

void print_map(char map[M_HEIGHT][M_WIDTH], int cnt)
{
    refresh();
    for (int y = 0; y < M_HEIGHT; y++)
    {
        for (int x = 0; x < M_WIDTH; x++)
        {
            mvprintw(y, x, "%c", map[y][x]);
            // printf("%c", );
        }
        // printf("\n");
    }
    mvprintw(M_HEIGHT, 0, "cnt: %d", cnt);

    refresh();
}