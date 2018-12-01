#pragma once
#ifndef MAP_H
#define MAP_H

class Map
{
public:
	void setvalues(int, int, int , double, double);

	//public vars
	double wS;
	double hS; //stetchers

	int Graphic;
	int iD[2];
private:
	
};

void Map::setvalues(int IDx, int IDy,int graphic, double widthStretch, double heightStretch)
{
	iD[0] = IDy;
	iD[1] = IDx;

	Graphic = graphic;

	wS = widthStretch;
	hS = heightStretch;

}


#endif // !MAP_H
