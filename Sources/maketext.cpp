#include "maketext.h"

/*
Maketext::Maketext()
{

}

Maketext::Maketext(int size, SDL_Rect rect)
{

}

Maketext::Maketext(int size, int x, int y, int w, int h)
{

}
 */

int Maketext::initialize_text(int size, int x, int y, int w, int h)
{
    TTF_Init(); // Initializes SDL ttf.

    Font = TTF_OpenFont("AppleGothic.ttf", size); // A size and the ttf (True Type Font).
    if (!Font)
    {
        return -1;
    }

    textLocation.x = x;
    textLocation.y = y;
    textLocation.w = w;
    textLocation.h = h;// Where the text will be.
    
    foregroundColor.r = 0;
    foregroundColor.g = 0;
    foregroundColor.b = 0; // foreground of the text.
    
    backgroundColor.r = 255;
    backgroundColor.g = 255;
    backgroundColor.b = 255; // Background of text.
    
    return 1;
}

void Maketext::display_text(SDL_Renderer *renderer)
{
    //snprintf(instance.buffer,256, "Put text here",counter); // Add outside of class.
    texts = TTF_RenderText_Shaded(Font, buffer, foregroundColor, backgroundColor); // Gives colour to the text.
    if (texts)
    {
        SDL_SetColorKey(texts,SDL_TRUE, 0);
        textt = SDL_CreateTextureFromSurface(renderer,texts); // Makes a texture of it.
        SDL_RenderCopy(renderer, textt, NULL, &textLocation); // Put it in renderer.
        SDL_FreeSurface(texts); // Free space in surface.
        SDL_DestroyTexture(textt); // Destroys texture after useage.
    }

}
