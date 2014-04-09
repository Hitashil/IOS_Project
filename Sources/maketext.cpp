#include "maketext.h"

Maketext::Maketext()
{
    
}

Maketext::Maketext(string text, int size, SDL_Rect rect, int r, int g, int b)
{
    this->text = text;
    
    textLocation = rect;
    fontsize = size;
    
    colour.r = r;
    colour.g = g;
    colour.b = b;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.");
    }
}

Maketext::Maketext(string text, int size, int x, int y, int w, int h, int r, int g, int b)
{
    this->text = text;
    
    textLocation.x = x;
    textLocation.y = y;
    textLocation.w = w;
    textLocation.h = h;
    
    colour.r = r;
    colour.g = g;
    colour.b = b;
    
    fontsize = size;
    
    if (initialize_text() != 1)
    {
        printf("Error while loading text.");
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
    //snprintf(instance.buffer,256, "Put text here",counter); // Add outside of class.
    texts = TTF_RenderText_Solid(Font, text.data(), colour); // Gives colour to the text.
    if (texts)
    {
        SDL_SetColorKey(texts,SDL_TRUE, 0);
        textt = SDL_CreateTextureFromSurface(renderer,texts); // Makes a texture of it.
        SDL_RenderCopy(renderer, textt, NULL, &textLocation); // Put it in renderer.
        SDL_FreeSurface(texts); // Free space in surface.
        SDL_DestroyTexture(textt); // Destroys texture after useage.
    }

}
