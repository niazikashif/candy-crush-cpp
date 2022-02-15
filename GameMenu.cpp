#include "GameMenu.h"

GameMenu::GameMenu()
{
	gameState = New;
}

GameMenu::GameMenu(State state) : gameState(state)
{
}

void GameMenu::setGameState(State state)
{
	gameState = state;
}

GameMenu::State GameMenu::getGameState() const
{
	return gameState;
}

//BUILDING THE GAME
void GameMenu::BuildGame()
{

	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	objBoard.drawBoard();	   //Drawing the  Board
	objBoard.drawGemOnBoard(); //Drawing the Gems on Board

	if (objLevel.getLevelMode() == LevelMode::Normal) /* 	LEVEL MODE === NORMAL	*/
	{
		if (objLevel.getScore() >= objLevel.getgScore()) //When Target is met Update and Increment Level Details
		{
			objLevel.InLevelN();
			objLevel.ingScore(50);
			objLevel.setScore(0);
		}
		else if (objLevel.getgScore() > -1) //When Target is yet to be achieved
		{
			/*	To Resume Game After Pause	*/
			//Resetting
			if (objLevel.getPrevMode() != objLevel.getLevelMode()) // If Previous Mode != Curr Mode THEN Reset
			{
				/*objLevel.setScore(0);
				objLevel.setLevelN(1);*/
			}
			/*								*/

			objLevel.setScore(objLevel.getScore());
			objLevel.DisplayCurrLevelStat();
			objPlayer.DisplaypName();
		}
	}
	else if (objLevel.getLevelMode() == LevelMode::Trialed) /* 	LEVEL MODE === TIME TRIALED	*/
	{
		if (objLevel.getLives() <= 0)
		{
			gameState = Over;
		}

		if (objLevel.getScore() >= objLevel.getgScore()) //When Target is met Update and Increment Level Details
		{

			objLevel.InLevelN();
			objLevel.ingScore(50);
			objLevel.setScore(objLevel.getgScore() / 2);
			objLevel.TimerIn(objLevel.getLevelN());
		}
		else if (objLevel.getScore() > 0)
		{
			/*	To Resume Game After Pause	*/
			//Resetting
			if (objLevel.getPrevMode() != objLevel.getLevelMode()) // If Previous Mode != Curr Mode THEN Reset
			{
			//	objLevel.setScore(50);
			//	objLevel.setgScore(100);
			//	objLevel.setTimer(60);
			//	objLevel.setLives(3);
			//	objLevel.setLevelN(1);
			}
			/*								*/

			cout << objPlayer.getpName() << endl;
			//gameFile << getGameState() << endl;
			cout << objLevel.getLevelN() << endl;
			cout << objLevel.getScore() << endl;
			cout << objLevel.getLives() << endl;
			cout << objLevel.getTimer() << endl;
			cout << objLevel.getLevelMode() << endl;


			objLevel.DisplayCurrLevelStat();
			objLevel.DisplayTimerandLife();
			objPlayer.DisplaypName();
		}
	}
}

//Update Game when Mouse Attempts Swap
void GameMenu::UpdateSwapGame(int ipos1, int ipos2, int jpos1, int jpos2)
{
	objBoard.swapGems(ipos1, ipos2, jpos1, jpos2);
}

//Update Game
void GameMenu::UpdateGame()
{
	if (getGameState() == Ready) //If GameState==Ready then Update Game
	{
		if (objLevel.getLevelMode() == LevelMode::Normal) //Implementation of Normal Mode Update
		{
			objLevel.InScore(objBoard.foundMatch()); //Total Number of Matches determines Score Multiplication ( Increment )
			objBoard.refill();

			/*CATERING PLAYER STATS*/
			objPlayer.setpLevel(objLevel.getLevelN());
			objPlayer.setpScore(objLevel.getScore());
			objPlayer.setpLevelTime(objLevel.getTimer());
			/*						*/
		}
		if (objLevel.getLevelMode() == LevelMode::Trialed) //Implementation of Time Trialed Mode Update
		{
			objLevel.InScore(objBoard.foundMatch()); //Total Number of Matches determines Score Multiplication ( Increment )
			objLevel.setScore(objLevel.getScore());
			objBoard.refill();
			objLevel.TimerDec();
			objLevel.DeScore(1);
			objLevel.LivesDe();

			/*CATERING PLAYER STATS*/
			objPlayer.setpLevel(objLevel.getLevelN());
			objPlayer.setpScore(objLevel.getScore());
			objPlayer.setpLevelTime(objLevel.getTimer());
			/*						*/
		}
		/* 		PAUSE/PLAY Implementation		*/
		objLevel.setPrevMode(objLevel.getLevelMode());
	}
	/* 		PAUSE/PLAY Implementation		*/
	else if (getGameState() == Pause)
	{
		if (objLevel.getLevelMode() == LevelMode::Normal) //Implementation of Normal Mode Update
		{
			objLevel.setScore(objLevel.getScore());
			objPlayer.setpLevel(objLevel.getLevelN());
			objPlayer.setpScore(objLevel.getScore());
			objPlayer.setpLevelTime(objLevel.getTimer());
		}
		if (objLevel.getLevelMode() == LevelMode::Trialed) //Implementation of Time Trialed Mode Update
		{
			objLevel.setScore(objLevel.getScore());
			objLevel.setTimer(objLevel.getTimer());
			objLevel.setLives(objLevel.getLives());
			objPlayer.setpLevel(objLevel.getLevelN());
			objPlayer.setpScore(objLevel.getScore());
			objPlayer.setpLives(objLevel.getLives());
			objPlayer.setpLevelTime(objLevel.getTimer());
		}
		objLevel.setLevelMode(LevelMode::NoMode);
	}
	/* 										*/
}

void GameMenu::DisplayGameMenu(int state, int x, int y)
{
	glClearColor(0.0, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	///////////////////////////////////////////////////////////////////
	/////////////////// MAIN MENU /////////////////////////////////////
	DrawString(420, 600, "DESI BEJEWELED", colors[ORANGE]);
	DrawString(420, 450, "Play Normal Mode", colors[WHITE]);
	DrawString(410, 380, "Play Time Trial Mode", colors[WHITE]);
	DrawString(445, 310, "High Scores", colors[WHITE]);
	DrawString(460, 240, "Settings", colors[WHITE]);
	DrawString(453, 170, "Exit Game", colors[WHITE]);

	if ((x >= 400 && x <= 600) && (y >= 190 && y <= 215))
	{
		DrawString(420, 450, "Play Normal Mode", colors[RED]);
		if (state == GLUT_DOWN)
		{
			objLevel.setLevelMode(LevelMode::Normal);
			gameState = Ready;

			while (objBoard.foundMatch()) //Removing All Matches Before Game Starts
			{
				objBoard.refill();
			}
			return;
		}
	}
	if ((x >= 400 && x <= 600) && (y >= 260 && y <= 290))
	{
		DrawString(410, 380, "Play Time Trial Mode", colors[RED]);
		if (state == GLUT_DOWN)
		{
			objLevel.setLevelMode(LevelMode::Trialed);

			cout << objPlayer.getpName() << endl;
			//gameFile << getGameState() << endl;
			cout << objLevel.getLevelN() << endl;
			cout << objLevel.getScore() << endl;
			cout << objLevel.getLives() << endl;
			cout << objLevel.getTimer() << endl;
			cout << objLevel.getLevelMode() << endl;

			gameState = Ready;
			while (objBoard.foundMatch()) //Removing All Matches Before Game Starts
			{
				objBoard.refill();
			}
			return;
		}
	}
	if ((x >= 400 && x <= 600) && (y >= 330 && y <= 355))
	{
		DrawString(445, 310, "High Scores", colors[RED]);
		if (state == GLUT_DOWN)
		{
			gameState = HighScore;
			return;
		}
	}
	if ((x >= 400 && x <= 600) && (y >= 400 && y <= 425))
	{
		DrawString(460, 240, "Settings", colors[RED]);
		if (state == GLUT_DOWN)
		{
			gameState = Setting;
			return;
		}
	}
	if ((x >= 400 && x <= 600) && (y >= 470 && y <= 495))
	{
		DrawString(453, 170, "Exit Game", colors[RED]);
		if (state == GLUT_DOWN)
		{
			SaveData();
			exit(1);
			return;
		}
	}
	///////////////////////////////////////////////////////////////////
}

void GameMenu::DisplayInGameMenu(int state, int x, int y)
{

	///////////////////////////////////////////////////////////////////
	/////////////////////// IN-GAME MENU //////////////////////////////
	// Pause Button
	DrawCircle(40, 120, 20, colors[DARK_BLUE]);
	DrawLine(35, 110, 35, 130, 2, colors[WHITE]);
	DrawLine(45, 110, 45, 130, 2, colors[WHITE]);
	//Hint Button
	DrawCircle(90, 50, 40, colors[DARK_BLUE]);
	DrawString(70, 43, "HINT", colors[WHITE]);

	if ((x >= 15 && x <= 60) && (y >= 515 && y <= 560) && state == GLUT_DOWN)
	{

		DrawCircle(40, 120, 20, colors[DARK_BLUE]);
		DrawLine(35, 110, 35, 130, 2, colors[WHITE]);
		DrawLine(45, 110, 45, 130, 2, colors[WHITE]);
		gameState = Pause;
		return;
	}
	if ((x >= 45 && x <= 135) && (y >= 570 && y <= 640) && state == GLUT_DOWN)

	{
		using namespace literals::chrono_literals;
		DrawCircle(90, 50, 40, colors[ORANGE]);
		DrawString(70, 43, "HINT", colors[WHITE]);
		objBoard.hintMatch();
		objLevel.DeScore(10);
		return;
	}
	////////////////////////////////////////////////////////////////////
}

void GameMenu::DisplayNewPlayerMenu(unsigned char pn)
{
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	///////////////////////////////////////////////////////////////////
	/////////////////////// PLAYER NAME INTRO//////////////////////////
	objPlayer.setpName(pn);
	DrawString(250, 400, "Enter Name :", colors[WHITE]);
	DrawRoundRect(300, 344, 500, 34, colors[LIGHT_GREEN], 10);
	DrawRoundRect(301, 346, 498, 30, colors[BLACK], 10);
	DrawString(310, 355, objPlayer.getpName(), colors[WHITE]);
	cout << objPlayer.getpName() << endl;
	///////////////////////////////////////////////////////////////////
}

void GameMenu::DisplaySettingsMenu(int state, int x, int y)
{
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	///////////////////////////////////////////////////////////////////
	/////////////////////// SETTINGS MENU /////////////////////////////
	if (!objSettings.getHTP())
	{
		objSettings.DisplaySettings();
		if ((x >= 300 && x <= 400) && (y <= 310 && y >= 290) && state == GLUT_DOWN)
			objSettings.setHTP(true);
		if ((x >= 595 && x <= 720) && (y <= 310 && y >= 290) && state == GLUT_DOWN)
			objSettings.setMusic();
		if ((x >= 195 && x <= 240) && (y <= 560 && y >= 540) && state == GLUT_DOWN)
			gameState = Pause;
	}
	else if (objSettings.getHTP())
	{
		objSettings.HowToPlay();
		if ((x >= 195 && x <= 240) && (y <= 560 && y >= 540) && state == GLUT_DOWN)
			objSettings.setHTP(false);
	}
	///////////////////////////////////////////////////////////////////
}

void GameMenu::DisplayHighScores(int state, int x, int y)
{
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	///////////////////////////////////////////////////////////////////
	/////////////////////// SETTINGS MENU /////////////////////////////
	fstream HighScoregameFile;
	HighScoregameFile.open("highscores.txt", ios::in);
	int i = 0;
	int lines = 0;
	string loadName;
	int loadScore;
	while (HighScoregameFile && lines<4)
	{
		HighScoregameFile >> loadScore;

		cout << loadScore << endl;
		DrawString(500, 550, "Score", colors[GREEN]);
		DrawString(510, 450-i, to_string(loadScore), colors[WHITE]);
		HighScoregameFile >> loadName;
		DrawString(200, 550, "Player Name", colors[GREEN]);
		DrawString(220, 450-i, loadName, colors[WHITE]);
		lines++;
		i += 20;
	}
	HighScoregameFile.close();
	DrawString(200, 100, "Back", colors[GRAY]);
	if ((x >= 195 && x <= 240) && (y <= 560 && y >= 540) && state == GLUT_DOWN)
		gameState = Pause;

}

void GameMenu::DisplayGameStatus()
{
	using namespace literals::chrono_literals;
	glClearColor(0, 0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawString(200, 400, "GAME OVER", colors[RED]);
	this_thread::sleep_for(5s);
	objLevel.setLives(3);
	objLevel.setLevelN(1);
	if (objLevel.getLevelMode() == LevelMode::Normal)
		objLevel.setScore(0);
	else if (objLevel.getLevelMode() == LevelMode::Trialed)
	{
		objLevel.setgScore(50);
		objLevel.setTimer(60);
	}
	objLevel.setLevelMode(LevelMode::NoMode);
	//this_thread::sleep_for(5s);
	gameState = Pause;
		
	
}

bool GameMenu::SaveData()
{
	/////////////////////// SAVING GAME //////////////////////////

	cout << objPlayer.getpName() << endl;
	fstream gameFile;
	gameFile.open(objPlayer.getpName() + ".txt", ios::out | ios::trunc);
	this->setGameState(Pause);
	while (gameFile)
	{
		gameFile << objPlayer.getpName() << endl;
		//gameFile << getGameState() << endl;
		gameFile << objLevel.getLevelN() << endl;
		gameFile << objLevel.getScore() << endl;
		gameFile << objLevel.getLives() << endl;
		gameFile << objLevel.getTimer() << endl;
		gameFile << objLevel.getLevelMode() << endl;

		break;
	}
	gameFile.close();

	fstream PgameFile;
	PgameFile.open("playernames.txt", ios::out | ios::app);
	this->setGameState(Pause);
	while (PgameFile)
	{
		PgameFile << objPlayer.getpName() << endl;
		PgameFile << objLevel.getScore() << endl;
		break;
	}
	PgameFile.close();

	int p_HighScore[100] = { 0 };
	string pName_Score[100] = { "" };

	
	int size = 0;
	PgameFile.open("playernames.txt", ios::in);
	this->setGameState(Pause);
	while (PgameFile)
	{
		PgameFile >> pName_Score[size];
		PgameFile >> p_HighScore[size];
		size++;
	}
	PgameFile.close();

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size-1; j++)
			if (p_HighScore[j] < p_HighScore[j + 1])
			{
				int temp = p_HighScore[j];
				p_HighScore[j] = p_HighScore[j + 1];
				p_HighScore[j + 1] = temp;

				string stemp = pName_Score[j];
				pName_Score[j] = pName_Score[j + 1];
				pName_Score[j + 1] = stemp;
			}

	
	cout << size;
	fstream HighScoregameFile;
	HighScoregameFile.open("highscores.txt", ios::out | ios::trunc);
	int i = 0;
	while (HighScoregameFile && i<size)
	{
		HighScoregameFile << p_HighScore[i] << endl;
		HighScoregameFile << pName_Score[i] << endl;
		i++;
	}
	HighScoregameFile.close();

	
	return true;
}

bool GameMenu::loadData()
{
	/////////////////////// LOADING GAME //////////////////////////

	int loadVar;
	string loadName;
	fstream gameFile;
	gameFile.open(objPlayer.getpName() + ".txt", ios::in);
	//gameFile.seekg(0, ios::beg);
	while (gameFile)
	{
		getline(gameFile, loadName);
		if (this->objPlayer.getpName() != loadName)
			return false;
		objPlayer.setpName(loadName);
		cout << loadName << endl;
		/*gameFile >> loadVar;
		if (loadVar == 1)
			setGameState(Ready);
		else if (loadVar == 2)
			setGameState(Pause);*/
		gameFile >> loadVar;
		cout << loadVar << endl;
		objLevel.setLevelN(loadVar);
		gameFile >> loadVar;
		cout << loadVar << endl;
		objLevel.setScore(loadVar);
		gameFile >> loadVar;
		cout << loadVar << endl;
		objLevel.setLives(loadVar);
		gameFile >> loadVar;
		cout << loadVar << endl;
		objLevel.setTimer(loadVar);
		gameFile >> loadVar;
		cout << loadVar << endl;
		if (loadVar == 1)
			objLevel.setLevelMode(LevelMode::Normal);
		else if (loadVar == 2)
			objLevel.setLevelMode(LevelMode::Trialed);
		cout << "Success" << endl;
		break;
	}
	gameFile.close();
	return true;
}

GameMenu::~GameMenu()
{

}
