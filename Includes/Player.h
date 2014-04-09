//
//  Player.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-04-02.
//
//

#ifndef __BASESDL2APPIPAD__Player__
#define __BASESDL2APPIPAD__Player__

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

class Player : public Entity
{
    public:
        SDL_Rect move;
    
    public:
        Player();
        Player(int x, int y);
        Player(SDL_Rect rect);
        ~Player();
    
    public:
        void movePlayer(SDL_Joystick *joystick);
};

#endif /* defined(__BASESDL2APPIPAD__Player__) */
