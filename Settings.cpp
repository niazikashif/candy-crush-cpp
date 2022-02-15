#include "Settings.h"

Settings::Settings()
{
	isMusicOn = false;
	isHTPOn = false;
}

void Settings::DisplaySettings()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////// SETTINGS MENU //////////////////////////////////////////
	glClearColor(0.0, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawString(420, 600, "DESI BEJEWELED", colors[ORANGE]);
	DrawString(460, 480, "Settings", colors[PINK]);
	DrawString(300, 350, "How To Play", colors[WHITE]);
	DrawString(600, 350, "Music : ", colors[WHITE]);
	if (isMusicOn)
		DrawString(690, 350, "On", colors[GREEN]);
	else
		DrawString(690, 350, "Off", colors[RED]);
	DrawString(200, 100, "Back", colors[GRAY]);
}

void Settings::HowToPlay()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////// HOW TO PLAY INSTRUCTIONS //////////////////////////////////////////
	glClearColor(0.0, 0.0, 0.0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawString(420, 600, "DESI BEJEWELED", colors[ORANGE]);
	DrawString(440, 500, "How To Play", colors[WHITE]);
	DrawString(150, 450, "Normal Mode", colors[ORANGE]);
	DrawString(50, 410, "1. Match Gems of same shape and color", colors[WHITE]);
	DrawString(70, 380, "to increase score.", colors[WHITE]);
	DrawString(50, 350, "2. Get to the Target to reach the next Level.", colors[WHITE]);
	DrawString(600, 450, "Time Trialed Mode", colors[ORANGE]);
	DrawString(520, 410, "1. Match Gems of same shape and color", colors[WHITE]);
	DrawString(540, 380, "to increase score.", colors[WHITE]);
	DrawString(520, 350, "2. Get to the Target to reach the next Level.", colors[WHITE]);
	DrawString(520, 320, "3. Your score depletes with the passage of Time.", colors[WHITE]);
	DrawString(520, 290, "4. You have three lives.", colors[WHITE]);
	DrawString(540, 260, "You lose a life every time the Timer", colors[WHITE]);
	DrawString(540, 230, "hits zero and score is reset.", colors[WHITE]);
	DrawString(540, 200, "You gain a life every time you level up.", colors[WHITE]);
	DrawString(520, 170, "5. Reach the Target before you lose all your lives.", colors[WHITE]);
	DrawString(200, 100, "Back", colors[GRAY]);
	/////////////////////////////////////////////////////////////////////////////////////////////////
}

void Settings::setHTP(bool HTP)
{
	isHTPOn = HTP;
}

bool Settings::getHTP()
{
	return isHTPOn;
}

void Settings::playMusic()
{
}

void Settings::setMusic()
{
	if (!isMusicOn)
		isMusicOn = true;
	else if (isMusicOn)
		isMusicOn = false;
}

bool Settings::getMusic()
{
	return isMusicOn;
}

Settings::~Settings()
{
}