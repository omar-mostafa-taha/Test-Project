

#include "../../common/tm4c123gh6pm.h"
#include "LED.h"
#include "../TIMER/Timer.h"

#include "../GPIO/GPIO_interface.h"

int i;

void Set_Led(int led)
{
	GPIO_PORTB_DATA_R |= (1 << led); // PB3
}
void Clear_Led(int led)
{
	GPIO_PORTB_DATA_R &= ~(1 << led); // PB3
}

void ToggleLED(int led)
{
	for (i = 0; i < 3; i++)
	{
		GPIO_PORTB_DATA_R |= (1 << led); // PB3
		Timer2_delay(20);
		GPIO_PORTB_DATA_R &= ~(1 << led); // PB3
		Timer2_delay(20);
	}
}

