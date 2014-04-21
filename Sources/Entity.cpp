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

Entity::Entity(const char *name, int x, int y,  SDL_Renderer *renderer)
{
	if(!createEntity(name, renderer))
	{
		printf("Could not load image correctly...\n");
		exit(-1);
	}

    rect.x = x;
    rect.y = y;
}

Entity::Entity(const char *name, SDL_Rect rect, SDL_Renderer *renderer)
{
	if(!createEntity(name, renderer))
	{
		printf("Could not load image correctly...\n");
		exit(-1);
	}

	this->rect.x = rect.x;
	this->rect.x = rect.y;
}

Entity::~Entity()
{
	SDL_DestroyTexture(texture);
}

bool Entity::createEntity(const char *name, SDL_Renderer *renderer)
{
    surface = IMG_Load(name);

	if (!surface)
	{
		printf("IMAGE ERROR: Could not load - %s\n", name);
		return false;
	}

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
