#include <iostream>
#include "space_invader_object.h"
#include "get_input.h"

void Player::setPosition(int x_position, int y_position)
{
    int x_pos = x_position;
    int y_pox = y_position;
}

int Player::getPosition(int x_position, int y_position, char ch)
{
    int val = get_dx(ch);
    int next_x = x_position + val;
    return position[y_position][next_x];
}


int Player::getScore()
{

}

int Invader::giveScore()
{

}
