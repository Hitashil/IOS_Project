//
//  Entity.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-26.
//
//

#include "Entity.h"

Entity::Entity()
{
    
}

Entity::Entity(int x, int y)
{
    rect.x = x;
    rect.y = y;
}

Entity::Entity(SDL_Rect rect)
{
    this->rect = rect;
}

Entity::~Entity()
{
    
}

bool Entity::createEntity(const char *name, SDL_Renderer *renderer)
{
    surface = IMG_Load(name);
    SDL_SetColorKey(surface, 1, SDL_MapRGB(surface->format, 0, 0, 0));
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    rect.w = surface->w;
    rect.h = surface->h;
    
    SDL_FreeSurface(surface);
    return true;
}

void Entity::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
