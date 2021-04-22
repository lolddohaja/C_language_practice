#include <stdio.h>
#include <stdlib.h>
#include <ncursesw/curses.h>
#include <unistd.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ko_KR.UTF-8");
    initscr();
    noecho();
    curs_set(0);

    int x = 0;
    int y = 0;

    mvprintw(0, x, "@");

    for(int i = 0;i <10; i++)
    {
        char ch = getch();
        mvprintw(0,x," ");
        if(ch == 'f')
        {
            x+=1;
        }
        else if(ch == 'b')
        {
            x -= 1;
        }

        sleep(0.01);
        mvprintw(0,x,"@///");
        refresh();
        mvprintw(5,0,"%d",i);

    }
    endwin();
    return 0;
}