#include "Bar.h"

Bar::Bar()
{
    rect1.x=0;rect1.y=0;
}

Bar::~Bar()
{
    ;
}
void Bar::setrect(int number,int x,int y)
{
    rect.x=x;
    rect.y=y;
    if(number==3) {rect.h=48;rect1.h=250;}
    else {rect.h=18;rect1.h=225;}
}
void Bar::setrectw(int x)
{
    rect1.w=x*315;
    rect.w=48*x;
}
void Bar::setrectw(float x)
{
    rect1.w=225*x;
    rect.w=18*x;
}
SDL_Rect Bar::getrect1(){return rect1;}
