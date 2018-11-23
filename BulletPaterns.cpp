#include "BulletPaterns.h"



BulletPaterns::BulletPaterns()
{
	this->posX = 750;
	this->posY = 180;
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
void BulletPaterns::moveBullet(int patern, float frametime)
{
	switch(patern)
	{
	case 0:
		this->posX += this->speedX * frametime;
		this->posY += this->speedY * frametime;

		return;
	case 1:
		this->posX += 10 * frametime;
		this->posY += 20 * frametime;
		return;
	case 2:
		this->posX += 30 * frametime;
		this->posY += 5 * frametime;
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
}
void BulletPaterns::setGoal(double newGoalX, double newGoalY)
{
	this->goalX = newGoalY;
	this->goalY = newGoalX;
}
void BulletPaterns::calculateSpeed(int extraSpeed)
{
	this->speedX = ((goalX - posX) / 30) * extraSpeed;
	this->speedY = ((goalY - posY) / 30) * extraSpeed;

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
