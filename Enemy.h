#pragma once
class Enemy
{
public:
	Enemy();
	int dealDamage();
	void takeDamage(int damage);
	void setHP(int hp);
	int getHP();
	int getMercyPoints();
	void lowerMercyPoints();
	void setMercyPoints(int mercyPoints);
private:
	int health;
	int attack;
	int tillMercyPoints;
};

