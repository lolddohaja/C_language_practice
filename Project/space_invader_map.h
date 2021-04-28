#include <cstring>
#include <ncurses.h>
#include <fcntl.h>
#include <fstream>
#include <vector>

using namespace std;

struct Map
{
    vector<string> map;
    int width;
    int height;
};

void loadMap(struct Map *selectMap, string mapName);
void printMap(struct Map map);
