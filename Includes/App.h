//
//  App.h
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

/*
 bring back to main menu.
 spacing out enemies
 turn enemies around
 smaller enemies/player?
 more shots?
 name of game on intro screen
 collision with enemies and laser
 respawn enemies at the top.
 */

#ifndef __BASESDL2APPIPAD__App__
#define __BASESDL2APPIPAD__App__

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

#define MAXENEMIES 5
#define MAXPROJEC 3

enum {INTROSCREEN, LOADINGSCREEN, GAMEPLAYSCREEN, GAMEOVERSCREEN};

class App
{
	// Jordan
    private:
        SDL_Rect SCREEN_RECT;
        SDL_Window *window;
        SDL_Renderer *renderer;
    
        SDL_Joystick *joystick;
    
        bool runningGame;
    
		// Cass
    public:
        Background *bg;
    
        Player *player1;
		Enemies *enemies[MAXENEMIES];
        Projectile *bullets[MAXPROJEC];
    
    // Josh
    public:
        int points;
        int life;
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
        Maketext *Title;
        Maketext *People;
		Maketext *click_to_begin;
		Maketext *loading;
		Maketext *gameover;
		Maketext *gameoverN;
		int screen;
		void Introscreen();
		void loadingscreen();
		void Introevent(SDL_Event Event);
        void Outroevent(SDL_Event Event);
		void gameoverscreen();

    private:
        bool initialize();
        void update_event(SDL_Event Event);
        void post_update();
        void update();
        void draw();
};

#endif /* defined(__BASESDL2APPIPAD__App__) */
