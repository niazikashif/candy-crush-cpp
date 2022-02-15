#pragma once
#include "util.h"
#include "Gem.h"
#include "Board.h"
#include "LevelMode.h"
#include "Player.h"
#include "Settings.h"
#include <fstream>
class GameMenu
{

	//PUBLIC ENUM
public:
	/*		THIS ENUM CLASS WILL HELP DETERMINE THE STATE OF GAME	 */
	enum State
	{
		Ready = 1,
		Pause,
		Resume,
		Over,
		Levels,
		HighScore,
		Setting,
		New,
		Quit
	};
	//PRIVATE MEMBERS
private:
	State gameState;
	Board objBoard;
	LevelMode objLevel;
	Player objPlayer;
	Settings objSettings;
	//CONSTRUCTORS
public:
	GameMenu();
	GameMenu(State state);

	//METHODS
public:
	void setGameState(State state);									 //Set Game State
	State getGameState() const;										 //Get Game State
	void BuildGame();												 //Build the Game
	void UpdateSwapGame(int ipos1, int ipos2, int jpos1, int jpos2); //Update Game when Mouse Attempts Swap
	void UpdateGame();												 //Game Updater
	void DisplayGameMenu(int state, int x, int y);					 //Display Game Menu
	void DisplayInGameMenu(int state, int x, int y);				 //Display In Game Menu
	void DisplayNewPlayerMenu(unsigned char pn);					 //Display New Player Menu
	void DisplayGameStatus();										 //Display Game Status
	void DisplaySettingsMenu(int state, int x, int y);				 //Display Settings Menu
	void DisplayHighScores(int state, int x, int y);				 //Display High Scores
	bool SaveData();												 //Save Game Data
	bool loadData();												 //Load Game Data

	//DESTRUCTOR
public:
	~GameMenu();
};