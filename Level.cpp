#include "Level.h"

Level::Level()
{
	LevelNum = 1;
	score = 0;
	goalScore = 100;
	isOver = false;
}

Level::Level(int LevelNum, int score, int goalScore, bool isOver)
{
	this->LevelNum = LevelNum;
	this->score = score;
	this->goalScore = goalScore;
	this->isOver = isOver;
}

void Level::setLevelN(int l_Num)
{
	LevelNum = l_Num;
}

int Level::getLevelN() const
{
	return LevelNum;
}

void Level::setScore(int s)
{
	score = s;
}

int Level::getScore() const
{
	return score;
}

void Level::setgScore(int gS)
{
	goalScore = gS;
}

void Level::ingScore(int IgS)
{
	goalScore += IgS;
}

int Level::getgScore() const
{
	return goalScore;
}

void Level::InLevelN()
{
	LevelNum++;
}

bool Level::InScore(int Is)
{
	if (Is > 0)
	{
		if (Is < 4)
			score += 3;
		else if (Is == 4)
		{
			score += 3 * 3;
		}
		else if (Is > 4)
		{
			score += 3 * 5;
		}
		return 1;
	}

	return 0;
}

void Level::DeScore(int Ds)
{
	score -= Ds;
	if (score < 0)
	{
		score = 0;
	}
}

void Level::DisplayCurrLevelStat() const
{

	//////////////////////////////////////////////////////////////////////////
	//// Level Stats ////
	DrawString(40, 580, "Level :", colors[WHITE]);
	DrawString(120, 580, to_string(getLevelN()), colors[WHITE]);
	DrawString(870, 580, "Score :", colors[WHITE]);
	DrawString(950, 580, to_string(getScore()), colors[WHITE]);
	DrawString(870, 620, "Target :", colors[WHITE]);
	DrawString(950, 620, to_string(getgScore()), colors[WHITE]);

	//////////////////////////////////////////////////////////////////////////
	//// Progress Bar ////
	int increase = score * 480 / getgScore();
	DrawLine(930, 70, 930, 550, 300, colors[GRAY]);
	DrawLine(924, 70, 924, 550, 2, colors[WHITE]);
	DrawLine(924, 550, 935, 550, 2, colors[WHITE]);
	DrawLine(935, 70, 935, 550, 2, colors[WHITE]);
	DrawLine(924, 70, 935, 70, 2, colors[WHITE]);
	if (getScore() <= getgScore() / 2.8)
	{
		DrawLine(930, 70, 930, 70 + increase, 300, colors[YELLOW_GREEN]);
	}
	else if (getScore() <= getgScore() / 1.3)
	{
		DrawLine(930, 70, 930, 70 + increase, 300, colors[GREEN]);
	}
	else if (getScore() > getgScore() / 1.3)
	{
		DrawLine(930, 70, 930, 70 + increase, 300, colors[RED]);
	}
	//////////////////////////////////////////////////////////////////////////
}

void Level::DisplayLevelFinalStat() const
{
	//////////////////////////////////////////////////////////////////////////
	//// Final Stats ////
	DrawString(300, 520, "Level : ", colors[WHITE]);
	DrawString(380, 520, to_string(getLevelN()), colors[WHITE]);
	DrawString(300, 480, "Score : ", colors[WHITE]);
	DrawString(380, 480, to_string(getScore()), colors[WHITE]);
	//////////////////////////////////////////////////////////////////////////
}

void Level::LevelOver(int over)
{
	if (over)
		isOver = 1;
	else
		isOver = 0;
}

bool Level::isLevelOver() const
{
	return isOver;
}

Level::~Level()
{
}