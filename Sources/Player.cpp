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

void Player::collision(int x, int y)
{
    if ( rect.x <= 0 )
        rect.x = 0;
    if ( ( rect.x + rect.w ) >= x )
        rect.x = x - rect.w;
        
}

void Player::update(SDL_Event event, SDL_Joystick *joystick)
{
    move.x = SDL_JoystickGetAxis(joystick, 0);
    
    if (move.x >= 3200)
    {
        rect.x += 5;
    }
    else if (move.x <= -3200)
    {
        rect.x -= 5;
    }
}