
#include "./drivers/NOKIA5110/Nokia5110.h"
#include "./common/TExaS.h"
#include "./common/XO Game.h"
#include "./drivers/GPIO/GPIO_interface.h"
#include "./drivers/NVIC/NVIC_interface.h"
#include "./common/tm4c123gh6pm.h"
#include "./drivers/TIMER/Timer.h"
#include "./drivers/UART/UART.h"
void vidButtonsInit();
int CheckMode();
char n;
int uart =0;
unsigned char Right = 0, Left = 0, Up = 0, Dwon = 0, Sw5Flag = 0;
int main(void)
{
 	TExaS_Init(SSI0_Real_Nokia5110_Scope);

	PortF_Init(); 
	PortB_Init();
    UART_Init();
	vidButtonsInit();
	Nokia5110_Init(); 
	Nokia5110_ClearBuffer(); 
	Nokia5110_DisplayBuffer(); 
	Intro(); 
    CheckMode();
	GameReset(); 
	DrawGrid(); 
	

	while (1)
	{
		
		
		if(!GPIO_enuReadPinValue(GPIOF,PIN4)){
			 NVIC_vidEnableInterrupt(30);
       NVIC_vidSetPendingFlag(30);
		}

		
		if(!GPIO_enuReadPinValue(GPIOF,PIN3)){
			 NVIC_vidEnableInterrupt(30);
       NVIC_vidSetPendingFlag(30);
		}
		
		if(!GPIO_enuReadPinValue(GPIOF,PIN2)){
			 NVIC_vidEnableInterrupt(30);
       NVIC_vidSetPendingFlag(30);
		}
		
		if(!GPIO_enuReadPinValue(GPIOF,PIN1)){
			 NVIC_vidEnableInterrupt(30);
       NVIC_vidSetPendingFlag(30);
		}
		
			if(!GPIO_enuReadPinValue(GPIOF,PIN0)){
			 NVIC_vidEnableInterrupt(30);
       NVIC_vidSetPendingFlag(30);
		}


		if(uart==1){
			
		UART_OutString("\n\r W-> Up  S-> Dwon  D->Right  A-> Left  X-> Play: ");
     n = UART_InChar();
   UART_OutChar(n);
		UART_OutString("\n\r");
		switch(n){
			case 'd':
				Right=1;
			break;
			case 'a':
				Left=1;
			break;
			case 'w':
				Up=1;
			break;
			case 's':
				Dwon=1;
			break;
			case 'x':
				Sw5Flag=1;
			break;
		
		}
		}

		StartGame(); 
	}
}





/************************************************************************************
 * Function Name: vidButtonsInit
 * Function Inputs : none
 * Description: Initialize the directional buttons
 ************************************************************************************/
void vidButtonsInit(){
	/*Set Pinns direction from PF0 to PF4  as an INPUT bins*/
	GPIO_vidSetPinDirection(GPIOF, PIN0, INPUT);
	GPIO_vidSetPinDirection(GPIOF, PIN1, INPUT);
	GPIO_vidSetPinDirection(GPIOF, PIN2, INPUT);
	GPIO_vidSetPinDirection(GPIOF, PIN3, INPUT);
	GPIO_vidSetPinDirection(GPIOF, PIN4, INPUT);

	/*Set Pull up resistor for pins from PF0 to PF4*/
	GPIO_vidSetPUR(GPIOF, PIN0, 1);
	GPIO_vidSetPUR(GPIOF, PIN1, 1);
	GPIO_vidSetPUR(GPIOF, PIN2, 1);
	GPIO_vidSetPUR(GPIOF, PIN3, 1);
	GPIO_vidSetPUR(GPIOF, PIN4, 1);

    /*Enable digital pins from PF0 to PF4*/
	GPIO_vidSetPinDigEnable(GPIOF,PIN0, ENABLE );
	GPIO_vidSetPinDigEnable(GPIOF,PIN1, ENABLE );
	GPIO_vidSetPinDigEnable(GPIOF,PIN2, ENABLE );
	GPIO_vidSetPinDigEnable(GPIOF,PIN3, ENABLE );
	GPIO_vidSetPinDigEnable(GPIOF,PIN4, ENABLE );
	
	/*Set Interrupt sense  to edge*/
    GPIO_vidSelectInterruptSense(GPIOF, PIN0, GPIO_SENSE_EDGE);
	GPIO_vidSelectInterruptSense(GPIOF, PIN1, GPIO_SENSE_EDGE);
	GPIO_vidSelectInterruptSense(GPIOF, PIN2, GPIO_SENSE_EDGE);
	GPIO_vidSelectInterruptSense(GPIOF, PIN3, GPIO_SENSE_EDGE);
    GPIO_vidSelectInterruptSense(GPIOF, PIN4, GPIO_SENSE_EDGE);
	
	/*Clear inyerrupt from pins */
	GPIO_vidClearInterrupt(GPIOF, PIN0);
	GPIO_vidClearInterrupt(GPIOF, PIN1);
	GPIO_vidClearInterrupt(GPIOF, PIN2);
	GPIO_vidClearInterrupt(GPIOF, PIN3);
	GPIO_vidClearInterrupt(GPIOF, PIN4);
    
	/*Enable Interrupt to pins*/
	GPIO_vidEnableInterrupt(GPIOF, PIN0);
	GPIO_vidEnableInterrupt(GPIOF, PIN1);
	GPIO_vidEnableInterrupt(GPIOF, PIN2);
	GPIO_vidEnableInterrupt(GPIOF, PIN3);		
	GPIO_vidEnableInterrupt(GPIOF, PIN4);
	
	/*Select the falling edge as an interrupt event*/
	GPIO_vidSelectInterruptEvent(GPIOF, PIN0, GPIO_LL_FE );
	GPIO_vidSelectInterruptEvent(GPIOF, PIN1, GPIO_LL_FE );
	GPIO_vidSelectInterruptEvent(GPIOF, PIN2, GPIO_LL_FE );
	GPIO_vidSelectInterruptEvent(GPIOF, PIN3, GPIO_LL_FE );
	GPIO_vidSelectInterruptEvent(GPIOF, PIN4, GPIO_LL_FE );
	
    GPIO_vidInterruptBothEdges(GPIOF, PIN0, 0);
    GPIO_vidInterruptBothEdges(GPIOF, PIN1, 0);
    GPIO_vidInterruptBothEdges(GPIOF, PIN2, 0);
    GPIO_vidInterruptBothEdges(GPIOF, PIN3, 0);
    GPIO_vidInterruptBothEdges(GPIOF, PIN4, 0);
}


/************************************************************************************
 * Function Name: GPIOPortF_Handler
 * Function Inputs : none
 * Description: Function to handle the interrupts of switchs
 ************************************************************************************/
void GPIOPortF_Handler(void)
{
  while (GPIO_PORTF_MIS_R != 0)
  {
		
	 if (GPIO_PORTF_MIS_R & 0x01) 
    {                                 
      Timer2_delay(5);
      if (!(GPIO_enuReadPinValue(GPIOF, PIN0)))
      {
        Sw5Flag = 1;
        GPIO_vidClearInterrupt(GPIOF, PIN0);
      }
    }
    if (GPIO_PORTF_MIS_R & 0x10) 
    {                      
      Timer2_delay(5);
      if (!(GPIO_enuReadPinValue(GPIOF, PIN4)))
      {
        Right = 1;
        GPIO_vidClearInterrupt(GPIOF, PIN4);
      }
    }
		
		if (GPIO_PORTF_MIS_R & 0x08) 
    {                            
 
      Timer2_delay(5);
      if (!(GPIO_enuReadPinValue(GPIOF, PIN3)))
      {
        Left = 1;
        GPIO_vidClearInterrupt(GPIOF, PIN3);
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x04) 
    {                            

      Timer2_delay(5);
      if (!(GPIO_enuReadPinValue(GPIOF, PIN2)))
      {
        Up = 1;
        GPIO_vidClearInterrupt(GPIOF, PIN2);
      }
    }
		
		 if (GPIO_PORTF_MIS_R & 0x02) 
    {                           
      Timer2_delay(5);
      if (!(GPIO_enuReadPinValue(GPIOF, PIN1)))
      {
        Dwon = 1;
       GPIO_vidClearInterrupt(GPIOF, PIN1);
      }
    }

    else
    { 
      GPIO_PORTF_ICR_R = GPIO_PORTF_MIS_R;
    }
  }
}





