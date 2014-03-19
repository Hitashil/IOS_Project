//
//  App.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#ifndef __BASESDL2APPIPAD__App__
#define __BASESDL2APPIPAD__App__

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "SDL.h"
#include <time.h>
//include "common.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

class App
{
    private:
        SDL_Rect SCREEN_RECT;
        SDL_Window *window;
        SDL_Renderer *renderer;
    
        bool runningGame;
    
    public:
        App(void);
        ~App(void);
        void run();
    
    private:
        bool initialize();
        void update_event(SDL_Event event);
        void update();
        void draw();
};

#endif /* defined(__BASESDL2APPIPAD__App__) */
