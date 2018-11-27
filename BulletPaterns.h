#ifndef BULLET_H
#define BULLET_H
class BulletPaterns
{
public:
	BulletPaterns();
	void setXY(double newX, double newY);
	double getX();
	double getY();
	void moveBullet(int whatPatern, float frametime, int bulletNum, double playerX, double playerY);
	void setGoal(double newGoalX, double newGoalY);
	void calculateAngleAndSpeedCombo(int extraSpeed);
	bool legalBullet(double extraTop, double extraBottom, double extraLeft, double extraRight);
	void initbullets(int bulletNum, int attackNum, double playerX, double playerY, float frametime);
	bool ifTimeIsAppear(int currentTime, int number);
private:
	double posX, posY, goalX, goalY, speedX, speedY;
	double positionForBulletsToAppear[99] = { 750, 146, 375, 146, 825, 146, 900, 146, 400, 146 };
	int timesToSpawnBullets[99];
	int pauseTime = 0;
};

#endif