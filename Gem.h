#pragma once
#include "util.h"
class Gem
{
	//PROTECTED MEMBERS
protected:
	float sx;
	float sy;
	float cx;
	float cy;
	float *color;
	char shape;

	//CONSTRUCTORS
public:
	Gem();
	Gem(float sx, float sy, float *c, char s);

	//PUBLIC METHODS
public:
	void setXc(float x);					//set X co-ordinates of Gem
	float getXc() const;					//get X co-ordinates of Gem
	void setYc(float y);					//set Y co-ordinates of Gem
	float getYc() const;					//get Y co-ordinates of Gem
	void setXnc(float x);					//set new X co-ordinates of Gem
	int getXnc() const;						//get new X co-ordinates of Gem
	void setYnc(float y);					//set new Y co-ordinates of Gem
	int getYnc() const;						//get new Y co-ordinates of Gem
	void setcolor(float *c);				//set Color of Gem
	float *getcolor() const;				//get Color of Gem
	void setshape(char s);					//set Shape of Gem
	char getshape();						//get Shape of Gem
	virtual void drawGem(int x, int y) = 0; //Draw Gems //pure virtual function

	//DESTRUCTORS
public:
	virtual ~Gem();
};