#include "Text.h"

Text::Text()
{
    textcolor={255,255,255};rect.x=0;rect.y=0;wordsdisplay="";rect.w=30;rect.h=30;
}
Text::~Text()
{
    ;
}
void Text::setcolor(Uint8 x,Uint8 y,Uint8 z){textcolor={x,y,z};}
void Text::setfont(char *path,int sizeword){font = TTF_OpenFont(path,sizeword);}
void Text::setwordisplay(string i){wordsdisplay=i;}
void Text::setrectxy(int x,int y){rect.x=x;rect.y=y;}
void Text::setwordisplayscore(int &x){string i="SCORE";wordsdisplay=i+" "+to_string(x);}
void Text::settexturerenderer()
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font,wordsdisplay.c_str(),textcolor);
    tex=SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(tex,NULL,NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer,tex,NULL,&rect);
}
