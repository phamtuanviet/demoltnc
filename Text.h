#ifndef TEXT_H
#define TEXT_H
#include"Baseobject.h"
class Text:public Baseobject
{
    public:
        Text();
        ~Text();
        void setcolor(Uint8 x,Uint8 y,Uint8 z);
        void setfont(char *path,int sizeword);
        void setwordisplay(string i);
        void setrectxy(int x,int y);
        void setwordisplayscore(int &x);
        void settexturerenderer();
    protected:
        TTF_Font* font;
        SDL_Color textcolor;
        string wordsdisplay;
};

#endif // TEXT_H
