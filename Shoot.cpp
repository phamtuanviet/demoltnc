#include "Shoot.h"

Shoot::Shoot()
{
    tex=nullptr;
}

Shoot::~Shoot()
{
    ;
}
void Shoot::setmove(bool a){
    if(a==true&&rect.x<=1620)
    {running=a;}}
void Shoot::myhandlemove()
{
if(running==true)
{
    rect.x+=10;
        if(rect.x>=1080)
    {
        running=false;
    }
}
}
 bool Shoot::getstatus(){return running;}
