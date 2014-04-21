//
//  Enemies.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#include "Enemies.h"

Enemies::Enemies() : Entity()
{
    
}

Enemies::Enemies(const char *name, int x, int y,  SDL_Renderer *renderer) : Entity(name, x, y, renderer)
{
    
}

Enemies::Enemies(const char *name, SDL_Rect rect,  SDL_Renderer *renderer) : Entity(name, rect, renderer)
{
    
}

bool Enemies::collision(int x, int y)
{
	// X Axis collision.
	if (rect.x <= 0)
		return true;
	else if (rect.x >= x)
		return true;

	// Y Axis collision.
	if (rect.y >= y)
		return true;


	return false;
}

void Enemies::moveEnemies(int x, int y)
{
	rect.x += x;
	rect.y += y;
}