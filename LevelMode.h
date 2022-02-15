#pragma once
#include "Level.h"
class LevelMode : public Level
{
	//PUBLIC ENUM
public:
	/*		THIS ENUM CLASS WILL HELP DETERMINE THE MODE OF LEVEL	 */
	enum Mode
	{
		Normal = 1,
		Trialed,
		NoMode
	};

	//PRIVATE MEMBERS
private:
	bool isTrialed;
	bool isNormal;
	int Time;
	int Lives;
	Mode pMode;

	//CONSTRUCTORS
public:
	LevelMode();
	LevelMode(bool isTrialed, bool isNormal, int Time, int Lives, Mode pMode, int LevelNum, int score, int goalScore, bool isOver);
	//METHODS
public:
	void setLevelMode(Mode mode);	 //Set Level Mode
	Mode getLevelMode();			 //Get Level Mode
	void setPrevMode(Mode prevmode); //Keep Previous Level Mode
	Mode getPrevMode();				 //Get Previous Level Mode
	void setTimer(int t);			 //Set Timer
	int getTimer() const;			 //Get Timer
	int TimerIn(int It);			 //increment Timer
	void TimerDec();				 //decrement Timer
	void setLives(int l);			 //Set Lives
	int getLives();					 //Get Lives
	void LivesIn();					 //increment Lives
	void LivesDe();					 //decrement Lives

	void DisplayTimerandLife(); //Display Timer and Life

	//DESTRUCTORS
public:
	~LevelMode();
};