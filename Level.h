#pragma once
#include <thread>
#include "util.h"
class Level
{
	//PROTECTED MEMBERS
protected:
	int LevelNum;
	int score;
	int goalScore;
	bool isOver;

	//CONSTRUCTORS
public:
	Level();
	Level(int LevelNum, int score, int goalScore, bool isOver);

	//METHODS
public:
	void setLevelN(int l_Num); //set Level Number
	void InLevelN();		   //increment Level Number
	int getLevelN() const;	   //get Level Number
	void setScore(int s);	   //set Score
	bool InScore(int Is);	   //increment Score
	void DeScore(int Ds);	   //decrement Score
	int getScore() const;	   //get Score
	void setgScore(int gS);	   //set Target Score
	void ingScore(int IgS);	   //increment Target Score
	int getgScore() const;	   //get Target Score

	void DisplayCurrLevelStat() const;	//Display Current Stats of Level
	void DisplayLevelFinalStat() const; //Display Final Stats

	void LevelOver(int over); //To Set Level to be Over
	bool isLevelOver() const; //To Get if Level is Over

	//DESTRUCTORS
public:
	virtual ~Level();
};