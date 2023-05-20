/*****************************************************************************************
 * File Name: GPIO_program.c
 *
 * Authors: Ahmed Nashaat - Mohamed Sherif - Kariem ALaa - Omar Mostafa - Omar Shabaan
 ****************************************************************************************/

#include "../../common/Types.h"
#include "../../common/BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "../../common/tm4c123gh6pm.h"



volatile unsigned long delay;
/************************************************************************************
 * Service Name:GPIO_vidSetPinDirection
 * Parameters (in): Port - PinNumber - Direction (INPUT - OUTPUT)
 * Return value: None
 * Description: function to set the direction of pins
 ************************************************************************************/
void GPIO_vidSetPinDirection(_enuGPIOx portNum, _enuPINx pinNum, _enuIOx pinDirection) {
	switch (portNum) {
		case GPIOA:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOA_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOA_DIR_R,pinNum);
			}
			break;
		case GPIOB:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOB_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOB_DIR_R,pinNum);
			}
			break;
		case GPIOC:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOC_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOC_DIR_R,pinNum);
			}
			break;
		case GPIOD:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOD_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOD_DIR_R,pinNum);
			}
			break;
		case GPIOE:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOE_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOE_DIR_R,pinNum);
			}
			break;
		case GPIOF:
			if (pinDirection == OUTPUT) {
				SET_BIT(GPIOF_DIR_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOF_DIR_R,pinNum);
			}
			break;
	}

}

/************************************************************************************
 * Service Name:GPIO_vidSetPinValue
 * Parameters (in): Port - PinNumber - PinValue (LOW - HIGH )
 * Return value: None
 * Description: function to set the the value of pins
 ************************************************************************************/
void GPIO_vidSetPinValue(_enuGPIOx portNum, _enuPINx pinNum, _enuPINVALUE pinValue) {
	switch (portNum) {
		case GPIOA:
			if (pinValue == HIGH) {
				SET_BIT(GPIOA_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOA_DATA_R,pinNum);
			}
			break;
		case GPIOB:
			if (pinValue == HIGH) {
				SET_BIT(GPIOB_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOB_DATA_R,pinNum);
			}
			break;
		case GPIOC:
			if (pinValue == HIGH) {
				SET_BIT(GPIOC_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOC_DATA_R,pinNum);
			}
			break;
		case GPIOD:
			if (pinValue == HIGH) {
				SET_BIT(GPIOD_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOD_DATA_R,pinNum);
			}
			break;
		case GPIOE:
			if (pinValue == HIGH) {
				SET_BIT(GPIOE_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOE_DATA_R,pinNum);
			}
			break;
		case GPIOF:
			if (pinValue == HIGH) {
				SET_BIT(GPIOF_DATA_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOF_DATA_R,pinNum);
			}
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidGetinDirection
 * Parameters (in): Port - PinNumber 
 * Return value: u8 PinValue
 * Description: function to get the value of pins
 ************************************************************************************/
_enuPINVALUE GPIO_enuReadPinValue(_enuGPIOx portNum, _enuPINx pinNum)
{
     _enuPINVALUE enuPinReturnedValue;

	switch(portNum)
	{
		case GPIOA:
			enuPinReturnedValue = GET_BIT(GPIOA_DATA_R,pinNum);
			break;
		case GPIOB:
			enuPinReturnedValue = GET_BIT(GPIOB_DATA_R,pinNum);
			break;
		case GPIOC:
			enuPinReturnedValue = GET_BIT(GPIOC_DATA_R,pinNum);
			break;
		case GPIOD:
			enuPinReturnedValue = GET_BIT(GPIOD_DATA_R,pinNum);
			break;
		case GPIOE:
			enuPinReturnedValue = GET_BIT(GPIOE_DATA_R,pinNum);
			break;
		case GPIOF:
			enuPinReturnedValue = GET_BIT(GPIOF_DATA_R,pinNum);
			break;
	}
	return enuPinReturnedValue;
}


void GPIO_vidTogglePin(_enuGPIOx portNum, _enuPINx pinNum)
{
	switch(portNum)
	{
		case GPIOA:
			TOG_BIT(GPIOA_DATA_R, pinNum);
		break;
		case GPIOB:
			TOG_BIT(GPIOB_DATA_R,pinNum);
		break;
		case GPIOC:
			TOG_BIT(GPIOC_DATA_R,pinNum);
		break;
		case GPIOD:
			TOG_BIT(GPIOD_DATA_R,pinNum);
			break;
		case GPIOE:
			TOG_BIT(GPIOE_DATA_R,pinNum);
			break;
		case GPIOF:
			TOG_BIT(GPIOF_DATA_R,pinNum);
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidSetPinDigEnable
 * Parameters (in): Port - PinNumber - DigEnable (ENABLE - DISABLE )
 * Return value: None
 * Description: function to set digital pins
 ************************************************************************************/
void GPIO_vidSetPinDigEnable(_enuGPIOx portNum, _enuPINx pinNum, _enuDigitalEnable DigitalEnable ) {
	switch (portNum) {
		case GPIOA:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOA_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOA_DEN_R,pinNum);
			}
		case GPIOB:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOB_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOB_DEN_R,pinNum);
			}
		case GPIOC:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOC_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOC_DEN_R,pinNum);
			}
		case GPIOD:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOD_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOD_DEN_R,pinNum);
			}
		case GPIOE:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOE_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOE_DEN_R,pinNum);
	          }

	    case GPIOF:
			if (DigitalEnable == ENABLE) {
				SET_BIT(GPIOF_DEN_R,pinNum);	
			}
			else {
				CLR_BIT(GPIOF_DEN_R,pinNum);
	          }
			}
}

/************************************************************************************
 * Service Name:GPIO_vidSetPUR
 * Parameters (in): Port - PinNumber - PURConfig (ENABLE - DISABLE)
 * Return value: None
 * Description: function to set pull up resistors for pins
 ************************************************************************************/
void GPIO_vidSetPUR(_enuGPIOx portNum, _enuPINx pinNum, u8 u8PURConfig)
{
switch (portNum) {
		case GPIOA:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOA_PUR_R, pinNum);	
			}
			else {
				CLR_BIT(GPIOA_PUR_R, pinNum);
			}
			break;
		case GPIOB:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOB_PUR_R, pinNum);	
			}
			else {
				CLR_BIT(GPIOB_PUR_R, pinNum);
			}
			break;
		case GPIOC:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOC_PUR_R, pinNum);	
			}
			else {
				CLR_BIT(GPIOB_PUR_R, pinNum);
			}
			break;
		case GPIOD:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOD_PUR_R, pinNum);
			}
			else {
				CLR_BIT(GPIOD_PUR_R, pinNum);
			}
			break;
		case GPIOE:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOE_PUR_R, pinNum);
			}
			else {
				CLR_BIT(GPIOE_PUR_R, pinNum);
			}
			break;
		case GPIOF:
			if (u8PURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOF_PUR_R, pinNum);
			}
			else {
				CLR_BIT(GPIOF_PUR_R, pinNum);
			}
			break;
	}
}
/************************************************************************************
 * Service Name:GPIO_vidSelectAlterFunction
 * Parameters (in): Port - PinNumber 
 * Return value: None
 * Description: function to set the alternate function for pins
 ************************************************************************************/
void GPIO_vidSelectAlterFunction(_enuGPIOx portNum, _enuPINx pinNum)
 {
	switch(portNum) {
		case GPIOA:
			SET_BIT(GPIOA_AFSEL_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIOB_AFSEL_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIOC_AFSEL_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIOD_AFSEL_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIOE_AFSEL_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIOF_AFSEL_R, pinNum);
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidEnableInterrupt
 * Parameters (in): Port - PinNumber
 * Return value: None
 * Description: function to enable interrupts for pins
 ************************************************************************************/
void GPIO_vidEnableInterrupt(_enuGPIOx portNum, _enuPINx pinNum)
{
switch(portNum) {
		case GPIOA:
			SET_BIT(GPIOA_IM_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIOB_IM_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIOC_IM_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIOD_IM_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIOE_IM_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIOF_IM_R,pinNum);
			break;
	}
}


/************************************************************************************
 * Service Name:GPIO_vidSelectInterruptSense
 * Parameters (in): Port - PinNumber - Sense (EGGE - LEVEL)
 * Return value: None
 * Description: function to select interrupt detection mechanism for pins
 ************************************************************************************/
void GPIO_vidSelectInterruptSense(_enuGPIOx portNum, _enuPINx pinNum, u8 u8Sense)
{
	switch (portNum)
	{
		case GPIOA:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOA_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOA_IS_R,pinNum);
			}
			break;
		case GPIOB:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOB_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOB_IS_R,pinNum);
			}
			break;
		case GPIOC:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOC_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOC_IS_R,pinNum);
			}
			break;
		case GPIOD:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOD_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOD_IS_R,pinNum);
			}
			break;
		case GPIOE:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOE_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOE_IS_R,pinNum);
			}
			break;
    	case GPIOF:
			if (u8Sense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOF_IS_R , pinNum);
			}
			else
			{
				SET_BIT(GPIOF_IS_R,pinNum);
			}
			break;
	}

}

/************************************************************************************
 * Service Name:GPIO_vidDisableInterrupt
 * Parameters (in): Port - PinNumber
 * Return value: None
 * Description: function to Disable Interrupt for pins
 ************************************************************************************/
void GPIO_vidDisableInterrupt(_enuGPIOx portNum, _enuPINx pinNum)
{
switch(portNum) {
		case GPIOA:
			CLR_BIT(GPIOA_IM_R, pinNum);
			break;
		case GPIOB:
			CLR_BIT(GPIOB_IM_R, pinNum);
			break;
		case GPIOC:
			CLR_BIT(GPIOC_IM_R, pinNum);
			break;
		case GPIOD:
			CLR_BIT(GPIOD_IM_R, pinNum);
			break;
		case GPIOE:
			CLR_BIT(GPIOE_IM_R, pinNum);
			break;
		case GPIOF:
			CLR_BIT(GPIOF_IM_R, pinNum);
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidClearInterrupts
 * Parameters (in): Port - PinNumber 
 * Return value: None
 * Description: function to Clear Interrups for pins
 ************************************************************************************/
void GPIO_vidClearInterrupt(_enuGPIOx portNum, _enuPINx pinNum)
{
	switch(portNum)
	{
		case GPIOA:
			SET_BIT(GPIOA_ICR_R, pinNum);
			break;
		case GPIOB:
			SET_BIT(GPIOB_ICR_R, pinNum);
			break;
		case GPIOC:
			SET_BIT(GPIOC_ICR_R, pinNum);
			break;
		case GPIOD:
			SET_BIT(GPIOD_ICR_R, pinNum);
			break;
		case GPIOE:
			SET_BIT(GPIOE_ICR_R, pinNum);
			break;
		case GPIOF:
			SET_BIT(GPIOF_ICR_R, pinNum);
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidUnlock
 * Parameters (in): Port 
 * Return value: None
 * Description: function to unlock ports
 ************************************************************************************/
void GPIO_vidUnlock(_enuGPIOx portNum)
{
	switch(portNum)
	{
		case GPIOA:
				GPIOA_LOCK_R = 0x4C4F434B;
			break;
		case GPIOB:
				GPIOB_LOCK_R = 0x4C4F434B;
			break;
		case GPIOC:
				GPIOC_LOCK_R = 0x4C4F434B;
			break;
		case GPIOD:
				GPIOD_LOCK_R = 0x4C4F434B;
			break;
		case GPIOE:
				GPIOE_LOCK_R = 0x4C4F434B;
			break;
		case GPIOF:
				GPIOF_LOCK_R = 0x4C4F434B;
			break;
	}
}

/************************************************************************************
 * Service Name:GPIO_vidlock
 * Parameters (in): Port
 * Return value: None
 * Description: function to lock ports
 ************************************************************************************/
void GPIO_vidLock(_enuGPIOx portNum)
{
	switch(portNum)
	{
		case GPIOA:
			GPIOA_LOCK_R = 0;
			break;
		case GPIOB:
			GPIOB_LOCK_R = 0;
			break;
		case GPIOC:
			GPIOC_LOCK_R = 0;
			break;
		case GPIOD:
			GPIOD_LOCK_R = 0;
			break;
		case GPIOE:
			GPIOE_LOCK_R = 0;
			break;
		case GPIOF:
			GPIOF_LOCK_R = 0;
			break;
	}
}



void GPIO_vidSelectInterruptEvent(_enuGPIOx portNum, _enuPINx pinNum, u8 u8Event)
{
	switch(portNum)
	{
		case GPIOA:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOA_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOA_IEV_R, pinNum);
			}
			break;
		case GPIOB:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOB_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOB_IEV_R, pinNum);
			}
			break;
		case GPIOC:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOC_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOC_IEV_R, pinNum);
			}
			break;
		case GPIOD:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOD_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOD_IEV_R, pinNum);
			}
			break;
		case GPIOE:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOE_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOE_IEV_R, pinNum);
			}
			break;
		case GPIOF:
			if (u8Event == GPIO_HL_RE)
			{
				SET_BIT(GPIOF_IEV_R,pinNum);
			}
			else
			{
				CLR_BIT(GPIOF_IEV_R, pinNum);
			}
			break;
	}
}


void GPIO_vidInterruptBothEdges(_enuGPIOx portNum, _enuPINx pinNum , u8 u8BothEdges)
{
	switch(portNum)
	{
		case GPIOA:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOA_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOA_IBE_R, pinNum);
			}
			break;
		case GPIOB:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOB_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOB_IBE_R, pinNum);
			}
			break;
		case GPIOC:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOC_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOC_IBE_R, pinNum);
			}
			break;
		case GPIOD:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOD_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOD_IBE_R, pinNum);
			}
			break;
		case GPIOE:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOE_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOE_IBE_R, pinNum);
			}
			break;
		case GPIOF:
			if (u8BothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOF_IBE_R, pinNum);
			}
			else
			{
				CLR_BIT(GPIOF_IBE_R, pinNum);
			}
			break;
	}
}

void PortF_Init(void)
{ 

  SYSCTL_RCGC2_R |= 0x00000020;   // 1) F clock
  delay = SYSCTL_RCGC2_R;         // delay
	GPIO_vidUnlock(GPIOF);
  GPIOF_CR_R = 0x1F;         // allow changes to PF4-0
  GPIOF_AMSEL_R = 0x00;      // 3) disable analog function
  GPIOF_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIOF_AFSEL_R = 0x00;      // 6) no alternate function
  NVIC_PRI7_R = (NVIC_PRI7_R & 0xff00ffff) | 0x00A00000;
  //EnableInterrupts();
}

void PortB_Init(void)
{

  SYSCTL_RCGC2_R |= 0x00000002;   // 1) B clock
  delay = SYSCTL_RCGCGPIO_R;      // delay
  GPIO_PORTB_LOCK_R = 0x4C4F434B; // 2)unlock GPIO of PORTB
  GPIO_PORTB_CR_R = 0x01;         // Enable commit
  GPIO_PORTB_AMSEL_R = 0x00;      // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIO_PORTB_DIR_R = 0x3F ;        // 5) PORT output
  GPIO_PORTB_AFSEL_R = 0x00;      // 6) no alternate function
  GPIO_PORTB_DEN_R = 0xFF;        // 7) enable digital pins PF4-PF0

}


