//
//  Background.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-09.
//
//

#ifndef __BASESDL2APPIPAD__Background__
#define __BASESDL2APPIPAD__Background__

#include <iostream>

#include "Entity.h"

class Background : public Entity
{
    public:
        Background();
        Background(const char *name, int x, int y,  SDL_Renderer *renderer);
        Background(const char *name, SDL_Rect rect,  SDL_Renderer *renderer);
};

#endif /* defined(__BASESDL2APPIPAD__Background__) */
