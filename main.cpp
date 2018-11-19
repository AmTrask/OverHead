/*
Joshua Trask
a prototype for a ray caster in console
*/
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <cmath>

//global variables
const short w = 1500;
const short h = 400;
int gamestate = 1; //0 = overworld, 1 = initcombat, 2 = combat



//Guy on screen, numbers are associated with a colour
int MockGuy[8][8] = {
	{ 00,00,00,06,06,00,00,00 },
	{ 00,00,06,06,06,06,00,00 },
	{ 00,06,14,14,14,14,06,00 },
	{ 06,06,14,00,14,00,14,06 },
	{ 00,00,14,14,00,14,14,00 },
	{ 00,00,00,00,14,00,00,00 },
	{ 00,00,12,12,12,12,12,00 },
	{ 00,00,03,03,03,03,03,00 }

};

int backgound[h][w] = { {} };

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
				if ((x ==  365 * i + 100 || x == 365 * i + 300) && (y >= 325 && y <= 375))
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
					backgound[y + 330][x +(365 * i ) + 125] = graphic[y / 10][x / 10] * 8 * 16;
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
	
}
//draws sprite to the screen.
void draw_sprite(CHAR_INFO *screen, double posX, double posY, int spr[8][8]) 
{
	for (int x = 0; x < 8; x++)
	{

		for (int y = 0; y < 8; y++)
		{
			screen[((int)posY + y)* w + ((int)posX + x)].Attributes = spr[y][x] * 16;
			

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
			if (x > 675 && x < 825 && y > 10 && y < 140)
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
				else if ( y > 300)
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
			draw_sprite(screen, posX, posY, MockGuy);




			oldtime = time;
			time = std::chrono::system_clock::now();
			std::chrono::duration<float> elapsed = time - oldtime;
			float frametime = elapsed.count();

			//movement
			if (GetAsyncKeyState((unsigned short) 'W') & 0x8000)
			{
				posY -= 20.0*frametime;
			}
			if (GetAsyncKeyState((unsigned short) 'S') & 0x8000)
			{
				posY += 20.0*frametime;
			}
			if (GetAsyncKeyState((unsigned short) 'A') & 0x8000)
			{
				posX -= 20.0*frametime;
			}
			if (GetAsyncKeyState((unsigned short) 'D') & 0x8000)
			{
				posX += 20.0*frametime;
			}

			//changes gamestate to combat
			if (posX >= 100)
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