// https://alwaysnr.tistory.com/18
// STDIN_FILENO is define in unistd.h
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

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

int main()
{

    for (int i = 0; i < 10; i++)
    {
        while (kbhit())
        {
            char ch = getchar();
            printf("%c", ch);
        }
        printf("%d ", i);
        sleep(1);
    }
    return 0;
}