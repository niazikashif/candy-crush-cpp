#pragma once
#include "util.h"
class Settings
{

	//PRIVATE MEMBERS
private:
	bool isMusicOn;
	bool isHTPOn;

	//CONSTRUCTORS
public:
	Settings();

	//METHODS
public:
	void setHTP(bool HTP);	//HowToPlay Requested 1/0
	bool getHTP();			//Get HowToPlay State

		/*	DUMMY METHODS	*/
	void setMusic();		//Music Requested 1/0
	bool getMusic();		//Get Music State
	void playMusic();		//Play Music
		/*					*/

	void HowToPlay();		//Display HowToPlay
	void DisplaySettings(); //Display Settings Menu

	//DESTRUCTORS
public:
	~Settings();
};