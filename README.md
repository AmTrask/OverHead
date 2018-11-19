#include <iostream>
#include <random>
#define LOG(x) std::cout << x << std::endl; //Defines simply to save myself some time
#define FIVE for (int x = 0; x < 5; x++)
void ifFight(int*, int*);
bool ifMercy(int*, int*);
void ifItem(int*, int*, int*);
void ifAct(int*);



bool ifMercy(int* tillMercyPoint, int* runChance)
{
	char input;
	LOG("Do You Want To Spare Or Run?");
	LOG("s - Spare : r - Run");
	std::cin >> input;
	if (input == 's') 
	{
		FIVE //Runs through the five numbers to check if the spare is possible
		{
			if (tillMercyPoint[x] != 0) //0's represent spare ready
			{
				return false; //Will return false if not spare ready
			}
		}
		return true; //Returns true if spare ready
	}
	else if(input == 'r') 
	{
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> random(1, *runChance); 
		int didRun = random(rng);
		if (didRun == 1) 
		{
			LOG("You Ran Coward!");
			return true;
		}
		else 
		{
			LOG("YOU FAILED TO RUN MWAHAHAHAHAHA!");
			return false;
		}
	}
}

void ifAct(int* tillMercyPoint)
{
	LOG("What Action Do You Want To Do?");
	LOG("1, 2, 3, 4 or 5");
	int action;
	std::cin >> action;
	if (tillMercyPoint[action - 1] != 0) 
	{ 
		tillMercyPoint[action - 1] --; //Will lower the current index's array value by one to bring it closer to the spare ready
	}
}

void ifFight(int* enemyHealthBar, int* playerDamageStrengthPoint)
{
	*enemyHealthBar -= *playerDamageStrengthPoint; //Reduces the current enemy's health by the current player damage
}

void ifItem(int* itemsPoint, int* playerHealthPoint, int* playerDamageStrengthPoint) 
{
	LOG("What Item Do You Want To Use?");
	LOG("1, 2, 3, 4 or 5");
	int item;
	std::cin >> item;
	switch (itemsPoint[item - 1]) //Enters the value of the number of the inputed array index to check if there is an item or not
	{
	case 1:
		*playerHealthPoint += 10; //Adds ten health to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 2:
		*playerHealthPoint += 30; //Adds 30 health to the user
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 3:
		*playerDamageStrengthPoint += 5; //Adds 5 damage to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 4:
		*playerDamageStrengthPoint += 10; //Adds 10 damage to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 5:
		*playerDamageStrengthPoint -= 5; //Reduces the damage of the player by 5
		*playerHealthPoint += 50; //Adds 50 health to the player
		itemsPoint[item - 1] = 0; //Used the item so it's no longer valid so re-use
		return;
	case 0:
		LOG("Nothing here bub"); //If the player tried using an non-existing item
	}
}
//Ignore these next few functions I will get rid of them later but I am going to keep trying something until then
void ifFroggit() 
{
	int tillMercy[5] = { 1, 1, 1, 0, 0 };
	int healthEnemy = 20;
	int enemyDamageStrength = 2;
}
void ifWhimsun() 
{
	int tillMercy[5] = { 0, 0, 0, 0, 0 };
	int healthEnemy = 1;
	int enemyDamageStrength = 0;
}
void ifNapstablook() 
{
	int tillMercy[5] = { 1, 1, 1, 1, 1 };
	int healthEnemy = 20;
	int enemyDamageStrength = 5;
}
void ifToriel(int* tillMercyPoint, int* healthEnemyPoint, int* enemyDamageStrengthPoint) 
{
	int tillMercy[5] = { 2, 2, 2, 2, 2 };
	tillMercyPoint = tillMercy;
	LOG(tillMercyPoint);
	int healthEnemy = 100;
	int enemyDamageStrength = 10;
}


int main() 
{
	int playerHealth = 100; //Sets players health to 100
	int* playerHealthPoint = &playerHealth; //Assignes a pointer to the players health
	int playerDamageStrength = 30; //You know
	int* playerDamageStrengthPoint = &playerDamageStrength; //Same here
	int items[5] = { 5, 4, 2, 3, 1 }; //The items that I gave the player
	int* itemsPoint = items; //Pointers!

	char monster = 'T'; //The monster the player will fight
	
	int tillMercy[5] = {}; //Array that will contain the amount needed to spare
	int* tillMercyPoint = tillMercy; //POINT
	int healthEnemy = 0; //Enemy's health
	int* healthEnemyPoint = &healthEnemy; //POINT!!!
	int enemyDamageStrength = 0; //Enemy's strength
	int* enemyDamageStrengthPoint = &enemyDamageStrength; //pOiNTinG111
	int runChance = 0;
	int* runChancePoint = &runChance;
	switch (monster) { //I will just explain one as they are the essentially the same
	case 'F': //Froggit data
		for (int x = 0; x < 3; x++) 
		{
			tillMercyPoint[x] = 1;//Sets three first values to 1 for needing to spare
		}
		healthEnemy = 20; //Sets the health
		enemyDamageStrength = 2; //Sets the strength
		runChance = 4;
		break;
	case 'T':
		FIVE
		{
			tillMercyPoint[x] = 2;
		}
		healthEnemy = 100;
		enemyDamageStrength = 10;
		runChance = 10000;
		break;
	case 'N':
		FIVE
		{
			tillMercyPoint[x] = 1;
		}
		healthEnemy = 20;
		enemyDamageStrength = 5;
		runChance = 25;

		break;
	case 'W':
		healthEnemy = 0;
		runChance = 1;
	}
	
	/* 
						This is the original way I wanted to do things, Simply reassigning the pointer using functions to identify the monster to battle. 
						I could not figure out how to keep the change in pointer after the function was done
	ifToriel(tillMercyPoint, healthEnemyPoint, enemyDamageStrengthPoint);
	LOG(tillMercyPoint);
	*/
	bool defeated = false; //Used to see if the fight has concluded
	bool run = false; //Useless for now
	LOG("Your health:" << playerHealth);
	LOG("Enemy health:" << healthEnemy);
	do 
	{
		char input;
		LOG("");
		LOG("What Do You Want To Do?");
		LOG("f = fight, a - Act, i - Item, m - Mercy");
		std::cin >> input;
		switch (input)
		{
		case 'f': //Will activate the fight action
			ifFight(healthEnemyPoint, playerDamageStrengthPoint);
			break;
		case 'a': //Act Action
			ifAct(tillMercyPoint);
			break;
		case 'i': //Item Action
			ifItem(itemsPoint, playerHealthPoint, playerDamageStrengthPoint);
			break;
		case 'm': //Mercy Action
			ifMercy(tillMercyPoint, runChancePoint);
			break;
		}
		if (healthEnemy > 0) { //Checks if the enemy is dead or not
			playerHealth -= enemyDamageStrength; //Damages player
		}
		LOG("");
		LOG("Your health:" << playerHealth);
		LOG("Enemy health:" << healthEnemy);
		if (playerHealth == 0 || healthEnemy == 0) 
		{ //Checks if player or enemy is dead
			defeated = true; //Turns exit condition to true as the fight is over
		}
	} while (defeated == false && run == false);


	system("pause");
	return 0;
}