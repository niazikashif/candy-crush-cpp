#pragma once
#include "Gem.h"
class gemCir : public Gem
{
	//PRIVATE MEMBERS
private:
	float radius;

	//CONSTRUCTORS
public:
	gemCir();
	gemCir(float radius, float sx, float sy, float *c, char s);

	//PUBLIC METHODS
public:
	void setRad(float rad);
	float getRad() const;
	void drawGem(int x, int y) override;

public:
	//DESTRUCTOR
	~gemCir();
};