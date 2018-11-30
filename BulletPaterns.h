#ifndef BULLET_H
#define BULLET_H
#include <random>

class BulletPaterns
{
public:
	BulletPaterns();
	void setXY(double newX, double newY);
	double getX();
	double getY();
	void moveBullet(int whatPatern, float frametime, int bulletNum, double playerX, double playerY, double *sharedAngle);
	void setGoal(double newGoalX, double newGoalY);
	void calculateAngleAndSpeedCombo(int extraSpeed);
	bool legalBullet(double extraTop, double extraBottom, double extraLeft, double extraRight);
	void initbullets(int bulletNum, int attackNum, double playerX, double playerY, float frametime);
	bool ifTimeIsAppear(int currentTime, int number);
	int getSpriteToUse();
	void resetBullets();
private:
	double posX, posY, goalX, goalY, speedX, speedY;
	double positionForBulletsToAppear[999];
	int timesToSpawnBullets[99];
	int pauseTime = 0;
	double descend;
	int spriteToUse;
	double angle = 0;
};
#endif