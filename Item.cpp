#include "Item.h"

Item::Item()
{
    display=false;rect.h=40;rect.w=40,rect.x=0;rect.y=0;slowspeed=0;rect1.w=21;rect1.h=21;rect1.y=0;frame=0;x_pos=0;
}

Item::~Item()
{
    ;
}
void Item::setrectitemload(int x)
{
    if(x>=490&&x<=1030) rect.x=x_pos-x+490;
    else if(x<490) rect.x=x_pos;
    else rect.x=x_pos-540;
}
void Item::setrectitem()
{
    rect.y=((rand()%3)*3+2)*60;
    rect.x=(rand()%12+6)*60;
    x_pos=rect.x;
}
void Item::setrectitem(int x)
{
    rect.y=((rand()%3)*3+2)*60;
    if(x>=490&&x<=1030)
    {rect.x=(rand()%12+6)*60-x+490;
    x_pos=rect.x+x-490;}
    else if(x<490) rect.x=(rand()%12+6)*60;
    else rect.x=(rand()%12+6)*60-540;
}
void Item::setdisplay()
{
    display =false;
}
bool &Item::getdisplay()
{
    return display;
}
SDL_Rect &Item::getrect1(){return rect1;}
void Item::setrectimage()
{
    slowspeed++;
    if(slowspeed==150) slowspeed=0;
    if(slowspeed%30==0) frame++;
    int i=frame%7;
    rect1.x=i*21;
}
void Item::setdisplayscreen()
{
    if(display==false){
    static int i=1;
    i++;
    if(i%1000==0) {display=true;i=1;}
    }
}
void Item::reset(int x)
{
    setdisplay();
    setrectitem(x);
}
