#pragma once
#ifndef BULLET_H
#define BULLET_H
class BulletPaterns
{
public:
	BulletPaterns();
	void setXY(double newX, double newY);
	double getX();
	double getY();
	void moveBullet(int whatPatern, float frametime);
	void setGoal(double newGoalX, double newGoalY);
	void calculateSpeed(int extraSpeed);
	bool legalBullet(double extraTop, double extraBottom, double extraLeft, double extraRight);
private:
	double posX, posY, goalX, goalY, speedX, speedY;
};

#endif