#include "Commonfunction.h"
SDL_Renderer *renderer=nullptr;
bool run=true;
int score=0;
vector<vector<int>>tilemap={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,3,2,1,2,1,0,0,0,0,0,0,0,2,3,1,3,3,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,4,0,0,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,3,2,1,2,1,2,3,3,2,1,3,2,2,3,1,3,3,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,4,0,0,4,0,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0},
    {1,2,3,1,3,1,1,2,1,3,1,1,2,1,3,1,2,1,3,1,1,2,1,3,1,2,1}};
bool checkcondition(SDL_Rect& object1,SDL_Rect& object2)
{
    int l1=object1.x;
    int r1=object1.x +object1.w;
    int t1=object1.y;
    int b1=object1.y +object1.h;
    int l2=object2.x;
    int r2=object2.x +object2.w;
    int t2=object2.y;
    int b2=object2.y +object2.h;
    bool xoverlap=(r1>l2)&&(r2>l1);
    bool yoverlap=(b1>t2)&& (b2>t1);
    return xoverlap&&yoverlap;
}
void savehighscore(int &x)
{
    ifstream infile("highscore.txt");
    int i1;
    if(infile>>i1){;}
    else i1=0;
    infile.close();
    if(x>i1)
    {
      ofstream outfile("highscore.txt",ios::trunc);
      outfile<<x;
      outfile.close();
    }
}
