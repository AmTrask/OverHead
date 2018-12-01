#ifndef LOAD_H
#define LOAD_H
#include "Map.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <random>
#include "Player.h"
#include "Enemy.h"
#include "State.h"
#include "attackSpites.h"
#include "maps.h"
#include "AttackSequence.h"
#include "BulletPaterns.h"
#include "PlayerItems.h"
#include "monsterSprites.h"


#define LOG(x) std::cout << x << std::endl //Defines simply to save myself some time
#define FIVE for (int x = 0; x < 5; x++)


//global variables

const short w = 1500;
const short h = 400;
int gamestate = 0; //0 = overworld, 1 = initcombat, 2 = combat, 3 = init enemy attack phase, 4 = enemy attack phase //5 = enemy kill //6 = gameover
int backgound[h][w] = { {} };
int dir = 0;


Player p(800, 200);
Player p2(220, 750); //X and Y are backwards for this one HURRAY!!!
Enemy e;
State s;
AttackSequence a;
BulletPaterns b[999];
PlayerItems pi;

//maps stuff
Map maps[40];
int currentmap;
int CurrMapPos[2];

void fightBox(CHAR_INFO *screen);
void drawOval(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen);
void drawOvalForBullets(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen, int bulletIdentification, int &invincible);
void drawEnemyDmg(CHAR_INFO *screen);
void initOverworld(CHAR_INFO *screen);
void initBattleSreen(CHAR_INFO *screen);
void initEnemyBattle(CHAR_INFO *screen);
void drawBackground(CHAR_INFO *screen);
void draw_sprite(CHAR_INFO *screen, double posX, double posY, int spr[8][8]);
void drawHeart(CHAR_INFO *screen, double posX, double posY);
void checkHitAndDealDmg(CHAR_INFO *screen, int bulletIdentification, int &invincible);
void drawBullets(double posX, double posY, int bulletIdentification, CHAR_INFO *screen, int &invincible);
void drawAndMoveBullets(float frametime, CHAR_INFO *screen, int bulletIdentification, int patternToUse, double initPosX, double initPosY, int &invincible);
void draw_backgound(CHAR_INFO *screen);
void draw_battle(CHAR_INFO *screen, int selection);
void printScreen(HANDLE hconsole, CHAR_INFO *screen, SMALL_RECT c);
void gameloop();
void drawHealthBars(CHAR_INFO *screen);






//placeholder variables (these should not be in the final program



#endif LOAD_H