/*
 * GPIO_LEDs.h
 *
 *  Created on: 9 Jan 2021
 *      Author: oliver
 */

#ifndef SRC_GPIO_LEDS_H_
#define SRC_GPIO_LEDS_H_

#include "xgpio.h"

#define SINGLE_LED_CHANNEL 1
#define RGB_LED_CHANNEL    2


// for loop value for LED test
#define LED_DELAY     10000000

extern XGpio Gpio_LEDs; /* The Instance of the GPIO Driver */

void turnOffLEDS(XGpio Gpio_LEDs);
void Single_LED_test(int LED_NUM);

#endif /* SRC_GPIO_LEDS_H_ */
