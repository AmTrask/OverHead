#include "Player.h"

Player::Player(double posX, double posY)
{
	//initial position
	pX = posX;
	pY = posY;


	this->health = 100;
	this->attack = 10;

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
int Player::getAttack() 
{
	return attack;
}
void Player::setAttack(int buff)
{
	attack += buff;
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
void Player::invertedMove(float frametime)
{
	//Inverted movement
	if (GetAsyncKeyState((unsigned short) 'A') & 0x8000)
	{
		pY -= 100.0*frametime;
		if ((pY - 12) <= 354) //Heart left
		{
			pY = (354 + 12);
		}
	}
	if (GetAsyncKeyState((unsigned short) 'D') & 0x8000)
	{
		pY += 100.0*frametime;
		if ((pY+20) >= 1150) //Heart right
		{
			pY = (1149 - 20);
		}
	}
	if (GetAsyncKeyState((unsigned short) 'W') & 0x8000)
	{
		pX -= 75.0*frametime;
		if ((pX - 13) <= 142) //Top of heart
		{
			pX = (142 + 13);
		}
	}
	if (GetAsyncKeyState((unsigned short) 'S') & 0x8000)
	{
		pX += 75.0*frametime;
		if ((pX) + 1 >= 271) //Bottom of heart
		{
			pX = (271 - 1);
		}
	}
}
void Player::setX(double x)
{
	pX = x;
}
void Player::setY(double y)
{
	pX = y;
}

double Player::getX()
{
	return pX;
}
double Player::getY()
{
	return pY;
}