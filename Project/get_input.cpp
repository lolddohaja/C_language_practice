#include "get_input.h"

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