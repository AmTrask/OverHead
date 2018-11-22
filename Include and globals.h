#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <random>
#include "Player.h"
#include "Enemy.h"
#include "State.h"
#include "AttackSequence.h"
#define LOG(x) std::cout << x << std::endl; //Defines simply to save myself some time
#define FIVE for (int x = 0; x < 5; x++)

#ifndef LOAD_H
#define LOAD_H
//global variables
const short w = 1500;
const short h = 400;

void ifFight(int*, int*, CHAR_INFO *screen);
void ifMercy(int*, int*);
void ifItem(int*, int*, int*);
void ifAct(int*);
void fightBox(CHAR_INFO *screen);

int gamestate = 1; //0 = overworld, 1 = initcombat, 2 = combat, 3 = init enemy attack phase, 4 = enemy attack phase
Player p(1, 1);
Player p2(220, 750); //X and Y are backwards for this one HURRAY!!!
Enemy e;
State s;
AttackSequence a;
int backgound[h][w] = { {} };
//				I HAVE NO IDEA HOW IT'S RUNNING WITHOUT THESE QQ



//placeholder variables (these should not be in the final program



#endif LOAD_H