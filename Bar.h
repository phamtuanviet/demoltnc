#ifndef BAR_H
#define BAR_H
#include"Baseobject.h"
class Bar:public Baseobject
{
    public:
        Bar();
        ~Bar();
        void setrect(int number,int x,int y);
        void setrectw(int x);
        void setrectw(float x);
        SDL_Rect getrect1();
    protected:
        SDL_Rect rect1;
};

#endif // BAR_H
