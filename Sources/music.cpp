#include "music.h"

void music::inialize_music(const char file[], int loops)
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    music1 = Mix_LoadWAV(file);
    Mix_PlayChannelTimed(-1, music1, loops, 0);
}

void music::close_music()
{
    //Mix_FreeMusic(music1);
    Mix_CloseAudio();
}