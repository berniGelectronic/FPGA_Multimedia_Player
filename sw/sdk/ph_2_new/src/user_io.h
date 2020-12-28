/*
 * user_io.h
 *
 *  Created on: 16 Jul 2020
 *      Author: admin
 */

#ifndef SRC_USER_IO_H_
#define SRC_USER_IO_H_

/*
 * define LEDS register positions to LED physical number
 */
#define LED1 0x01
#define LED2 0x02
#define LED3 0x04
#define LED4 0x08

#define LED_RGB1_B 0x01
#define LED_RGB1_G 0x02
#define LED_RGB1_R 0x04

#define LED_RGB2_B 0x08
#define LED_RGB2_G 0x10
#define LED_RGB2_R 0x20

/**
 * Define each button & SW reg value
 */
#define BTN_0	0x1
#define BTN_1	0x2
#define BTN_2	0x4
#define BTN_3	0x8

#define SW_0	0x1
#define SW_1	0x2

// Setup control menu buttons and switches
typedef enum {
	DEFAULT = 0,
	VOLUME,
	OPTIONAL1, 	//not yet implemented
	OPTIONAL2,	//not yet implemented
} switch_t;

typedef enum {
	PLAY = BTN_3,
	STOP = BTN_2,
	DOWN = BTN_1,
	UP = BTN_0
} button_t;

#endif /* SRC_USER_IO_H_ */
