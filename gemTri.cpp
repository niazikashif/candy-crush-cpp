#include "gemTri.h"

//CONSTRUCTORS
gemTri::gemTri() : Gem()
{
}

gemTri::gemTri(float sx, float sy, float *c, char s) : Gem(sx, sy, c, s)
{
}
//PUBLIC METHODS
void gemTri::drawGem(int x, int y)
{
	setXnc(sx + x - 2);
	setYnc(sy + y + 30);
	DrawTriangle(cx, cy, cx + 46, cy, cx + 22, cy - 30, color);
	DrawRoundRect(cx, cy - 5, 45, 10, colors[WHITE], 5);
	DrawString(cx, cy - 10, "******", colors[DARK_BLUE]);
}

//DESTRUCTOR
gemTri::~gemTri()
{
}