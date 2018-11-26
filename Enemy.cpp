#include "Enemy.h"


Enemy::Enemy()
{
	this->health = 1;
	this->attack = 1;
	this->tillMercyPoints = 1;
	this->missingHealth = 0;
}
void Enemy::setNapstablook()
{
	health = 88;
	attack = 10;
	tillMercyPoints = 4;
	missingHealth = 0;
	defence = 10;
	numberOfActs = 4;
	whatLowersMercyPoints = 3;
	possibleActs[0] = { "*CHECK" };
	possibleActs[1] = { "*FLIRT"};
	possibleActs[2] = { "*THREAT" };
	possibleActs[3] = { "*CHEER" };
	responces[0] = { "*NAPSTABLOOK ATK-10 DEF-10" };
	responces[1] = { "*YOU CANNOT FLIRT WITH A GHOST" };
	responces[2] = { "*YOU CANNOT THREATEN THIS GHOST" };
	responces[3] = { "*YOU CHEER UP NAPSTABLOOK" };
	runChance = 25;

}
void Enemy::setFroggit()
{
	health = 30;
	attack = 4;
	tillMercyPoints = 1;
	missingHealth = 0;
	defence = 3;
	numberOfActs = 3;
	whatLowersMercyPoints = 1;
	possibleActs[0] = { "*CHECK" };
	possibleActs[1] = { "*COMPLIMENT" };
	possibleActs[2] = { "*THREATEN" };
	responces[0] = { "*FROGGIT ATK-4 DEF-3" };
	responces[1] = { "*YOU COMPLEMENT THE FROG, IT BLUSHES" };
	responces[2] = { "*YOU THREATEN THE FROG!" };
	runChance = 4;
}
void Enemy::setToriel()
{
	health = 480;
	attack = 20;
	tillMercyPoints = 20;
	missingHealth = 0;
	defence = 0;
	numberOfActs = 2;
	whatLowersMercyPoints = 1;
	possibleActs[0] = { "*CHECK" };
	possibleActs[1] = { "*TALK" };
	responces[0] = { "*TORIEL ATK-20 DEF-0" };
	responces[1] = { "*YOU CANNOT THINK OF WHAT TO SAY" };
	runChance = 9999999999999999999;
}
void Enemy::setWhimsun()
{
	health = 10;
	attack = 5;
	tillMercyPoints = 0;
	missingHealth = 0;
	defence = 1;
	numberOfActs = 3;
	whatLowersMercyPoints = 999;
	possibleActs[0] = { "*CHECK" };
	possibleActs[1] = { "*CONSOLE" };
	possibleActs[2] = { "*TERRORIZE" };
	responces[0] = { "*WHIMSUN ATK-5 DEF-1" };
	responces[1] = { "*YOU TRIED CONSOLING, IT DIDN'T WORK" };
	responces[2] = { "*WHIMSUN CANNOT BE MORE TERRORIZED" };
	runChance = 1;

}
int Enemy::getNumActs()
{
	return numberOfActs;
}
std::string Enemy::getActWord(int position)
{
	return possibleActs[position];
}
std::string Enemy::getResponce(int position)
{
	return responces[position];
}
bool Enemy::isLowersMercyPoints(int position)
{
	return (position == whatLowersMercyPoints);
}
int Enemy::getRunChance()
{
	return runChance;
}
int Enemy::dealDamage() 
{
	return attack;
}
void Enemy::takeDamage(int damage) 
{
	int diff = 0;
	if (damage - defence > 0)
	{
		health -= (damage - defence);
		missingHealth += (damage - defence);
		if (health < 0)
		{
			diff = 0 - health;
			health += diff;
			missingHealth -= diff;
		}
	}
}
void Enemy::setHP(int hp) 
{
	health = hp;
}
int Enemy::getHP() 
{ 
	return health; 
}
int Enemy::getMissingHP()
{
	return missingHealth;
}
int Enemy::getMercyPoints()
{
	return tillMercyPoints;
}
void Enemy::lowerMercyPoints()
{
	if (tillMercyPoints > 0)
	{
		tillMercyPoints--;
	}
}
void Enemy::setMercyPoints(int mercyPoints)
{
	tillMercyPoints = mercyPoints;
}