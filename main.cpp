
#include "Include and globals.h" 






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

//Oval Bullets
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
					checkHitAndDealDmg(screen, bulletIdentification, ((j + x)* w + i + y), invincible);
					screen[((j + x)* w + i + y)].Attributes = color * 16;
				}
			}
		}
	}
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

	//candy room 
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			backgound[y][x] = candyRoom[int(y / 5.715)][int(x / 9.678)] * 16;
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

	int graphic[4][15] = {
		{ 1,1,1,1,1,0,1,0,1,0,1,1,1,1,1 },
		{ 0,0,1,0,0,0,0,1,0,0,0,0,1,0,0 },
		{ 0,0,1,0,0,0,1,0,1,0,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0,0,1,0,0,1,0,0 }
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
				//verticle
				if ((x == 365 * i + 100 || x == 365 * i + 300) && (y >= 325 && y <= 375))
				{
					backgound[y][x] = 8 * 16;
				}
				//Horizontal
				if ((x >= 365 * i + 100 && x <= 365 * i + 300) && (y == 325 || y == 375))
				{
					backgound[y][x] = 8 * 16;
				}
				//text
				//this code will be real jank :( sorry - josh
				if ((double(x) / 10 < 15 && double(y) / 10 < 4))
				{
					backgound[y + 330][x + (365 * i) + 125] = graphic[y / 10][x / 10] * 8 * 16;
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
void checkHitAndDealDmg(CHAR_INFO *screen, int bulletIdentification, int posToCheck, int &invincible)
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
void drawBullets(double posX, double posY, int bulletIdentification, CHAR_INFO *screen, int &invincible)
{
	//for (int j(0); j < 4; j++)
	//{
		//for (int i(0); i < 6; i++)
		//{
			//checkHitAndDealDmg(screen, bulletIdentification, ((j + int(posY)) * w + i + int(posX)), invincible);
			//screen[(j + int(posY)) * w + i + int(posX)].Attributes = 6 * 16;
		//}
	//}
	drawOvalForBullets(posY, posX, 2, 2, 2, 1, 2, 1, 8, screen, bulletIdentification, invincible);
}

//Calls the move bullet function member and the draw bullet function
void drawAndMoveBullets(float frametime, CHAR_INFO *screen, int bulletIdentification, int patternToUse, double initPosX, double initPosY, int &invincible)
{
	b[bulletIdentification].moveBullet(patternToUse, frametime);
	if (b[bulletIdentification].legalBullet(4, 4, 0, 0))
	{
		drawBullets(b[bulletIdentification].getX(), b[bulletIdentification].getY(), bulletIdentification, screen, invincible);
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

			//draw monster (it will just be a square for now)
			if (x > 675 && x < 825 && y > 10 && y < 100)
			{
				screen[y*w + x].Attributes = 15 * 16;
			}

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
	/* //For testing purposes if not wanted to start in the overworld
	static int test = 0;
	if (test == 0) {
		e.setFroggit();
		test++;
	}
	*/



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

		if (gamestate == 0)
		{
			//draw things
			draw_backgound(screen);
			posX = p.getX();
			posY = p.getY();
			draw_sprite(screen, posX, posY, p.sprite[dir]);




			dir = p.move(frametime, backgound);


			//changes gamestate to combat
			if (posY >= 350)
			{
				gamestate = 1;

				std::mt19937 rand;
				rand.seed(std::random_device()());
				std::uniform_int_distribution<std::mt19937::result_type> random(1, 4); // distribution in range [1, 4] 
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
						p.setX(0);
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
					p.setX(0);
					select3 = 0;
					buffer2--;
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
			static int toMove[999] = { 0 };
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
			
			

			
			
			p2.invertedMove(frametime);

			

			if (duration % 2 == 1)
			{
				b[legalBullets].setXY(750, 180);
				b[legalBullets].setGoal(p2.getX(), p2.getY());
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}
			if ((duration + 1) % 2 == 1)
			{
				b[legalBullets].setXY(600, 180);
				b[legalBullets].setGoal(p2.getX() + 30, p2.getY() - 30);
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}
			if ((duration + 300) % 2 == 1)
			{
				b[legalBullets].setXY(850, 220);
				b[legalBullets].setGoal(p2.getX() - 30, p2.getY() + 30);
				b[legalBullets].calculateSpeed(15);
				legalBullets++;
			}



			if (duration >= 1)
			{
				for (int x = 0; x < legalBullets; x++)
				{
					if (b[x].legalBullet(4, 4, 7, 10))
					{
						drawAndMoveBullets(frametime, screen, x, 0, 1, 1, invincible);
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
			}
			else if (WHY == 0)
			{
				Sleep(2000); //Uses milliseconds
				gamestate = 0;
				initOverworld(screen);
				p.setX(0);
				p.setY(0);
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
	pi.itemStore(4);
	//pi.itemStore(3);
	//pi.itemStore(1);

	gameloop();


	//time for modifiers

	system("pause");
	return 0;
}