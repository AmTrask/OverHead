#pragma once
#include <vector>;
#include <Windows.h>
#include <chrono>
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
	//member functions
	Player(double posX, double posY);
	void move(float frametime);
	double getX();
	void setX(double x);
	void setY(double y);
	double getY();
	int getHP();
	void setHP();
	void takeDmg(int damage);
	
	//please put sprite in a different file or something
	int sprite[8][8] = {
		{ 00,00,00,06,06,00,00,00 },
		{ 00,00,06,06,06,06,00,00 },
		{ 00,06,14,14,14,14,06,00 },
		{ 06,06,14,00,14,00,14,06 },
		{ 00,00,14,14,00,14,14,00 },
		{ 00,00,00,00,14,00,00,00 },
		{ 00,00,12,12,12,12,12,00 },
		{ 00,00,03,03,03,03,03,00 }

	};


private:
	std::vector<int> inventory;
	//combat variables
	int health;
	int attack; 

	//overworld variables
	double pX, pY;


};


#endif // !PLAYER_H
