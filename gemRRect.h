#pragma once
#include "Gem.h"
class gemRRect : public Gem
{
	//PRIVATE MEMBERS
private:
	float width;
	float height;
	float radius;

	//CONSTRUCTORS
public:
	gemRRect();
	gemRRect(float width, float height, float radius, float sx, float sy, float* c, char s);

	//PUBLIC METHODS
public:
	void setWidth(int w);
	int getWidth() const;
	void setHeight(int h);
	int getHeight() const;
	void drawGem(int x, int y) override;

public:
	//DESTRUCTOR
	~gemRRect();
};