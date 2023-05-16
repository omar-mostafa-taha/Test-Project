
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

