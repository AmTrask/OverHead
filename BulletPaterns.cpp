#include "BulletPaterns.h"
#include <cmath>
//#include <cstdlib>

BulletPaterns::BulletPaterns()
{
	this->posX = 750;
	this->posY = 220;
	this->speedX = 0;
	this->speedY = 0;
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
void BulletPaterns::initbullets(int bulletNum, int attackNum, double playerX, double playerY, float frametime)
{
	switch (attackNum)
	{
	case 0:
		return;
	case 1:
		return;
	case 2:
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


		setXY(positionForBulletsToAppear[bulletNum * 2], positionForBulletsToAppear[bulletNum * 2 + 1]);
		setGoal(playerX, playerY);
		calculateAngleAndSpeedCombo(20);
		return;
	case 3:
		return;
	case 4:
		return;
	case 5:
		return;
	case 6:
		return;
	case 7:
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


void BulletPaterns::moveBullet(int patern, float frametime, int bulletNum, double playerX, double playerY)
{
	switch(patern)
	{
		
		//Napstablook attacks
	case 0:
		this->posX += 10 * frametime;
		this->posY += 40 * frametime;
		return;
	case 1:
		this->posX += 10 * frametime;
		this->posY += 20 * frametime;
		return;
		
		//Froggit attacks
	case 2:
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
		if (this->posX > 1100)
		{
			this->posX = 1100;
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
		this->posX += 300 * frametime;
		this->posY += 5 * frametime;
		return;

		//Toriel attacks
	case 4:
		this->posX += 30 * frametime;
		this->posY += 50 * frametime;
		return;
	case 5:
		this->posX += 1 * frametime;
		this->posY += 7 * frametime;
		return;
	case 6:
		this->posX += 90 * frametime;
		this->posY += 2 * frametime;
		return;
	case 7:
		this->posX += 20 * frametime;
		this->posY += 80 * frametime;
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
	float angle = atan2(goalY - posY, goalX - posX);
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
//BulletPaterns::
