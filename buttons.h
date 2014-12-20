/*
 * buttons.h
 *
 *  Created on: Dec 18, 2014
 *      Author: dawid
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <stdbool.h>
#include <stdint.h>

const int buttons_delayBouncing = 30;

typedef struct
{
	volatile uint8_t * DDR;
	volatile uint8_t * PORT;
	volatile uint8_t * PIN;
	uint8_t INOUT;
}Button;

void buttons_init(const Button * button);
bool buttons_isPressed(const Button * button);

#endif /* BUTTONS_H_ */
