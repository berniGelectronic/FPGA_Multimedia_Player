/*
 * GPIO_LEDs.c
 *
 *  Created on: 9 Jan 2021
 *      Author: oliver
 */
#include "GPIO_LEDs.h"
#include "xgpio.h"

XGpio Gpio_LEDs; /* The Instance of the GPIO Driver */

void turnOffLEDS(XGpio Gpio_LEDs){
	XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, 0x00);
}

void Single_LED_test(int LED_NUM) {
	volatile int Delay;
	/* Set the LED to High */
	XGpio_DiscreteWrite(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED_NUM);

#ifdef TESTING
	print("led  4 ON \n\r");
#endif

	/* Wait a small amount of time so the LED is visible */
	for (Delay = 0; Delay < LED_DELAY; Delay++)
		;

	/* Clear the LED bit */
	XGpio_DiscreteClear(&Gpio_LEDs, SINGLE_LED_CHANNEL, LED_NUM);

#ifdef TESTING
	print("led  4 OFF \n\r");
#endif

	/* Wait a small amount of time so the LED is visible */
	for (Delay = 0; Delay < LED_DELAY; Delay++)
		;
}


/*****************************************************************************/
void rgb_test(int LED_RGB_VAL) {
	volatile int Delay;
	/* Set the LED to High */
	XGpio_DiscreteWrite(&Gpio_LEDs, RGB_LED_CHANNEL, LED_RGB_VAL);

#ifdef TESTING
	print("led  4 ON \n\r");
#endif

	/* Wait a small amount of time so the LED is visible */
	for (Delay = 0; Delay < LED_DELAY; Delay++)
		;

	/* Clear the LED bit */
	XGpio_DiscreteClear(&Gpio_LEDs, RGB_LED_CHANNEL, LED_RGB_VAL);

#ifdef TESTING
	print("led  4 OFF \n\r");
#endif

	/* Wait a small amount of time so the LED is visible */
	for (Delay = 0; Delay < LED_DELAY; Delay++)
		;
}
