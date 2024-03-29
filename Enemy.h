#ifndef ENEMY_H
#define ENEMY_H
#include"Baseobject.h"
class Enemy:public Baseobject
{
    public:
        Enemy();
        ~Enemy();
        void handlerun();
        void reset();
        SDL_Rect &getrectimage();
        bool &gettouch();
        void setrectimage();
        void settouch(bool a);
    protected:
        int x_val;
        int y_val;
        SDL_Rect rect1;
        int frame;
        int slowspeed;
        bool touch;
};

#endif // ENEMY_H
