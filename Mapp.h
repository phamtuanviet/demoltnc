#ifndef MAPP_H
#define MAPP_H
#include"Baseobject.h"
class Mapp:public Baseobject
{
    public:
        Mapp();
        ~Mapp();
        void setrect(int y,int x);
        void resetmap();
        void setrect(int x);
        void setrect1(int x,int y,int w,int h);
        SDL_Rect &getrect1();
        void updatemap(int x);
        void setxy(int y_,int  x_);
        void settouch(bool a);
        int &getvalx();
        int &getvaly();
        bool &gettouch();
    protected:
        SDL_Rect rect1;
        bool touch;
        int valx;
        int valy;
};

#endif // MAPP_H
