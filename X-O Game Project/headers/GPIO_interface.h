#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "Types.h"

typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF
}_enuGPIOx;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7 
}_enuPINx;

typedef enum
{
    INPUT = 0,
    OUTPUT
}_enuIOx;

typedef enum
{
    LOW = 0,
    HIGH
}_enuPINVALUE;

typedef enum
{
   DISABLE =0 ,
   ENABLE
}_enuDigitalEnable;


#define GPIO_PUR_DISABLED 0
#define GPIO_PUR_ENABLED 1

#define GPIO_SENSE_EDGE 0
#define GPIO_SENSE_LEVEL 1

#define GPIO_LL_FE 0
#define GPIO_HL_RE 1

#define GPIO_INTERRUPT_EVENTCONTROLLED 0
#define GPIO_INTERRUPT_BOTHEDGES 1

void GPIO_vidSetPinDirection(_enuGPIOx portNum, _enuPINx pinNum, _enuIOx pinDirection);
void GPIO_vidSetPinValue(_enuGPIOx portNum, _enuPINx pinNum, _enuPINVALUE pinValue);
_enuPINVALUE GPIO_enuReadPinValue(_enuGPIOx portNum, _enuPINx pinNum);
void GPIO_vidSetPinDigEnable(_enuGPIOx portNum, _enuPINx pinNum, _enuDigitalEnable DigitalEnable );
void GPIO_vidDisableInterrupt(_enuGPIOx portNum, _enuPINx pinNum);

void GPIO_vidSetPUR(_enuGPIOx portNum, _enuPINx pinNum, u8 u8PURConfig);
void GPIO_vidSelectInterruptSense(_enuGPIOx portNum, _enuPINx pinNum, u8 u8Sense);
void GPIO_vidEnableInterrupt(_enuGPIOx portNum, _enuPINx pinNum);
void GPIO_vidClearInterrupt(_enuGPIOx portNum, _enuPINx pinNum);
void GPIO_vidUnlock(_enuGPIOx portNum);
void GPIO_vidInterruptBothEdges(_enuGPIOx portNum, _enuPINx pinNum , u8 u8BothEdges);
void GPIO_vidSelectInterruptEvent(_enuGPIOx portNum, _enuPINx pinNum, u8 u8Event);
void PortF_Init(); 
void PortB_Init();
void EnableInterrupts(void);

#endif