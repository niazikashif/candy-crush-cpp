#pragma once
#include "Gem.h"
class gemTri : public Gem
{
	//CONSTRUCTORS
public:
	gemTri();
	gemTri(float sx, float sy, float *c, char s);

	//PUBLIC METHODS
public:
	void drawGem(int x, int y) override;

public:
	//DESTRUCTOR
	~gemTri();
};