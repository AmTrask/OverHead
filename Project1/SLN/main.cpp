
#include "Include and globals.h" 
#include <fstream>
std::ofstream playerPos;

//finds map that was just entered 
int findMap(int x, int y)
{
	for (int i = 0; i < 40; i++)//cycles through maps 
	{
		if (x == maps[i].iD[1] && y == maps[i].iD[0])
		{
			return maps[i].Graphic;
		}
	}
	//return 0; 
}


//Draws the indidual letter on the screen
void drawLetters(CHAR_INFO *screen, double posX, double posY, int modX, int modY, char letter, int color)
{
	const int DIMENTION_W = 21;
	const int DIMENTION_H = 11;
	static int ex[DIMENTION_H][DIMENTION_W] =
	{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	static int comma[DIMENTION_H][DIMENTION_W] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0}
	};

	static int apos[DIMENTION_H][DIMENTION_W] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	static int per[DIMENTION_H][DIMENTION_W] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	static int colon[DIMENTION_H][DIMENTION_W] =
	{ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	static int question[DIMENTION_H][DIMENTION_W] =
	{
	{0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0} };

	//I didn't add the non capitalised letters as I do not think they are needed, if someone wants to add them remember to follow the font style: 8bitoperator
	static int a[DIMENTION_H][DIMENTION_W];
	static int b[DIMENTION_H][DIMENTION_W];
	static int c[DIMENTION_H][DIMENTION_W];
	static int d[DIMENTION_H][DIMENTION_W];
	static int e[DIMENTION_H][DIMENTION_W];
	static int f[DIMENTION_H][DIMENTION_W];
	static int g[DIMENTION_H][DIMENTION_W];
	static int h[DIMENTION_H][DIMENTION_W];
	static int i[DIMENTION_H][DIMENTION_W];
	static int j[DIMENTION_H][DIMENTION_W];
	static int k[DIMENTION_H][DIMENTION_W];
	static int l[DIMENTION_H][DIMENTION_W];
	static int m[DIMENTION_H][DIMENTION_W];
	static int n[DIMENTION_H][DIMENTION_W];
	static int o[DIMENTION_H][DIMENTION_W];
	static int p[DIMENTION_H][DIMENTION_W];
	static int q[DIMENTION_H][DIMENTION_W];
	static int r[DIMENTION_H][DIMENTION_W];
	static int s[DIMENTION_H][DIMENTION_W];
	static int t[DIMENTION_H][DIMENTION_W];
	static int u[DIMENTION_H][DIMENTION_W];
	static int v[DIMENTION_H][DIMENTION_W];
	static int wLet[DIMENTION_H][DIMENTION_W];
	static int xLet[DIMENTION_H][DIMENTION_W];
	static int yLet[DIMENTION_H][DIMENTION_W];
	static int z[DIMENTION_H][DIMENTION_W];


	static int A[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	static int B[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int C[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int D[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int E[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	static int F[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	static int G[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int H[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0} };
	static int I[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int J[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int K[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0} };
	static int L[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0} };
	static int M[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0} };
	static int N[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0} };
	static int O[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	static int P[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0} };
	static int Q[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0} };
	static int R[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0} };
	static int S[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0} };
	static int T[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0} };
	static int U[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int V[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0} };
	static int W[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0} };
	static int X[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0} };
	static int Y[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0} };
	static int Z[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0} };
	static int star[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	static int one[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int two[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0} };
	static int three[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int four[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0} };
	static int five[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0} };
	static int six[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0} };
	static int seven[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0} };
	static int eight[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0} };
	static int nine[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	static int zero[DIMENTION_H][DIMENTION_W] =
	{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0} };
	
#define LETTERTODRAW(toInsert) for (int x = 0; x < DIMENTION_W * modX; x++) { for (int y = 0; y < DIMENTION_H * modY; y++) { if((toInsert[y / modY][x / modX] * 16) != 0){screen[((int)posY + y)* w + ((int)posX + x)].Attributes = color * 16; } } }
	int * ref = &ex[1][2];
	switch (letter)
	{ 
	case ':':
		LETTERTODRAW(colon);
		break;
	case ',':
		LETTERTODRAW(comma);
		break;
	case '\'':
		LETTERTODRAW(apos);
		break;
	case '.':
		LETTERTODRAW(per);
		break;
	case '?':
		LETTERTODRAW(question);
		break;
	case '*':
		LETTERTODRAW(star);
		break;
	case '!':
		LETTERTODRAW(ex);
		break;
	case 'Z':
		LETTERTODRAW(Z);
		break;
	case 'Y':
		LETTERTODRAW(Y);
		break;
	case 'X':
		LETTERTODRAW(X);
		break;
	case 'W':
		LETTERTODRAW(W);
		break;
	case 'V':
		LETTERTODRAW(V);
		break;
	case 'U':
		LETTERTODRAW(U);
		break;
	case 'T':
		LETTERTODRAW(T);
		break;
	case 'S':
		LETTERTODRAW(S);
		break;
	case 'R':
		LETTERTODRAW(R);
		break;
	case 'Q':
		LETTERTODRAW(Q);
		break;
	case 'P':
		LETTERTODRAW(P);
		break;
	case 'O':
		LETTERTODRAW(O);
		break;
	case 'N':
		LETTERTODRAW(N);
		break;
	case 'M':
		LETTERTODRAW(M);
		break;
	case 'L':
		LETTERTODRAW(L);
		break;
	case 'K':
		LETTERTODRAW(K);
		break;
	case 'J':
		LETTERTODRAW(J);
		break;
	case 'I':
		LETTERTODRAW(I);
		break;
	case 'H':
		LETTERTODRAW(H);
		break;
	case 'G':
		LETTERTODRAW(G);
		break;
	case 'F':
		LETTERTODRAW(F);
		break;
	case 'E':
		LETTERTODRAW(E);
		break;
	case 'D':
		LETTERTODRAW(D);
		break;
	case 'C':
		LETTERTODRAW(C);
		break;
	case 'B':
		LETTERTODRAW(B);
		break;
	case 'A':
		LETTERTODRAW(A);
		break;
	case 'z':
		LETTERTODRAW(z);
		break;
	case 'y':
		LETTERTODRAW(yLet);
		break;
	case 'x':
		LETTERTODRAW(xLet);
		break;
	case 'w':
		LETTERTODRAW(wLet);
		break;
	case 'v':
		LETTERTODRAW(v);
		break;
	case 'u':
		LETTERTODRAW(u);
		break;
	case 't':
		LETTERTODRAW(t);
		break;
	case 's':
		LETTERTODRAW(s);
		break;
	case 'r':
		LETTERTODRAW(r);
		break;
	case 'q':
		LETTERTODRAW(q);
		break;
	case 'p':
		LETTERTODRAW(p);
		break;
	case 'o':
		LETTERTODRAW(o);
		break;
	case 'n':
		LETTERTODRAW(n);
		break;
	case 'm':
		LETTERTODRAW(m);
		break;
	case 'l':
		LETTERTODRAW(l);
		break;
	case 'k':
		LETTERTODRAW(k);
		break;
	case 'j':
		LETTERTODRAW(j);
		break;
	case 'i':
		LETTERTODRAW(i);
		break;
	case 'h':
		LETTERTODRAW(h);
		break;
	case 'g':
		LETTERTODRAW(g);
		break;
	case 'f':
		LETTERTODRAW(f);
		break;
	case 'e':
		LETTERTODRAW(e);
		break;
	case 'd':
		LETTERTODRAW(d);
		break;
	case 'c':
		LETTERTODRAW(c);
		break;
	case 'b':
		LETTERTODRAW(b);
		break;
	case 'a':
		LETTERTODRAW(a);
		break;
	case '0':
		LETTERTODRAW(zero);
		break;
	case '9':
		LETTERTODRAW(nine);
		break;
	case '8':
		LETTERTODRAW(eight);
		break;
	case '7':
		LETTERTODRAW(seven);
		break;
	case '6':
		LETTERTODRAW(six);
		break;
	case '5':
		LETTERTODRAW(five);
		break;
	case '4':
		LETTERTODRAW(four);
		break;
	case '3':
		LETTERTODRAW(three);
		break;
	case '2':
		LETTERTODRAW(two);
		break;
	case '1':
		LETTERTODRAW(one);
		break;
	}
}

//Passes the letters to draw into the drawLetters function
void drawWords(CHAR_INFO *screen, double posX, double posY, int modX, int modY, std::string wordToDraw, int color)
{
	double distBetwLet = 16 * modX;
	for (int x = 0; x < size(wordToDraw); x++)
	{
		drawLetters(screen, posX + (distBetwLet * x), posY, modX, modY, wordToDraw[x]/*letter*/, color);
	}
}

//Gets items list and prints them
void drawItemOptions(CHAR_INFO *screen, int select)
{
	double posWords[12] = { 190, 170, 830, 170, 190, 205, 830, 205, 190, 240, 830, 240 };
	int color = 3;
	
	if (pi.getItemCount() == 0)
	{
		drawWords(screen, posWords[0], posWords[1], 2, 2, pi.getItemName(999), color);
	}
	else
	{
		for (int x = 0; x < pi.getItemCount(); x++)
		{
			if (select == x)
			{
				color = 3;
			}
			else
			{
				color = 8;
			}
			drawWords(screen, posWords[x * 2 + 0], posWords[x * 2 + 1], 2, 2, pi.getItemName(pi.getItemIdentification(x)), color);
		}
	}
}

void drawOverWorldMenu(CHAR_INFO *screen, int select)
{
	double posWord[6] = { 187, 100, 219, 100, 251, 100 };

	for (int x = 0; x < 80 * 3; x++)
	{
		for (int y = 0; y < 75 * 3; y++)
		{
			screen[(y + 150) * w + 50 + x].Attributes = menuScreen[y/3][x/3] * 16;
		}
	}
	drawWords(screen, 120, 338, 1, 1, std::to_string(p.getHP()), 15);
	drawHeart(screen, posWord[0 + 2 * select], posWord[1 + 2 * select]);
}

//Draws the item menu in the overworld
void drawItemOptionsOverWorld(CHAR_INFO *screen, int select)
{
	double posWords[12] = { 450, 170, 450, 199, 450, 228, 450, 257, 450, 286, 450, 315 };
	double posWord[20] = { 425, 170, 425, 199, 425, 228, 425, 257, 425, 286, 425, 317, 0,0, 380, 348, 510, 348, 655, 348 };
	int color = 15;
	for (int x = 0; x < 150 * 3; x++)
	{
		for (int y = 0; y < 75 * 3; y++)
		{
			screen[(y + 150) * w + 300 + x].Attributes = bigBoxMenu[y / 3][x / 3] * 16;
		}
	}

	if (pi.getItemCount() == 0)
	{
		drawWords(screen, posWords[0], posWords[1], 1, 1, pi.getItemName(999), color);
	}
	else
	{
		for (int x = 0; x < pi.getItemCount(); x++)
		{
			drawWords(screen, posWords[x * 2 + 0], posWords[x * 2 + 1], 1.5, 1.5, pi.getItemName(pi.getItemIdentification(x)), color);
		}
	}

	drawHeart(screen, posWord[1 + 2 * select] + 10, posWord[0 + 2 * select] - 50);
}

void printStats(CHAR_INFO *screen)
{
	for (int x = 0; x < 200 * 2; x++)
	{
		for (int y = 0; y < 134 * 2; y++)
		{
			screen[(y + 108) * w + 300 + x].Attributes = stats[y / 2][x / 2] * 16;
		}
	}
}


//Displays the mercy options
void drawMercyOptions(CHAR_INFO *screen, int select)
{
	double posWords[12] = { 190, 170, 830, 170, 190, 205, 830, 205, 190, 240, 830, 240 };
	std::string word[2] = { "*SPARE", "*RUN" };
	int color = 3;
	for (int x = 0; x < 2; x++)
	{
		if (select == x)
		{
			color = 3;
		}
		else
		{
			color = 8;
		}
		drawWords(screen, posWords[x * 2 + 0], posWords[x * 2 + 1], 2, 2, word[x], color);
	}
}

//Displays the mercy options
void drawActOptions(CHAR_INFO *screen, int select) 
{
	double posWords[12] = { 190, 170, 830, 170, 190, 205, 830, 205, 190, 240, 830, 240 };
	//std::string word[4] = { "*CONFORT", "*LAUGH", "*CRY", "*IGNORE" };
	int color = 3;
	for (int x = 0; x < e.getNumActs(); x++)
	{
		if (select == x)
		{
			color = 3;
		}
		else
		{
			color = 8;
		}
		drawWords(screen, posWords[x * 2 + 0], posWords[x * 2 + 1], 2, 2, e.getActWord(x), color);
	}
}

//draws ovals
void drawOval(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen)
{
	int theta = 0; //The current angle that it's on
	//int posY = 210; //position of oval's center 
	//int posX = 750;
	//int r = 200; //The radius of the circle
	//int thinkness = 4;
	int step = 1; // amount to add to theta each time 
	for (; theta <= 360; theta += step)
	{
		int j = posY + radius * cos(theta) * xModify; //Y's position to print 
		int i = posX + radius * sin(theta) * yModify; //y's position to print
		screen[(j)* w + i].Attributes = 7 * 16; //Prints the color on screen
		if (radius == 625) //This is not an exact thing, not even close I just put a number and it worked for what I needed it to do
		{
			for (int x(0); x < thinkness + modThinkY; x++)
			{
				for (int y(0); y < thinkness + modThinkX; y++) {
					screen[(j + x)* w + i + y].Attributes = color * 16;
				}
			}
		}
		else
		{
			for (int x(0); x < thinkness; x++) //Adds thinkness to solve broken oval (first for loop controls the upper and lower lines thinkness while seccond controls the sides)
			{
				for (int y(0); y < thinkness; y++) {
					screen[((j + x)* w + i + y)].Attributes = color * 16;
				}
			}
		}
	}
}

//Oval Bullets Will be taken out soon
void drawOvalForBullets(int posY, int posX, int radius, int thinkness, float xModify, float yModify, int modThinkX, int modThinkY, int color, CHAR_INFO *screen, int bulletIdentification, int &invincible)
{
	int theta = 0; //The current angle that it's on
	//int posY = 210; //position of oval's center 
	//int posX = 750;
	//int r = 200; //The radius of the circle
	//int thinkness = 4;
	int step = 1; // amount to add to theta each time 
	for (; theta <= 360; theta += step)
	{
		int j = posY + radius * cos(theta) * xModify; //Y's position to print 
		int i = posX + radius * sin(theta) * yModify; //y's position to print
		screen[(j)* w + i].Attributes = 7 * 16; //Prints the color on screen
		if (radius == 625) //This is not an exact thing, not even close I just put a number and it worked for what I needed it to do
		{
			for (int x(0); x < thinkness + modThinkY; x++)
			{
				for (int y(0); y < thinkness + modThinkX; y++) {
					screen[(j + x)* w + i + y].Attributes = color * 16;
				}
			}
		}
		else
		{
			for (int x(0); x < thinkness; x++) //Adds thinkness to solve broken oval (first for loop controls the upper and lower lines thinkness while seccond controls the sides)
			{
				for (int y(0); y < thinkness; y++) {
					checkHitAndDealDmg(screen, ((j + x)* w + i + y), invincible);
					screen[((j + x)* w + i + y)].Attributes = color * 16;
				}
			}
		}
	}
}

//Draws toriels fire
void drawFireAndAnimate(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 20 * xModify; x++)
		{
			if ((fire1[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{ 
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16; 
			}
		}
	}
}
void drawFireAndAnimate2(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 20 * xModify; x++)
		{
			if ((fire2[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}

//Draws flues
void drawFlyAndAnimate(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 20 * xModify; x++)
		{
			if ((fly1[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}
void drawFlyAndAnimate2(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 20 * xModify; x++)
		{
			if ((fly2[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}

//Draws frog
void drawFrogAndAnimate(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 40 * xModify; x++)
		{
			if ((frog1[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}
void drawFrogAndAnimate2(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 30 * yModify; y++)
	{
		for (int x = 0; x < 50 * xModify; x++)
		{
			if ((frog2[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}

//Draws tears
void drawTears(int posY, int posX, float xModify, float yModify, CHAR_INFO *screen, int &invincible)
{
	for (int y = 0; y < 20 * yModify; y++)
	{
		for (int x = 0; x < 20 * xModify; x++)
		{
			if ((tear[y / (int)yModify][x / (int)xModify] * 16) != 0)
			{
				checkHitAndDealDmg(screen, ((int)posY + y)* w + ((int)posX + x), invincible);
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = 15 * 16;
			}
		}
	}
}

//Gets a random number for the attacks
int getRandom(int maxNumForAttack)
{
	std::mt19937 rand;
	rand.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> random(0, maxNumForAttack);
	return random(rand);
}

//drays the graphics for the damage box
void fightBox(CHAR_INFO *screen)
{
	//Makes box thicker
	for (int i(1301), u(6); i > 0; i--, u--)
	{
		if (u > 0) {
			for (int j = 0; j < 130; j++)
			{
				screen[(j + 148) * w + u + 100].Attributes = 15 * 16;
				screen[(j + 148) * w + u + 1396].Attributes = 15 * 16;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			screen[(j + 275) * w + i + 99].Attributes = 15 * 16;
			screen[(j + 148) * w + i + 99].Attributes = 15 * 16;
		}
	}
	for (int u(20); u > 0; u--) //Draws red bars
	{
		if (u > 0)
		{
			for (int j(53); j > 0; j--)
			{
				screen[(j + 183) * w + u + 200].Attributes = 4 * 16;
				screen[(j + 183) * w + u + 1300].Attributes = 4 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws yellow bars
	{
		if (u > 0)
		{
			for (int j(103); j > 0; j--)
			{
				screen[(j + 157) * w + u + 500].Attributes = 6 * 16;
				screen[(j + 157) * w + u + 1000].Attributes = 6 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws green bars
	{
		if (u > 0)
		{
			for (int j(112); j > 0; j--)
			{
				screen[(j + 154) * w + u + 800].Attributes = 10 * 16;
				screen[(j + 154) * w + u + 700].Attributes = 10 * 16;
			}
		}
	}
	for (int u(20); u > 0; u--) //Draws shiny green bars
	{
		if (u > 0)
		{
			for (int j(112); j > 0; j--)
			{
				screen[(j + 154) * w + u + 780].Attributes = 2 * 16;
				screen[(j + 154) * w + u + 720].Attributes = 2 * 16;
			}
		}
	}
	for (int u(80); u > 0; u--) //Draws shiny green bars cont
	{
		if (u > 0)
		{
			for (int j(10); j > 0; j--)
			{
				screen[(j + 256) * w + u + 720].Attributes = 2 * 16;
				screen[(j + 154) * w + u + 720].Attributes = 2 * 16;
			}
		}
	}

	//Ovals in fight sequence
	drawOval(210, 750, 625, 10, 0.09, 1, 8, (-8), 10, screen);
}

//Updates the hp bar
void drawEnemyDmg(CHAR_INFO *screen)
{
	if (e.getHP() > 0)
	{
		//e.takeDamage(p.getAttack());
		if (e.getHP() < 0)
		{
			e.setHP(0);
		}
		//int moveRight = e.getHP() - e.getMissingHP();
		for (int i = e.getHP() + e.getMissingHP(); i > e.getHP(); i--)
		{
			for (int j = 0; j < 5; j++)
			{
				screen[(j + 120) * w + i + 724].Attributes = 4 * 16;
			}
		}
	}
	else
	{
		for (int i = e.getHP() + e.getMissingHP(); i > 0; i--)
		{
			for (int j = 0; j < 5; j++)
			{
				screen[(j + 120) * w + i + 724].Attributes = 4 * 16;
			}
		}
	}
}

//the overworld
void initOverworld(CHAR_INFO *screen)
{/*
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			backgound[i][j] = 0;
		}
	}*/

	//draw maps
	currentmap = findMap(CurrMapPos[1], CurrMapPos[0]);
	if (currentmap == 14)
	{
		p.setX(250);
	}
	if (CurrMapPos[0] == 11 && CurrMapPos[1] == 10)
	{
			p.setY(315);
			p.setX(25);
	}
	//currentmap = 13;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			//backgound[y][x] = MapList[3][int(y /5.715)][int(x / 9.678)] * 16; 
			backgound[y][x] = MapList[currentmap][int(y / maps[currentmap].hS)][int(x / maps[currentmap].wS)] * 16;

		}
	}

}

//Erases only the box in the fight screen
void eraseWhatIsInBox(CHAR_INFO *screen)
{
	for (int x = 0; x <= 1298; x++)
	{
		for (int y = 0; y <= 123; y++)
		{
			screen[(y + 151) * w + x + 101].Attributes = 0 * 16;
		}
	}
}

//draws the battle screen for the bullet hell
void initBattleSreen(CHAR_INFO *screen)
{

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			backgound[i][j] = 0;
		}
	}

	static int battle[h][w];

	int graphic[4][12][90] = {
		//Fight 
	{
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,8,0,0,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
	},
		//Act 
	{
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8 },
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,8,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
	},
		//Item 
	{
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,8,8,0,0,8,8,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,0,0,8,8,8,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,8,8,0,0,0,8,8,0,0,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,8,8,8,8,8,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
	},
		//Mercy 
	{
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,8,0,0,0,0,0,0,0,8,8,8,8,0,0,0,0,0,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,8,8,8,8,8,8,8,8,8,0,0,8,8,8,0,0,0,0,8,8,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,0,0,0,0,8,8,0,0,0,0,8,8,8,0,0,8,8,8,0,0,0,0,8,8,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,8,8,8,0,0,8,8,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,8,8,8,0,0,8,8,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,8,8,8,8,8,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,8,0,0,8,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,8,8,8,8,0,0,0,0,8,8,0,0,0,0,8,8,8,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,8,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,0,0,0,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,8,8,8,0,0,0,8,8,0,0,0,0,8,8,8,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,0,8,8,0,0,0,8,8,8,8,8,8,8,8,8,8,0,0,0,8,8,8,0,0,0,0,0,8,8,8,0,0,8,8,8,8,8,8,8,8,8,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
	}
	};

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			//make main box
			//vert lines
			if ((x == 1400 || x == 100) && (y >= 150 && y <= 275))
			{
				backgound[y][x] = 15 * 16;
			}
			//horz lines
			if ((x <= 1400 && x >= 100) && (y == 150 || y == 275))
			{
				backgound[y][x] = 15 * 16;
			}

			//selection boxes
			for (int i = 0; i < 4; i++)
			{
				//text
				//this code will be real jank :( sorry - josh
				if ((double(x) / 1 < 178 && double(y) / 4 < 6))
				{
					backgound[y + 330][x + (365 * i) + 125] = graphic[i][y / 2][x / 2] * 8 * 16;
				}
			}
		}

	}
	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{
			screen[y * w + x].Attributes = backgound[y][x];
		}
	}
	drawHealthBars(screen);
}

//Draws healthBars
void drawHealthBars(CHAR_INFO *screen)
{
	//draw players health bar

	for (int i = 0; i < p.getHP(); i++)
	{
		for (int j = 0; j < 15; j++)
		{
			screen[(j + 290) * w + i + 701].Attributes = 6 * 16;
		}
	}
	if (p.getHP() > 0)
	{

		for (int i = 100; i > p.getHP(); i--)
		{
			for (int j = 0; j < 15; j++)
			{
				screen[(j + 290) * w + i + 700].Attributes = 4 * 16;

			}
		}
	}
	//draw enemy health bar
	for (int i = 0; i < e.getHP() + e.getMissingHP(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			screen[(j + 120) * w + i + 725].Attributes = 10 * 16;
		}
	}
}

//draws the background for the bullet hell section
void initEnemyBattle(CHAR_INFO *screen)
{
	for (int x = 0; x < w; x++)
	{

		for (int y = 125; y + 123 < h; y++)
		{
			screen[y * w + x].Attributes = 0 * 16;
		}
	}
	for (int j(0); j < 3; j++)
	{
		for (int i(0); i < 800; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 272) * w + i + 350].Attributes = 15 * 16;
		}
	}
	for (int j(0); j < 135; j++)
	{
		for (int i(0); i < 4; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 140) * w + i + 1150].Attributes = 15 * 16;
		}
	}
}

//resets the background for the bullet hell section
void drawBackground(CHAR_INFO *screen)
{
	for (int j(0); j < 3; j++)
	{
		for (int i(0); i < 800; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 272) * w + i + 350].Attributes = 15 * 16;
		}
	}
	for (int j(0); j < 135; j++)
	{
		for (int i(0); i < 4; i++)
		{
			screen[(j + 140) * w + i + 350].Attributes = 15 * 16;
			screen[(j + 140) * w + i + 1150].Attributes = 15 * 16;
		}
	}
	for (int x = 0; x < 796; x++)
	{

		for (int y = 129; y > 0; y--)
		{
			screen[(y + 142) * w + x + 354].Attributes = 0 * 16;
		}
	}

}

//draws sprite to the screen.
void draw_sprite(CHAR_INFO *screen, double posX, double posY, int spr[17][25])
{
	for (int x = 0; x < 50; x++)
	{

		for (int y = 0; y < 34; y++)
		{

			if ((double(x) / 2 < 50 && double(y) / 2 < 34) && (spr[y / 2][x / 2] >= 0))
			{
				screen[((int)posY + y)* w + ((int)posX + x)].Attributes = spr[y / 2][x / 2] * 16;

			}
		}
	}
}

//draws the heart
void drawHeart(CHAR_INFO *screen, double posX, double posY)
{
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 8; i++)
		{
			screen[(j + int(posX)) * w + i + int(posY)].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 16; i++)
		{
			screen[(j + int(posX) + (-2)) * w + i + int(posY) - 4].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 24; i++)
		{
			screen[(j + int(posX) + -4) * w + i + int(posY) - 8].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 32; i++)
		{
			screen[(j + int(posX) + -6) * w + i + int(posY) - 12].Attributes = 4 * 16;
			screen[(j + int(posX) + -8) * w + i + int(posY) - 12].Attributes = 4 * 16;
		}
	}
	for (int j(0); j < 2; j++)
	{
		for (int i(0); i < 14; i++)
		{
			screen[(j + int(posX) + -10) * w + i + int(posY) - 12].Attributes = 4 * 16;
			screen[(j + int(posX) + -10) * w + i + int(posY) + 6].Attributes = 4 * 16;

		}
	}
	for (int j(0); j < 1; j++)
	{
		for (int i(0); i < 9; i++)
		{
			screen[(j + int(posX) + -11) * w + i + int(posY) - 10].Attributes = 4 * 16;
			screen[(j + int(posX) + -11) * w + i + int(posY) + 9].Attributes = 4 * 16;

		}
	}
	for (int j(0); j < 1; j++)
	{
		for (int i(0); i < 3; i++)
		{
			screen[(j + int(posX) + -12) * w + i + int(posY) - 8].Attributes = 4 * 16;
			screen[(j + int(posX) + -12) * w + i + int(posY) + 13].Attributes = 4 * 16;

		}
	}
	//Dimension box findings and possible hitbox?
	/*for (int j(0); j < 14; j++) {
		for (int i(0); i < 32; i++) {
			screen[int(posX - j + 1) * w + int(posY - 12)].Attributes = 7 * 16; // 1 vertival to get to the bottom
			screen[int(posX - j + 1) * w + int(posY + 20)].Attributes = 7 * 16; // 20 right to get to right side
			screen[int(posX + 1) * w + int(posY + i - 12)].Attributes = 7 * 16; // 12 left to get to left side
			screen[int(posX - 12) * w + int(posY + i - 12)].Attributes = 7 * 16; // 12 up to get to top
		}
	}*/
}

//Checks for hitbox
void checkHitAndDealDmg(CHAR_INFO *screen, int posToCheck, int &invincible)
{

	if (invincible != 0)
	{
		return;
	}
	else if (screen[posToCheck].Attributes == 4 * 16)
	{
		invincible = 10;
		//draw over player health bar
		if (p.getHP() > 0)
		{
			p.takeDmg(e.dealDamage());
			if (p.getHP() < 0)
			{
				p.setHP();
			}

			for (int i = 100; i > p.getHP(); i--)
			{
				for (int j = 0; j < 15; j++)
				{
					screen[(j + 290) * w + i + 700].Attributes = 4 * 16;
				}
			}
		}
		return;
	}
	else
	{
		return;
	}
}

//draws the bullets
void drawBullets(double posX, double posY, int bulletIdentification, CHAR_INFO *screen, int &invincible, int whatToDraw)
{
	//for (int j(0); j < 4; j++)
	//{
		//for (int i(0); i < 6; i++)
		//{
			//checkHitAndDealDmg(screen, bulletIdentification, ((j + int(posY)) * w + i + int(posX)), invincible);
			//screen[(j + int(posY)) * w + i + int(posX)].Attributes = 6 * 16;
		//}
	//}
	switch (whatToDraw)
	{
	case 0:
		drawOvalForBullets(posY, posX, 2, 2, 2, 1, 2, 1, 8, screen, bulletIdentification, invincible);
		break;
	case 1:
		drawFireAndAnimate(posY, posX, 1, 1, screen, invincible);
		break;
	case 2:
		drawFireAndAnimate2(posY, posX, 1, 1, screen, invincible);
		break;
	case 3:
		drawFlyAndAnimate(posY, posX, 1, 1, screen, invincible);
		break;
	case 4:
		drawFlyAndAnimate2(posY, posX, 1, 1, screen, invincible);
		break;
	case 5:
		drawFrogAndAnimate(posY, posX, 1, 1, screen, invincible);
		break;
	case 6:
		drawFrogAndAnimate2(posY, posX, 1, 1, screen, invincible);
		break;
	case 7:
		drawTears(posY, posX, 1, 1, screen, invincible);
		break;
	}
}

//Calls the move bullet function member and the draw bullet function
void drawAndMoveBullets(float frametime, CHAR_INFO *screen, int bulletIdentification, int patternToUse, double initPosX, double initPosY, int &invincible, double *sharedAngle)
{
	double legalAdditionSides;
	double legalAdditionUpDown;
	b[bulletIdentification].moveBullet(e.getAttackID(patternToUse), frametime, bulletIdentification, p2.getX(), p2.getY(), sharedAngle);
	if (b[bulletIdentification].getSpriteToUse() == 1 || b[bulletIdentification].getSpriteToUse() == 2)
	{
		legalAdditionSides = 5;
		legalAdditionUpDown = 4;
	}
	else
	{
		legalAdditionSides = 4;
		legalAdditionUpDown = 4;
	}
	if (b[bulletIdentification].legalBullet(legalAdditionUpDown, legalAdditionUpDown, legalAdditionSides, legalAdditionSides))
	{
		drawBullets(b[bulletIdentification].getX(), b[bulletIdentification].getY(), bulletIdentification, screen, invincible, b[bulletIdentification].getSpriteToUse());
	}
}

//draws the backgound
void draw_backgound(CHAR_INFO *screen)
{
	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{
			screen[y * w + x].Attributes = backgound[y][x];

		}
	}
}

//draws the backgound for battle screen
void draw_battle(CHAR_INFO *screen, int selection)
{

	for (int x = 0; x < w; x++)
	{

		for (int y = 0; y < h; y++)
		{

		

			if (backgound[y][x] != 0)
			{

				//highlights selected button
				if (x <= selection * 365 + 325 && x >= selection * 365 + 75 && y > 300)
				{
					screen[y*w + x].Attributes = 3 * 16;
				}
				//unhighlights things not selected
				else if (y > 300)
				{
					screen[y*w + x].Attributes = 8 * 16;

				}
			}
		}
	}
	//draw monster (it will just be a square for now)
	switch (e.getMonsterID())
	{
	case 0:
		for (int y = 0; y < 18 * 6; y++)
		{
			for (int x = 0; x < 25 * 6; x++)
			{
				if ((napstablook[y / 6][x / 6]) == 7)
				{
					screen[(y + 10)* w + (x + 675)].Attributes = 15 * 16;
				}
			}
		}
		break;
	case 2:
		for (int y = 0; y < 26 * 4; y++)
		{
			for (int x = 0; x < 25 * 4; x++)
			{
				if ((toriel[y / 4][x / 4]) == 7)
				{
					screen[(y + 10)* w + (x + 675)].Attributes = 15 * 16;
				}
				if ((toriel[y / 4][x / 4]) == 9)
				{
					screen[(y + 10)* w + (x + 675)].Attributes = 9 * 16;
				}
				if ((toriel[y / 4][x / 4]) == 5)
				{
					screen[(y + 10)* w + (x + 675)].Attributes = 5 * 16;
				}
			}
		}
		break; 
	case 1:
			for (int y = 0; y < 9 * 8; y++)
			{
				for (int x = 0; x < 20 * 8; x++)
				{
					if ((froggit[y / 8][x / 8]) == 7)
					{
						screen[(y + 10)* w + (x + 675)].Attributes = 15 * 16;
					}
				}
			}
			break;
	case 3:
		for (int y = 0; y < 10 * 8; y++)
		{
			for (int x = 0; x < 24 * 8; x++)
			{
				if ((whimsun[y / 8][x / 8]) == 7)
				{
					screen[(y + 10)* w + (x + 675)].Attributes = 15 * 16;
				}
			}
		}
		break;
	}
}

//puts everything drawn to "Screen" on the screen
void printScreen(HANDLE hconsole, CHAR_INFO *screen, SMALL_RECT c)
{
	screen[w*h - 1].Char.AsciiChar = '\0';
	WriteConsoleOutput(hconsole, screen, { w,h }, { 0,0 }, &c);
}

//main gameloop
void gameloop()
{

	//create buffer
	CHAR_INFO *screen = new CHAR_INFO[w*h];
	HANDLE hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hconsole);
	SMALL_RECT c = { 0,0,w,h };
	for (int i = 0; i < h*w; i++)
	{
		screen[i].Char.AsciiChar = ' ';
	}

	int select = 0;


	auto time = std::chrono::system_clock::now();
	auto oldtime = std::chrono::system_clock::now();
	double posX(1), posY(1);
	initOverworld(screen);
	//just an infinite loop, should probably make it not infinite
	while (true)
	{

		oldtime = time;
		time = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = time - oldtime;
		float frametime = elapsed.count();
		static int btnCooldown = 0;
		static int lastState = 0;
		static int fixUnknownProblem = 0;
		
		playerPos.open("posfile.txt");
		playerPos << p.getX() << " , " << p.getY();
		playerPos.close();

		if (lastState != 2 * gamestate)
		{
			lastState = 2 * gamestate;
			fixUnknownProblem = lastState;
		}

		if (fixUnknownProblem == 0)
		{
			playWalking();
			fixUnknownProblem++;
		}
		if (fixUnknownProblem == 2)
		{
			playFight();
			fixUnknownProblem++;
		}
		if (fixUnknownProblem == 10)
		{
			playVictory();
			fixUnknownProblem++;
		}
		if (fixUnknownProblem == 12)
		{
			playGameOver();
			fixUnknownProblem++;
		}
		if (fixUnknownProblem == 14)
		{
			playMainMenu();
			fixUnknownProblem++;
		}
		
		
		
		if (gamestate == 0)
		{
			if (btnCooldown > 0)
			{
				btnCooldown--;
			}
			if (s.isOverWorld())
			{

				//draw things
				draw_backgound(screen);
				posX = p.getX();
				posY = p.getY();
				draw_sprite(screen, posX, posY, p.sprite[dir]);
				static int numOfStepSinceLastCheck = 0;
				int &pointNumOfStepSinceLastCheck = numOfStepSinceLastCheck;

				dir = p.move(frametime, backgound, pointNumOfStepSinceLastCheck);
				
				
				
				if (currentmap == 1)
				{
					if (posY < 220)
					{
						CurrMapPos[1] = 10;
						CurrMapPos[0] = 10;

						p.setY(70);
						p.setX(90);
						initOverworld(screen);
					}
				}
				
				else if (posY < 25)
				{
					CurrMapPos[1] += 1;
					p.setY(350);
					initOverworld(screen);
				}
				if (posX > 1425)
				{
					CurrMapPos[0] += 1;
					p.setX(100);

					initOverworld(screen);
				}
				if (miniboss == false && CurrMapPos[0] == 7 && CurrMapPos[1] == 4 && posX > 750)

				{
					miniboss = true;
					//do miniboss fight
					gamestate = 1;
					e.setNapstablook();
				}

				if (boss == false && CurrMapPos[0] == 11 && CurrMapPos[1] == 10 && p.getY() < 100)

				{
					boss = true;
					//do miniboss fight
					gamestate = 1;
					e.setToriel();
				}

				//changes gamestate to combat
				if (numOfStepSinceLastCheck % 50 == 0 && numOfStepSinceLastCheck != 0)
				{
					std::mt19937 monsterChance;
					monsterChance.seed(std::random_device()());
					std::uniform_int_distribution<std::mt19937::result_type> random(1, 4); // distribution in range [1, 4] 
					int isMonster = random(monsterChance);
					if (isMonster == 1 || numOfStepSinceLastCheck == 151)
					{
						numOfStepSinceLastCheck = 0;
						gamestate = 1;

						std::mt19937 rand;
						rand.seed(std::random_device()());
						std::uniform_int_distribution<std::mt19937::result_type> random(3, 4); // distribution in range [1, 4] 
						int monsterID = random(rand);
						switch (monsterID)
						{
						case 1:
							e.setNapstablook();
							break;
						case 2:
							e.setToriel();
							break;
						case 3:
							e.setFroggit();
							break;
						case 4:
							e.setWhimsun();
							break;
						}
					}
				}
				if (GetAsyncKeyState((unsigned short) 'C') & 0x8000)
				{
					s.setOverWorldState(1);
				}
			}
			else if (s.isMainOverWorld())
			{

				static int select6 = 0;
				drawOverWorldMenu(screen, select6);

				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					if (select6 == 0)
					{
						btnCooldown = 5;
						s.setOverWorldState(2);
					}
					else if (select6 == 1)
					{
						btnCooldown = 5;
						s.setOverWorldState(3);
					}
				}
				else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0)
				{
					s.setOverWorldState(0);
					select6 = 0;
				}
				if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000 && btnCooldown == 0)
				{
					if (select6 - 1 >= 0)
					{
						btnCooldown = 3;
						select6 -= 1;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_DOWN) & 0x8000 && btnCooldown == 0)
				{
					if (select6 + 1 <= 2)
					{
						btnCooldown = 3;
						select6 += 1;
					}
				}
				
			}

			else if (s.isItemOverWorld())
			{
				static int tempItemStore;
				static int select7 = 0;

				if (select7 >= 0 && select7 <= pi.getItemCount())
				{
				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					btnCooldown = 5;
					tempItemStore = select7;
					select7 = 7;
				}
				else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0)
				{
					draw_backgound(screen);
					draw_sprite(screen, posX, posY, p.sprite[dir]);
					s.setOverWorldState(1);
					select7 = 0;
				}
					if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000 && btnCooldown == 0)
					{
						if (select7 - 1 >= 0)
						{
							btnCooldown = 3;
							select7 -= 1;
						}
					}
					if (GetAsyncKeyState((unsigned short)VK_DOWN) & 0x8000 && btnCooldown == 0)
					{
						if (select7 + 1 < pi.getItemCount())
						{
							btnCooldown = 3;
							select7 += 1;
						}
					}
				}
				else if (select7 >= 7)
				{
					if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
					{
						if (select7 == 7)
						{
							p.itemEffect(pi.getItemIdentification(tempItemStore));
							pi.itemUse(tempItemStore);
							select7 = 0;
							drawOverWorldMenu(screen, 0);
						}
						else if (select7 == 8)
						{
							//Put something here?
							;
						}
						else if (select7 == 9)
						{
							pi.itemDelete(tempItemStore);
							select7 = 0;
						}
					}
					else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0)
					{
						select7 = tempItemStore;
					}
					if (GetAsyncKeyState((unsigned short)VK_LEFT) & 0x8000 && btnCooldown == 0)
					{
						if (select7 - 1 >= 7)
						{
							btnCooldown = 3;
							select7 -= 1;
						}
					}
					if (GetAsyncKeyState((unsigned short)VK_RIGHT) & 0x8000 && btnCooldown == 0)
					{
						if (select7 + 1 <= 9)
						{
							btnCooldown = 3;
							select7 += 1;
						}
					}
				}
				if (s.isItemOverWorld())
				{
					drawItemOptionsOverWorld(screen, select7);
				}
			}

			else if (s.isStats())
			{
				static int allowPause = 0;
				if (allowPause == 0)
				{
					printStats(screen);
					allowPause++;
				}
				else if (allowPause == 3)
				{
					Sleep(3000);
					allowPause = 0;
					s.setOverWorldState(0);
				}
				else
				{
					allowPause++;
				}
			}

		}
		else if (gamestate == 1)
		{
			//changes background to battle screen
			initBattleSreen(screen);
			gamestate = 2;
			s.setState(0);

		}
		else if (gamestate == 2)
		{
			static int btnCooldown = 0;
			//main battle loop	
			if (btnCooldown)
			{
				btnCooldown--;
			}
			draw_battle(screen, select);
			if (s.isMain())
			{
				if (GetAsyncKeyState((unsigned short) VK_LEFT) & 0x8000 && btnCooldown == 0)
				{
					select--;
					if (select < 0)
					{
						select++;
					}
					btnCooldown = 5;
				}
				if (GetAsyncKeyState((unsigned short) VK_RIGHT) & 0x8000 && btnCooldown == 0)
				{
					select++;
					if (select >= 4)
					{
						select--;
					}
					btnCooldown = 5;
				}
				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					btnCooldown = 2;	//can take out later when other things happen after your turn


					switch (select)
					{
					case 0:
						fightBox(screen);
						s.setState(1);
						break;
					case 1:
						//drawOptions(screen, wantedPosX, wantedPosY);
						s.setState(2);
						btnCooldown = 5;
						break;
					case 2:
						s.setState(3);
						btnCooldown = 5;
						break;
					case 3:
						s.setState(4);
						btnCooldown = 5;
					}
				}
			}
			else if (s.isAttack())
			{
				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					btnCooldown = 5;
					s.setState(0);
					e.takeDamage(int(a.determineDamage() * p.getAttack()));
					a.reset();
					initBattleSreen(screen);
					draw_battle(screen, select);
					drawEnemyDmg(screen);
					gamestate = 3;
					if (e.getHP() == 0) 
					{
						gamestate = 5;
					}
					else if (e.getMonsterID() == 3)
					{
						drawWords(screen, 190, 170, 2, 2, "WHIMSUN RAN AWAY CRYING", 4);
						gamestate = 5;
					}
				}
				else if (!a.isDone())
				{
					eraseWhatIsInBox(screen);
					fightBox(screen);
					a.move(frametime);
					a.drawAttackBar(screen, w);
				}
				else
				{
					s.setState(0);
					a.reset();
					btnCooldown = 5;
					initBattleSreen(screen);
					draw_battle(screen, select);
					drawEnemyDmg(screen);
					gamestate = 3;
					if (e.getMonsterID() == 3)
					{
						drawWords(screen, 190, 170, 2, 2, "WHIMSUN RAN AWAY CRYING", 4);

						gamestate = 5;
					}
				}
			}
			else if (s.isItem())
			{
				static int select2 = 0;
				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					if (pi.isValidDuringFights(select2))
					{
						if (pi.getItemIdentification(select2) == 999)
						{
							s.setState(0);
							eraseWhatIsInBox(screen);
							btnCooldown = 3;
							select2 = 0;
						}
						else
						{
							p.itemEffect(pi.getItemIdentification(select2));
							pi.itemUse(select2);
							eraseWhatIsInBox(screen);
							s.setState(0);
							gamestate = 3;
							drawHealthBars(screen);
							select2 = 0;
							if (e.getMonsterID() == 3)
							{
								drawWords(screen, 190, 170, 2, 2, "WHIMSUN RAN AWAY CRYING", 4);

								gamestate = 5;
							}
						}
					}
					btnCooldown = 3;
				}
				else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0)
				{
					s.setState(0);
					eraseWhatIsInBox(screen);
					btnCooldown = 3;
					select2 = 0;
				}
				if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000 && btnCooldown == 0)
				{
					if (select2 - 2 >= 0)
					{
						btnCooldown = 3;
						select2 -= 2;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_DOWN) & 0x8000 && btnCooldown == 0)
				{
					if (select2 + 2 < pi.getItemCount())
					{
						btnCooldown = 3;
						select2 += 2;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_LEFT) & 0x8000 && btnCooldown == 0)
				{
					if (select2 - 1 >= 0)
					{
						btnCooldown = 3;
						select2 -= 1;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_RIGHT) & 0x8000 && btnCooldown == 0)
				{
					if (select2 + 1 < pi.getItemCount())
					{
						btnCooldown = 3;
						select2 += 1;
					}
				}
				if (s.isItem())
				{
					drawItemOptions(screen, select2);
				}
			}
			else if (s.isMercy())
			{


				static int select3 = 0;
				static int buffer2 = 0;

				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0)
				{
					if (select3 == 0)
					{
						if (e.getMercyPoints() == 0)
						{
							buffer2 = 10;
						}
						else
						{
							buffer2 = 30;
							
						}
					}
					else
					{
						std::mt19937 rand;
						rand.seed(std::random_device()());
						std::uniform_int_distribution<std::mt19937::result_type> random(1, e.getRunChance()); // distribution in range 1 to num 
						int monsterRUN = random(rand);
						if (monsterRUN == 1)
						{
							buffer2 = 80;
						}
						else
						{
							buffer2 = 60;
						}
					}
				}
				else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0)
				{
					s.setState(0);
					eraseWhatIsInBox(screen);
					btnCooldown = 3;
					select3 = 0;
				}
				if (GetAsyncKeyState((unsigned short)VK_LEFT) & 0x8000 && btnCooldown == 0)
				{
					if (select3 - 1 >= 0)
					{
						btnCooldown = 3;
						select3 -= 1;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_RIGHT) & 0x8000 && btnCooldown == 0)
				{
					if (select3 + 1 <= 1)
					{
						btnCooldown = 3;
						select3 += 1;
					}
				}
				if (s.isMercy() && buffer2 == 0)
				{
					drawMercyOptions(screen, select3);
				}
				if (buffer2 == 1)
				{
					if (e.getMercyPoints() == 0)
					{
						initOverworld(screen);
						gamestate = 0;
						s.setState(0);
						buffer2--;
					}
				}
				if (buffer2 > 1  && buffer2 < 20)
				{
					eraseWhatIsInBox(screen);
					buffer2--;
					drawWords(screen, 190, 170, 2, 2, "*YOU SUCCESSFULLY SPARED", 8);
				}
				if (buffer2 == 20)
				{
					s.setState(0);
					eraseWhatIsInBox(screen);
					gamestate = 3;
					buffer2 = 0;
				}
				if (buffer2 > 20 && buffer2 < 50)
				{
					eraseWhatIsInBox(screen);
					buffer2--;
					drawWords(screen, 190, 170, 2, 2, "*SPARE FAILED!", 8);
				}
				if (buffer2 == 50)
				{
					s.setState(0);
					eraseWhatIsInBox(screen);
					gamestate = 3;
					buffer2 = 0;
				}
				if (buffer2 > 50 && buffer2 < 70)
				{
					eraseWhatIsInBox(screen);
					buffer2--;
					drawWords(screen, 190, 170, 2, 2, "*YOU TRIPED TRYING TO RUN", 8);
				}
				if (buffer2 == 70)
				{
					initOverworld(screen);
					gamestate = 0;
					s.setState(0);
					select3 = 0;
					buffer2 = 0;
				}
				if (buffer2 > 70)
				{
					eraseWhatIsInBox(screen);
					buffer2--;
					drawWords(screen, 190, 170, 2, 2, "*YOU RAN AWAY  COWARD!", 8);
				}
			}
			else if (s.isAct())
			{
				static int buffer = 0;
				static int select4 = 0;

				if ((GetAsyncKeyState((unsigned short) 'Z') & 0x8000) && btnCooldown == 0 && buffer == 0)
				{
					btnCooldown = 5;
					buffer = 20;
				}
				else if ((GetAsyncKeyState((unsigned short) 'X') & 0x8000) && btnCooldown == 0 && buffer == 0)
				{
					s.setState(0);
					eraseWhatIsInBox(screen);
					btnCooldown = 3;
					select4 = 0;
				}
				if (GetAsyncKeyState((unsigned short)VK_UP) & 0x8000 && btnCooldown == 0 && buffer == 0)
				{
					if (select4 - 2 >= 0)
					{
						btnCooldown = 3;
						select4 -= 2;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_DOWN) & 0x8000 && btnCooldown == 0 && buffer == 0)
				{
					if (select4 + 2 < 4)
					{
						btnCooldown = 3;
						select4 += 2;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_LEFT) & 0x8000 && btnCooldown == 0 && buffer == 0)
				{
					if (select4 - 1 >= 0)
					{
						btnCooldown = 3;
						select4 -= 1;
					}
				}
				if (GetAsyncKeyState((unsigned short)VK_RIGHT) & 0x8000 && btnCooldown == 0 && buffer == 0)
				{
					if (select4 + 1 <= 3)
					{
						btnCooldown = 3;
						select4 += 1;
					}
				}
				if (s.isAct() && buffer == 0)
				{
					drawActOptions(screen, select4);
				}
				if (buffer > 0)
				{
					buffer--;
					if (e.isLowersMercyPoints(select4))
					{
						e.lowerMercyPoints();
					}
					if (buffer >= 1)
					{
						eraseWhatIsInBox(screen);
						drawWords(screen, 190, 170, 2, 2, e.getResponce(select4), 8);
					}
					if (buffer == 1)
					{
						s.setState(0);
						eraseWhatIsInBox(screen);
						gamestate = 3;
						drawHealthBars(screen);
						buffer = 0;
						select4 = 0;
						if (e.getMonsterID() == 3)
						{
							drawWords(screen, 190, 170, 2, 2, "WHIMSUN RAN AWAY CRYING", 4);

							gamestate = 5;
						}
					}
				}
			}
		}
		else if (gamestate == 3) 
		{
			initEnemyBattle(screen);
			gamestate = 4;
		}
		else if (gamestate == 4)
		{
			static int legalBullets = 0;
			static int invincible = 0;
			static int duration = 0;
			drawBackground(screen);
			int pos2X = p2.getX();
			int pos2Y = p2.getY();
			//Works invincibility and "animation" for it
			if (invincible > 0)
			{
				invincible--;
				if (invincible % 2 == 0)
				{
					drawHeart(screen, pos2X, pos2Y);
				}
			}
			else
			{
				drawHeart(screen, pos2X, pos2Y);
			}
			
			
			static int attackNumber = 0;
			int maxNumForAttack;
			switch(e.getMonsterID())
			{
			case 0:
				maxNumForAttack = 1;
				break;
			case 1:
				maxNumForAttack = 1;
				break;
			case 2:
				maxNumForAttack = 3;
				break;
			case 3:
				maxNumForAttack = 0;
				break;
			}
			if (duration == 0)
			{
				attackNumber = getRandom(maxNumForAttack);
			}
			
			p2.invertedMove(frametime);
			//Spawns the bullet with it's pattern

			//Special, for attacks that initialize more then one bullet at once

			if (e.getAttackID(attackNumber) == 4 || e.getAttackID(attackNumber) == 5 || e.getAttackID(attackNumber) == 7)
			{
				for (int x = 0; x < e.getAmountOfBullets(); x++)
				{
					if (b->ifTimeIsAppear(duration, x))
					{
						b[legalBullets].initbullets(legalBullets, e.getAttackID(attackNumber), p2.getX(), p2.getY(), frametime);
						legalBullets++;
					}
				}
			}
			//Normal attacks 
			else if (b->ifTimeIsAppear(duration, legalBullets))
			{
				b[legalBullets].initbullets(legalBullets, e.getAttackID(attackNumber), p2.getX(), p2.getY(), frametime);
				legalBullets++;
			}
			static double sharedAngles = 0;
			double* sharedAngle = &sharedAngles;
			//Checks if bullets are legal (exist and in bounds) if so draws and moves them
			//I will add the different bullet sprites later
			if (duration >= 1)
			{
				for (int x = 0; x < legalBullets; x++)
				{
					if (b[x].legalBullet(4, 4, 7, 10))
					{
						drawAndMoveBullets(frametime, screen, x, attackNumber, 1, 1, invincible, sharedAngle);
					}
				}
			}




			duration++;
			if (p.getHP() == 0)
			{
				gamestate = 6;
			}
			if (duration >= 130 && gamestate != 6)
			{
				gamestate = 1;
				duration = 0;
				if (e.getAttackID(attackNumber) == 2 || e.getAttackID(attackNumber) == 3)
				{
					b->resetBullets();
				}
				legalBullets = 0;
				initBattleSreen(screen);
				gamestate = 2;
				s.setState(0);
				drawEnemyDmg(screen);
				p2.reset();

			}
		}
		else if (gamestate == 5) 
		{
			static int WHY = 1;
			if (WHY > 0)
			{
				initBattleSreen(screen);
				drawEnemyDmg(screen);
				WHY--;
				if (e.getMonsterID() == 3 && e.getHP() > 0)
				{
					drawWords(screen, 190, 170, 2, 2, "WHIMSUN RAN AWAY CRYING", 4);
				}
			}
			else if (WHY == 0)
			{
				Sleep(4000); //Uses milliseconds
				gamestate = 0;
				initOverworld(screen);
				WHY = 1;
			}
		}
		else if (gamestate == 6)
		{
			for (int j = 0; j < w; j++)
			{
				for (int i = 0; i < h; i++)
				{
					screen[i * w + j].Attributes = 0;
				}
			}
			drawWords(screen, 120, 80, 8, 4, "GAME OVER", 15);
			drawWords(screen, 120, 140, 6, 3, "YOU SUCK!", 15);
		}
		else if (gamestate == 7)
		{
			static int titlllllllllllllllllllllllle = 0;
			if (titlllllllllllllllllllllllle == 0)
			{
				for (int x = 0; x < w; x++)
				{
					for (int y = 0; y < h; y++)
					{
						screen[y * w + x].Attributes = 0 * 16;
					}
				}
				for (int x = 0; x < 150 * 10; x++)
				{
					for (int y = 0; y < 38 * 10; y++)
					{
						screen[y * w + x].Attributes = titleScreen[y / 10][x / 10] * 16;
					}
				}
				titlllllllllllllllllllllllle++;
			}
			if(GetAsyncKeyState((unsigned short) 'Z'))
			{
				gamestate = 0;
			}
		}



		printScreen(hconsole, screen, c);

	}
}


int main()
{
	//gamestate = 1;
	//change font size
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	font.nFont = 0;
	font.dwFontSize.X = 2;
	font.dwFontSize.Y = 2;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &font);

	//Adding to test items
	//This is what will be used when picking up an item in the overworld
	
	pi.itemStore(4);
	pi.itemStore(3);
	pi.itemStore(1);
	pi.itemStore(4);
	pi.itemStore(3);
	pi.itemStore(1);
	pi.itemStore(4);
	pi.itemStore(3);
	pi.itemStore(1);


	//make maps cuz why not 
maps[0].setvalues(0, -1, 0, 9.678, 5.715);
	maps[1].setvalues(6, 8, 1, 5, 3.390);
	maps[2].setvalues(1, 1, 2, 5.715, 5.715);
	maps[3].setvalues(4, 8, 3, 5.715, 5.715);
	maps[4].setvalues(10, 11, 4, 3, 1.5);
	maps[5].setvalues(5, 9, 5, 3, 3);
	maps[6].setvalues(7, 9, 6, 5.715, 5.715);
	maps[7].setvalues(1, 0, 7, 3, 2.5);
	maps[8].setvalues(0, 0, 8, 3, 3);
	maps[9].setvalues(4, 4, 9, 9.6, 7);
	maps[10].setvalues(6, 9, 10, 3.8, 2.6);
	maps[11].setvalues(6, 9, 11, 3, 4);
	maps[12].setvalues(7, 7, 12, 3.5, 3.5);
	maps[13].setvalues(10, 10, 13, 3, 4);
	maps[14].setvalues(5, 7, 14, 3.8, 4.5);
	maps[15].setvalues(4, 7, 15, 9.678, 5.715);
	maps[16].setvalues(2, 0, 16, 5, 5);
	maps[17].setvalues(3, 0, 17, 5.715, 5.715);
	maps[18].setvalues(4, 0, 18, 9.678, 7.5);
	maps[19].setvalues(4, 1, 19, 9.6, 7.5);
	//maps[20].setvalues(4, 2, 20, 1, 1);
	//maps[21].setvalues(5, 2, 21, 1, 1);
	maps[22].setvalues(4, 2, 22, 9.6, 6);
	maps[23].setvalues(4, 3, 23, 9.6, 8);
	maps[24].setvalues(6, 7, 24, 5.715, 5.715);
	maps[25].setvalues(13, 11, 25, 5.715, 5.715);
	maps[26].setvalues(12, 11, 26, 5.715, 5.715);
	maps[27].setvalues(11, 11, 27, 5.715, 5.715);
	maps[28].setvalues(1, 1, 28, 5.715, 5.715);
	maps[29].setvalues(5, 8, 29, 5.715, 5.715);
	maps[30].setvalues(1, 1, 30, 5.715, 5.715);
	maps[31].setvalues(1, 1, 31, 5.715, 5.715);
	maps[32].setvalues(4, 5, 32, 9.6, 7);
	maps[33].setvalues(4, 6, 33, 9.6, 7);


	//p.setX(400);
	currentmap = 0;
	CurrMapPos[0] = 0;
	CurrMapPos[1] = 0;



	gameloop();


	//time for modifiers

	system("pause");
	return 0;
}