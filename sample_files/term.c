// gcc term.c -lncurses

#include <ncurses.h>

int func1()
{
    int val;
    initscr();
    mvprintw(0, 0, "Hello, World"); // 화면의 0행, 0열부터 Hello, World를 출력합니다.
    refresh();                      // 화면에 출력하도록 합니다.
    // sleep(1);
    scanf("%d", &val);
    endwin();
    return 0;
}

int main()
{
    printf("hello \n");
    return func1();
}