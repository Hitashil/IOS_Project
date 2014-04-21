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

Player::Player(const char *name, int x, int y,  SDL_Renderer *renderer) : Entity(name, x, y, renderer)
{
    
}

Player::Player(const char *name, SDL_Rect rect,  SDL_Renderer *renderer) : Entity(name, rect, renderer)
{
    
}

void Player::collision(int x, int y)
{
    if ( rect.x <= 0 )
        rect.x = 0;
    if ( ( rect.x + rect.w ) >= x )
        rect.x = x - rect.w;
        
}

bool Player::fireBullet(SDL_Event Event)
{
	if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == 1)
    {
		// (Josh) Firing sound.
		fire.inialize_music("laser1.wav");
		fire.play_music(0);
		return true;
    }
	else
		return false;
}

void Player::update(SDL_Event Event, SDL_Joystick *joystick)
{
    move.x = SDL_JoystickGetAxis(joystick, 0);
    
    if (move.x >= 1600)
    {
        rect.x += 5;
    }
    else if (move.x <= -1600)
    {
        rect.x -= 5;
    }
}