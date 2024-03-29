#include "Enemy.h"

Enemy::Enemy()
{
    tex=nullptr;rect.x=1024;rect.y=0;frame=0;slowspeed=0;touch=false;
}

Enemy::~Enemy()
{
    ;
}
void Enemy::handlerun()
{
    x_val=-5;
    slowspeed+=1;
    if(slowspeed==120) slowspeed=0;
    if(slowspeed%4==0) frame+=1;
    rect.x+=x_val;
    if(rect.x<=0)  {rect.x=1024;rect.y=((rand()%3)*3+2)*60+10;score++;touch=false;}
    setrectimage();
}
void Enemy::reset()
{
    score+=3;
    rect.x=1080+300;
    rect.y=((rand()%3)*3+2)*60+10;
    touch=false;
}
SDL_Rect &Enemy::getrectimage(){return rect1;}
bool &Enemy::gettouch(){return touch;}
void Enemy::setrectimage()
{
    rect1.w=53;
    rect1.h=57;
    rect1.y=0;
    int i=frame%3;
    rect1.x=i*53;
}
void Enemy::settouch(bool a){touch=a;}
