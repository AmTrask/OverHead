#include "Player.h"

Player::Player(double posX, double posY)
{
	//initial position
	pX = posX;
	pY = posY;


	this->health = 100;
	
}

void Player::takeDmg(int damage)
{
	health -= damage;
}

int Player::getHP()
{
	return health;
}
void Player::setHP()
{
	health = 0;
}

void Player::move(float frametime)
{
	//movement
	if (GetAsyncKeyState((unsigned short) 'W') & 0x8000)
	{
		pY -= 50.0*frametime;
	}
	if (GetAsyncKeyState((unsigned short) 'S') & 0x8000)
	{
		pY += 50.0*frametime;
	}
	if (GetAsyncKeyState((unsigned short) 'A') & 0x8000)
	{
		pX -= 75.0*frametime;
	}
	if (GetAsyncKeyState((unsigned short) 'D') & 0x8000)
	{
		pX += 75.0*frametime;
	}
}
void Player::setX(double x)
{
	pX = x;
}

double Player::getX()
{
	return pX;
}
double Player::getY()
{
	return pY;
}