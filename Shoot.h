#ifndef SHOOT_H
#define SHOOT_H
#include"Baseobject.h"
class Shoot:public Baseobject
{
    public:
        Shoot();
        ~Shoot();
        void setmove(bool a);
        void myhandlemove();
        bool getstatus();
    protected:
        bool running=false;
};

#endif // SHOOT_H
