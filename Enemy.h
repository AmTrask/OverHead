#pragma once
#ifndef ENEMY_H
#define ENEMY_H
class Enemy
{
public:
	Enemy();
	void setNapstablook();
	int dealDamage();
	void takeDamage(int damage);
	void setHP(int hp);
	int getHP();
	int getMissingHP();
	int getMercyPoints();
	void lowerMercyPoints();
	void setMercyPoints(int mercyPoints);
private:
	int health;
	int attack;
	int tillMercyPoints;
	int missingHealth;
};

#endif ENEMY_H