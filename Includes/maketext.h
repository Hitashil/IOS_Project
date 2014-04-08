/*
	MODULE NAME: A class to create text (SDL).

	FUNCTION:    Creates text to the screen.

	INPUTS:      None.

	OUTPUTS:     Screen, (to a main function).

	USAGE:       Able to create text
	.


	DESIGN NOTES:
		Requirements:
            - Pass in the image name, x and y coordinates.


		Design:
			- PASSES IN DATA.
			- READS DATA TO LOAD IMAGE.
			- INITALIZE OTHER DATA.
			- DISPLAY IMAGE.

     PROGRAMMER: Jordan St Germain.

     DATE: March 12, 2013.
*/

#ifndef _MAKETEXT_H_
#define _MAKETEXT_H_

#include "SDL.h"
#include "SDL_ttf.h"

#include <string>

using namespace std;

class Maketext
{
    protected:
		TTF_Font *Font;
		SDL_Surface *texts;
		SDL_Texture *textt;

    private:
        string text;
        int fontsize;
		SDL_Color colour;
		SDL_Rect textLocation;

	public:
		Maketext();
		~Maketext();
		Maketext(string text, int size, SDL_Rect rect, int r, int g, int b);
        Maketext(string text, int size, int x, int y, int w, int h, int r, int g, int b);

		int initialize_text(); //  Sets up text.
		void display_text(SDL_Renderer *renderer); // Displays text.
};

#endif
