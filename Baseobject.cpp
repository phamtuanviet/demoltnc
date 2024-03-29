#include "Baseobject.h"

Baseobject::Baseobject()
{
    tex=nullptr;rect.x=0;rect.y=0;
}

Baseobject::~Baseobject()
{
    ;
}
void Baseobject::setrect(int x,int y,int w,int h)
{
    rect.x=x;
    rect.y=y;
    rect.w=w;
    rect.h=h;
}
void Baseobject::loadtexture(string path)
{
    string i1="anh/";
    i1+=path;
    SDL_Surface *surface=IMG_Load(i1.c_str());
    tex=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
}
void Baseobject::loadtexture(string path,int a,int b,int c)
{
    string i1="anh/";
    i1+=path;
    SDL_Surface *surface=IMG_Load(i1.c_str());
    SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,a,b,c));
    tex=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
}
SDL_Rect& Baseobject::getrect(){return rect;}
void Baseobject::setrender()
{
    SDL_RenderCopy(renderer,tex,NULL,&rect);
}
void Baseobject::setrender(SDL_Rect rect1)
{
    SDL_RenderCopy(renderer,tex,&rect1,&rect);
}
void Baseobject::setrenderbackground()
{
    SDL_RenderCopy(renderer,tex,NULL,NULL);
}
