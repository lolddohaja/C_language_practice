#include <stdio.h>

typedef struct my
{
    int val;
};

typedef struct my
{
    int val;
} POS;

POS my;

struct robot
{
    int posX;
    int posY;
    char *name;
    double energy;
    int mydata[100000000];
};

void printRobot(struct robot *robot_p)
{
    printf("%s: (%d, %d) [%lf]\n", robot_p->name, robot_p->posX, robot_p->posY, robot_p->energy);
}

void chargeRobot(struct robot *robot_p, int charge) // copy : call by value
{
    robot_p->energy += charge;
    robot_p->posX = 0;
    robot_p->posY = 0;
}

int main()
{
    struct robot robot1;
    robot1.posX = 10;
    robot1.posY = 20;
    robot1.name = "robot 1";
    robot1.energy = 89.338;
    struct robot *robot_p;
    robot_p = &robot1;

    struct robot robot2 = {10, 20, "robot 2", 43.2};

    struct robot robot3 = {
        11,
        44,
    };
    robot3.name = "robot 3";
    robot3.energy = 89.338;

    printRobot(&robot1);
    // printRobot(robot2);
    // printRobot(robot3);

    chargeRobot(&robot1, 23);
    printRobot(&robot1);

    return 0;
}