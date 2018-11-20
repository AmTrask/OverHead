/*
Joshua Trask
a prototype for a ray caster in console
*/
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <cmath>
#include <random>
#include "Player.h"
#include "Enemy.h"
#define LOG(x) std::cout << x << std::endl; //Defines simply to save myself some time
#define FIVE for (int x = 0; x < 5; x++)

//global variables
const short w = 1500;
const short h = 400;
int gamestate = 0; //0 = overworld, 1 = initcombat, 2 = combat
Player p(1, 1);
Enemy e;
void ifFight(int*, int*);
void ifMercy(int*, int*);
void ifItem(int*, int*, int*);
void ifAct(int*);

int backgound[h][w] = { {} };

//placeholder variables (these should not be in the final program

//pls forgive D:





void ifMercy(int* tillMercyPoint, int* runChance)
{
	p.setX(1);
	gamestate = 0;

	//char input;
	//LOG("Do You Want To Spare Or Run?");
	//LOG("s - Spare : r - Run");
	//std::cin >> input;
	//if (input == 's')
	//{
	//	FIVE //Runs through the five numbers to check if the spare is possible
	//	{
	//		if (tillMercyPoint[x] != 0) //0's represent spare ready
	//		{
	//			return false; //Will return false if not spare ready
	//		}
	//	}
	//	return true; //Returns true if spare ready
	//}
	//else if (input == 'r')
	//{
	//	std::mt19937 rng;
	//	rng.seed(std::random_device()());
	//	std::uniform_int_distribution<std::mt19937::result_type> random(1, *runChance);
	//	int didRun = random(rng);
	//	if (didRun == 1)
	//	{
	//		LOG("You Ran Coward!");
	//		return true;
	//	}
	//	else
	//	{
	//		LOG("YOU FAILED TO RUN MWAHAHAHAHAHA!");
	//		return false;
	//	}
	//}
}

void ifAct(int* tillMercyPoint)
{
	e.lowerMercyPoints();
}

void ifFight(int* enemyHealthBar, int* playerDamageStrengthPoint, CHAR_INFO *screen)
{

	//*enemyHealthBar -= *playerDamageStrengthPoint; //Reduces the current enemy's health by the current player damage
	//draw over player health bar
	if (p.getHP() > 0)
	{
		p.takeDmg(e.dealDamage());
		if (p.getHP() < 0)
		{
			p.setHP();
		}

		for (int i = 100; i > p.getHP(); i--)
		{
			for (int j = 0; j < 15; j++)
			{
				screen[(j + 290) * w + i + 700].Attributes = 4 * 16;
			}
		}
	}
	if (e.getHP() > 0)
	{
		e.takeDamage(p.getAttack());
		if (e.getHP() < 0)
		{
			e.setHP(0);
		}
		for (int i = 50; i > e.getHP(); i--)
		{
			for (int j = 0; j < 5; j++)
			{
				screen[(j + 120) * w + i + 724].Attributes = 4 * 16;
			}
		}
	}
}

void ifItem(int* itemsPoint, int* playerHealthPoint, int* playerDamageStrengthPoint)
{
	LOG("What Item Do You Want To Use?");
	LOG("1, 2, 3, 4 or 5");
	int item;
	std::cin >> item;
	switch (itemsPoint[item - 1]) //Enters the value of the number of the inputed array index to check if there is an item or not
	{
	case 1:
		*playerHealthPoint += 10; //Adds ten health to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 2:
		*playerHealthPoint += 30; //Adds 30 health to the user
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 3:
		*playerDamageStrengthPoint += 5; //Adds 5 damage to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 4:
		*playerDamageStrengthPoint += 10; //Adds 10 damage to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 5:
		*playerDamageStrengthPoint -= 5; //Reduces the damage of the player by 5
		*playerHealthPoint += 50; //Adds 50 health to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 0:
		LOG("Nothing here bub"); //If the player tried using an non-existing item
	}
}

void initOverworld(CHAR_INFO *screen)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			backgound[i][j] = 0;
		}
	}
}

void initBattleSreen(CHAR_INFO *screen)
{
	static int battle[h][w];

	int graphic[4][15] = {
		{ 1,1,1,1,1,0,1,0,1,0,1,1,1,1,1 },
		{ 0,0,1,0,0,0,0,1,0,0,0,0,1,0,0 },
		{ 0,0,1,0,0,0,1,0,1,0,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0,0,1,0,0,1,0,0 }
	};

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			//make main box
			//vert lines
			if ((x == 1400 || x == 100) && (y >= 150 && y <= 275))
			{
				backgound[y][x] = 15 * 16;
			}
			//horz lines
			if ((x <= 1400 && x >= 100) && (y == 150 || y == 275))
			{
				backgound[y][x] = 15 * 16;
			}

			//selection boxes
			for (int i = 0; i < 4; i++)
			{
				//verticle
				if ((x == 365 * i + 100 || x == 365 * i + 300) && (y >= 325 && y <= 375))
				{
					backgound[y][x] = 8 * 16;
				}
				//Horizontal
				if ((x >= 365 * i + 100 && x <= 365 * i + 300) && (y == 325 || y == 375))
				{
					backgound[y][x] = 8 * 16;
				}
				//text
				//this code will be real jank :( sorry - josh
				if ((double(x) / 10 < 15 && double(y) / 10 < 4))
				{
					backgound[y + 330][x + (365 * i) + 125] = graphic[y / 10][x / 10] * 8 * 16;
				}
			}





		}

	}
	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{
			screen[y * w + x].Attributes = backgound[y][x];
		}
	}
	//draw players health bar

	for (int i = 0; i < p.getHP(); i++)
	{
		for (int j = 0; j < 15; j++)
		{
			screen[(j + 290) * w + i + 701].Attributes = 6 * 16;
		}
	}
	if (p.getHP() > 0)
	{

		for (int i = 100; i > p.getHP(); i--)
		{
			for (int j = 0; j < 15; j++)
			{
				screen[(j + 290) * w + i + 700].Attributes = 4 * 16;

			}
		}
	}
	//draw enemy health bar
	for (int i = 0; i < e.getHP(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			screen[(j + 120) * w + i + 725].Attributes = 10 * 16;
		}
	}


}
//draws sprite to the screen.
void draw_sprite(CHAR_INFO *screen, double posX, double posY, int spr[8][8])
{
	for (int x = 0; x < 80; x++)
	{

		for (int y = 0; y < 80; y++)
		{
			if ((double(x) / 10 < 8 && double(y) / 10 < 8))
			{
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = spr[y / 10][x / 10] * 16;

			}


		}
	}
}
//draws the backgound
void draw_backgound(CHAR_INFO *screen)
{
	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{
			screen[y * w + x].Attributes = backgound[y][x];

		}
	}
}

//draws the backgound for battle screen
void draw_battle(CHAR_INFO *screen, int selection)
{

	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{

			//draw monster (it will just be a square for now)
			if (x > 675 && x < 825 && y > 10 && y < 100)
			{
				screen[y*w + x].Attributes = 15 * 16;
			}

			if (backgound[y][x] != 0)
			{

				//highlights selected button
				if (x <= selection * 365 + 325 && x >= selection * 365 + 75 && y > 300)
				{
					screen[y*w + x].Attributes = 3 * 16;
				}
				//unhighlights things not selected
				else if (y > 300)
				{
					screen[y*w + x].Attributes = 8 * 16;

				}
			}
		}
	}


}

//puts everything drawn to "Screen" on the screen
void printScreen(HANDLE hconsole, CHAR_INFO *screen, SMALL_RECT c)
{
	screen[w*h - 1].Char.AsciiChar = '\0';
	WriteConsoleOutput(hconsole, screen, { w,h }, { 0,0 }, &c);
}
//main gameloop

void gameloop()
{

	//create buffer
	CHAR_INFO *screen = new CHAR_INFO[w*h];
	HANDLE hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hconsole);
	SMALL_RECT c = { 0,0,w,h };
	for (int i = 0; i < h*w; i++)
	{
		screen[i].Char.AsciiChar = ' ';
	}

	int select = 0;


	auto time = std::chrono::system_clock::now();
	auto oldtime = std::chrono::system_clock::now();
	double posX(1), posY(1);
	//just an infinite loop, should probably make it not infinite
	while (true)
	{
		if (gamestate == 0)
		{
			//draw things
			draw_backgound(screen);
			posX = p.getX();
			posY = p.getY();
			draw_sprite(screen, posX, posY, p.sprite);




			oldtime = time;
			time = std::chrono::system_clock::now();
			std::chrono::duration<float> elapsed = time - oldtime;
			float frametime = elapsed.count();

			p.move(frametime);


			//changes gamestate to combat
			if (posX >= 300)
			{
				gamestate = 1;
			}
		}
		else if (gamestate == 1)
		{
			//changes background to battle screen
			initBattleSreen(screen);
			gamestate = 2;
		}
		else
		{
			static int btnCooldown = 0;
			//main battle loop	
			if (btnCooldown)
			{
				btnCooldown--;
			}
			draw_battle(screen, select);
			if (GetAsyncKeyState((unsigned short) 'A') & 0x8000 && btnCooldown == 0)
			{
				select--;
				if (select < 0)
				{
					select++;
				}
				btnCooldown = 5;
			}
			if (GetAsyncKeyState((unsigned short) 'D') & 0x8000 && btnCooldown == 0)
			{
				select++;
				if (select >= 4)
				{
					select--;
				}
				btnCooldown = 5;
			}
			if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
			{
				btnCooldown = 5;	//can take out later when other things happen after your turn


				switch (select)
				{
				case 0:
					ifFight(0, 0, screen);
					break;
				case 1:
					ifAct(0);
					break;
				case 2:

					break;
				case 3:
					if (e.getMercyPoints() == 0)
					{
						ifMercy(0, 0);
						initOverworld(screen);
						e.setHP(50);
					}
					break;
				}
			}
		}

		printScreen(hconsole, screen, c);

	}
}


int main()
{
	//change font size
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 2;
	font.dwFontSize.Y = 2;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);



	gameloop();


	//time for modifiers

	system("pause");
	return 0;
}