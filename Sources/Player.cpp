//
//  Player.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#include "Player.h"

Player::Player() : Entity()
{
    
}

Player::Player(int x, int y) : Entity(x, y)
{
    
}

Player::Player(SDL_Rect rect) : Entity(rect)
{
    
}

void Player::movePlayer(SDL_Joystick *joystick)
{
    move.x = SDL_JoystickGetAxis(joystick, 1);
    
    if (move.x >= 3200)
    {
        rect.x++;
    }
    else if (move.x <= -3200)
    {
        rect.x--;
    }
}