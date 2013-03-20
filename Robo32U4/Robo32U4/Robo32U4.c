/*
 * Robo32U4.c
 *
 * Created: 19/03/2013 21:50:43
 *  Author: oriol
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void InitPWM()
{
	TCCR0B = 1 << CS00; //Enable counter with no prescaling
	//Set 8-bit fast PWM mode
	TCCR0A|=(1<<WGM00)|(1<<WGM01)|(1<<CS00)|(1<<COM0A1);
	
	//Initialize port D as output
	DDRB|=(1 << PB7);
}

void SetPWMOutput(uint8_t duty)
{
	OCR0A=duty;
}


int main(void)
{
	uint8_t brightness=125;

	//Initialize PWM Channel 0
	InitPWM();

	while(1)
	{
		SetPWMOutput(brightness);

		
	}
}