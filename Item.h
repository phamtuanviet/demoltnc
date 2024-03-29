#ifndef ITEM_H
#define ITEM_H
#include"Baseobject.h"
class Item:public Baseobject
{
    public:
        Item();
        ~Item();
        void setrectitemload(int x);
        void setrectitem();
        void setrectitem(int x);
        void setdisplay();
        bool &getdisplay();
        SDL_Rect &getrect1();
        void setrectimage();
        void setdisplayscreen();
        void reset(int x);
    protected:
        bool display;
        SDL_Rect rect1;
        int slowspeed;
        int frame;
        int x_pos;
};

#endif // ITEM_H
