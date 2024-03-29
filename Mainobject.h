#ifndef MAINOBJECT_H
#define MAINOBJECT_H
#include"Shoot.h"
#include"Mapp.h"
#include"Audio.h"
class Mainobject:public Baseobject
{
    public:
        enum Doing
        {
           DUNG=0,
           CHAY=1,
           NHAY=2,
           ROI=3,
           CHEO=4,
           DAU=5,
           NEM=6,
        };
        Mainobject();
        ~Mainobject();
        void setshootlist(vector<Shoot*>shoot);
        vector<Shoot*> &getshootlist();
        void uppos();
        void reset();
        void checkmap(vector<vector<int>>mapp);
        void freefall();
        void handleevent();
        void handlestatus();
        void handleaudio(Audio audio);
        void handle();
        void setisground(bool a);
        int &getxpos();
        int getypos();
        int getyval();
        int getxval();
        bool getisground();
        bool &getisright();
        void setstatus();
        void setstatusdau();
        void setrectimage();
        void setmana();
        void sethp(bool a);
        float &getmana();
        int &gethp();
        int &getstatus();
        void resetstatus();
        void addmana();
        bool &getispause();
        void setispause(bool a);
        SDL_Rect getrectimage();
    protected:
        int x_val;
        int y_val;
        vector<Shoot*>shootlist;
        int x_pos;
        int y_pos;
        bool is_ground;
        int speedfall;
        bool isright;
        int status;
        int statusbefore;
        int slowspeed;
        SDL_Rect rect1;
        bool cheo;
        int numbercheo;
        int frame;
        bool fixerror;
        int hp;
        float mana;
        bool ispause;
        unordered_map<SDL_Keycode, float> keypress;
};

#endif // MAINOBJECT_H
