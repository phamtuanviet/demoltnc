#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include"Commonfunction.h"

class Baseobject
{
    public:
        Baseobject();
        ~Baseobject();
        void setrect(int x,int y,int w,int h);
        void loadtexture(string path);
        void loadtexture(string path,int a,int b,int c);
        SDL_Rect &getrect();
        void setrender();
        void setrender(SDL_Rect rect1);
        void setrenderbackground();
    protected:
        SDL_Texture *tex;
        SDL_Rect rect;
};

#endif // BASEOBJECT_H
