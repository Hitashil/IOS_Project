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
    private:
        SDL_Texture *texture;
        SDL_Surface *surface;

	public:
		SDL_Rect rect;
    
    public:
        Entity();
        Entity(const char *name, SDL_Rect rect, SDL_Renderer *renderer);
        Entity(const char *name, int x, int y, SDL_Renderer *renderer);
        ~Entity();
    
    public:
        virtual bool createEntity(const char *name, SDL_Renderer *renderer);
        virtual void draw(SDL_Renderer *renderer);

	public:	
		void SetRect(SDL_Rect rect)
		{
			this->rect.x = rect.x;
			this->rect.y = rect.y;
		}

		void SetRect(int x, int y)
		{
			this->rect.x = x;
			this->rect.y = y;
		}
		
		SDL_Rect GetRect(void)
		{
			return rect;
		}
};

#endif /* defined(__BASESDL2APPIPAD__Entity__) */
