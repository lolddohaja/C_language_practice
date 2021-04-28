#include "space_invader_map.h"

using namespace std;

// struct Map
// {
//     vector<string> map;
//     int width;
//     int height;
// };

void loadMap(struct Map *selectMap, string mapName)
{
    int cnt = 0;
    int width = 0;
    int height = 0;
    fstream fp;
    fp.open(mapName);

    if(fp.is_open()){
        while(!fp.eof()){
            string temp;
            getline(fp,temp);
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