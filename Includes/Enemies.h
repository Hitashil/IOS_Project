//
//  Enemies.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#ifndef __BASESDL2APPIPAD__Enemies__
#define __BASESDL2APPIPAD__Enemies__

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

class Enemies: public Entity
{
	public:
		Enemies();
		Enemies(const char *name, int x, int y,  SDL_Renderer *renderer);
		Enemies(const char *name, SDL_Rect rect, SDL_Renderer *renderer);
		~Enemies();

	public:
		bool collision(int x, int y);
		void moveEnemies(int x, int y);
};
#endif /* defined(__BASESDL2APPIPAD__Enemies__) */
