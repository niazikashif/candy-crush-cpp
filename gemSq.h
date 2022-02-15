#pragma once
#include "Gem.h"
class gemSq : public Gem
{
	//PRIVATE MEMBERS
private:
	int size;

	//CONSTRUCTORS
public:
	gemSq();
	gemSq(int size, float sx, float sy, float *c, char s);

	//PUBLIC METHODS
public:
	void setSize(int sz);
	int getSize() const;
	void drawGem(int x, int y) override;

public:
	//DESTRUCTOR
	~gemSq();
};