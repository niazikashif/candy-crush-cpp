#pragma once
#include "Gem.h"
class gemRect : public Gem
{
	//PRIVATE MEMBERS
private:
	int width;
	int height;

	//CONSTRUCTORS
public:
	gemRect();
	gemRect(int width, int height, float sx, float sy, float *c, char s);

	//PUBLIC METHODS
public:
	void setWidth(int w);
	int getWidth() const;
	void setHeight(int h);
	int getHeight() const;
	void drawGem(int x, int y) override;

public:
	//DESTRUCTOR
	~gemRect();
};