#include "Enemy.h"


Enemy::Enemy()
{
	this->health = 50;
	this->attack = 10;
	this->tillMercyPoints = 4;
}
int Enemy::dealDamage() 
{
	return attack;
}
void Enemy::takeDamage(int damage) 
{
	health -= damage;
}
void Enemy::setHP(int hp) 
{
	health = hp;
}
int Enemy::getHP() 
{ 
	return health; 
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