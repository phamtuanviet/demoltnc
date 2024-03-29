#include "Menu.h"

Menu::Menu()
{
    isplay=false;isexit=false;istutorial=false;ispause=false;
}

Menu::~Menu()
{
    ;
}
void Menu::creattextandimage()
{
    textplay.setfont("chu.ttf",70);
    textplay.setrect(450,200,180,50);
    textplay.setwordisplay("PLAY");
    textexit.setfont("chu.ttf",70);
    textexit.setrect(450,280,180,50);
    textexit.setwordisplay("EXIT");
    texttutorial.setfont("chu.ttf",70);
    texttutorial.setrect(400,350,180,50);
    texttutorial.setwordisplay("TUTORIAL");
    texthighscore.setfont("chu.ttf",70);
    texthighscore.setrect(370,430,180,50);
    texthighscore.setwordisplay("HIGH SCORE");
    background.loadtexture("menu.png");
}
void Menu::displaypause()
{
    Text resume;
    resume.setfont("chu.ttf",150);
    resume.setwordisplay("RESUME");
    resume.setrect(320,200,100,100);
    Text exitbutton;
    exitbutton.setfont("chu.ttf",150);
    exitbutton.setwordisplay("EXIT");
    exitbutton.setrect(400,360,100,100);
    Baseobject image;
    image.loadtexture("anh.png");
    while(ispause==true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_RenderClear(renderer);
        image.setrenderbackground();
        resume.settexturerenderer();
        exitbutton.settexturerenderer();
        SDL_RenderPresent(renderer);
        if(event.type == SDL_QUIT){ispause=false;run=false;isplay=false;}
        if(x>=320&&x<800&&y>=200&&y<350){resume.setcolor(255,0,0);exitbutton.setcolor(33,42,66);}
        else if(x>=400&&x<650&&y>=360&&y<510){resume.setcolor(33,42,66);exitbutton.setcolor(255,0,0);}
        else{resume.setcolor(33,42,66);exitbutton.setcolor(33,42,66);}
        if (event.type == SDL_MOUSEBUTTONDOWN) {
        if(x>=320&&x<800&&y>=200&&y<=350){ispause=false;}
        else if(x>=400&&x<650&&y>=360&&y<510){ispause=false;run=false;isplay=false;}
        }
    }
}
void Menu::displaytutorial()
{
    Baseobject tutorial;
    tutorial.loadtexture("tutorial.png");
    while(istutorial==true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_RenderClear(renderer);
        tutorial.setrenderbackground();
        SDL_RenderPresent(renderer);
        if(event.type == SDL_QUIT){isexit=true;istutorial=false;}
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
        if(x>=1000&&x<=1060&&y>=20&&y<=70){istutorial=false;}
        }
    }
}
void Menu::displayhighscore()
{
    ifstream infile("highscore.txt");
    string i1;
    if(infile>>i1){;}
    else{i1="0";}
    infile.close();
    Text highscore;
    highscore.setcolor(255,0,0);
    highscore.setfont("chu.ttf",100);
    highscore.setwordisplay(i1);
    highscore.setrect(500,300,100,100);
    Baseobject image;
    image.loadtexture("highscore.png");
    while(ishighscore==true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_RenderClear(renderer);
        image.setrenderbackground();
        highscore.settexturerenderer();
        SDL_RenderPresent(renderer);
        if(event.type == SDL_QUIT){isexit=true;ishighscore=false;}
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
        if(x>=1000&&x<=1060&&y>=20&&y<=70){ishighscore=false;}
        }
    }
}
void Menu::handleevent()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    int x, y;
    SDL_GetMouseState(&x, &y);
    if(event.type == SDL_QUIT){isexit=true;}
    if (x>=450&&x<580&&y>=200&&y<280) {
        textplay.setcolor(255,0,0);
        textexit.setcolor(33,42,66);
        texttutorial.setcolor(33,42,66);
        texthighscore.setcolor(33,42,66);
        } else if (x>=450&&x<580&&y>=280&&y<350){
        textplay.setcolor(33,42,66);
        texttutorial.setcolor(33,42,66);
        texthighscore.setcolor(33,42,66);
        textexit.setcolor(255,0,0);
        } else if (x>=400&&x<650&&y>=350&&y<430){
        textplay.setcolor(33,42,66);
        textexit.setcolor(33,42,66);
        texthighscore.setcolor(33,42,66);
        texttutorial.setcolor(255,0,0);
        }else if(x>=370&&x<680&&y>=430&&y<510){
        textplay.setcolor(33,42,66);
        textexit.setcolor(33,42,66);
        texthighscore.setcolor(250,0,0);
        texttutorial.setcolor(33,42,66);
        }else{
        textplay.setcolor(33,42,66);
        textexit.setcolor(33,42,66);
        texthighscore.setcolor(33,42,66);
        texttutorial.setcolor(33,42,66);
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (x>=450&&x<580&&y>=200&&y<280) {
        isplay = true;
        } else if (x>=450&&x<580&&y>=280&&y<350){
        isexit = true;
        } else if (x>=400&&x<650&&y>=350&&y<430){
        istutorial=true;
        }
          else if (x>=370&&x<680&&y>=430&&y<510){
        ishighscore=true;
        }
        }
}
void Menu::setisplay(bool a){isplay=a;}
void Menu::setisexit(bool a){isexit=a;}
void Menu::setispause(bool a){ispause=a;}
void Menu::display()
{
        SDL_RenderClear(renderer);
        background.setrenderbackground();
        textplay.settexturerenderer();
        textexit.settexturerenderer();
        texttutorial.settexturerenderer();
        texthighscore.settexturerenderer();
        SDL_RenderPresent(renderer);
}
bool &Menu::getisplay(){return isplay;}
bool &Menu::getisexit(){return isexit;}
bool &Menu::getisettutorialt(){return istutorial;}
bool &Menu::getishighscore(){return ishighscore;}
