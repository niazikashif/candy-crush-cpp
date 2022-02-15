#pragma once
#include <ctime>
#include <cstdlib>
#include <thread>
#include "gemCir.h"
#include "gemRect.h"
#include "gemRRect.h"
#include "gemSq.h"
#include "gemTri.h"
class Board
{
	//PRIVATE MEMBERS
private:
	int rows;
	int cols;
	Gem ***gBoard;

	//CONSTRUCTORS
public:
	Board();

	//PUBLIC METHODS
public:
	void drawBoard();															 //Draw Board
	void drawGemOnBoard();														 //Draw Gems On Board
	int foundMatch();															 //Return the number of Gem Matches found
	void hintMatch();															 //Hint function
	void sortMatch(int row, int col);											 //Sort all Matches
	void refill();																 //Refill the Board
	void swapGems(int selGemRow, int selGemCol, int swapGemRow, int swapGemCol); //Swap Gems

	//DESTRUCTOR
public:
	~Board();
};