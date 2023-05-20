/*****************************************************************************************
 * File Name: NVIC_program.c
 *
 * Authors: Ahmed Nashaat - Mohamed Sherif - Kariem ALaa - Omar Mostafa - Omar Shabaan
 ****************************************************************************************/

#include "../../common/Types.h"
#include "../../common/BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void NVIC_vidEnableInterrupt(u8 u8InterruptNumber)
{
    if(u8InterruptNumber <= 31)
    {
        NVIC_EN0_R = (1 << u8InterruptNumber);
    }
    else if(u8InterruptNumber <= 63)
    {
        u8InterruptNumber -= 32;
        NVIC_EN1_R = (1 << u8InterruptNumber);
    }
}


void NVIC_vidDisableInterrupt(u8 u8InterruptNumber)
{
    if(u8InterruptNumber <= 31)
    {
        NVIC_DIS0_R = (1 << u8InterruptNumber);
    }
    else if(u8InterruptNumber <= 63)
    {
        u8InterruptNumber -= 32;
        NVIC_DIS1_R = (1 << u8InterruptNumber);
    }
}


void NVIC_vidSetPendingFlag(u8 u8InterruptNumber)
{
    if(u8InterruptNumber <= 31)
    {
        NVIC_PEND0_R = (1 << u8InterruptNumber);
    }
    else if(u8InterruptNumber <= 63)
    {
        u8InterruptNumber -= 32;
       NVIC_PEND1_R= (1 << u8InterruptNumber);
    }
}

void NVIC_vidClearPendingFlag(u8 u8InterruptNumber)
{
    if(u8InterruptNumber <= 31)
    {
        NVIC_UNPEND0_R = (1 << u8InterruptNumber);
    }
    else if(u8InterruptNumber <= 63)
    {
        u8InterruptNumber -= 32;
       NVIC_UNPEND1_R = (1 << u8InterruptNumber);
    }
}




