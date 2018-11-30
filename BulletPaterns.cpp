#include "BulletPaterns.h"
#include <cmath>
#include <random>
#include "time.h"
//#include <cstdlib>

BulletPaterns::BulletPaterns()
{
	this->posX = 999;
	this->posY = 999;
	this->speedX = 0;
	this->speedY = 0;
	this->descend = 0;
	this->spriteToUse = 0;
}
void BulletPaterns::resetBullets()
{
	this->posX = 999;
	this->posY = 999;
	this->speedX = 0;
	this->speedY = 0;
	this->descend = 0;
	this->spriteToUse = 0;
	this-> angle = 0;
	this->pauseTime = 0;
	for (int x = 0; x < 98; x++)
	{
		this->timesToSpawnBullets[x+1] = 999;
	}
	for (int x = 0; x < 999; x++)
	{
		this->positionForBulletsToAppear[x] = 0;
	}
}
void BulletPaterns::setXY(double newX, double newY)
{
	this->posX = newX;
	this->posY = newY;
}
double BulletPaterns::getX()
{
	return this->posX;
}
double BulletPaterns::getY()
{
	return this->posY;
}

double getRandomCordX()
{
	std::mt19937 rand;
	rand.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> random(360, 1140); // distribution in range [1, 4] 
	return random(rand);
}
double getRandomCordY()
{
	std::mt19937 rand;
	rand.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> random(200, 268); // distribution in range [1, 4] 
	return random(rand);
}

void BulletPaterns::initbullets(int bulletNum, int attackNum, double playerX, double playerY, float frametime)
{
	switch (attackNum)
	{
	case 0:
		positionForBulletsToAppear[0] = { 750 };
		positionForBulletsToAppear[1] = { 146 };
		for (int x = 0; x < 99; x++)
		{
			timesToSpawnBullets[x] = 1 + x;
		}
		setXY(positionForBulletsToAppear[0], positionForBulletsToAppear[1]);
		//setGoal(getRandomCordX(), getRandomCordY());
		this->pauseTime = 0;
		this->spriteToUse = 7;
		calculateAngleAndSpeedCombo(20);
		return;
	case 1:
		positionForBulletsToAppear[0] = { 750 };
		positionForBulletsToAppear[1] = { 146 };
		for (int x = 0; x < 99; x++)
		{
			timesToSpawnBullets[x] = 1 + x;
		}
		setXY(positionForBulletsToAppear[0], positionForBulletsToAppear[1]);
		setGoal(750, 230);
		this->pauseTime = 0;
		this->spriteToUse = 7;
		calculateAngleAndSpeedCombo(50);
		return;
	case 2:
	{
		//Positions for bullets to appear first num being x, seccond y
		positionForBulletsToAppear[0] = { 750 };
		positionForBulletsToAppear[1] = { 146 };
		positionForBulletsToAppear[2] = { 375 };
		positionForBulletsToAppear[3] = { 146 };
		positionForBulletsToAppear[4] = { 825 };
		positionForBulletsToAppear[5] = { 146 };
		positionForBulletsToAppear[6] = { 900 };
		positionForBulletsToAppear[7] = { 146 };
		positionForBulletsToAppear[8] = { 400 };
		positionForBulletsToAppear[9] = { 146 };
		//Times you want bullets to appear
		timesToSpawnBullets[0] = 1;
		timesToSpawnBullets[1] = 12;
		timesToSpawnBullets[2] = 24;
		timesToSpawnBullets[3] = 35;
		timesToSpawnBullets[4] = 47;
	}
		setXY(positionForBulletsToAppear[bulletNum * 2], positionForBulletsToAppear[bulletNum * 2 + 1]);
		setGoal(playerX, playerY);
		calculateAngleAndSpeedCombo(20);
		this->spriteToUse = 3;
		return;
	case 3:
		positionForBulletsToAppear[0] = { 1100 };
		positionForBulletsToAppear[1] = { 250 };
		timesToSpawnBullets[0] = 1;
		setXY(positionForBulletsToAppear[bulletNum * 2], positionForBulletsToAppear[bulletNum * 2 + 1]);
		descend = 5;
		pauseTime = 0;
		this->spriteToUse = 5;
		return;
	case 4:
	{		
		positionForBulletsToAppear[0] = { 421 };
		positionForBulletsToAppear[1] = { 149 };

		positionForBulletsToAppear[2] = { 488 };
		positionForBulletsToAppear[3] = { 154 };

		positionForBulletsToAppear[4] = { 555 };
		positionForBulletsToAppear[5] = { 159 };

		positionForBulletsToAppear[6] = { 622 };
		positionForBulletsToAppear[7] = { 164 };

		positionForBulletsToAppear[8] = { 689 };
		positionForBulletsToAppear[9] = { 169 };

		positionForBulletsToAppear[10] = { 756 };
		positionForBulletsToAppear[11] = { 173 };

		positionForBulletsToAppear[12] = { 823 };
		positionForBulletsToAppear[13] = { 169 };

		positionForBulletsToAppear[14] = { 890 };
		positionForBulletsToAppear[15] = { 164 };

		positionForBulletsToAppear[16] = { 957 };
		positionForBulletsToAppear[17] = { 159 };

		positionForBulletsToAppear[18] = { 1024 };
		positionForBulletsToAppear[19] = { 154 };

		positionForBulletsToAppear[20] = { 1091 };
		positionForBulletsToAppear[21] = { 149 };

		timesToSpawnBullets[0] = 1;
		timesToSpawnBullets[1] = 4;
		timesToSpawnBullets[2] = 7;
		timesToSpawnBullets[3] = 10;
		timesToSpawnBullets[4] = 13;
		timesToSpawnBullets[5] = 16;
		timesToSpawnBullets[6] = 19;
		timesToSpawnBullets[7] = 22;
		timesToSpawnBullets[8] = 25;
		timesToSpawnBullets[9] = 28;
		timesToSpawnBullets[10] = 31;
	}
	{
		positionForBulletsToAppear[22] = { 421 };
		positionForBulletsToAppear[23] = { 265 };

		positionForBulletsToAppear[24] = { 488 };
		positionForBulletsToAppear[25] = { 260 };

		positionForBulletsToAppear[26] = { 555 };
		positionForBulletsToAppear[27] = { 255 };

		positionForBulletsToAppear[28] = { 622 };
		positionForBulletsToAppear[29] = { 250 };

		positionForBulletsToAppear[30] = { 689 };
		positionForBulletsToAppear[31] = { 245 };

		positionForBulletsToAppear[32] = { 756 };
		positionForBulletsToAppear[33] = { 240 };

		positionForBulletsToAppear[34] = { 823 };
		positionForBulletsToAppear[35] = { 245 };

		positionForBulletsToAppear[36] = { 890 };
		positionForBulletsToAppear[37] = { 250 };

		positionForBulletsToAppear[38] = { 957 };
		positionForBulletsToAppear[39] = { 255 };

		positionForBulletsToAppear[40] = { 1024 };
		positionForBulletsToAppear[41] = { 260 };

		positionForBulletsToAppear[42] = { 1091 };
		positionForBulletsToAppear[43] = { 265 };

		timesToSpawnBullets[11] = 1;
		timesToSpawnBullets[12] = 4;
		timesToSpawnBullets[13] = 7;
		timesToSpawnBullets[14] = 10;
		timesToSpawnBullets[15] = 13;
		timesToSpawnBullets[16] = 16;
		timesToSpawnBullets[17] = 19;
		timesToSpawnBullets[18] = 22;
		timesToSpawnBullets[19] = 25;
		timesToSpawnBullets[20] = 28;
		timesToSpawnBullets[21] = 31;
	}
		this->pauseTime = 20;
		setXY(positionForBulletsToAppear[bulletNum * 2], positionForBulletsToAppear[bulletNum * 2 + 1]);
		this->spriteToUse = 1;
		return;
	case 5:
		for (int x = 0; x < 99; x++)
		{
			timesToSpawnBullets[x] = 999;
		}
		{
			positionForBulletsToAppear[24] = { 750 };
			positionForBulletsToAppear[25] = { 149 };

			positionForBulletsToAppear[22] = { 380 };
			positionForBulletsToAppear[23] = { 265 };
			positionForBulletsToAppear[4] = { 405 };
			positionForBulletsToAppear[5] = { 265 };
			positionForBulletsToAppear[0] = { 430 };
			positionForBulletsToAppear[1] = { 265 };
			positionForBulletsToAppear[2] = { 455 };
			positionForBulletsToAppear[3] = { 265 };
			positionForBulletsToAppear[18] = { 480 };
			positionForBulletsToAppear[19] = { 265 };
			positionForBulletsToAppear[6] = { 510 };
			positionForBulletsToAppear[7] = { 265 };
			

			positionForBulletsToAppear[8] = { 1000 };
			positionForBulletsToAppear[9] = { 265 };
			positionForBulletsToAppear[10] = { 1100 };
			positionForBulletsToAppear[11] = { 265 };
			positionForBulletsToAppear[12] = { 1125 };
			positionForBulletsToAppear[13] = { 265 };
			positionForBulletsToAppear[14] = { 1075 };
			positionForBulletsToAppear[15] = { 265 };
			positionForBulletsToAppear[16] = { 1050 };
			positionForBulletsToAppear[17] = { 265 };
			positionForBulletsToAppear[20] = { 1025 };
			positionForBulletsToAppear[21] = { 265 };
			for (int x = 0; x < 50; x++)
			{
				timesToSpawnBullets[0 + x] = 1 + 15 * x;
			}

			if (bulletNum % 5 == 0)
			{
				this->speedX = -1500;
			}
			else if (bulletNum % 6 == 0)
			{
				this->speedX = -2000;
			}
			else if (bulletNum % 9 == 0)
			{
				this->speedX = 1700;
			}
			else if (bulletNum % 8 == 0)
			{
				this->speedX = 1400;
			}
			else if (bulletNum % 7 == 0)
			{
				this->speedX = 1100;
			}
			else if (bulletNum % 4 == 0)
			{
				this->speedX = 1100;
			}
			else if (bulletNum % 3 == 0)
			{
				this->speedX = 1400;
			}
			else if (bulletNum % 2 == 0)
			{
				this->speedX = 1700;
			}
			else if (bulletNum % 1 == 0)
			{
				this->speedX = 2000;
			}
			timesToSpawnBullets[99] = 0;
			timesToSpawnBullets[98] = 0;
			timesToSpawnBullets[97] = 0;
			timesToSpawnBullets[96] = 0;
			timesToSpawnBullets[95] = 0;
			timesToSpawnBullets[94] = 0;
			timesToSpawnBullets[93] = 0;
			timesToSpawnBullets[92] = 0;
			timesToSpawnBullets[91] = 0;
			timesToSpawnBullets[90] = 0;
			timesToSpawnBullets[89] = 0;

			setXY(positionForBulletsToAppear[24], positionForBulletsToAppear[25]);
			if (bulletNum == 0 || bulletNum == 1 || bulletNum == 2 || bulletNum == 3 || bulletNum == 4 || bulletNum == 5 || bulletNum == 6 || bulletNum == 7 || bulletNum == 8 || bulletNum == 9 || bulletNum == 10 || bulletNum == 11)
			{
				setXY(positionForBulletsToAppear[2 * bulletNum], positionForBulletsToAppear[2 * bulletNum + 1]);
				this->speedY = 400;
			}
			this->spriteToUse = 1;
			this->pauseTime = posX;
		}
		return;
	case 6:
	{
		positionForBulletsToAppear[0] = { 380 };
		positionForBulletsToAppear[1] = { 150 };
		positionForBulletsToAppear[2] = { 420 };
		positionForBulletsToAppear[3] = { 160 };
		positionForBulletsToAppear[4] = { 470 };
		positionForBulletsToAppear[5] = { 165 };
		positionForBulletsToAppear[6] = { 520 };
		positionForBulletsToAppear[7] = { 170 };
		positionForBulletsToAppear[8] = { 580 };
		positionForBulletsToAppear[9] = { 165 };
		positionForBulletsToAppear[10] = { 650 };
		positionForBulletsToAppear[11] = { 160 };
		positionForBulletsToAppear[12] = { 740 };
		positionForBulletsToAppear[13] = { 155 };
		positionForBulletsToAppear[14] = { 840 };
		positionForBulletsToAppear[15] = { 150 };
		positionForBulletsToAppear[16] = { 990 };
		positionForBulletsToAppear[17] = { 148 };
		timesToSpawnBullets[0] = 1;
		timesToSpawnBullets[1] = 4;
		timesToSpawnBullets[2] = 7;
		timesToSpawnBullets[3] = 10;
		timesToSpawnBullets[4] = 13;
		timesToSpawnBullets[5] = 16;
		timesToSpawnBullets[6] = 19;
		timesToSpawnBullets[7] = 22;
		timesToSpawnBullets[8] = 25;
	}
		this->pauseTime = 25;
		this->spriteToUse = 1;
		setXY(positionForBulletsToAppear[bulletNum * 2], positionForBulletsToAppear[bulletNum * 2 + 1]);
		return;
	case 7:
		for (int x = 0; x < 99; x++)
		{
			timesToSpawnBullets[x] = 999;
		}
		{
			positionForBulletsToAppear[24] = { 750 };
			positionForBulletsToAppear[25] = { 149 };

			positionForBulletsToAppear[22] = { 380 };
			positionForBulletsToAppear[23] = { 265 };
			positionForBulletsToAppear[4] = { 405 };
			positionForBulletsToAppear[5] = { 265 };
			positionForBulletsToAppear[0] = { 430 };
			positionForBulletsToAppear[1] = { 265 };
			positionForBulletsToAppear[2] = { 455 };
			positionForBulletsToAppear[3] = { 265 };
			positionForBulletsToAppear[18] = { 480 };
			positionForBulletsToAppear[19] = { 265 };
			positionForBulletsToAppear[6] = { 510 };
			positionForBulletsToAppear[7] = { 265 };


			positionForBulletsToAppear[8] = { 1000 };
			positionForBulletsToAppear[9] = { 265 };
			positionForBulletsToAppear[10] = { 1100 };
			positionForBulletsToAppear[11] = { 265 };
			positionForBulletsToAppear[12] = { 1125 };
			positionForBulletsToAppear[13] = { 265 };
			positionForBulletsToAppear[14] = { 1075 };
			positionForBulletsToAppear[15] = { 265 };
			positionForBulletsToAppear[16] = { 1050 };
			positionForBulletsToAppear[17] = { 265 };
			positionForBulletsToAppear[20] = { 1025 };
			positionForBulletsToAppear[21] = { 265 };
			for (int x = 0; x < 88; x++)
			{
				timesToSpawnBullets[0 + x] = 1 + 2 * x;
			}

			if (bulletNum % 2 == 0)
			{
				this->speedX = 2000;
			}
			else if (bulletNum % 1 == 0)
			{
				this->speedX = -2000;
			}
			timesToSpawnBullets[99] = 0;
			timesToSpawnBullets[98] = 0;
			timesToSpawnBullets[97] = 0;
			timesToSpawnBullets[96] = 0;
			timesToSpawnBullets[95] = 0;
			timesToSpawnBullets[94] = 0;
			timesToSpawnBullets[93] = 0;
			timesToSpawnBullets[92] = 0;
			timesToSpawnBullets[91] = 0;
			timesToSpawnBullets[90] = 0;
			timesToSpawnBullets[89] = 0;
			this->angle = 0;
			this->speedY = 20;
			setXY(positionForBulletsToAppear[24], positionForBulletsToAppear[25]);
			if (bulletNum == 0 || bulletNum == 1 || bulletNum == 2 || bulletNum == 3 || bulletNum == 4 || bulletNum == 5 || bulletNum == 6 || bulletNum == 7 || bulletNum == 8 || bulletNum == 9 || bulletNum == 10 || bulletNum == 11)
			{
				setXY(positionForBulletsToAppear[2 * bulletNum], positionForBulletsToAppear[2 * bulletNum + 1]);
				this->speedY = 400;
			}
			this->spriteToUse = 1;
			this->pauseTime = posX;
		}
		return;
		return;
	case 8:
		return;


	}
	//moveBullet(attackNum, frametime, int bulletNum, int attackNum, dplayerX, playerY);

}

bool BulletPaterns::ifTimeIsAppear(int currentTime, int number)
{
	return (currentTime == timesToSpawnBullets[number]);
}

void BulletPaterns::moveBullet(int patern, float frametime, int bulletNum, double playerX, double playerY, double *sharedAngle)
{
	switch(patern)
	{
		
		//Napstablook attacks
	case 0:
		if (this->pauseTime == 0)
		{
			setGoal(getRandomCordY(), getRandomCordX());
			calculateAngleAndSpeedCombo(70);
			this->pauseTime++;
		}
		this->posX += this->speedX * frametime;
		this->posY += this->speedY * frametime;
		return;
	case 1:
		
		this->posX += speedX * frametime;
		this->posY += speedY * frametime;
		if (this->pauseTime == 0)
		{
			setGoal(750, 300);
			calculateAngleAndSpeedCombo(70);
			this->speedX = 0;
		}
		if (this->posY > 260 && this->pauseTime == 0)
		{
			this->posY = 260;
			this->speedX = 300;
			this->speedY = 0;
			this->pauseTime++;
		}
		else if (this->posX > 1100 && this->pauseTime == 1)
		{
			this->posX = 1100;
			this->speedX = 0;
			this->speedY = -200;
			this->pauseTime++;
		}
		else if (this->posY < 146 && this->pauseTime == 2)
		{
			this->posY = 146;
			this->speedX = -200;
			this->speedY = 0;
			this->pauseTime++;
		}
		else if (this->pauseTime == 3 && this->posX >= playerY - 20 && this->posX <= playerY + 5)
		{
			// && this->posX >= playerX + 20)
			this->speedX = 0;
			this->speedY = 70;
		}
		return;
		
		//Froggit attacks
	case 2:
		if (this->descend == 0)
		{
			this->descend++;
			this->spriteToUse = 3;
		}
		else if (this->descend == 1)
		{
			this->descend--;
			this->spriteToUse = 4;
		}
		if (this->pauseTime == -20)
		{
			this->pauseTime = 10;
			setGoal(playerX, playerY);
			calculateAngleAndSpeedCombo(130);
		}
		else if (pauseTime > 1)
		{
			this->pauseTime--;
		}
		else
		{
			this->posX += this->speedX * frametime;
			this->posY += this->speedY * frametime;
			pauseTime--;
		}
		if (this->posX < 375)
		{
			this->posX = 375;
		}
		if (this->posX > 1300)
		{
			this->posX = 1300;
		}
		if (this->posY < 146)
		{
			this->posY = 146;
		}
		if (this->posY > 266)
		{
			this->posY = 266;
		}
		return;
	case 3:
		if (this->posY == 250)
		{
			this->spriteToUse = 5;
		}
		else
		{
			this->spriteToUse = 6;
		}
		if (pauseTime <= 20)
		{
			pauseTime++;
		}
		if (pauseTime == 20)
		{
			setGoal(playerX - 10, playerY);
			calculateAngleAndSpeedCombo(400);
		}
		if (pauseTime >= 20)
		{
			this->posX += speedX * frametime;

			if (posX >= playerY) 
			{
				this->posY += speedY * frametime;
			}
			if (posX < playerY)
			{
				this->posY += descend * frametime;
				descend *= 2;
			}
			if (this->posX < 375)
			{
				this->posX = 375;
				this->speedX = 0;
			}
			if (this->posX > 1100)
			{
				this->posX = 1100;
				this->speedX = 0;
			}
			if (this->posY < 146)
			{
				this->posY = 146;
			}
			if (this->posY > 250)
			{
				this->posY = 250;
				this->speedX = 0;
				this->speedY = 0;
			}
		}
		return;

		//Toriel attacks
	case 4:
		if (this->descend == 0)
		{
			this->descend++;
			this->spriteToUse = 1;
		}
		else if (this->descend == 1)
		{
			this->descend--;
			this->spriteToUse = 2;
		}
		if (this->pauseTime == 1)
		{
			setGoal(playerX, playerY);
			calculateAngleAndSpeedCombo(100);
		}
		if (this->pauseTime > 0)
		{
			this->pauseTime--;
		}
		if (this->pauseTime == 0)
		{
			this->posX += speedX * frametime;
			this->posY += speedY * frametime;
		}
		return;
	case 5:
		if (this->descend == 0)
		{
			this->descend++;
			this->spriteToUse = 1;
		}
		else if (this->descend == 1)
		{
			this->descend--;
			this->spriteToUse = 2;
		}
		if (bulletNum == 0 || bulletNum == 1 || bulletNum == 2 || bulletNum == 3 || bulletNum == 4 || bulletNum == 5 || bulletNum == 6 || bulletNum == 7 || bulletNum == 8 || bulletNum == 9 || bulletNum == 10 || bulletNum == 11)
		{
			this->posY += this->speedY * frametime;
			if (this->posY < 146)
			{
				this->posY = 146;
				this->speedY *= -1;
			}
			if (this->posY > 264)
			{
				this->posY = 264;
				this->speedY *= -1;
			}
		}
		else
		{
			this->posX = pauseTime + sin(*sharedAngle) * (this->speedX) * frametime;
			this->posY += 20 * frametime;
			for (int x = 0; x < 50; x += 4)
			{
				if (bulletNum == x)
				{
					*sharedAngle += 0.2;
				}
			}
		}
		return;
	case 6:
		if (this->descend == 0)
		{
			this->descend++;
			this->spriteToUse = 1;
		}
		else if (this->descend == 1)
		{
			this->descend--;
			this->spriteToUse = 2;
		}
		if (this->pauseTime == 1)
		{
			setGoal(playerX, playerY);
			calculateAngleAndSpeedCombo(150);
		}
		if (this->pauseTime > 0)
		{
			this->pauseTime--;
		}
		if (this->pauseTime == 0)
		{
			this->posX += speedX * frametime;
			this->posY += speedY * frametime;
		}
		if (this->posX < 375)
		{
			this->posX = 375;
			this->speedX *= -1;
		}
		if (this->posX > 1100)
		{
			this->posX = 1100;
			this->speedX *= -1;
		}
		if (this->posY < 146)
		{
			this->posY = 146;
			this->speedY *= -1;
		}
		if (this->posY > 266)
		{
			this->posY = 266;
			this->speedY *= -1;
		}
		return;
	case 7:
		if (this->descend == 0)
		{
			this->descend++;
			this->spriteToUse = 1;
		}
		else if (this->descend == 1)
		{
			this->descend--;
			this->spriteToUse = 2;
		}
		if (bulletNum == 0 || bulletNum == 1 || bulletNum == 2 || bulletNum == 3 || bulletNum == 4 || bulletNum == 5 || bulletNum == 6 || bulletNum == 7 || bulletNum == 8 || bulletNum == 9 || bulletNum == 10 || bulletNum == 11)
		{
			this->posY += this->speedY * frametime;
			if (this->posY < 146)
			{
				this->posY = 146;
				this->speedY *= -1;
			}
			if (this->posY > 264)
			{
				this->posY = 264;
				this->speedY *= -1;
			}
		}
		else
		{
			this->angle += 0.2;
			if (this->angle > 3.25)
			{
				this->angle = 0;
				if (this->speedY == 20)
				{
					this->speedY = 18;
				}
				else
				{
					this->speedY = 10;

				}
			}
			this->posX = pauseTime + sin(this->angle) * (this->speedX) * frametime;
			this->posY += speedY * frametime;
			if (this->posY > 264)
			{
				this->posY = 264;
			}
		}
		return;

		//Whimsun attacks
	case 8:
		this->posX += 25 * frametime;
		this->posY += 9 * frametime * frametime;
		return;


	}
}
void BulletPaterns::setGoal(double newGoalX, double newGoalY)
{
	this->goalX = newGoalY;
	this->goalY = newGoalX;
}
void BulletPaterns::calculateAngleAndSpeedCombo(int extraSpeed)
{
	float angle = atan2(this->goalY - this->posY, this->goalX - this->posX);
	this->speedX = cos(angle) * extraSpeed;
	this->speedY = sin(angle) * extraSpeed;

}
bool BulletPaterns::legalBullet(double extraTop, double extraBottom, double extraLeft, double extraRight)
{
	if (this->posX != 0 && this->posY != 0)
		if (this->posX >= 354 + extraLeft  && this->posX <= 1150 - extraRight && this->posY >= 142 + extraTop && this->posY <= 271 - extraBottom)
		{
			{
				return true;
			}
		}
		else 
		{
			return false;
		}
}
int BulletPaterns::getSpriteToUse()
{
	return this->spriteToUse;
}

//BulletPaterns::
