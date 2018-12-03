#include "AttackSequence.h"



void AttackSequence::drawAttackBar(CHAR_INFO *screen, const short w)
{
	for (int j = 0; j < 115; j++)
	{
		for (int i = 0; i < 10; i++)
		{

			screen[(j + int(this->posY)) * w + i + int(posX)].Attributes = 15 * 16;
		} 
	}
}
void AttackSequence::move(float frametime)
{
	posX += 500* frametime;
	if (posX > 1390) {
		posX = 1390;
	}
}
bool AttackSequence::isDone() 
{
	return (posX >= 1390);
}
void AttackSequence::reset()
{
	posX = 100;
}
float AttackSequence::determineDamage()
{
	if (posX == 1390)
	{
		return 0;
	}
	else if (posX <= 200 || posX >= 1300) {
		return 0.25;
	}
	else if ((posX > 200 && posX <= 500) || (posX < 1300 && posX >= 1000))
	{
		return 0.5;
	} 
	else if ((posX > 500 && posX <= 700) || (posX < 1000 && posX >= 800))
	{
		return 0.75;
	}
	else if (posX < 800 || posX > 700) {
		return 1;
	}
}