#ifndef SPACE_INVADER_GAMESET
#define SPACE_INVADER_GAMESET

#include <cstring>
#include <ncurses.h>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

struct Map
{
    vector<string> map;
    int width;
    int height;
};

void loadMap(struct Map *selectMap, string mapName);
void printMap(struct Map map);
void map_menu();

#endif