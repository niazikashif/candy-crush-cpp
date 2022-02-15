#include "Gem.h"

//CONSTRUCTORS

Gem::Gem()
{
	sx = 0.00f;
	sy = 0.00f;
	cx = 0.00f;
	cy = 0.00f;
	color = nullptr;
	shape = ' ';
}

Gem::Gem(float sx, float sy, float *c, char s)
{
	this->sx = sx;
	this->sy = sy;
	this->cx = 0;
	this->cy = 0;
	color = c;
	shape = s;
}

// PUBLIC METHODS

void Gem::setXc(float x) //set X co-ordinates of Gem
{
	sx = x;
}

float Gem::getXc() const //get X co-ordinates of Gem
{
	return sx;
}

void Gem::setYc(float y) //set  Y co-ordinates of Gem
{
	sy = y;
}

float Gem::getYc() const //get Y co-ordinates of Gem
{
	return sy;
}

void Gem::setXnc(float x)
{
	cx = x;
}

int Gem::getXnc() const
{
	return cx;
}

void Gem::setYnc(float y)
{
	cy = y;
}

int Gem::getYnc() const
{
	return cy;
}

void Gem::setcolor(float *c) //set Color of Gem
{
	color = c;
}

float *Gem::getcolor() const //get Color of Gem
{
	return color;
}

void Gem::setshape(char s) //set Shape of Gem
{
	shape = s;
}

char Gem::getshape() //get Shape of Gem
{
	return shape;
}

void Gem::drawGem(int x, int y)
{
}

// DESTRUCTOR
Gem::~Gem()
{
}