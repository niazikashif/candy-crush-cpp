#include "gemCir.h"

//CONSTRUCTORS

gemCir::gemCir() : Gem()
{
}

gemCir::gemCir(float radius, float sx, float sy, float *c, char s) : Gem(sx, sy, c, s)
{
	this->radius = radius;
}

//PUBLIC METHODS
void gemCir::setRad(float rad)
{
	radius = rad;
}

float gemCir::getRad() const
{
	return radius;
}

void gemCir::drawGem(int x, int y)
{
	setXnc(sx + x + 20);
	setYnc(sy + y + 20);
	DrawCircle(sx + x + 20, sy + y + 20, radius, color);
	DrawLine(sx + x + 2, sy + y + 10, sx + x + 35, sy + y + 30, 3, colors[WHITE]);
	DrawLine(sx + x + 35, sy + y + 10, sx + x + 25, sy + y + 40, 3, colors[WHITE]);
	DrawCircle(sx + x + 10, sy + y + 30, 5, colors[DARK_BLUE]);
	DrawCircle(sx + x + 20, sy + y + 10, 5, colors[DARK_BLUE]);
}

//DESTRUCTOR
gemCir::~gemCir()
{
}