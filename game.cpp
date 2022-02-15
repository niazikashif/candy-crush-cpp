//============================================================================
// Name        : ->cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede->->->
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "Board.h"
#include "LevelMode.h"
#include "Player.h"
#include "GameMenu.h"
#include <iostream>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

GameMenu *g = new GameMenu(); //global object that controls the whole game

/*	The GameState is an enum of GameMenu that helps in determining the current state of Game	*/

void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height->
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function->
 * */

void GameDisplay() /**/
{

	if (g->getGameState() == GameMenu::New) //Displaying New Game Screen
		g->DisplayNewPlayerMenu('\0');

	else if (g->getGameState() == GameMenu::Ready) //Building Game and Displaying Menu
	{
		g->BuildGame();

		g->DisplayInGameMenu(GLUT_UP, 0, 0);
	}
	else if (g->getGameState() == GameMenu::Setting) //Displaying Settings Menu
		g->DisplaySettingsMenu(GLUT_UP, 0, 0);
	else if (g->getGameState() == GameMenu::HighScore)
		g->DisplayHighScores(GLUT_UP,0,0);

	glutSwapBuffers(); // do not modify this line->->
}

void NonPrintableKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
	}
	else if (key == GLUT_KEY_RIGHT)
	{
	}
	else if (key == GLUT_KEY_UP)
	{
	}

	else if (key == GLUT_KEY_DOWN)
	{
	}

	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y)
{
	if (g->getGameState() == GameMenu::New) //Taking Name Input On Screen
	{
		if (key == 13 /* Enter key ASCII */) //Load Game after user hits Enter
		{
			g->loadData();

			g->setGameState(GameMenu::Pause); //Set GameState to Pause
		}
		else if (key != 13) // Keep taking input if key is not == 13
			g->DisplayNewPlayerMenu(key);
	}

	if (key == 27 /* Escape key ASCII*/) // Exit Game and Save Data
	{
		g->SaveData();
		exit(1); // exit the program when escape key is pressed->
	}
	glutPostRedisplay();
}

void Timer(int m)
{
	// once again we tell the library to call our Timer function after next 1000/FPS

	g->UpdateGame(); //Update Game after every 1 second
	glutTimerFunc(1000.0, Timer, 0);
	glutPostRedisplay();
}

void MousePressedAndMoved(int x, int y)
{
}
void MouseMoved(int x, int y)
{

	if (g->getGameState() == GameMenu::Pause) //Handling Main Menu
	{
		g->DisplayGameMenu(GLUT_UP, x, y);
		glutPostRedisplay();
	}

	if (g->getGameState() == GameMenu::Ready) //Handling in-game Menu
	{
		g->DisplayInGameMenu(GLUT_UP, x, y);
		glutPostRedisplay();
	}

	if (g->getGameState() == GameMenu::Setting) //Handling Settings Menu
	{
		g->DisplaySettingsMenu(GLUT_UP, x, y);
		glutPostRedisplay();
	}

}

void MouseClicked(int button, int state, int x, int y)
{
	cout << x << " " << y << endl;
	static int selRow = 0;
	static int selCol = 0;
	static int swapRowCheck = 0;
	static int swapColCheck = 0;

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if (g->getGameState() == GameMenu::Pause && state == GLUT_DOWN) //Handling Main Menu
			g->DisplayGameMenu(state, x, y);

		else if (g->getGameState() == GameMenu::Ready && state == GLUT_DOWN) //Handling in-game Menu
			g->DisplayInGameMenu(state, x, y);

		else if (g->getGameState() == GameMenu::Setting && state == GLUT_DOWN) //Handling Settings Menu
			g->DisplaySettingsMenu(state, x, y);

		else if (g->getGameState() == GameMenu::HighScore && state == GLUT_DOWN)
			g->DisplayHighScores(state, x, y);

		/*		IMPLEMENTING GEM SWAP OPERATION		*/
		if (g->getGameState() == GameMenu::Ready && state == GLUT_DOWN)
		{
			selRow = (600 - y) / 60;
			selCol = (x - 180) / 77.5f;
		}
		if (g->getGameState() == GameMenu::Ready && state == GLUT_UP)
		{
			swapRowCheck = (600 - y) / 60;
			swapColCheck = (x - 180) / 77.5f;
			g->UpdateSwapGame(selRow, selCol, swapRowCheck, swapColCheck);
		}
		/*	The formula applied to set selRow/selCol/swapRowCheck/swapColCheck gives appropriate index value to use to search in Board	*/
	}

	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
}

int main(int argc, char *argv[])
{

	int width = 1020, height = 660;				  // i have set my window size to be 800 x 600
	InitRandomizer();							  // seed the random number generator->->->
	glutInit(&argc, argv);						  // initialize the graphics library->->->
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50);				  // set the initial position of our window
	glutInitWindowSize(width, height);			  // set the size of our window
	glutCreateWindow("Thaki Hui Bejewled!");	  // set the title of our game window
	SetCanvasSize(width, height);				  // set the number of pixels->->->

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks->
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas->

	glutDisplayFunc(GameDisplay);	   // tell library which function to call for drawing Canvas->
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);   // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000->0/FPS milliseconds->->->
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);	  // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary->->->
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */