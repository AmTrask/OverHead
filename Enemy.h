#ifndef ENEMY_H
#define ENEMY_H
#include <string>
class Enemy
{
public:
	Enemy();
	void setNapstablook();
	void setFroggit();
	void setWhimsun();
	void setToriel();
	int dealDamage();
	void takeDamage(int damage);
	void setHP(int hp);
	int getHP();
	int getMissingHP();
	int getMercyPoints();
	void lowerMercyPoints();
	void setMercyPoints(int mercyPoints);
	int getNumActs();
	std::string getActWord(int position);
	bool isLowersMercyPoints(int position);
	std::string getResponce(int position);
	int getRunChance();
	int getMonsterID();
	int getNumberOfAttacks();
	int getAttackID(int attackID);
	int getAmountOfBullets();

private:
	int health;
	int attack;
	int tillMercyPoints;
	int missingHealth;
	int defence;
	int numberOfActs;
	int whatLowersMercyPoints;
	int runChance;
	int monsterID;
	int numberOfAttacks;
	std::string possibleActs[4];
	std::string responces[4];
	int amountOfBullets;

};

#endif ENEMY_H