#include "space_invader_gameset.h"
#include "kbhit.h"
using namespace std;

void loadMap(struct Map *selectMap, string mapName)
{
    int cnt = 0;
    int width = 0;
    int height = 0;
    fstream fp;
    fp.open(mapName);

    if (fp.is_open())
    {
        while (!fp.eof())
        {
            string temp;
            getline(fp, temp);
            selectMap->map.push_back(temp);
            cnt++;
        }
        fp.close();
    }
    selectMap->map.push_back(" ");

    selectMap->width = selectMap->map[0].size();
    selectMap->height = cnt;
}

void printMap(struct Map map)
{
    refresh();
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            mvprintw(y, x, "%c", map.map[y][x]);
        }
    }
    refresh();
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
            mvprintw(0,  0, " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ");
            mvprintw(1,  0, "=                                                               =");
            mvprintw(2,  0, "                          Select  Map                            ");
            mvprintw(3,  0, "=                          1. level1                            =");
            mvprintw(4,  0, "                           2. level2                             ");
            mvprintw(5,  0, "=                          3. level3                            =");
            mvprintw(6,  0, "                           4. level4                             ");
            mvprintw(7,  0, "=                          5. level5                            =");
            mvprintw(8,  0, "                           q.  exit                              ");
            mvprintw(9,  0, "=                                                               =");
            mvprintw(9,  0, "                                                                 ");
            mvprintw(10, 0, "=                             key                               =");
            mvprintw(11, 0, "                            ←   : a                             ");
            mvprintw(12, 0, "=                           ↑   : w                            =");
            mvprintw(13, 0, "                            →   : d                             ");
            mvprintw(14, 0, "=                           ↓   : s                            =");
            mvprintw(15, 0, "                      back to the menu: q                        ");
            mvprintw(16, 0, "=                                                               =");
            mvprintw(17, 0, " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = ");
            usleep(150000);
            refresh();
            n = !n;
        }
        else if (!n)
        {
            refresh();
            mvprintw(0,  0, "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
            mvprintw(1,  0, "                                                                 ");
            mvprintw(2,  0, "=                         Select  Map                           =");
            mvprintw(3,  0, "                           1. level1                             ");
            mvprintw(4,  0, "=                          2. level2                            =");
            mvprintw(5,  0, "                           3. level3                             ");
            mvprintw(6,  0, "=                          4. level4                            =");
            mvprintw(7,  0, "                           5. level5                             ");
            mvprintw(8,  0, "=                          q.  exit                             =");
            mvprintw(9,  0, "                                                                 ");
            mvprintw(9,  0, "=                                                               =");
            mvprintw(10, 0, "                              key                                ");
            mvprintw(11, 0, "=                           ←   : a                            =");
            mvprintw(12, 0, "                            ↑   : w                             ");
            mvprintw(13, 0, "=                           →   : d                            =");
            mvprintw(14, 0, "                            ↓   : s                             ");
            mvprintw(15, 0, "=                     back to the menu: q                       =");
            mvprintw(16, 0, "                                                                 ");
            mvprintw(17, 0, "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
            usleep(150000);
            refresh();
            n = !n;
        }
    }
}

