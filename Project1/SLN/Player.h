#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <Windows.h>
#include <chrono>

class Player
{
public:
	//member functions
	Player(double posX, double posY);
	int move(float frametime, int background[400][1500], int &pointNumOfStepSinceLastCheck);
	void invertedMove(float frametime);
	double getX();
	void setX(double x);
	void setY(double y);
	double getY();
	int getHP();
	void setHP();
	int getAttack();
	void setAttack(int buff);
	void takeDmg(int damage);
	void reset();
	void itemEffect(int itemIdentification);



	//please put sprite in a different file or something
	int sprite[4][17][25] = {
		{
		{ -1,-1,-1,-1,-1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,-1,-1 ,-1},
		{ -1,-1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,-1 ,-1 },
		{ -1,-1,4,4,4,4,4,6,6,6,4,4,6,6,4,4,4,4,4,4,4,4,4,4 ,-1 },
		{ -1,-1,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,6,6,4,4,4,4,4 ,-1 },
		{ -1,4,4,4,4,4,6,0,0,0,6,6,6,6,0,0,0,6,6,6,4,4,4,4,-1 },
		{ -1,4,4,4,4,4,6,6,6,6,6,0,0,6,6,6,6,4,4,4,4,4,4,4 ,-1 },
		{ -1,-1,4,4,4,4,4,4,4,6,6,6,6,6,6,4,4,4,4,4,4,4,4,-1 ,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,4,6,6,4,4,4,-1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,4,4,3,3,3,3,3,3,3,4,4,4,4,-1,-1,-1,-1 ,-1 },
		{ -1,-1,-1,-1,-1,4,4,4,4,5,5,5,5,5,5,5,5,5,4,4,4,4,-1,-1 ,-1 },
		{ -1,-1,-1,-1,4,3,3,4,3,3,3,3,3,3,3,3,3,3,4,4,3,3,4,-1 ,-1 },
		{ -1,-1,-1,-1,4,6,6,4,5,5,5,5,5,5,5,5,5,5,5,4,6,6,4,-1 ,-1 },
		{ -1,-1,-1,-1,4,4,4,4,3,3,3,4,4,4,3,3,3,3,3,4,4,4,4,-1 ,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,4,4,4,4,4,4,4,4,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,4,4,4,4,-1,4,4,4,4,4,-1,-1,-1,-1,-1,-1,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,4,4,4,4,4,-1,4,4,4,4,4,4,-1,-1,-1,-1,-1 ,-1 }
	},
	{
		{ -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1,-1 },
		{ -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1 ,-1 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1 ,-1 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ,-1 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ,-1 },
		{ -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ,-1 },
		{ -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ,-1 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1 ,-1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 6, 6, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1,-1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, -1, -1, -1, -1 ,-1 },
		{ -1, -1, -1, -1, -1, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, -1, -1 ,-1 },
		{ -1, -1, -1, -1, 4, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 4, -1 ,-1 },
		{ -1, -1, -1, -1, 4, 6, 6, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 6, 6, 4, -1 ,-1 },
		{ -1, -1, -1, -1, 4, 4, 4, 4, 3, 3, 3, 4, 4, 4, 3, 3, 3, 3, 3, 4, 4, 4, 4, -1 ,-1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1 ,-1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, -1, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1 ,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 ,-1 }

	},
	{
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1 },
		{ -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1 },
		{ -1, 4, 4, 4, 4, 4, 8, 8, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ -1, 4, 4, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ -1, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1 },
		{ -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 3, 3, 3, 3, 3, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, 4, 4, 5, 5, 5, 4, 3, 3, 3, 4, 5, 4, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, 4, 3, 3, 3, 3, 3, 4, 3, 3, 3, 4, 3, 3, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, 4, 5, 5, 5, 5, 5, 4, 6, 6, 4, 4, 5, 5, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, 4, 4, 3, 3, 3, 3, 4, 4, 4, 4, 3, 4, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
	},
	{
		{ -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1 },
		{ -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8, 8, 4, 4, 4, 4, 4, -1 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 6, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 4, 4, -1 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 6, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4 },
		{ -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, -1 },
		{ -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 3, 3, 3, 3, 3, 4, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 5, 4, 3, 3, 3, 4, 5, 5, 5, 4, 4, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 3, 3, 4, 3, 3, 3, 4, 3, 3, 3, 3, 3, 4, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 5, 5, 4, 4, 6, 6, 4, 5, 5, 5, 5, 5, 4, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, 4, 4, 3, 4, 4, 4, 4, 3, 3, 3, 3, 4, 4, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 4, 4, 4, 4, 4, 4, 4, -1, -1, -1, -1, -1, -1 }
	}
	};


private:
	std::vector<int> inventory;
	//combat variables
	int health;
	int attack;

	int lastDir;
	//overworld variables
	double pX, pY;

	//Can take out the constant part if we want to add leveling
	const int MAXHEALTH = 100;

};


#endif // !PLAYER_H