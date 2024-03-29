#include "Mapp.h"

Mapp::Mapp()
{
    tex=nullptr;rect.w=60;rect.h=60;
}

Mapp::~Mapp()
{
    ;
}
void Mapp::setrect(int y,int x)
{
    rect.x=x*60;
    rect.y=y*60;
}
void Mapp::resetmap()
{
    rect.x=valx*60;
    rect.y=valy*60;
}
void Mapp::setrect(int x)
{
    if(x>=480&&x<=1020) rect.x=valx*60-x+480;
}
void Mapp::setrect1(int x,int y,int w,int h)
{
    rect1.x=x;
    rect1.y=y;
    rect1.w=w;
    rect1.h=h;
}
SDL_Rect& Mapp::getrect1(){return rect1;}
void Mapp::updatemap(int x)
{
    if(x<=1020&&x>=480) rect.x=x-480;
}
void Mapp::setxy(int y_,int  x_){valx=x_;valy=y_;}
void Mapp::settouch(bool a){touch=a;}
int &Mapp::getvalx(){return valx;}
int &Mapp::getvaly(){return valy;}
bool&Mapp::gettouch(){return touch;}
