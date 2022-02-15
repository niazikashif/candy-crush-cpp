#include "gemRect.h"

//CONSTRUCTORS

gemRect::gemRect() : Gem()
{
	width = 0;
	height = 0;
}

gemRect::gemRect(int width, int height, float sx, float sy, float *c, char s) : Gem(sx, sy, c, s)
{
	this->width = width;
	this->height = height;
}

//PUBLIC METHODS

void gemRect::setWidth(int w)
{
	width = w;
}

int gemRect::getWidth() const
{
	return width;
}

void gemRect::setHeight(int h)
{
	height = h;
}

int gemRect::getHeight() const
{
	return height;
}

void gemRect::drawGem(int x, int y)
{
	setXnc(sx + x);
	setYnc(sy + y);
	DrawRectangle(sx + x, sy + y, width, height, color);
	DrawString(sx + x, sy + y, "~~~~", colors[RED]);
	DrawString(sx + x, sy + y + 30, "~~~~", colors[RED]);
	DrawLine(sx + x, sy + y + 19, sx + x + 12, sy + y + 19, 5, colors[ORANGE]);
	DrawCircle(sx + x + 20, sy + y + 20, 5, colors[RED]);
	DrawLine(sx + x + 27, sy + y + 19, sx + x + 39, sy + y + 19, 5, colors[ORANGE]);
}

//DESTRUCTOR

gemRect::~gemRect()
{
}