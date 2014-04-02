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
    Projectile(int x, int y);
    Projectile(SDL_Rect rect);
    ~Projectile();
};

#endif /* defined(__BASESDL2APPIPAD__Projectile__) */
