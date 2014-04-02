#include "music.h"

void music::inialize_music(const char file[])
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    music1 = Mix_LoadWAV(file);
}

void music::play_music(int loops)
{
    Mix_PlayChannelTimed(-1, music1, loops, 0);
}

void music::pause_music()
{
    Mix_Pause(-1);
}

void music::resume_music()
{
    Mix_Resume(-1);
}

void music::close_music()
{
    Mix_CloseAudio();
}