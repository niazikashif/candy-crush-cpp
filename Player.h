#pragma once
#include "util.h"
class Player
{

	//PRIVATE MEMBERS
private:
	string p_Name;
	int p_Score;
	int p_Level;
	int P_LevelTime;
	int p_Lives;

	//CONSTRUCTORS
public:
	Player();
	Player(string p_Name, int p_Score, int p_Level, int p_LevelTime);

	//METHODS
public:
	void setpName(string pname); //Set Name of Player using a String
	void setpName(char pname);	 //Set Name of Player Character by Character
	string getpName() const;	 //Get Name of Player
	void setpScore(int ps);		 //Set Score of Player
	int getpScore() const;		 //Get Score of Player
	void setpLevel(int pl);		 //Set Level of Player
	int getpLevel() const;		 //Get Level of Player
	void setpLevelTime(int pt);	 //Set Level Timer of Player
	int getpLevelTime() const;	 //Get Level Timer of Player
	void setpLives(int plives);	 //Set Level Lives of Player
	int getpLives() const;		 //Get Level Lives of Player

	void DisplaypName() const;	 //Display Player Name

	//DESTRUCTORS
	~Player();
};