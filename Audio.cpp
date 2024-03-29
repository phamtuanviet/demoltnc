#include "Audio.h"

Audio::Audio()
{
    chunk=nullptr;loop=0;play=false;
}

Audio::~Audio()
{
    ;
}
void Audio::run()
{
    Mix_PlayChannel(-1,chunk,loop);
}
void Audio::setloop(int loop_){loop=loop_;}
void Audio::setchunk(string path)
{
    string i="nhac/";
    i+=path;
    chunk = Mix_LoadWAV(i.c_str());
}
void Audio::setplay(bool a){play=a;}
bool Audio::getplay(){return play;}
