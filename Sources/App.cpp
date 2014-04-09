//
//  App.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#include "App.h"

template <typename T>
string toString(T num)
{
    ostringstream int_str;
    string str;
    
    int_str << num;
    
    str = int_str.str();
    return str;
}

App::App()
{
    runningGame = true;
    score = new Maketext("Score: " + toString(points), 32, 10,0,100,32,255,255,255);
    lives = new Maketext("Lives: " + toString(life), 32, 425,0,75,32,255,255,255);
}

App::~App()
{
    // Shutdown SDL.
    SDL_Quit();
}

bool App::initialize()
{
    //initialize SDL video
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr,"Error building SDL: %s", SDL_GetError());
        return false;
    }
    
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    
    // Create main window and renderer.
    window = SDL_CreateWindow("Invaders From Space", 0, 0, 0, 0,
							  SDL_WINDOW_SHOWN);
    
    SDL_GetWindowSize(window, &SCREEN_RECT.w, &SCREEN_RECT.h);
    
    renderer = SDL_CreateRenderer(window, 0, 0);
    
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    
    // Background
    bg = new Background(0, 0);
    bg->createEntity("spacedJamiPhoneBackground.png", renderer);
    
    // Player.
    player1 = new Player((SCREEN_RECT.w/2) - 50, 780);
    player1->createEntity("ship1.PNG", renderer);
    
    //Player Projectile
    
    for (int i = 0; i < MAXPROJEC; i++)
    {
        bullets[i] = new Projectile(player1->rect.x + 68,820);
        bullets[i]->createEntity("spacedJamPlayerLaser.png", renderer);
    }
    
    
    //josh
    background.inialize_music("bitbop.wav");
    background.play_music(-1);
    
    return true;
}

void App::update_event(SDL_Event event)
{
    // For debug...
    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == 1)
    {
        
    }

    // Joystick movement.
    SDL_JoystickUpdate();
    player1->movePlayer(joystick);
}

void App::post_update()
{
    
}

void App::update()
{
    
}

void App::draw()
{
    SDL_RenderClear(renderer);
    
    bg->draw(renderer);
    
    for (int i = 0; i < MAXPROJEC; i++)
    {
        bullets[i]->draw(renderer);
    }
    
    player1->draw(renderer);
    
    score->display_text(renderer);
    lives->display_text(renderer);
    
    // draw inbetween here.
    
    SDL_RenderPresent(renderer);
}

void App::run()
{
    if (!App::initialize())
    {
        printf("An error has occur!");
        return;
    }
    
    while (runningGame)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
            {
                return;
            }
            else
                App::update_event(event);
        }
        
        
        App::post_update();
        App::update();
        
        App::draw();
        
        SDL_Delay(10);
    }
}
