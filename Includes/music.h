/*
	MODULE NAME: Making music (SDL)

	FUNCTION:    Creates music on the fly.

	INPUTS:      NONE.

	OUTPUTS:     Speakers.

	USAGE:       Allowing awesome music to be played.


	DESIGN NOTES:
		Requirements:
			- Pass in a file of the music (in WAVE form).

		Design:
			- ADD (SDL_mixer-1.2.11\include) IN PROJECT, BUILD OPTIONS, SEARCH DIRECTERIES, COMPILER TAB.
			- ADDD (SDL_mixer-1.2.11\lib) IN PROJECT, BUILD OPTIONS, SEARCH DIRECTERIES, LINKER TAB.
			- THEN ADD (-lmingw32 -lSDL_mixer) IN PROJECT, BUILD OPTIONS, LINKER SETTING, OTHER LINKER OPTIONS.
			- THEN ADD FILE NAME TO INITALIZE MUSIC.

     PROGRAMMER: Jordan St Germain.

     DATE: April 8, 2013.

*/

#include "SDL.h"
#include "SDL_mixer.h"

#ifndef _MUSIC_H
#define _MUSIC_H

class music
{

    private:
        Mix_Chunk *music1;
    
    public:
        void inialize_music(const char file[]);
        void play_music(int loops);
        void resume_music();
        void pause_music();
        void close_music();

};

#endif
