#ifndef AUDIO_H
#define AUDIO_H
#include"Commonfunction.h"
class Audio
{
    public:
        Audio();
        ~Audio();
        void run();
        void setloop(int loop_);
        void setchunk(string path);
        void setplay(bool a);
        bool getplay();
    protected:
        int loop;
        Mix_Chunk *chunk;
        bool play;
};

#endif // AUDIO_H
