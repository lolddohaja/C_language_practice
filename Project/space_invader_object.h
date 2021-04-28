#ifndef SPACE_INVADER_OBJECT
#define SPACE_INVADER_OBJECT
#include <iostream>

class GameObject
{
private:
    int x_position;
    int y_position;
    char *shape;
public:
    virtual void set_position(int x_position,int y_position);
    virtual int get_position(int x_position,int y_position);
    virtual void set_shape(char *shape);
    void set_life(int life);
    int dead();
    void set_score(int score);
};

class Player : public GameObject
{
private:
    int life;
    int score;
public:
    int get_score();
};

class Invader : public GameObject
{
private:
    int life;
    int score;
public:
    int give_score();

};

class bullet : public GameObject
{
private:
    enum BulletType
    {
        PLAYER_BULLET,
        INVADER_BULLET
    };
public:

};

#endif