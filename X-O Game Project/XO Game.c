
#include "./common/tm4c123gh6pm.h"
#include "./drivers/NOKIA5110/Nokia5110.h"
#include "./common/TExaS.h"
#include "./common/GameArt.h"
#include "./common/XO Game.h"
#include "./drivers/TIMER/Timer.h"
#include "./drivers/LED/LED.h"
#include "./drivers/GPIO/GPIO_interface.h"


unsigned long TimerCount;

int playedCells, currentCell;

char playletter, GameMatrix[9], xWins = 0, oWins = 0;

extern unsigned char Right , Left ,  Up , Dwon, Sw5Flag;
extern int uart;

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

/************************************************************************************
 * Function Name:checkWinner
 * Function Inputs: char player
 * Description: Function to check the winner
 ************************************************************************************/

int checkWinner(char player)
{
	int Winning_cell_1 = 0, Winning_cell_2 = 0, Winning_cell_3 = 0, i; 
	if (GameMatrix[0] == player && GameMatrix[1] == player && GameMatrix[2] == player)
	{
		Winning_cell_1 = 0;
		Winning_cell_2 = 1;
		Winning_cell_3 = 2;
		i = 0;
	}
	else if (GameMatrix[3] == player && GameMatrix[4] == player && GameMatrix[5] == player)
	{
		Winning_cell_1 = 3;
		Winning_cell_2 = 4;
		Winning_cell_3 = 5;
		i = 1;
	}
	else if (GameMatrix[6] == player && GameMatrix[7] == player && GameMatrix[8] == player)
	{
		Winning_cell_1 = 6;
		Winning_cell_2 = 7;
		Winning_cell_3 = 8;
		i = 2;
	}
	else if (GameMatrix[0] == player && GameMatrix[3] == player && GameMatrix[6] == player)
	{
		Winning_cell_1 = 0;
		Winning_cell_2 = 3;
		Winning_cell_3 = 6;
		i = 3;
	}
	else if (GameMatrix[1] == player && GameMatrix[4] == player && GameMatrix[7] == player)
	{
		Winning_cell_1 = 1;
		Winning_cell_2 = 4;
		Winning_cell_3 = 7;
		i = 4;
	}
	else if (GameMatrix[2] == player && GameMatrix[5] == player && GameMatrix[8] == player)
	{
		Winning_cell_1 = 2;
		Winning_cell_2 = 5;
		Winning_cell_3 = 8;
		i = 5;
	}
	else if (GameMatrix[0] == player && GameMatrix[4] == player && GameMatrix[8] == player)
	{
		Winning_cell_1 = 0;
		Winning_cell_2 = 4;
		Winning_cell_3 = 8;
		i = 6;
	}
	else if (GameMatrix[2] == player && GameMatrix[4] == player && GameMatrix[6] == player)
	{
		Winning_cell_1 = 2;
		Winning_cell_2 = 4;
		Winning_cell_3 = 6;
		i = 7;
	}
	if (Winning_cell_1 || Winning_cell_2 || Winning_cell_2)
	{
		if (player == 'X')
		{ /*Hoovering the 3 selected winning cells*/
			Nokia5110_PrintBMP((Winning_cell_1 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_1 % 3), (Winning_cell_1 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_1 / 3), hoveredX, 0);
			Nokia5110_PrintBMP((Winning_cell_2 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_2 % 3), (Winning_cell_2 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_2 / 3), hoveredX, 0);
			Nokia5110_PrintBMP((Winning_cell_3 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_3 % 3), (Winning_cell_3 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_3 / 3), hoveredX, 0);
	
			ToggleLED(3);
			Clear_Led(2);
			Clear_Led(3);
			Clear_Led(4);
			GPIO_PORTF_DATA_R = 0x04; // LED is blue (X won)
			Nokia5110_DisplayBuffer();
		}
		else
		{
			Nokia5110_PrintBMP((Winning_cell_1 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_1 % 3), (Winning_cell_1 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_1 / 3), hoveredO, 0);
			Nokia5110_PrintBMP((Winning_cell_2 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_2 % 3), (Winning_cell_2 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_2 / 3), hoveredO, 0);
			Nokia5110_PrintBMP((Winning_cell_3 % 3) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_3 % 3), (Winning_cell_3 / 3 + 1) * (SQUAREHEIGHT - 1) + 3 * (Winning_cell_3 / 3), hoveredO, 0);
			
			ToggleLED(4);
			Clear_Led(2);
			Clear_Led(3);
			Clear_Led(4);
			GPIO_PORTF_DATA_R = 0x08;
			Nokia5110_DisplayBuffer();
		}
		
		Nokia5110_DisplayBuffer();
		Timer2_delay(5);
		GPIO_PORTF_DATA_R = 0x00; 
		Clear_Led(2);
		Clear_Led(3);
		Clear_Led(4);
		return 1; 
	}
	return 0; 
}

/************************************************************************************
 * Function Name:Display_Winner
 * Function Inputs: None
 * Description: Function to display the winner 
 ************************************************************************************/
void Display_Winner(char player)
{
	(player == 'X') ? xWins++ : oWins++; 
	Nokia5110_ClearBuffer();
	Nokia5110_PrintBMP(0, 47, border, 0); 
	Nokia5110_DisplayBuffer();
	Nokia5110_SetCursor(2, 3);
	Nokia5110_OutChar(player);
	Nokia5110_OutString("-Player");
	Nokia5110_SetCursor(4, 4);
	Nokia5110_OutString("wins");
	Timer2_delay(100);
	Nokia5110_DisplayBuffer();

	Nokia5110_SetCursor(2, 3);
	Nokia5110_OutString("X: ");
	Nokia5110_OutUDec(xWins);
	Nokia5110_SetCursor(2, 4);
	Nokia5110_OutString("O: ");
	Nokia5110_OutUDec(oWins);
	Timer2_delay(50);
	Nokia5110_Clear();
}

/************************************************************************************
 * Function Name:displayDraw
 * Function Inputs: None
 * Description: Function to display if the players is draw
 ************************************************************************************/
void displayDraw()
{
	GPIO_PORTF_DATA_R = 0x0E;
  ToggleLED(2);
	Timer2_delay(5);
	GPIO_PORTF_DATA_R = 0x00; 
	
	Nokia5110_SetCursor(1, 3);
	Nokia5110_OutString("Players");
	Nokia5110_SetCursor(1, 4);
	Nokia5110_OutString("are Draw");
	Timer2_delay(100);
	Nokia5110_Clear();
}

/************************************************************************************
 * Function Name:displayPlayer
 * Function Inputs : None
 * Description: Function to display whose has the role to play
 ************************************************************************************/
void displayPlayer()
{
	Nokia5110_SetCursor(7, 1);
	Nokia5110_OutChar('[');
	Nokia5110_OutChar(playletter);
	Nokia5110_OutChar(']');
	Nokia5110_SetCursor(7, 2);
	Nokia5110_OutString("Move");
}
/************************************************************************************
 * Function Name: CheckPlayAgain
 * Function Inputs : none
 * Description: function to ask player to play again or not
 ************************************************************************************/
int CheckPlayAgain()
{
	Nokia5110_ClearBuffer();
  Nokia5110_SetCursor(1, 1);
	Nokia5110_OutString("Play Again");
	Nokia5110_SetCursor(1, 3);
	Nokia5110_OutString("Right|Left");
	Nokia5110_SetCursor(1, 4);
	Nokia5110_OutString(" Yes | No");
	while (1)
	{
		if (Right == 1)
		{
			Right = 0;
			return 1;
		}

		if (Left == 1)
		{
			Left = 0;
			return 0;
		}
	}

}

/************************************************************************************
 * Function Name: CheckMode
 * Function Inputs : none
 * Description: function to select the mode of play (Switches- UART) 
 ************************************************************************************/
int CheckMode()
{
	Nokia5110_ClearBuffer();
  Nokia5110_SetCursor(0, 1);
	Nokia5110_OutString("Select Mode");
	Nokia5110_SetCursor(0, 3);
	Nokia5110_OutString("SWS | UART");
	Nokia5110_SetCursor(0, 4);
	Nokia5110_OutString("Left|Right");
	while (1)
	{
			if(!GPIO_enuReadPinValue(GPIOF,PIN4)){
			
       uart=1;
				return 1;
		}

			if(!GPIO_enuReadPinValue(GPIOF,PIN3)){
			uart=0;
				return 0;
		}

	}

}

void EndGame()
{ 
	Nokia5110_Clear();
}
