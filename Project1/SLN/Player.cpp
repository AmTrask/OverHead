#include "Player.h"

Player::Player(double posX, double posY)
{
	//initial position
	pX = posX;
	pY = posY;
	lastDir = 0;

	this->health = MAXHEALTH;
	this->attack = 15;

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

int Player::move(float frametime, int background[400][1500], int &pointNumOfStepSinceLastCheck)
{
	//movement
	if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000)
	{
		pointNumOfStepSinceLastCheck++;
		lastDir = 1;
		//keeps player in bounds 
		//if (pY - 50 * frametime > 0 && (background[int(pY + 25 - 50 * frametime)][int(pX)] == 208 || background[int(pY + 25 - 50 * frametime)][int(pX)] == 64) && (background[int(pY + 32 - 50 * frametime)][int(pX + 50)] == 208 || background[int(pY + 32 - 50 * frametime)][int(pX + 25)] == 64))
		{
			pY -= 50.0*frametime;
		}
	}
	if (GetAsyncKeyState((unsigned short) VK_DOWN) & 0x8000)
	{
		pointNumOfStepSinceLastCheck++;
		//if (pY + 50 * frametime < 1500 && (background[int(pY + 32 + 50 * frametime)][int(pX + 10)] == 208 || background[int(pY + 32 + 50 * frametime)][int(pX + 5)] == 64) && (background[int(pY + 32 + 50 * frametime)][int(pX + 50)] == 208 || background[int(pY + 32 + 50 * frametime)][int(pX + 25)] == 64))
		{
			pY += 50.0*frametime;
		}
		lastDir = 0;
	}
	if (GetAsyncKeyState((unsigned short) VK_LEFT) & 0x8000)
	{
		pointNumOfStepSinceLastCheck++;
		//if (pX - 75 * frametime > 0 && (background[int(pY + 25)][int(pX - 75 * frametime)] == 208 || background[int(pY + 25)][int(pX - 75 * frametime)] == 64) && (background[int(pY + 25)][int(pX - 75 * frametime)] == 208 || background[int(pY + 25)][int(pX - 75 * frametime)] == 64))
		{
			pX -= 75.0*frametime;
		}
		lastDir = 2;
	}
	if (GetAsyncKeyState((unsigned short) VK_RIGHT) & 0x8000)
	{
		pointNumOfStepSinceLastCheck++;
		//if (pX + 50 + 75 * frametime < 1500 && (background[int(pY + 25)][int(pX + 50 + 75 * frametime)] == 208 || background[int(pY + 25)][int(pX + 25 + 75 * frametime)] == 64) && (background[int(pY + 25)][int(pX + 25 + 75 * frametime)] == 208 || background[int(pY + 25)][int(pX + 50 + 75 * frametime)] == 64))
		{
			pX += 75.0*frametime;
		}
		lastDir = 3;
	}
	return lastDir;
}
void Player::invertedMove(float frametime)
{
	//Inverted movement
	if (GetAsyncKeyState((unsigned short) VK_LEFT) & 0x8000)
	{
		pY -= 100.0*frametime;
		if ((pY - 12) <= 354) //Heart left
		{
			pY = (354 + 12);
		}
	}
	if (GetAsyncKeyState((unsigned short) VK_RIGHT) & 0x8000)
	{
		pY += 100.0*frametime;
		if ((pY+20) >= 1150) //Heart right
		{
			pY = (1149 - 20);
		}
	}
	if (GetAsyncKeyState((unsigned short) VK_UP) & 0x8000)
	{
		pX -= 75.0*frametime;
		if ((pX - 13) <= 142) //Top of heart
		{
			pX = (142 + 13);
		}
	}
	if (GetAsyncKeyState((unsigned short) VK_DOWN) & 0x8000)
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
void Player::reset()
{
	pX = 220;
	pY = 750;
}
void Player::itemEffect(int itemIdentification)
{
	switch (itemIdentification)
	{
	case 1:		
		health += 10;
		if (health > MAXHEALTH)
		{
			health = MAXHEALTH;
		}
		break;
	case 2:
		health += 20;
		if (health > MAXHEALTH)
		{
			health = MAXHEALTH;
		}
		break;
	case 3:
		health += 15;
		if (health > MAXHEALTH)
		{
			health = MAXHEALTH;
		}
		break;
	case 4:
		health += 40;
		if (health > MAXHEALTH)
		{
			health = MAXHEALTH;
		}
		break;
	}
}