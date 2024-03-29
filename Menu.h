#ifndef MENU_H
#define MENU_H
#include"Text.h"
class Menu:public Baseobject
{
    public:
        Menu();
        ~Menu();
        void creattextandimage();
        void displaypause();
        void displaytutorial();
        void displayhighscore();
        void handleevent();
        void setisplay(bool a);
        void setisexit(bool a);
        void setispause(bool a);
        void display();
        bool &getisplay();
        bool &getisexit();
        bool &getisettutorialt();
        bool &getishighscore();
    protected:
        Text textplay;
        Text textexit;
        Text texttutorial;
        Text texthighscore;
        Baseobject background;
        bool isplay;
        bool isexit;
        bool istutorial;
        bool ishighscore;
        bool ispause;
};

#endif // MENU_H
