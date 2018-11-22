#include "State.h"


bool State::isMain()
{
	return currentState == 0;
}
bool State::isAttack()
{
	return currentState == 1;
}
bool State::isDodge()
{
	return currentState == 2;
}
bool State::isAct()
{
	return currentState == 3;
}
bool State::isItem()
{
	return currentState == 4;
}
bool State::isMercy()
{
	return currentState == 5;
}
void State::setState(int toSwitchTo)
{
	currentState = toSwitchTo;
}