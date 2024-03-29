#include"Mainobject.h"
#include"Bar.h"
#include"Enemy.h"
#include"Item.h"
#include"Menu.h"
int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Text text1;
    text1.setfont("chu.ttf",20);
    text1.setrectxy(520,10);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    vector<Audio>audio(8);
    for(int i=0;i<8;i++)
    {
        Audio setaudio;
        audio.push_back(setaudio);
    }
    audio[0].setchunk("an.wav");
    audio[1].setchunk("dau.wav");
    audio[2].setchunk("chay.wav");
    audio[3].setchunk("nem.wav");
    audio[4].setchunk("nhay.wav");
    audio[5].setchunk("thua.wav");
    audio[6].setchunk("cheo.wav");
    audio[7].setchunk("backsound.wav");
    audio[7].setloop(-1);
    bool isground=false;
    audio[7].run();
    SDL_Window*window=SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1080,600,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_Surface *surface=IMG_Load("anh/anh.png");
    SDL_Texture *tex=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    vector<Mapp>mapp;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<27;j++)
        {
            Mapp setmap;
            setmap.setrect(i,j);
            setmap.setxy(i,j);
            setmap.loadtexture("map.png");
            if(tilemap[i][j]==1)
            {
                setmap.setrect1(16,16,16,16);
                setmap.settouch(true);
                mapp.push_back(setmap);
            }
            else if(tilemap[i][j]==2)
            {
                setmap.setrect1(48,16,16,16);
                setmap.settouch(true);
                mapp.push_back(setmap);
            }
            else if(tilemap[i][j]==3)
            {
                setmap.setrect1(80,16,16,16);
                setmap.settouch(true);
                mapp.push_back(setmap);
            }
            else if(tilemap[i][j]==4)
            {
                setmap.setrect1(16,112,16,16);
                setmap.settouch(false);
                mapp.push_back(setmap);
            }
        }
    }
    Bar healthbar;
    healthbar.loadtexture("heart.png");
    healthbar.setrect(3,100,35);
    Bar manabar;
    manabar.loadtexture("mana.png",255,255,255);
    manabar.setrect(8,100,85);
    Baseobject avatar;
    avatar.loadtexture("avartar.png");
    avatar.setrect(35,15,75,75);
    Baseobject buttonpause;
    buttonpause.loadtexture("pause.png");
    buttonpause.setrect(1000,20,60,50);
    Mainobject mainot;
    mainot.setrect(400,200,50,50);
    mainot.uppos();
    mainot.loadtexture("main.png");
    Enemy *enemys=new Enemy[7];
    for(int e=0;e<7;e++)
    {
       Enemy *enemy=(enemys+e);
       enemy->setrect(1620+e*350,((rand()%3)*3+2)*60+10,40,40);
       enemy->loadtexture("roi.png");
    }
    SDL_Rect rect1{0,0,1620,600};
    SDL_Rect rect2{1620,0,1620,600};
    vector<Item>item;
    for(int i=0;i<2;i++)
    {
        Item setitem;
        setitem.loadtexture("cherry.png");
        setitem.setrectitem();
        item.push_back(setitem);
    }
    Menu menu;
    menu.creattextandimage();
    while (menu.getisexit()!=true)
    {
        menu.handleevent();
        menu.display();
        run=true;
        if(menu.getisettutorialt()==true){ menu.displaytutorial();}
        else if(menu.getishighscore()==true){menu.displayhighscore();}
        else if(menu.getisplay()==true){
    while(run)
    {
        int i1=SDL_GetTicks();
        SDL_RenderClear(renderer);
        text1.setwordisplayscore(score);
        rect1.x-=1;
        rect2.x-=1;
        SDL_RenderCopy(renderer,tex,NULL,&rect1);
        SDL_RenderCopy(renderer,tex,NULL,&rect2);
        if(rect1.x<=-1620) rect1.x=1620;
        if(rect2.x<=-1620) rect2.x=1620;
        mainot.handleevent();
        if(mainot.getispause()==true){menu.setispause(true);menu.displaypause();mainot.setispause(false);}
        if(run==false){menu.setisexit(true);menu.setisplay(false);}
        mainot.freefall();
        mainot.checkmap(tilemap);
        mainot.handlestatus();
        for(int i=0;i<mapp.size();i++)
        {   int xpos=mainot.getxpos();
            mapp[i].updatemap(xpos);
            mapp[i].setrect(xpos);
            mapp[i].setrender(mapp[i].getrect1());
        }
        for(int i=0;i<item.size();i++)
        {   int xpos=mainot.getxpos();
            item[i].setdisplayscreen();
            if(item[i].getdisplay()==true){
            item[i].setrectimage();
            item[i].setrectitemload(xpos);
            bool a=checkcondition(mainot.getrect(),item[i].getrect());
            if(a==true) {audio[0].run();item[i].reset(xpos);mainot.sethp(true);mainot.addmana();}
            else {item[i].setrender(item[i].getrect1());}}

        }
        vector<Shoot*>& shootlist = mainot.getshootlist();
          for (int i=0;i<shootlist.size();)
    {
         Shoot* shoot = shootlist[i];
       if (shoot->getstatus()==true)
       {
          shoot->myhandlemove();
          shoot->setrender();
              for(int i2=0;i2<7;i2++)
          {
              Enemy *enemy=(enemys+i2);
              bool kt2=checkcondition(shoot->getrect(),enemy->getrect());
              if(kt2==true)
              {
                  enemy->reset();
                  delete shoot;
                  shootlist.erase(shootlist.begin() + i);
                  i2==5;
              }
          }
          i++;
       }
       else
       {
          delete shoot;
          shootlist.erase(shootlist.begin() + i);
       }
    }
      for(int e=0;e<5;e++)
      {
        Enemy *enemy=(enemys+e);
        enemy->handlerun();
        enemy->setrender(enemy->getrectimage());
        bool kt=checkcondition(mainot.getrect(),enemy->getrect());
        if(kt==true)
        {
            mainot.setstatusdau();
            if(enemy->gettouch()==false)
            {mainot.sethp(false);
            enemy->settouch(true);
            audio[1].run();}
        }
      }
        mainot.handlestatus();
        avatar.setrender();
        buttonpause.setrender();
        int statusmain =mainot.getstatus();
        if(statusmain==1){mainot.handleaudio(audio[2]);}
        else if(statusmain==2){mainot.handleaudio(audio[4]);}
        else if(statusmain==6){mainot.handleaudio(audio[3]);}
        else if(statusmain==4){mainot.handleaudio(audio[6]);}
        mainot.handle();
        int hp=mainot.gethp();
        healthbar.setrectw(hp);
        float mana=mainot.getmana();
        manabar.setrectw(mana);
        healthbar.setrender(healthbar.getrect1());
        manabar.setrender(manabar.getrect1());
        mainot.setrender(mainot.getrectimage());
        text1.settexturerenderer();
        SDL_RenderPresent(renderer);
        if(mainot.getstatus()==5) mainot.resetstatus();
        if(hp<=0) {
                audio[5].run();
                SDL_Delay(3000);
                menu.setisplay(false);
                run =false;
                savehighscore(score);
                mainot.reset();
                for(int e=0;e<5;e++)
               {
               Enemy *enemy=(enemys+e);
               enemy->setrect(1620+e*350,((rand()%3)*3+2)*60+10,40,40);
               }
               for(int i=0;i<mapp.size();i++)
               {
                  mapp[i].resetmap();
               }
        }
        int i2=SDL_GetTicks();
        if(i2-i1<1000/60)
        {
            SDL_Delay(100/6-i2+i1);
        }
    }
    }
    }
    return 0;

}
