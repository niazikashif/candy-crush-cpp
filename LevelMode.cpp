#include "LevelMode.h"

LevelMode::LevelMode() : Level()
{
	isTrialed = false;
	isNormal = false;
	Time = 60;
	Lives = 3;
	pMode = NoMode;
}

//int LevelMode::Time;

LevelMode::LevelMode(bool isTrialed, bool isNormal, int Time, int Lives, Mode pMode, int LevelNum, int score, int goalScore, bool isOver) : Level(LevelNum, score, goalScore, isOver)
{
	this->isTrialed = isTrialed;
	this->isNormal = isNormal;
	this->Time = Time;
	this->Lives = Lives;
	this->pMode = pMode;
}

void LevelMode::setLevelMode(Mode mode)
{
	if (mode == Normal)
		isNormal = true;
	else if (mode == Trialed)
	{
		if (getScore() == 0)
			setScore(getgScore() / 2);
		else
			setScore(getScore());
		isTrialed = true;
	}
	else if (mode == NoMode)
	{
		isNormal = 0;
		isTrialed = 0;
	}
}

enum LevelMode::Mode LevelMode::getLevelMode()
{
	if (isNormal)
		return Normal;
	else if (isTrialed)
		return Trialed;
	else
		return NoMode;
}

void LevelMode::setPrevMode(Mode prevmode)
{
	pMode = prevmode;
}

enum LevelMode::Mode LevelMode::getPrevMode()
{
	return pMode;
}

void LevelMode::setTimer(int t)
{
	Time = t;
}

int LevelMode::getTimer() const
{
	return Time;
}

int LevelMode::TimerIn(int It)
{
	return Time = 60 * It;
}

void LevelMode::TimerDec()
{
	Time--;
}

void LevelMode::DisplayTimerandLife()
{
	/////////////////////////////////////////////////////////////////////////
	//////// Timer and Lives /////////
	DrawString(510, 620, to_string(getTimer()), colors[WHITE]);
	DrawString(40, 540, "Lives :", colors[WHITE]);
	DrawString(120, 540, to_string(getLives()), colors[WHITE]);
}

void LevelMode::setLives(int l)
{
	Lives = l;
}

int LevelMode::getLives()
{
	return Lives;
}

void LevelMode::LivesIn()
{
	Lives++;
}

void LevelMode::LivesDe()
{
	if (getTimer() <= 0)
	{
		Lives--;
		TimerIn(getLevelN());
		setScore(getgScore() / 2);
	}
	if (getScore() <= 0)
	{
		Lives--;
		TimerIn(getLevelN());
		setScore(getgScore() / 2);
	}
}

LevelMode::~LevelMode()
{
}