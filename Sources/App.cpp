//
//  App.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#include "App.h"

App::App()
{
    runningGame = true;
    
    //Testing....
    text.initialize_text(15, 150, 150, 50, 50);
    snprintf(text.buffer, 256, "Put text here");
}

App::~App()
{
    musictest.close_music();
    
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
    
    musictest.inialize_music("bitbop.wav", 1);
    player1 = new Player(300, 300);
    player1->createEntity("blah.png", renderer);
    
    return true;
}

void App::update_event(SDL_Event event)
{

}

void App::update()
{
    
}

void App::draw()
{
    SDL_RenderClear(renderer);
    // draw inbetween here.
    text.display_text(renderer);
    player1->draw(renderer);
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
        
        App::update();
        App::draw();
        
        SDL_Delay(10);
    }
}
