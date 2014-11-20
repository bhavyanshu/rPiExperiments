/**
 * Program for PIRsensor. Detects movement and activates connected LED
 * for 2 seconds.
 * Connect on board pin number 07 to Sensor, 11 to LED - Refer http://www.airspayce.com/mikem/bcm2835/group__constants.html#ga63c029bd6500167152db4e57736d0939
 *
 * Copyright 2014 - Bhavyanshu Parasher
 * No restriction on distribution/modification of the source
 */

#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SENSOR RPI_GPIO_P1_07
#define LED RPI_GPIO_P1_11
#define ACTIVE_VALUE 1

int main(int argc, char **argv)
{
	if (!bcm2835_init()) {
	printf("Please run this with sudo\n");
	return EXIT_FAILURE;
	}

	bcm2835_gpio_fsel(SENSOR, BCM2835_GPIO_FSEL_INPT);	//SENSOR as input
	bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);		//LED as output
	bcm2835_gpio_set_pud(SENSOR, BCM2835_GPIO_PUD_UP);
	uint8_t state = ACTIVE_VALUE; //Init state to HIGH

	while (1) {
		state = bcm2835_gpio_lev(SENSOR); //HIGH or LOW?
		if(state != ACTIVE_VALUE)
		{
			//Sensor not active
		}
		else
		{
			printf("Movement at %d\n",(int)time(NULL));
			bcm2835_gpio_set(LED);
			//Comment out both system() lines if don't wanna play wav file
			system("omxplayer beep.wav");
			sleep(2);
			//Another extra overhead!
			system("killall omxplayer.bin");
			bcm2835_gpio_clr(LED);
		}
	}
bcm2835_close();
return EXIT_SUCCESS;
}
#undef SENSOR
#undef LED
#undef ACTIVE_VALUE