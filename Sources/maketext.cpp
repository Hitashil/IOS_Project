#include "maketext.h"

Maketext::Maketext()
{
    
}

Maketext::Maketext(string text, int size, SDL_Rect rect, int r, int g, int b)
{
    this->text = text;
    
    textLocation.x = rect.x;
	textLocation.y = rect.y;
    fontsize = size;
    
    colour.r = r;
    colour.g = g;
    colour.b = b;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.\n");
		exit(-1);
    }
}

Maketext::Maketext(string text, int size, int x, int y, int r, int g, int b)
{
    this->text = text;
    
    textLocation.x = x;
    textLocation.y = y;
    
    colour.r = r;
    colour.g = g;
    colour.b = b;
    
    fontsize = size;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.\n");
		exit(-1);
    }
}

Maketext::Maketext(string text, int size, SDL_Rect rect, SDL_Color colour)
{
    this->text = text;
    
    textLocation.x = rect.x;
	textLocation.y = rect.y;
    fontsize = size;
    
    this->colour.r = colour.r;
    this->colour.g = colour.g;
    this->colour.b = colour.b;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.\n");
		exit(-1);
    }
}

Maketext::Maketext(string text, int size, int x, int y, SDL_Color colour)
{
    this->text = text;
    
    textLocation.x = x;
    textLocation.y = y;
    
    this->colour.r = colour.r;
    this->colour.g = colour.g;
    this->colour.b = colour.b;
    
    fontsize = size;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.\n");
		exit(-1);
    }
}

int Maketext::initialize_text()
{
    TTF_Init(); // Initializes SDL ttf.

    Font = TTF_OpenFont("AppleGothic.ttf", fontsize); // A size and the ttf (True Type Font).
    
    if (!Font)
    {
        return -1;
    }
    
    return 1;
}

void Maketext::set_text(string text)
{
    this->text = text;
}

void Maketext::display_text(SDL_Renderer *renderer)
{
    texts = TTF_RenderText_Solid(Font, text.data(), colour); // Gives colour to the text.
    if (texts)
    {
		// Dynamically updating the width and height of the text.
		textLocation.w = texts->w;
		textLocation.h = texts->h;
		
        SDL_SetColorKey(texts, SDL_TRUE, 0);
        textt = SDL_CreateTextureFromSurface(renderer,texts); // Makes a texture of it.
        SDL_RenderCopy(renderer, textt, NULL, &textLocation); // Put it in renderer.
        SDL_FreeSurface(texts); // Free space in surface.
        SDL_DestroyTexture(textt); // Destroys texture after useage.
    }

}
