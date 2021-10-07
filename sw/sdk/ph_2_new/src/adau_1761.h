/*
 * adau_1761.h
 *
 *  Created on: 8 Jun 2020
 *      Author: admin
 */

#ifndef SRC_ADAU_1761_H_
#define SRC_ADAU_1761_H_

#include "xil_types.h"

#define CODEC_ADDRESS 0x3B // 011 1011 3B

//CODEC Register ADDRESSES
#define ADAU_1761_CLOCK_CONTROL    	    0x4000
#define ADAU_1761_PLL_CONTROL       	0x4002
#define ADAU_1761_SERIAL_PORT_0			0x4015
#define ADAU_1761_SERIAL_PORT_1			0x4016
#define ADAU_1761_CONVERTER_0			0x4017
#define ADAU_1761_PLAY_MIXER_LEFT0		0x401C
#define ADAU_1761_PLAY_MIXER_LEFT1		0x401D
#define ADAU_1761_PLAY_MIXER_RIGHT0		0x401E
#define ADAU_1761_PLAY_MIXER_RIGHT1		0x401F
#define ADAU_1761_PLAY_LR_MIXER_LEFT	0x4020
#define ADAU_1761_PLAY_LR_MIXER_RIGHT	0x4021
#define ADAU_1761_PLAY_MIXER_MONO		0x4022
#define ADAU_1761_PLAY_HP_LEFT_VOL		0x4023
#define ADAU_1761_PLAY_HP_RIGHT_VOL		0x4024
#define ADAU_1761_PLAY_LINE_LEFT_VOL	0x4025
#define ADAU_1761_PLAY_LINE_RIGHT_VOL	0x4026
#define ADAU_1761_PLAY_POWER_MGMT		0x4029
#define ADAU_1761_DAC_CONTROL			0x402A
#define ADAU_1761_SERIAL_INPUT_ROUTE	0x40F2
#define ADAU_1761_CLK_ENABLE0			0x40F9
#define ADAU_1761_CLK_ENABLE1			0x40FA

#define PLL_SF_44 0x027101932901  //PLL register value for sampling frequency of 44.1KHZ
#define PLL_SF_48 0x007D00123101  //PLL register value for sampling frequency of 48KHZ

#define defaultVolume 30	// 30 dec
#define initialVolume ((defaultVolume<<2) | 0x03)	// 0x03 ==> first 2 bits for HPEN, LHPM


#define MAX_Volume 63 //maximum volume value
#define MIN_Volume 0  //minimum volume value
#define volumeStep 3  //increasing/decreasing volume step

//Supported sampling frequencies
#define samplingFrequency1 44100
#define samplingFrequency2 48000

#define defaultSamplingFrequency samplingFrequency1 // because it's the most popular one

struct register_values {
	u16 addr;
	u8 value;
};

struct channel{
	u8 left;
	u8 right;
};

typedef struct{
	 struct channel volume;
}output_t;


#endif /* SRC_ADAU_1761_H_ */
