#include "Mainobject.h"

Mainobject::Mainobject()
{
    x_val=0;y_val=0;tex=nullptr;rect.x=0;rect.y=0;is_ground=false;ispause=false; speedfall=1;
    isright=true;status=0;frame=0;statusbefore=-1;cheo=false;numbercheo=0;fixerror=false;hp=3;mana=8;
}

Mainobject::~Mainobject()
{
    ;
}
void Mainobject::setshootlist(vector<Shoot*>shoot){shootlist=shoot;}
vector<Shoot*> &Mainobject::getshootlist(){return shootlist;}
void Mainobject::uppos(){x_pos=rect.x;y_pos=rect.y;}
void Mainobject::reset(){
setrect(400,200,50,50);
uppos();
x_val=0;
y_val=0;
hp=3;mana=8;score=0;
status=ROI;
}
void Mainobject::checkmap(vector<vector<int>>mapp)
{
    x_pos+=x_val;
    if(x_pos>=1620-50) x_pos=1620-50;
    else if(x_pos<=0)  x_pos=0;
    y_pos+=y_val;
    if(y_pos>600-50) y_pos=600-50;
    else if(y_pos<0)  y_pos=0;
    is_ground=false;
    int rect_x1 = x_pos;
    int rect_x2 = x_pos + rect.w;
    int rect_y1 = y_pos;
    int rect_y2 = y_pos + rect.h;
    int x1= rect_x1/60;
    int x2=(rect_x2-1)/60;
    int y1=rect_y1/60;
    int y2=(rect_y2-1)/60;
    if(cheo==true)
    {
        if(((mapp[y2][x2]!=0&&mapp[y2][x2]!=4)||(mapp[y2][x1]!=0&&mapp[y2][x1]!=4))&&fixerror==true||numbercheo>0)
        {
            if(y2*60-50+1==491)
            {y_pos=y2*60-50+1;
            is_ground=true;
            cheo=false;numbercheo=0;
            fixerror=false;
            }
            else
            {
                if(statusbefore!=CHEO)
                {numbercheo=(y2+1);}
                is_ground=true;
                if(y_pos<numbercheo*60)
                {
                    is_ground=true;
                    y_val=2;
                    x_val=0;
                    y_pos+=y_val;
                    status=CHEO;
                }
                else {cheo=false;numbercheo=0;fixerror=false;}
            }
        }
        else
        {
            if((mapp[y1][x1]!=0&&mapp[y1][x1]!=4)||(mapp[y1][x2]!=0&&mapp[y1][x2]!=4)||numbercheo<0)
        {
            if(statusbefore!=CHEO)
            {numbercheo=-(y1-1);}
            if(y_pos>-numbercheo*60+10)
            {
                is_ground=true;
                y_val=-2;
                x_val=0;
                y_pos+=y_val;;
                status=CHEO;
            }
            else{
            cheo=false;
            numbercheo=0;
            }
        }
        else
        {
            cheo=false;
            numbercheo=0;
            y_pos-=y_val;
            y_val=0;
        }
        }
    }
    else{
    if((mapp[y2][x2]!=0&&mapp[y2][x2]!=4)||(mapp[y2][x1]!=0&&mapp[y2][x1]!=4))
        {
            y_pos=y2*60-50+1;
            is_ground=true;
            if(y_val>0) y_val=0;
        }
    if(y_val<0)
    {
            if((mapp[y1][x1]!=0&&mapp[y1][x1]!=4)||(mapp[y1][x2]!=0&&mapp[y1][x2]!=4))
        {
            y_pos=(y1+1)*60;
            y_val=0;
        }
    }
    if(x_val>0)
    {
            if((mapp[y1][x2]!=0&&mapp[y1][x2]!=4))
        {
            x_pos=x2*60-50+1;
            x_val=0;
        }
    }
    else if(x_val<0)
    {
            if((mapp[y1][x1]!=0&&mapp[y1][x1]!=4))
        {
               x_pos=(x1+1)*60;
               x_val=0;
        }
    }
    }
}
void Mainobject::freefall()
{
    if(is_ground==false)
    {
        y_val+=speedfall;
        static int ii=1;
        ii++;
        if(ii==160) ii=0;
        if(ii%80==0) speedfall+=1;
        if(speedfall>=9) speedfall=9;
    }
    else speedfall=1;
}
void Mainobject::handleevent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    int x, y;
    SDL_GetMouseState(&x,&y);
    switch(event.type)
    {
        case SDL_QUIT:
            run=false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                    case SDLK_w:
                    if(keypress.find(SDLK_w)==keypress.end()) keypress[SDLK_w] =0;
                    if(keypress[SDLK_w]<15)
                    {y_val-=15;
                    if(y_val<=-60) y_val=-59;}
                    break;
                case SDLK_s:
                    if(keypress.find(SDLK_s)==keypress.end()) keypress[SDLK_s] =0;
                    if(keypress[SDLK_s]<15)
                    {y_val+=15;
                    if(y_val>=60) y_val=59;}
                    break;
                case SDLK_d:
                    if(keypress.find(SDLK_d) ==keypress.end()) keypress[SDLK_d] =0;
                    if(keypress[SDLK_d]<20)
                    {x_val+=15;if(x_val>=60) x_val=59;
                    isright=true;}
                    break;
                case SDLK_a:
                    if(keypress.find(SDLK_a) ==keypress.end()) keypress[SDLK_a] =0;
                    if(keypress[SDLK_a]<20)
                    {x_val-=15;if(x_val<=-60) x_val=-59;
                    isright=false;}
                    break;
                case SDLK_q:
                    if(keypress.find(SDLK_q) ==keypress.end()) keypress[SDLK_q] =0;
                    if(keypress[SDLK_q]<10)
                    {if(mana>=1)
                    {
                    status=NEM;
                    isright=true;
                    Shoot *shoot=new Shoot();
                    shoot->setrect(rect.x+30,rect.y+30,40,20);
                    shoot->loadtexture("Kunai.png");
                    shoot->setmove(true);
                    shootlist.push_back(shoot);
                    mana--;}
                    break;
                    }
                    break;
                case SDLK_f:
                        if(keypress.find(SDLK_f) ==keypress.end()) keypress[SDLK_f] =0;
                    if(keypress[SDLK_f]<10)
                        {cheo=true;
                        fixerror=true;}
                        break;
                case SDLK_e:
                        if(keypress.find(SDLK_e) ==keypress.end()) keypress[SDLK_e] =0;
                        if(keypress[SDLK_e]<10)
                        {cheo=true;
                        y_val-=10;
                        if(y_val>=-80) y_val=-79;}
                        break;
            }

            break;
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
                case SDLK_w:
                    keypress.erase(SDLK_w);
                    y_val=0;
                    break;
                case SDLK_s:
                    keypress.erase(SDLK_s);
                    y_val=0;
                    break;
                case SDLK_d:
                    keypress.erase(SDLK_d);
                    x_val=0;
                    break;
                case SDLK_a:
                    keypress.erase(SDLK_a);
                    x_val=0;
                    break;
                case SDLK_e:
                    keypress.erase(SDLK_e);
                    y_val=0;
                    break;
                case SDLK_f:
                    keypress.erase(SDLK_f);
                    y_val=0;
                    break;
                case SDLK_q:
                    keypress.erase(SDLK_q);
                    status=DUNG;
                    break;
                default:
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(x>=1000&&x<=1060&&y>=20&&y<=70){ispause=true;}
            break;
    }

    for(auto&[key,time]:keypress)
    {
        time +=5;
    }
}
void Mainobject::handlestatus()
{
    setstatus();
    setrectimage();
}
void Mainobject::handleaudio(Audio audio){audio.run();}
void Mainobject::handle()
{
    if(x_pos<490) rect.x=x_pos;
    else if(x_pos>1030) rect.x=x_pos-540;
    else rect.x=490;
    if(y_pos>540-50+1) y_pos=540-50-1;
    rect.y=y_pos;
    if(rect.y<0) rect.y=0;
    setmana();
}
void Mainobject::setisground(bool a){is_ground=a;}
int &Mainobject::getxpos(){return x_pos;}
int Mainobject::getypos(){return y_pos;}
int Mainobject::getyval(){return y_val;}
int Mainobject::getxval(){return x_val;}
bool Mainobject::getisground(){return is_ground;}
bool &Mainobject::getisright(){return isright;}
void Mainobject::setstatus()
{

    if(status==CHEO&&numbercheo!=0||status==DAU||status==NEM){;}
    else if(is_ground==true&&x_val==0) status=DUNG;
    else if(is_ground==true&&x_val!=0) status=CHAY;
    else if(is_ground==false&&y_val>0) status= ROI;
    else if(is_ground==false&&y_val<0) status= NHAY;
    if(statusbefore!=status)
    {
        frame=0;
        slowspeed=0;
    }
    statusbefore=status;
}
void Mainobject::setstatusdau()
{
    status=DAU;
}
SDL_Rect Mainobject::getrectimage()
{
    return rect1;
}
void Mainobject::setrectimage()
{
    rect1.w=33;
    rect1.h=33;
    if(isright==true) rect1.y=0;
    else rect1.y=33;
    if(status==DUNG)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%4==0) frame++;
        int i=frame%4;
        rect1.x=i*33;
    }
    else if(status==CHAY)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%5==0) frame++;
        int i=frame%5;
        rect1.x=(i+4)*33;
    }
    else if(status==NHAY)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%6==0) frame++;
        if(frame>=2) rect1.x=10*33;
        else rect1.x=9*33;
    }
    else if(status==ROI)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%4==0) frame++;
        int i=frame%2;
        rect1.x=(i+11)*33;
    }
    else if(status==CHEO)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%3==0) frame++;
        int i=frame%3;
        rect1.x=(i+13)*33;
    }
    else if(status==DAU)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%30==0) frame++;
        if(frame>=3) rect1.x=17*33;
        else rect1.x=16*33;
    }
    else if(status==NEM)
    {
        slowspeed+=1;
        if(slowspeed==120) slowspeed=0;
        if(slowspeed%30==0) frame++;
        int i=frame%2;
        rect1.x=(i+7)*33;
    }
}
void Mainobject::setmana()
{
    mana+=0.001;
    if(mana>=8) mana=8;
}
void Mainobject::sethp(bool a)
{
    if(a==true) hp+=1;
    else hp--;
    if(hp>3) hp=3;
}
float &Mainobject::getmana(){return mana;}
int &Mainobject::gethp(){return hp;}
int &Mainobject::getstatus(){return status;}
void Mainobject::resetstatus()
{
    status=DUNG;
}
void Mainobject::addmana()
{
    mana+=2;
    if(mana>8) mana=8;
}
bool &Mainobject::getispause(){return ispause;}
void Mainobject::setispause(bool a){ispause=a;}
