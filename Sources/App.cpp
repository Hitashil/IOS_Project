//
//  App.cpp
//  BASESDL2APPIPAD
//
//  Created by Student on 2014-03-19.
//
//

#include "App.h"

// Helps put int/float/double to string.
template <typename T>
string toString(T num)
{
    ostringstream int_str;
    string str;
    
    int_str << num;
    
    str = int_str.str();
	int_str.flush();
    return str;
}

App::App()
{
    runningGame = true;
    bulletIndex = 0;

	points = 0;
	life = 3;
}

App::~App()
{
    // Shutdown SDL.
    SDL_Quit();
}

bool App::initialize()
{
    //initialize SDL Flages.
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr,"Error building SDL: %s", SDL_GetError());
        return false;
    }
    
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    
    // Create main window and renderer.
	#if _WIN64
		window = SDL_CreateWindow("Invaders From Space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 960,
								SDL_WINDOW_SHOWN);
	#elif _WIN32
		window = SDL_CreateWindow("Invaders From Space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 960,
								SDL_WINDOW_SHOWN);
	#elif __APPLE__
		window = SDL_CreateWindow(NULL, 0, 0, 0, 0, SDL_WINDOW_SHOWN);
	#endif

	SDL_GetWindowSize(window, &SCREEN_RECT.w, &SCREEN_RECT.h);

    renderer = SDL_CreateRenderer(window, 0, 0);

	// Joystick intallization.
	if(SDL_JoystickEventState(SDL_ENABLE))
		joystick = SDL_JoystickOpen(0);
	else
	{
		printf("No Joystick installed.\n");
		return false;
	}

	srand(time(0));

	// Current screen.
	screen = INTROSCREEN;

	// Screen text.
	click_to_begin = new Maketext("Touch anywhere to begin!", 32, 150, (SCREEN_RECT.h/2 + 100), 255, 255, 255);
	loading = new Maketext("Loading...", 50, 200, (SCREEN_RECT.h/2 - 100), 255, 255, 255);
	gameover = new Maketext("You Died! Your score was " + toString(points) + ".", 32, 100, (SCREEN_RECT.h/2 - 50), 255, 255, 255);
	gameoverN = new Maketext("Try to beat your score!", 32, 125, SCREEN_RECT.h/2 , 255, 255, 255);

    // Background (Cass).
	#if _WIN64
		bg = new Background("spacedJamiPhoneBackground.png", 0, 0, renderer);
	#elif _WIN32
		bg = new Background("spacedJamiPhoneBackground.png", 0, 0, renderer);
	#elif __APPLE__
		#include "TargetConditionals.h"
		#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
			bg = new Background("spacedJamiPhoneBackground.png", 0, 0, renderer); 
		#else
			bg = new Background("spacedJamiPadBackground.png", 0, 0, renderer);
		#endif
	#endif
    
	// Text of health and lives (Josh).
    score = new Maketext("Score: " + toString(points), 32, 10, 0, 255, 255, 255);
	lives = new Maketext("Lives: " + toString(life), 32, (SCREEN_RECT.w - 150), 0, 255, 255, 255);
    
    // Player (Cass).
	player1 = new Player("ship2.png", ((SCREEN_RECT.w/2) - 50), (SCREEN_RECT.h - 150), renderer);

	for (int i = 0; i < MAXENEMIES; i++)
		enemies[i] = new Enemies("ship1green.png", rand() % SCREEN_RECT.w, -120, renderer);
    
    //Player Projectile (Cass).
    for (int i = 0; i < MAXPROJEC; i++)
		bullets[i] = new Projectile("SpacedJamPlayerLaser.png", 0, 0, renderer);
    
    
    // (Josh) Backgound music.
    background.inialize_music("bitbop.wav");
    background.play_music(-1);
    
    return true;
}

void App::Introevent(SDL_Event Event)
{
	if(Event.type == SDL_MOUSEBUTTONDOWN && Event.button.button == 1)
    {
		screen = LOADINGSCREEN;
	}
}

void App::Introscreen()
{
	SDL_RenderClear(renderer);
	click_to_begin->display_text(renderer);
	SDL_RenderPresent(renderer);
}

void App::loadingscreen()
{
	SDL_RenderClear(renderer);
	loading->display_text(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(2000);
	screen = GAMEPLAYSCREEN;
}

void App::gameoverscreen()
{
	SDL_RenderClear(renderer);
	gameover->display_text(renderer);
	gameoverN->display_text(renderer);
	SDL_RenderPresent(renderer);
}

void App::update_event(SDL_Event Event)
{
	// Once pressed, the bullet will fire.
	if(player1->fireBullet(Event))
    {
        bulletIndex++;
        
        if (bulletIndex >= MAXPROJEC)
        {
            bulletIndex = 0;
        }

        bullets[bulletIndex]->go = true;
		bullets[bulletIndex]->SetRect((player1->rect.x + 68), (SCREEN_RECT.h - player1->GetRect().h));
    }

    // Joystick movement.
    SDL_JoystickUpdate();
    player1->update(Event, joystick);
}

void App::post_update()
{
	if (life <= 0)
	{
		screen = GAMEOVERSCREEN;
	}

    player1->collision(SCREEN_RECT.w, SCREEN_RECT.h);
    
    for (int i = 0; i < MAXPROJEC; i++)
        bullets[i]->collision(SCREEN_RECT.w, SCREEN_RECT.h);

	for (int i = 0; i < MAXENEMIES; i++)
		if(enemies[i]->collision(SCREEN_RECT.w, SCREEN_RECT.h))
		{
			life--;
			enemies[i]->SetRect((rand() % SCREEN_RECT.w) , -enemies[i]->GetRect().h);
		}
}

void App::update()
{
	score->set_text("Score: " + toString(points));
	lives->set_text("Lives: " + toString(life));

	for (int i = 0; i < MAXPROJEC; i++)
        bullets[i]->moveProjec();

	for (int i = 0; i < MAXENEMIES; i++)
		enemies[i]->moveEnemies(0, 3);
}

void App::draw()
{
    SDL_RenderClear(renderer);
    
    bg->draw(renderer);
    
    for (int i = 0; i < MAXPROJEC; i++)
    {
        if (bullets[i]->go)
            bullets[i]->draw(renderer);
    }

	for (int i = 0; i < MAXENEMIES; i++)
		enemies[i]->draw(renderer);
    
    player1->draw(renderer);
    
    score->display_text(renderer);
    lives->display_text(renderer);
    
    SDL_RenderPresent(renderer);
}

void App::run()
{
    if (!App::initialize())
    {
        printf("An error has occur while initalizing!");
        return;
    }
    
    while (runningGame)
    {
		SDL_Event Event;

		while(SDL_PollEvent(&Event))
			{
				if (Event.type == SDL_QUIT)
				{
					return;
				}
				else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_ESCAPE)
				{
					return;
				}
				else if (screen == INTROSCREEN)
				{
					App::Introevent(Event);
				}
				else if (screen == GAMEPLAYSCREEN)
				{
					App::update_event(Event);
				}
			}

		if (screen == INTROSCREEN)
		{
			App::Introscreen();
		}
		else if (screen == LOADINGSCREEN)
		{
			App::loadingscreen();
		}
		else if (screen == GAMEPLAYSCREEN)
		{        
			App::post_update();
			App::update();
        
			App::draw();
        
			SDL_Delay(10);
		}
		else if (screen == GAMEOVERSCREEN)
		{
			App::gameoverscreen();
		}
    }
}
