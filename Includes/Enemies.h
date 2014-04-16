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
    Enemies(int x, int y);
    Enemies(SDL_Rect rect);
    ~Enemies();
};
#endif /* defined(__BASESDL2APPIPAD__Enemies__) */
