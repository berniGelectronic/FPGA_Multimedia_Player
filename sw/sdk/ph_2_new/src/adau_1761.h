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

//Address 0x4002 + 48 bits PLL Value (from ADAU 1761 datasheet or SigmaStudio)
u8 PLL_44[]={ADAU_1761_PLL_CONTROL>>8,(u8)ADAU_1761_PLL_CONTROL,0x02,0x71,0x01,0x93,0x29,0x01};
u8 PLL_48[]={ADAU_1761_PLL_CONTROL>>8,(u8)ADAU_1761_PLL_CONTROL,0x00,0x7D,0x00,0x12,0x31,0x01};


struct register_values {
	u16 addr;
	u8 value;
};

const struct register_values adau_1761_reg[] = {
	{ ADAU_1761_CLK_ENABLE0,			0x7F }, // SLEWPD=1, ALCPD=1, DECPD=1, SOUTPD=1, INTPD=1, SINPD=1, SPPD=1
	{ ADAU_1761_CLK_ENABLE1,			0x03 }, // CLK1=1, CLK0=1
	{ ADAU_1761_SERIAL_PORT_0,			0x01 }, // SPSRS=0, LRMOD=0, BPOL=0, LRPOL=0, CHPF=0, MS=1 (master mode)
	{ ADAU_1761_SERIAL_PORT_1,			0x00 }, // BPF=0, ADTDM=0, DATDM=0, MSBP=0, LRDEL=0
	{ ADAU_1761_CONVERTER_0,			0x00 }, // DAPAIR=0, DAOSR=0, ADOSR=0, CONVSR=0
	{ ADAU_1761_PLAY_MIXER_LEFT0,		0x21 }, // MX3RM=0, MX3LM=1, MX3AUXG=0, MX3EN=1
	{ ADAU_1761_PLAY_MIXER_RIGHT0,		0x41 }, // MX4RM=1, MX4LM=0, MX4AUXG=0, MX4EN=1
	{ ADAU_1761_PLAY_HP_LEFT_VOL,		initialVolume }, //LHPVOL=011011, LHPM=1, HPEN=1
	{ ADAU_1761_PLAY_HP_RIGHT_VOL,	    initialVolume }, //RHPVOL=011011, RHPM=1, HPMODE=1
	{ ADAU_1761_PLAY_POWER_MGMT,		0x03 }, // HPBIAS=0, DACBIAS=0, PBIAS=0, PREN=1, PLEN=1
	{ ADAU_1761_DAC_CONTROL,			0x23 }, // DACMONO=0, DACPOL=1,DEMPH=0, DACEN=3
	{ ADAU_1761_SERIAL_INPUT_ROUTE,		0x01 }  // SINRT=1 -Serial input [L0, R0] to DACs [L, R]
};

struct channel{
	u8 left;
	u8 right;
};
typedef struct{
	 struct channel volume;
}output_t;



#endif /* SRC_ADAU_1761_H_ */
