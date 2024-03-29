#ifndef COMMONFUNCION_H
#define COMMONFUNCION_H
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include <bits/stdc++.h>
using namespace std;
extern SDL_Renderer *renderer;
extern bool run;
extern int score;
extern vector<vector<int>>tilemap;
extern bool checkcondition(SDL_Rect& object1,SDL_Rect& object2);
extern void savehighscore(int &x);
#endif
