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
	void setState(int toSwitchTo);
private:
	int currentState;
};

#endif STATE_H