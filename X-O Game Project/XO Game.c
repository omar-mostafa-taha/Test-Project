
#include "./common/tm4c123gh6pm.h"
#include "./drivers/NOKIA5110/Nokia5110.h"
#include "./common/TExaS.h"
#include "./common/GameArt.h"
#include "./common/XO Game.h"
#include "./drivers/TIMER/Timer.h"
#include "./drivers//LED/LED.h"


unsigned long TimerCount;

int playedCells, currentCell;

char playletter, GameMatrix[9], xWins = 0, oWins = 0;

extern unsigned char Right , Left ,  Up , Dwon, Sw5Flag;


/************************************************************************************
 * Function Name:GameIntro
 * Function Inputs: None
 * Description: function to enter to the game
 ************************************************************************************/

void Intro(void)
{
	Nokia5110_PrintBMP(0, 47, intro, 0); 
	Nokia5110_DisplayBuffer();			  
	Timer2_delay(100);					  
	Nokia5110_Clear();					   
	Nokia5110_SetCursor(1, 2);			   
	Nokia5110_OutString("Welcome To");	   
	Nokia5110_SetCursor(1, 4);
	Nokia5110_OutString(" XO Game");
	Timer2_delay(50);
	Nokia5110_Clear();
	Nokia5110_SetCursor(2, 2);
	Nokia5110_OutString("X-Player");
	Nokia5110_SetCursor(1, 4);
	Nokia5110_OutString("Start Game");
	Nokia5110_Clear(); 
}

/************************************************************************************
 * Function Name: GameReset
 * Function Inputs: None
 * Description: Function for reset game 
 ************************************************************************************/
void GameReset()
{
	int i;
	playedCells = 0;  
	playletter = 'X';	  
	currentCell = 0; 
	for (i = 0; i < 9; i++)
		GameMatrix[i] = ' '; 
	Timer2_delay(50);
	Set_Led(3);
}

/************************************************************************************
 * Function Name:DrawGrid
 * Function Inputs: None
 * Description: Function for drawing the grid of the game
 ************************************************************************************/

void DrawGrid()
{
	
	Nokia5110_ClearBuffer();
	Nokia5110_PrintBMP(0, (SQUAREHEIGHT - 1), Cell, 0); // Nokia5110_printBMP(x_cor , y_cor , pointer_to_image (square or VL) , threshold(0 or 1))
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP((SQUAREHEIGHT - 1) + 3, (SQUAREHEIGHT - 1), Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP(2 * (SQUAREHEIGHT - 1) + 6, (SQUAREHEIGHT - 1), Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP(0, 2 * (SQUAREHEIGHT - 1) + 3, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP((SQUAREHEIGHT - 1) + 3, 2 * (SQUAREHEIGHT - 1) + 3, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP(2 * (SQUAREHEIGHT - 1) + 6, 2 * (SQUAREHEIGHT - 1) + 3, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP(0, 3 * (SQUAREHEIGHT - 1) + 6, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP((SQUAREHEIGHT - 1) + 3, 3 * (SQUAREHEIGHT - 1) + 6, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	Nokia5110_PrintBMP(2 * (SQUAREHEIGHT - 1) + 6, 3 * (SQUAREHEIGHT - 1) + 6, Cell, 0);
	Nokia5110_DisplayBuffer();
	Timer2_delay(5);

	displayPlayer(); 
}


/************************************************************************************
 * Service Name   :StartGame
 * Function Inputs : None
 * Description: Function for starting to play
 ************************************************************************************/
void StartGame()
{
		
	int row, col, lastRow, lastCol, lastCell;
/********************Rigt Move*****************************************************/

	if (Right)
	{
		Right = 0;
		lastCell = currentCell; 
		currentCell++;
		if (currentCell == 3 || currentCell == 6 || currentCell == 9)
			currentCell -=3;   
		row = currentCell / 3; 
		col = currentCell % 3;
		
		if (GameMatrix[currentCell] == 'X')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredX, 0);
		}
		else if (GameMatrix[currentCell] == 'O')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredO, 0);
		}
		else
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredSquare, 0);
		}

		if (lastCell == 8 || lastCell == -1)
		{
			lastRow = 2;
			lastCol = 2;
			lastCell = 8;
		}
		else
		{
			lastRow = (lastCell) / 3;
			lastCol = (lastCell) % 3;
		}

		if (GameMatrix[lastCell] == 'X')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, X, 0);
		}
		else if (GameMatrix[lastCell] == 'O')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, O, 0);
		}
		else
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, Cell, 0); // not to leave the last cell hoovered
		}
		Nokia5110_DisplayBuffer();
		displayPlayer();
		Timer2_delay(10);
	}
/**********************Dwon Move****************************************************/	
	if (Dwon)
	{
		Dwon = 0;
		lastCell = currentCell; 
		currentCell+=3;
		if (currentCell == 9 || currentCell == 10 || currentCell ==11 )
			currentCell -=9;   
		row = currentCell / 3; 
		col = currentCell % 3;
		
		if (GameMatrix[currentCell] == 'X')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredX, 0);
		}
		else if (GameMatrix[currentCell] == 'O')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredO, 0);
		}
		else
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredSquare, 0);
		}

		if (lastCell == 8 || lastCell == -1)
		{
			lastRow = 2;
			lastCol = 2;
			lastCell = 8;
		}
		else
		{
			lastRow = (lastCell) / 3;
			lastCol = (lastCell) % 3;
		}

		if (GameMatrix[lastCell] == 'X')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, X, 0);
		}
		else if (GameMatrix[lastCell] == 'O')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, O, 0);
		}
		else
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, Cell, 0); // not to leave the last cell hoovered
		}
		Nokia5110_DisplayBuffer();
		displayPlayer();
		Timer2_delay(10);
	}
	
/***************************************Left Move********************************/	
		if (Left)
	{
		Left = 0;
		lastCell = currentCell; 
		currentCell--;
		if (currentCell == -1 || currentCell == 2 || currentCell == 5)
			currentCell+=3;  
		row = currentCell / 3; 
		col = currentCell % 3;

		if (GameMatrix[currentCell] == 'X')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredX, 0);
		}
		else if (GameMatrix[currentCell] == 'O')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredO, 0);
		}
		else
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredSquare, 0);
		}
		
		if (lastCell == 8 || lastCell == -1)
		{
			lastRow = 2;
			lastCol = 2;
			lastCell = 8;
		}
		else
		{
			lastRow = (lastCell) / 3;
			lastCol = (lastCell) % 3;
		}

		if (GameMatrix[lastCell] == 'X')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, X, 0);
		}
		else if (GameMatrix[lastCell] == 'O')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, O, 0);
		}
		else
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, Cell, 0); // not to leave the last cell hoovered
		}
		Nokia5110_DisplayBuffer();
		displayPlayer();
		Timer2_delay(10);
	}
	
/**************************Up move************************************************************/
	if (Up)
	{
		Up = 0;
		lastCell = currentCell; 
		currentCell-=3;
		if (currentCell == -3 || currentCell == -2 || currentCell ==-1 )
			currentCell+=9;   
		row = currentCell / 3; 
		col = currentCell % 3;

		if (GameMatrix[currentCell] == 'X')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredX, 0);
		}
		else if (GameMatrix[currentCell] == 'O')
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredO, 0);
		}
		else
		{
			Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, hoveredSquare, 0);
		}

		if (lastCell == 8 || lastCell == -1)
		{
			lastRow = 2;
			lastCol = 2;
			lastCell = 8;
		}
		else
		{
			lastRow = (lastCell) / 3;
			lastCol = (lastCell) % 3;
		}

		if (GameMatrix[lastCell] == 'X')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, X, 0);
		}
		else if (GameMatrix[lastCell] == 'O')
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, O, 0);
		}
		else
		{
			Nokia5110_PrintBMP(lastCol * (SQUAREHEIGHT - 1) + 3 * lastCol, (lastRow + 1) * (SQUAREHEIGHT - 1) + 3 * lastRow, Cell, 0); // not to leave the last cell hoovered
		}
		Nokia5110_DisplayBuffer();
		displayPlayer();
		Timer2_delay(10);
	}
/***********************************Play Switch*******************************8*/
	if (Sw5Flag && currentCell != -1)
	{
		Sw5Flag = 0;
		if (GameMatrix[currentCell] == ' ')
		{ 
			row = currentCell / 3; 
			col = currentCell % 3;

			if (playletter == 'X')
			{

				Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, X, 0); 
				GameMatrix[currentCell] = playletter;																
				Clear_Led(3);
				Set_Led(4);
				if (checkWinner(playletter))
				{ 
					Display_Winner(playletter);
					if (CheckPlayAgain())
					{ 
						GameReset();
						CheckMode();
						DrawGrid();
						return; 
					}
					else
					{			   
						EndGame(); 
						while (1)
							; 
					}
				}
				
				playletter = 'O';
			}
		
			else
			{

				Nokia5110_PrintBMP(col * (SQUAREHEIGHT - 1) + 3 * col, (row + 1) * (SQUAREHEIGHT - 1) + 3 * row, O, 0);
				GameMatrix[currentCell] = playletter;
				Clear_Led(4);
				Set_Led(3);
				if (checkWinner(playletter))
				{
					Display_Winner(playletter);
					if (CheckPlayAgain())
					{
						GameReset();
						DrawGrid();
						return;
					}
					else
					{
						EndGame();
						while (1)
							;
					}
				}
	
				playletter = 'X';
			}
			Nokia5110_DisplayBuffer();
			displayPlayer();
			playedCells++;
			if (playedCells == 9) 
			{
				displayDraw();
				if (CheckPlayAgain())
				{
					GameReset();
					DrawGrid();
					return;
				}
				else
				{
					EndGame();
					while (1)
						;
				}
			}
		}
		else 
		{

			Nokia5110_SetCursor(7, 4);
			Nokia5110_OutString("Busy");
			Nokia5110_SetCursor(7, 5);
			Nokia5110_OutString("Cell");
      Set_Led(5);
			ToggleLED(2);
      Clear_Led(5);
			displayPlayer();
		}
		Timer2_delay(10);
	}
}
