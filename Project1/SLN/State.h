#ifndef STATE_H
#define STATE_H
class State
{
public:
	bool isMain();
	bool isAttack();
	bool isAct();
	bool isItem();
	bool isMercy();
	bool isOverWorld();
	bool isMainOverWorld();
	bool isItemOverWorld();
	bool isStats();
	void setOverWorldState(int toSwitchTo);
	void setState(int toSwitchTo);
	
private:
	int currentState;
	int currentOverWorldState = 0;
};

#endif STATE_H