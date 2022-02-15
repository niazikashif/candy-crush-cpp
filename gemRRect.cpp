#include "gemRRect.h"

//CONSTRUCTORS

gemRRect::gemRRect() : Gem()
{
	width = 0.00f;
	height = 0.00f;
	radius = 0.00f;
}

gemRRect::gemRRect(float width, float height, float radius, float sx, float sy, float *c, char s) : Gem(sx, sy, c, s)
{
	this->width = width;
	this->height = height;
	this->radius = radius;
}

//PUBLIC METHODS

void gemRRect::setWidth(int w)
{
	width = w;
}

int gemRRect::getWidth() const
{
	return width;
}

void gemRRect::setHeight(int h)
{
	height = h;
}

int gemRRect::getHeight() const
{
	return height;
}

void gemRRect::drawGem(int x, int y)
{
	setXnc(sx + x);
	setYnc(sy + y);
	DrawRoundRect(cx, cy, width, height, color, radius);
	DrawRoundRect(cx + 5, cy + 20, width - 5, 10, colors[RED], 5);
	DrawRoundRect(cx + 5, cy + 5, width - 5, 8, colors[DARK_BLUE], 5);
	DrawRoundRect(cx + 5, cy - 10, width - 5, 10, colors[DARK_GREEN], 5);
}

//DESTRUCTOR

gemRRect::~gemRRect()
{
}