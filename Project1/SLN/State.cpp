#include "State.h"


bool State::isMain()
{
	return currentState == 0;
}
bool State::isAttack()
{
	return currentState == 1;
}
bool State::isAct()
{
	return currentState == 2;
}
bool State::isItem()
{
	return currentState == 3;
}
bool State::isMercy()
{
	return currentState == 4;
}
void State::setState(int toSwitchTo)
{
	currentState = toSwitchTo;
}


bool State::isOverWorld()
{
	return currentOverWorldState == 0;
}
bool State::isMainOverWorld()
{
	return currentOverWorldState == 1;
}
bool State::isItemOverWorld()
{
	return currentOverWorldState == 2;
}
bool State::isStats()
{
	return currentOverWorldState == 3;
}
void State::setOverWorldState(int toSwitchTo)
{
	currentOverWorldState = toSwitchTo;
}