#include "Board.h"

//CONSTRUCTOR

/*	INTILIAZING THE BOARD 	*/
Board::Board()
{
	rows = 8;
	cols = 8;
	srand(time(0));
	gBoard = new Gem **[rows];
	for (int i = 0; i < cols; i++)
	{
		gBoard[i] = new Gem *[cols];
		for (int j = 0; j < cols; j++)
		{
			int randGem = rand() % 5 + 1;
			switch (randGem)
			{
			case 1:
				gBoard[i][j] = new gemCir(20, 190, 80, colors[RED], 'C');
				break;
			case 2:
				gBoard[i][j] = new gemSq(40, 190, 80, colors[GOLDEN_ROD], 'S');
				break;
			case 3:
				gBoard[i][j] = new gemRect(40, 40, 190, 80, colors[GREEN], 'R');
				break;
			case 4:
				gBoard[i][j] = new gemRRect(40, 20, 5, 190, 90, colors[BLACK], 'O');
				break;
			case 5:
				gBoard[i][j] = new gemTri(190, 80, colors[ORANGE], 'T');
				break;
			default:
				cout << "ERROR!!!!!!!" << endl;
				break;
			}
		}
	}
}

//PUBLIC METHODS

void Board::drawBoard() //Drawing Board
{

	for (int i = 0; i < rows + 1; i++)
	{
		DrawLine(170 + (i * 80), 70, 170 + (i * 80), 550, 40, colors[WHITE]);
		DrawLine(170, 70 + (i * 60), 810, 70 + (i * 60), 40, colors[WHITE]);
	}
}

void Board::drawGemOnBoard() //Drawing Gems on Board
{
	srand(time(0));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (gBoard[i][j]->getshape() != 'N')
				gBoard[i][j]->drawGem(j * 80, i * 60);
}

int Board::foundMatch() //Checking for Matching Gems In Rows/Columns
{
	int matchFound = 0; //NUMBER OF MATCHES

		//Checking the Rows
		for (int rowCheck = 0; rowCheck < rows; ++rowCheck)
		{
			for (int colCheck = 0; colCheck < cols; ++colCheck)
			{
				//Checking for 3 Gems Match
				if (colCheck > 1 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck][colCheck - 1]->getshape() && gBoard[rowCheck][colCheck - 1]->getshape() == gBoard[rowCheck][colCheck - 2]->getshape())
				{
					//Checking for 4 Gems Match
					if (colCheck < 7 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck][colCheck + 1]->getshape())
					{
						gBoard[rowCheck][colCheck + 1]->setshape('N');
						drawGemOnBoard(); //Gem Deletion Effect
						matchFound++;
						//Checking for 5 Gems Match
						if (colCheck < 6 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck][colCheck + 2]->getshape())
						{
							gBoard[rowCheck][colCheck + 2]->setshape('N');
							drawGemOnBoard(); //Gem Deletion Effect
							matchFound++;
						}
					}
					gBoard[rowCheck][colCheck]->setshape('N');
					gBoard[rowCheck][colCheck - 1]->setshape('N');
					gBoard[rowCheck][colCheck - 2]->setshape('N');
					drawGemOnBoard(); //Gem Deletion Effect
					matchFound += 3;
				}
			}
		}

		//Checking the Columns
		for (int colCheck = 0; colCheck < cols; ++colCheck)
		{
			for (int rowCheck = 0; rowCheck < rows; ++rowCheck)
			{
				//Checking for 3 Gems Match
				if (rowCheck > 1 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck - 1][colCheck]->getshape() && gBoard[rowCheck - 1][colCheck]->getshape() == gBoard[rowCheck - 2][colCheck]->getshape())
				{
					//Checking for 4 Gems Match
					if (rowCheck < 7 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck + 1][colCheck]->getshape())
					{
						gBoard[rowCheck + 1][colCheck]->setshape('N');
						drawGemOnBoard(); //Gem Deletion Effect
						matchFound++;
						//Checking for 5 Gems Match
						if (rowCheck < 6 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck + 2][colCheck]->getshape())
						{
							gBoard[rowCheck + 2][colCheck]->setshape('N');
							drawGemOnBoard(); //Gem Deletion Effect
							matchFound++;
						}
					}
					gBoard[rowCheck][colCheck]->setshape('N');
					gBoard[rowCheck - 1][colCheck]->setshape('N');
					gBoard[rowCheck - 2][colCheck]->setshape('N');
					drawGemOnBoard(); //Gem Deletion Effect
					matchFound += 3;

				}
			}
		}
	return matchFound; //Returning Total Number of Matches
}

void Board::hintMatch() //Checking for Matching Gems In Rows/Columns To Show As HINT
{

	//checking cols
	for (int colCheck = 0; colCheck < cols; colCheck++)
	{
		for (int rowCheck = 0; rowCheck < rows; rowCheck++)
		{
			if (rowCheck > 2 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck - 2][colCheck]->getshape() && gBoard[rowCheck - 2][colCheck]->getshape() == gBoard[rowCheck - 3][colCheck]->getshape())
			{
				gBoard[rowCheck - 2][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck - 3][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	for (int colCheck = 0; colCheck < cols; colCheck++)
	{
		for (int rowCheck = 0; rowCheck < rows; rowCheck++)
		{
			if (rowCheck < rows - 3 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck + 2][colCheck]->getshape() && gBoard[rowCheck + 2][colCheck]->getshape() == gBoard[rowCheck + 3][colCheck]->getshape())
			{
				gBoard[rowCheck + 2][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck + 3][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	//checking rows
	for (int rowCheck = 0; rowCheck < rows; rowCheck++)
	{
		for (int colCheck = 0; colCheck < cols; colCheck++)
		{
			if (colCheck > 2 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck][colCheck - 2]->getshape() && gBoard[rowCheck][colCheck - 2]->getshape() == gBoard[rowCheck][colCheck - 3]->getshape())
			{
				gBoard[rowCheck][colCheck - 2]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck - 3]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	for (int rowCheck = 0; rowCheck < rows; rowCheck++)
	{
		for (int colCheck = 0; colCheck < cols; colCheck++)
		{
			if (colCheck < cols - 3 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck][colCheck + 2]->getshape() && gBoard[rowCheck][colCheck + 2]->getshape() == gBoard[rowCheck][colCheck + 3]->getshape())
			{
				gBoard[rowCheck][colCheck + 2]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck + 3]->setcolor(colors[WHITE]);
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	//checking both columns and rows from left side
	for (int rowCheck = 0; rowCheck < rows; rowCheck++)
	{
		for (int colCheck = 0; colCheck < cols; colCheck++)
		{
			if (colCheck > 0 && rowCheck > 1 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck - 1][colCheck - 1]->getshape() && gBoard[rowCheck - 1][colCheck - 1]->getshape() == gBoard[rowCheck - 2][colCheck - 1]->getshape())
			{
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck - 1][colCheck - 1]->setcolor(colors[WHITE]);
				gBoard[rowCheck - 2][colCheck - 1]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	for (int rowCheck = 0; rowCheck < rows; rowCheck++)
	{
		for (int colCheck = 0; colCheck < cols; colCheck++)
		{
			if (colCheck < cols - 1 && rowCheck < rows - 2 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck + 1][colCheck + 1]->getshape() && gBoard[rowCheck + 1][colCheck + 1]->getshape() == gBoard[rowCheck + 2][colCheck + 1]->getshape())
			{
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck + 1][colCheck + 1]->setcolor(colors[WHITE]);
				gBoard[rowCheck + 2][colCheck + 1]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	//checking both rows and cols from right side
	for (int colCheck = 0; colCheck < cols; colCheck++)
	{
		for (int rowCheck = 0; rowCheck < rows; rowCheck++)
		{
			if (colCheck > 1 && rowCheck > 0 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck - 1][colCheck - 1]->getshape() && gBoard[rowCheck - 1][colCheck - 1]->getshape() == gBoard[rowCheck - 1][colCheck - 2]->getshape())
			{
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck - 1][colCheck - 1]->setcolor(colors[WHITE]);
				gBoard[rowCheck - 1][colCheck - 2]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}
	for (int colCheck = 0; colCheck < cols; colCheck++)
	{
		for (int rowCheck = 0; rowCheck < rows; rowCheck++)
		{
			if (colCheck < cols - 2 && rowCheck < rows - 1 && gBoard[rowCheck][colCheck]->getshape() == gBoard[rowCheck + 1][colCheck + 1]->getshape() && gBoard[rowCheck + 1][colCheck + 1]->getshape() == gBoard[rowCheck + 1][colCheck + 2]->getshape())
			{
				gBoard[rowCheck][colCheck]->setcolor(colors[WHITE]);
				gBoard[rowCheck + 1][colCheck + 1]->setcolor(colors[WHITE]);
				gBoard[rowCheck + 1][colCheck + 2]->setcolor(colors[WHITE]);
				goto jump;
			}
		}
	}

jump:
	return;
}

void Board::sortMatch(int row, int col) //Sorting The Board
{
	//Base Condition
	if (row > 6)
		return;
	if (gBoard[row + 1][col]->getshape() != 'N')
	{
		swap(gBoard[row][col], gBoard[row + 1][col]);
	}
	else if (gBoard[row + 1][col]->getshape() == 'N')
	{
		sortMatch(row + 1, col);
		swap(gBoard[row][col], gBoard[row + 1][col]);
	}
}

void Board::refill() //Refil the Board
{

	for (int rowCheck = 0; rowCheck < rows; rowCheck++)
	{
		for (int colCheck = 0; colCheck < cols; colCheck++)
		{
			if (gBoard[rowCheck][colCheck]->getshape() == 'N')
				sortMatch(rowCheck, colCheck);
		}
	}
	for (int rowAdd = 0; rowAdd < rows; rowAdd++)
	{
		for (int colAdd = 0; colAdd < cols; colAdd++)
		{
			if (gBoard[rowAdd][colAdd]->getshape() == 'N')
			{
				int randGem = rand() % 5 + 1;
				switch (randGem)
				{
				case 1:
					gBoard[rowAdd][colAdd] = new gemCir(20, 190, 80, colors[RED], 'C');
					break;
				case 2:
					gBoard[rowAdd][colAdd] = new gemSq(40, 190, 80, colors[GOLDEN_ROD], 'S');
					break;
				case 3:
					gBoard[rowAdd][colAdd] = new gemRect(40, 40, 190, 80, colors[GREEN], 'R');
					break;
				case 4:
					gBoard[rowAdd][colAdd] = new gemRRect(40, 20, 5, 190, 90, colors[BLACK], 'O');
					break;
				case 5:
					gBoard[rowAdd][colAdd] = new gemTri(190, 80, colors[ORANGE], 'T');
					break;
				default:
					cout << "ERROR!!!!!!!" << endl;
					break;
				}
			}
		}
	}
}

void Board::swapGems(int selGemRow, int selGemCol, int swapGemRow, int swapGemCol) //Swapping Gems
{
	if ((abs(swapGemRow - selGemRow) <= 1 && abs(swapGemCol - selGemCol) == 0) || (abs(swapGemRow - selGemRow) == 0 && abs(swapGemCol - selGemCol) <= 1) && (swapGemRow > -1 && swapGemRow < 9) && (swapGemCol > -1 && swapGemCol < 9) && (selGemRow > -1 && selGemRow < 9) && (selGemCol > -1 && selGemCol < 9))
	{

		swap(gBoard[selGemRow][selGemCol], gBoard[swapGemRow][swapGemCol]);
		if (!foundMatch())
			swap(gBoard[selGemRow][selGemCol], gBoard[swapGemRow][swapGemCol]);
	}
}

//DESTRUCTOR
Board::~Board()
{
}