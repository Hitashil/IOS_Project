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

Entity::~Entity()
{
    
}

bool Entity::createEntity(const char *name, SDL_Renderer *renderer)
{
    surface = IMG_Load(name);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    return true;
}

void Entity::move()
{
    
}

void Entity::draw()
{
    
}
