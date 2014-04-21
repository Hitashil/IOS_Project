//
//  Projectile.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#ifndef __BASESDL2APPIPAD__Projectile__
#define __BASESDL2APPIPAD__Projectile__

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

class Projectile : public Entity
{
    public:
        Projectile();
        Projectile(const char *name, int x, int y,  SDL_Renderer *renderer);
        Projectile(const char *name, SDL_Rect rect,  SDL_Renderer *renderer);
        ~Projectile();
    
    public:
        bool go;
        SDL_Rect originalRect;

	public:
        void collision(int x, int y);
        void moveProjec();
};

#endif /* defined(__BASESDL2APPIPAD__Projectile__) */
