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
    virtual void setPosition(int x_position,int y_position) = 0;
    virtual int getPosition(int x_position,int y_position) = 0;
    virtual void setShape(char *shape) = 0;
    virtual void setLife(int life) = 0;
    virtual int dead() = 0;
    virtual void setScore(int score) = 0;
};

class Player : public GameObject
{
private:
    int life;
    int score;
public:
    virtual void setPosition(int x_position,int y_position);
    virtual int getPosition(int x_position,int y_position, char ch);
    virtual void setShape(char *shape);
    int getScore();
};

class Invader : public GameObject
{
private:
    int life;
    int score;
public:
    virtual void setPosition(int x_position,int y_position);
    virtual int getPosition(int x_position,int y_position);
    virtual void setShape(char *shape);
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