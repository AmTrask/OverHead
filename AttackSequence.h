#ifndef ATTACK_H
#define ATTACK_H
#include <Windows.h>
class AttackSequence
{
public:
	
	void drawAttackBar(CHAR_INFO *screen, const short w);
	void move(float frametime);
	bool isDone();
	void reset();
	float determineDamage();
private:
	double posX = 100;
	const double posY = 155;
};

#endif ATTACK_H