#ifndef KBHIT
#define KBHIT

#include <string>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

int kbhit(void);

#endif