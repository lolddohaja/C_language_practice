#ifndef SPACE_INVADER_OBJECT
#define SPACE_INVADER_OBJECT
#include <iostream>
#include <vector>

using namespace std;

class GameObject
{
private:
    vector<string> position;
    int x_position;
    int y_position;
    char *shape;
public:
    virtual void setPosition(int x_position,int y_position);
    virtual int getPosition(int x_position,int y_position);
    virtual void setShape(char *shape);
    void setLife(int life);
    int dead();
    void setScore(int score);
};

class Player : public GameObject
{
private:
    int life;
    int score;
public:
    int getScore();
};

class Invader : public GameObject
{
private:
    int life;
    int score;
public:
    int giveScore();

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