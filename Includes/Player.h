//
//  Player.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#ifndef __BASESDL2APPIPAD__Player__
#define __BASESDL2APPIPAD__Player__

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

#include "music.h"
#include "Projectile.h"

class Player : public Entity
{
    public:
		music fire;
        SDL_Rect move;
    
    public:
        Player();
        Player(const char *name, int x, int y,  SDL_Renderer *renderer);
        Player(const char *name, SDL_Rect rect,  SDL_Renderer *renderer);
        ~Player();
    
    public:
        void collision(int x, int y);
        void update(SDL_Event Event ,SDL_Joystick *joystick);
		bool fireBullet(SDL_Event Event);
};

#endif /* defined(__BASESDL2APPIPAD__Player__) */
