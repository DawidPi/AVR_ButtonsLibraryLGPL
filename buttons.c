/*
 * buttons.c
 *
 *  Created on: Dec 18, 2014
 *      Author: dawid
 */

#include "buttons.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

static  const Button* recentButton;
static bool button_executed;

static inline bool isPressed(const Button *const button)
{
	if(((*(button->PIN)) & _BV(button->INOUT)) == 0)
		return true;
	else
		return false;
}

void buttons_init(const Button* button)
{
	(*(button->DDR)) &= ~_BV(button->INOUT); //input
	(*(button->PORT)) |= _BV(button->INOUT); //PIN gets high xD
}

bool buttons_isPressed(const Button* button)
{
	if(isPressed(button))
	{
		if(*button == *recentButton)
		{
			if(!button_executed)
			{
				_delay_ms(buttons_delayBouncing);
				if(isPressed(button))
				{
					button_executed = true;
					return true;
				}
				else
				{
					button_executed = false;
					recentButton = NULL;
					return false;
				}
			}
			else
				return false;
		}
		else
		{
			recentButton = button;
			button_executed=false;
			return false;
		}
	}
	else
	{
		recentButton = NULL;
		button_executed=false;
		return false;
	}
}
