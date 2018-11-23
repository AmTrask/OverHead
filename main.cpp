/*
Joshua Trask
a prototype for a ray caster in console
*/

#include "Include and globals.h" 


//pls forgive D:

//NO!!!! >:(


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

//Spares if valid
void ifMercy(int* tillMercyPoint, int* runChance)
{
	p.setX(1);
	gamestate = 0;
	e.setMercyPoints(4);
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

//Lowers points to allow a mercy
void ifAct(int* tillMercyPoint)
{
	e.lowerMercyPoints();
}

//Does the fight thigny
void ifFight(int* enemyHealthBar, int* playerDamageStrengthPoint, CHAR_INFO *screen)
{
	fightBox(screen);
}

//draws ovals
void drawOval(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen)
{
	int theta = 0; //The current angle that it's on
	//int posY = 210; //position of oval's center 
	//int posX = 750;
	//int r = 200; //The radius of the circle
	//int thinkness = 4;
	int step = 1; // amount to add to theta each time 
	for (; theta <= 360; theta += step)
	{
		int j = posY + radius * cos(theta) * xModify; //Y's position to print 
		int i = posX + radius * sin(theta) * yModify; //y's position to print
		screen[(j)* w + i].Attributes = 7 * 16; //Prints the color on screen
		if (radius == 625) //This is not an exact thing, not even close I just put a number and it worked for what I needed it to do
		{
			for (int x(0); x < thinkness + modThinkY; x++)
			{
				for (int y(0); y < thinkness + modThinkX; y++) {
					screen[(j + x)* w + i + y].Attributes = color * 16;
				}
			}
		}
		else
		{
			for (int x(0); x < thinkness; x++) //Adds thinkness to solve broken oval (first for loop controls the upper and lower lines thinkness while seccond controls the sides)
			{
				for (int y(0); y < thinkness; y++) {
					screen[((j + x)* w + i + y)].Attributes = color * 16;
				}
			}
		}
	}
}

void drawOvalForBullets(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen, int bulletIdentification, int &invincible)
{
	int theta = 0; //The current angle that it's on
	//int posY = 210; //position of oval's center 
	//int posX = 750;
	//int r = 200; //The radius of the circle
	//int thinkness = 4;
	int step = 1; // amount to add to theta each time 
	for (; theta <= 360; theta += step)
	{
		int j = posY + radius * cos(theta) * xModify; //Y's position to print 
		int i = posX + radius * sin(theta) * yModify; //y's position to print
		screen[(j)* w + i].Attributes = 7 * 16; //Prints the color on screen
		if (radius == 625) //This is not an exact thing, not even close I just put a number and it worked for what I needed it to do
		{
			for (int x(0); x < thinkness + modThinkY; x++)
			{
				for (int y(0); y < thinkness + modThinkX; y++) {
					screen[(j + x)* w + i + y].Attributes = color * 16;
				}
			}
		}
		else
		{
			for (int x(0); x < thinkness; x++) //Adds thinkness to solve broken oval (first for loop controls the upper and lower lines thinkness while seccond controls the sides)
			{
				for (int y(0); y < thinkness; y++) {
					checkHitAndDealDmg(screen, bulletIdentification, ((j + x)* w + i + y), invincible);
					screen[((j + x)* w + i + y)].Attributes = color * 16;
				}
			}
		}
	}
}

//drays the graphics for the damage box
void fightBox(CHAR_INFO *screen)
{
	//Makes box thicker
	for (int i(1301), u(6); i > 0; i--, u--)
	{
		if (u > 0) {
			for (int j = 0; j < 130; j++)
			{
				screen[(j + 148) * w + u + 100].Attributes = 15 * 16;
				screen[(j + 148) * w + u + 1396].Attributes = 15 * 16;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			screen[(j + 275) * w + i + 99].Attributes = 15 * 16;
			screen[(j + 148) * w + i + 99].Attributes = 15 * 16;
		}
	}
	for (int u(20); u > 0; u--) //Draws red bars
	{
		if (u > 0)
		{
			for (int j(53); j > 0; j--)
			{
				screen[(j + 183) * w + u + 200].Attributes = 4 * 16;
				screen[(j + 183) * w + u + 1300].Attributes = 4 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws yellow bars
	{
		if (u > 0)
		{
			for (int j(103); j > 0; j--)
			{
				screen[(j + 157) * w + u + 500].Attributes = 6 * 16;
				screen[(j + 157) * w + u + 1000].Attributes = 6 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws green bars
	{
		if (u > 0)
		{
			for (int j(112); j > 0; j--)
			{
				screen[(j + 154) * w + u + 800].Attributes = 10 * 16;
				screen[(j + 154) * w + u + 700].Attributes = 10 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws shiny green bars
	{
		if (u > 0)
		{
			for (int j(112); j > 0; j--)
			{
				screen[(j + 154) * w + u + 780].Attributes = 2 * 16;
				screen[(j + 154) * w + u + 720].Attributes = 2 * 16;
			}
		}
	}
	for (int u(80); u > 0; u--) //Draws shiny green bars cont
	{
		if (u > 0)
		{
			for (int j(10); j > 0; j--)
			{
				screen[(j + 256) * w + u + 720].Attributes = 2 * 16;
				screen[(j + 154) * w + u + 720].Attributes = 2 * 16;
			}
		}
	}

	//Ovals in fight sequence
	drawOval(210, 750, 625, 10, 0.09, 1, 8, (-8), 10, screen);
}

//Updates the hp bar
void drawEnemyDmg(CHAR_INFO *screen) 
{
	if (e.getHP() > 0)
	{
		//e.takeDamage(p.getAttack());
		if (e.getHP() < 0)
		{
			e.setHP(0);
		}
		//int moveRight = e.getHP() - e.getMissingHP();
		for (int i = e.getHP() + e.getMissingHP(); i > e.getHP(); i--)
		{
			for (int j = 0; j < 5; j++)
			{
				screen[(j + 120) * w + i + 724].Attributes = 4 * 16;
			}
		}
	}
	else
	{
		for (int i = e.getHP() + e.getMissingHP(); i > 0; i--)
		{
			for (int j = 0; j < 5; j++)
			{
				screen[(j + 120) * w + i + 724].Attributes = 4 * 16;
			}
		}
	}
}

//the overworld
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

//draws the battle screen for the bullet hell
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
	for (int i = 0; i < e.getHP() + e.getMissingHP(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			screen[(j + 120) * w + i + 725].Attributes = 10 * 16;
		}
	}
}

//draws the background for the bullet hell section
void initEnemyBattle(CHAR_INFO *screen)
{
	for (int x = 0; x < w; x++)
	{

		for (int y = 125; y + 123 < h; y++)
		{
			screen[y * w + x].Attributes = 0 * 16;
		}
	}
	for (int j(0); j < 3; j++)
	{
		for (int i(0); i < 800; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 272) * w + i + 350].Attributes = 15 * 16;
		}
	}
	for (int j(0); j < 135; j++)
	{
		for (int i(0); i < 4; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 140) * w + i + 1150].Attributes = 15 * 16;
		}
	}
}

//resets the background for the bullet hell section
void drawBackground(CHAR_INFO *screen)
{
	for (int j(0); j < 3; j++)
	{
		for (int i(0); i < 800; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 272) * w + i + 350].Attributes = 15 * 16;
		}
	}
	for (int j(0); j < 135; j++)
	{
		for (int i(0); i < 4; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 140) * w + i + 1150].Attributes = 15 * 16;
		}
	}
	for (int x = 0; x < 796; x++)
	{

		for (int y = 129; y > 0; y--)
		{
			screen[(y + 142) * w + x + 354].Attributes = 0 * 16;
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

//draws the heart
void drawHeart(CHAR_INFO *screen, double posX, double posY)
{
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 8; i++)
		{
			screen[(j + int(posX)) * w + i + int(posY)].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 16; i++)
		{
			screen[(j + int(posX) + (-2)) * w + i + int(posY) - 4].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 24; i++)
		{
			screen[(j + int(posX) + -4) * w + i + int(posY) - 8].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 32; i++)
		{
			screen[(j + int(posX) + -6) * w + i + int(posY) - 12].Attributes = 4 * 16;
			screen[(j + int(posX) + -8) * w + i + int(posY) - 12].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 14; i++)
		{
			screen[(j + int(posX) + -10) * w + i + int(posY) - 12].Attributes = 4 * 16;
			screen[(j + int(posX) + -10) * w + i + int(posY) + 6].Attributes = 4 * 16;

		}
	}
	for (int j(0); j < 1; j++)
	{
		for (int i(0); i < 9; i++)
		{
			screen[(j + int(posX) + -11) * w + i + int(posY) - 10].Attributes = 4 * 16;
			screen[(j + int(posX) + -11) * w + i + int(posY) + 9].Attributes = 4 * 16;

		}
	}
	for (int j(0); j < 1; j++)
	{
		for (int i(0); i < 3; i++)
		{
			screen[(j + int(posX) + -12) * w + i + int(posY) - 8].Attributes = 4 * 16;
			screen[(j + int(posX) + -12) * w + i + int(posY) + 13].Attributes = 4 * 16;

		}
	}
	//Dimension box findings and possible hitbox?
	/*for (int j(0); j < 14; j++) {
		for (int i(0); i < 32; i++) {
			screen[int(posX - j + 1) * w + int(posY - 12)].Attributes = 7 * 16; // 1 vertival to get to the bottom
			screen[int(posX - j + 1) * w + int(posY + 20)].Attributes = 7 * 16; // 20 right to get to right side
			screen[int(posX + 1) * w + int(posY + i - 12)].Attributes = 7 * 16; // 12 left to get to left side
			screen[int(posX - 12) * w + int(posY + i - 12)].Attributes = 7 * 16; // 12 up to get to top
		}
	}*/
}

//Checks for hitbox
void checkHitAndDealDmg(CHAR_INFO *screen, int bulletIdentification, int posToCheck, int &invincible)
{

	if (invincible != 0)
	{
		return;
	}
	else if (screen[posToCheck].Attributes == 4 * 16)
	{
		invincible = 10;
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
		return;
	}
	else
	{
		return;
	}
}

//draws the bullets
void drawBullets(double posX, double posY, int bulletIdentification, CHAR_INFO *screen, int &invincible)
{
	//for (int j(0); j < 4; j++)
	//{
		//for (int i(0); i < 6; i++)
		//{
			//checkHitAndDealDmg(screen, bulletIdentification, ((j + int(posY)) * w + i + int(posX)), invincible);
			//screen[(j + int(posY)) * w + i + int(posX)].Attributes = 6 * 16;
		//}
	//}
	drawOvalForBullets(posY, posX, 2, 2, 2, 1, 2, 1, 8, screen, bulletIdentification, invincible);
}

void drawAndMoveBullets(float frametime, CHAR_INFO *screen, int bulletIdentification, int patternToUse, double initPosX, double initPosY, int &invincible)
{
	b[bulletIdentification].moveBullet(patternToUse, frametime);
	if (b[bulletIdentification].legalBullet(4, 4, 0, 0))
	{
		drawBullets(b[bulletIdentification].getX(), b[bulletIdentification].getY(), bulletIdentification, screen, invincible);
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
		oldtime = time;
		time = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = time - oldtime;
		float frametime = elapsed.count();

		if (gamestate == 0)
		{
			//draw things
			draw_backgound(screen);
			posX = p.getX();
			posY = p.getY();
			draw_sprite(screen, posX, posY, p.sprite);




			p.move(frametime);


			//changes gamestate to combat
			if (posX >= 300)
			{
				gamestate = 1;
			}
		}
		else if (gamestate == 1)
		{
			e.setNapstablook();
			//changes background to battle screen
			initBattleSreen(screen);
			gamestate = 2;
			s.setState(0);

		}
		else if (gamestate == 2)
		{
			static int btnCooldown = 0;
			//main battle loop	
			if (btnCooldown)
			{
				btnCooldown--;
			}
			draw_battle(screen, select);
			if (s.isMain())
			{
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
					btnCooldown = 2;	//can take out later when other things happen after your turn


					switch (select)
					{
					case 0:
						ifFight(0, 0, screen);
						s.setState(1);
						break;
					case 1:
						ifAct(0);
						gamestate = 3;
						break;
					case 2:
						gamestate = 3;
						break;
					case 3:
						if (e.getMercyPoints() == 0)
						{
							ifMercy(0, 0);
							initOverworld(screen);
							e.setHP(50);
						}
						else
						{
							gamestate = 3;
						}
						break;
					}
				}
			}
			else if (s.isAttack())
			{
				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					btnCooldown = 5;
					s.setState(0);
					e.takeDamage(int(a.determineDamage() * p.getAttack()));
					a.reset();
					initBattleSreen(screen);
					draw_battle(screen, select);
					drawEnemyDmg(screen);
					gamestate = 3;
					if (e.getHP() == 0) 
					{
						gamestate = 5;
					}
				}
				else if (!a.isDone())
				{
					initBattleSreen(screen);
					draw_battle(screen, select);
					drawEnemyDmg(screen);
					fightBox(screen);
					a.move(frametime);
					a.drawAttackBar(screen, w);
				}
				else
				{
					s.setState(0);
					a.reset();
					btnCooldown = 5;
					initBattleSreen(screen);
					draw_battle(screen, select);
					drawEnemyDmg(screen);
					gamestate = 3;
				}
			}

		}
		else if (gamestate == 3) 
		{
			initEnemyBattle(screen);
			gamestate = 4;
		}
		else if (gamestate == 4)
		{
			static int legalBullets = 0;
			static int invincible = 0;
			static int duration = 0;
			static int toMove[999] = { 0 };
			drawBackground(screen);
			int pos2X = p2.getX();
			int pos2Y = p2.getY();
			//Works invincibility and "animation" for it
			if (invincible > 0)
			{
				invincible--;
				if (invincible % 2 == 0)
				{
					drawHeart(screen, pos2X, pos2Y);
				}
			}
			else
			{
				drawHeart(screen, pos2X, pos2Y);
			}
			
			
			
			
			p2.invertedMove(frametime);

			

			if (duration % 2 == 1)
			{
				b[legalBullets].setXY(750, 180);
				b[legalBullets].setGoal(p2.getX(), p2.getY());
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}
			if ((duration + 1) % 2 == 1)
			{
				b[legalBullets].setXY(600, 180);
				b[legalBullets].setGoal(p2.getX() + 30, p2.getY() - 30);
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}
			if ((duration + 300) % 2 == 1)
			{
				b[legalBullets].setXY(850, 220);
				b[legalBullets].setGoal(p2.getX() - 30, p2.getY() + 30);
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}



			if (duration >= 1)
			{
				for (int x = 0; x < legalBullets; x++)
				{
					if (b[x].legalBullet(4, 4, 7, 10))
					{
						drawAndMoveBullets(frametime, screen, x, 0, 1, 1, invincible);
					}
				}
			}




			duration++;
			if (p.getHP() == 0)
			{
				gamestate = 6;
			}
			if (duration >= 130 && gamestate != 6)
			{
				gamestate = 1;
				duration = 0;
				legalBullets = 0;
				initBattleSreen(screen);
				gamestate = 2;
				s.setState(0);
				drawEnemyDmg(screen);
				p2.reset();

			}
		}
		else if (gamestate == 5) 
		{
			static int WHY = 1;
			if (WHY > 0)
			{
				initBattleSreen(screen);
				drawEnemyDmg(screen);
				WHY--;
			}
			else if (WHY == 0)
			{
				Sleep(2000); //Uses milliseconds
				gamestate = 0;
				initOverworld(screen);
				p.setX(0);
				WHY = 1;
			}
		}
		else if (gamestate == 6)
		{
			;
		}

		printScreen(hconsole, screen, c);

	}
}


int main()
{
	//gamestate = 1;
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