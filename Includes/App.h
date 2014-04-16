//
//  App.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#ifndef __BASESDL2APPIPAD__App__
#define __BASESDL2APPIPAD__App__

#define MAXENEMIES 10
#define MAXPROJEC 3

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <time.h>

#include "Background.h"
#include "maketext.h"
#include "music.h"
#include "Player.h"
#include "Enemies.h"
#include "Projectile.h"

#include "SDL.h"

class App
{
    private:
        SDL_Rect SCREEN_RECT;
        SDL_Window *window;
        SDL_Renderer *renderer;
    
        SDL_Joystick *joystick;
    
        bool runningGame;
    
    public:
        Background *bg;
    
        Player *player1;
        Enemies *enemy;
        Projectile *bullets[MAXPROJEC];
    
    
    public://Josh
        int points = 0;
        int life = 3;
        Maketext *score;
        Maketext *lives;
        music background;
    
    public:
        int bulletIndex;
    
    public:
        App(void);
        ~App(void);
        void run();
    
    private:
        bool initialize();
        void update_event(SDL_Event event);
        void post_update();
        void update();
        void draw();
};

#endif /* defined(__BASESDL2APPIPAD__App__) */
