#ifndef SOUNDS_H
#define SOUNDS_H
#include <Windows.h>
#include <mmsystem.h>

void playWalking()
{
	PlaySound("Jumping Bubble (loopable).wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void playMainMenu()
{
	PlaySound("Wonder Land (Menu).wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void playFight()
{
	PlaySound("Catching Fire (fight scene).wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void playVictory()
{
	PlaySound("victory.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void playGameOver()
{
	PlaySound("gameover.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}
void playTorielFight()
{
	PlaySound("Last stand.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}




#endif SOUNDS_H
