/*
 * H-Bridge.c
 *
 * Created: 6/21/2022 5:11:31 PM
 * Author : Dell
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "Headers.h"
#include "H_Bridge.h"
int main(void)
{
	init_HBridge();
	//set motor to 50% duty cycle
	set_motor_speed(127,127);

	//set motor to 100% duty cycle 255
	//set set motor speed to 75% duty cycle 191
	//set set motor speed to 50% duty cycle 127
	//set motor to 25% duty cycle 64


    while (1)
    {
		forward();
		_delay_ms(3000);
		stop();
		_delay_ms(3000);
		backward();
		_delay_ms(3000);
		left();
		_delay_ms(3000);
		right();
		_delay_ms(3000);
		rotate_right();
		_delay_ms(3000);
		rotate_left();
		_delay_ms(3000);
    }
}
