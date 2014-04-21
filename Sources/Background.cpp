//
//  Background.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-09.
//
//

#include "Background.h"


Background::Background() : Entity()
{
    
}

Background::Background(const char *name, SDL_Rect rect,  SDL_Renderer *renderer) : Entity(name, rect, renderer)
{
    
}

Background::Background(const char *name, int x, int y,  SDL_Renderer *renderer) : Entity(name, x, y, renderer)
{
    
}