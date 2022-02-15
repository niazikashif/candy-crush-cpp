#include "gemSq.h"

//CONSTRUCTORS
gemSq::gemSq() : Gem()
{
	size = 0;
}

gemSq::gemSq(int size, float sx, float sy, float *c, char s) : Gem(sx, sy, c, s)
{
	this->size = size;
}

//PUBLIC METHODS
void gemSq::setSize(int sz)
{
	size = sz;
}

int gemSq::getSize() const
{
	return size;
}

void gemSq::drawGem(int x, int y)
{
	setXnc(sx + x);
	setYnc(sy + y);
	DrawSquare(cx, cy, 40, color);
	DrawString(cx, cy + 20, "|||||||||", colors[BLACK]);
	DrawCircle(cx + 5, cy + 5, 5, colors[INDIGO]);
	DrawCircle(cx + 15, cy + 5, 5, colors[INDIGO]);
	DrawCircle(cx + 25, cy + 5, 5, colors[INDIGO]);
	DrawCircle(cx + 35, cy + 5, 5, colors[INDIGO]);
}

//DESTRUCTOR
gemSq::~gemSq()
{
}