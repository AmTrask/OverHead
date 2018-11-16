/*
Joshua Trask
a prototype for a ray caster in console
*/
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <cmath>

//global variables
short w = 300;
short h = 80;

int spr[8][8] = {
	{ 00,00,00,06,06,00,00 },
	{ 0,0,6,6,6,6,0,0 },
	{ 0,6,14,14,14,14,6,0 },
	{ 6,6,14,0,14,0,14,6 },
	{ 0,0,14,14,0,14,14,0 },
	{ 0,0,0,0,14,0,0,0 },
	{ 0,0,12,12,12,12,12,0 },
	{ 0,0,3,3,3,3,3,0 }

};



int main()
{
	HANDLE hColour = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hColour, 3);

	//change font size
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 8;
	font.dwFontSize.Y = 8;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);

	//create buffer
	CHAR_INFO *screem = new CHAR_INFO[w*h];
	HANDLE hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hconsole);
	SMALL_RECT c = { 0,0,w,h };
	for (int i = 0; i < h*w; i++)
	{
		screem[i].Char.AsciiChar = ' ';
	}
	
	//time for modifiers
	auto time = std::chrono::system_clock::now();
	auto oldtime = std::chrono::system_clock::now();
	double posX(1), posY(1);

	while (true)
	{
		for (int x = 0; x < w; x++)
		{

			for (int y = 0; y < h; y++)
			{
				screem[y * w + x].Attributes = 0;
				
			}
		}
		for (int x = 0; x < 8; x++)
		{

			for (int y = 0; y < 8; y++)
			{
				screem[((int)posY + y)* w + ((int)posX + x)].Attributes = spr[y][x] * 16;

			}
		}
		
		oldtime = time;
		time = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = time - oldtime;
		float frametime = elapsed.count();

		if (GetAsyncKeyState((unsigned short) 'W') & 0x8000)
		{
			posY-= 20.0*frametime;
		}
		if (GetAsyncKeyState((unsigned short) 'S') & 0x8000)
		{
			posY+= 20.0*frametime;
		}
		if (GetAsyncKeyState((unsigned short) 'A') & 0x8000)
		{
			posX-= 20.0*frametime;
		}
		if (GetAsyncKeyState((unsigned short) 'D') & 0x8000)
		{
			posX+= 20.0*frametime;
		}
		//draw to screen w/ buffer
		screem[w*h - 1].Char.AsciiChar = '\0';
		WriteConsoleOutput(hconsole, screem, { w,h }, { 0,0 }, &c);
		
	}
	system("pause");
	return 0;
}