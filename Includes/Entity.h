//
//  Entity.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-26.
//
//

#ifndef __BASESDL2APPIPAD__Entity__
#define __BASESDL2APPIPAD__Entity__

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Entity
{
    public:
        SDL_Texture *texture;
        SDL_Surface *surface;
        SDL_Rect rect;
    
    public:
        Entity();
        ~Entity();
    
    public:
        virtual bool createEntity(const char *name, SDL_Renderer *renderer);
        virtual void move();
        virtual void draw();
};

#endif /* defined(__BASESDL2APPIPAD__Entity__) */
