/*
 * audio.c
 *
 *  Created on: 24 Sep 2021
 *      Author: admin
 */


#include "audio.h"
#include "sleep.h"


//Address 0x4002 + 48 bits PLL Value (from ADAU 1761 datasheet or SigmaStudio)
u8 PLL_44[]={ADAU_1761_PLL_CONTROL>>8,(u8)ADAU_1761_PLL_CONTROL,0x02,0x71,0x01,0x93,0x29,0x01};
u8 PLL_48[]={ADAU_1761_PLL_CONTROL>>8,(u8)ADAU_1761_PLL_CONTROL,0x00,0x7D,0x00,0x12,0x31,0x01};

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

/**
 * Writes the correct PLL value for the selected sampling frequency
 * Supports only 2 sampling rates, 44.1kHz and 48kHz
 *
 * @param 	sampling_rate	 	sample rate to write to the codec
 *
 * @return  None
 *
 * @note	PLL lock time required for the codec to set Lock Bit in register 0x4002
 */
void setCodecPLL(XIic *I2C, int sampling_rate) {
	int bytes = 9;

	switch (sampling_rate) {
	case 44100:
		XIic_MasterSend(I2C, PLL_44, bytes);
		#ifdef DEBUG
			xil_printf("\n\r SAMPLING FREQUENCY SET: 44100");
		#endif
		break;
	case 48000:
		XIic_MasterSend(I2C, PLL_48, bytes);
		#ifdef DEBUG
			xil_printf("\n\r SAMPLING FREQUENCY SET: 48000");
		#endif
		break;
	default:
		#ifdef DEBUG
			xil_printf("\n\r ***ERROR_PLL***");
		#endif
		break;
	}

	usleep(10 * 1000); //PLL LOCK time

	// according to the https://github.com/logicbricks/driver_alsa_logii2s/blob/master/test/app_i2s_test_linux/adau1761.c PLL lock time
}

/**
 * Sets volume for both channels (Stereo), volume can be incremented in min 1 step, total 64 steps
 * Table 95, page 90 ADAU 1761 Datasheet
 * volume: 0  [dec] 	equals to -57dB   -- Silent
 * volume: 63 [dec] 	equals to   6dB	  -- Highest volume
 *
 * @param 	output_t 	points to the structure of headphones
 * @param 	volume 		is the volume to be set
 *
 * @return  None
 *
 * @note	None
 */
void setVolume(output_t *HP, u8 volume) {
	u8 setFlag=0x03;	//higher 6bits are volume, 2bits for enable hp,
	HP->volume.left = volume;
	HP->volume.right = volume;

	I2C_send(ADAU_1761_PLAY_HP_LEFT_VOL, (HP->volume.left << 2) | setFlag);
	I2C_send(ADAU_1761_PLAY_HP_RIGHT_VOL, (HP->volume.right << 2) | setFlag);

//		xil_printf("\n\r !!VOLUME_SET!!! ");
#ifdef DEBUG
		xil_printf("\n\r volume.left = %02x ",HP->volume.left);
		xil_printf("\n\r volume.right = %02x ",HP->volume.right);
#endif
}

/**
 * Reads number of bytes from the codec
 *
 * @param 	Address	 	Address of register in Codec
 * @param 	*BufferPtr	points to the buffer to store read values
 * @param	ByteCount	Number of bytes to read
 *
 * @return  None
 *
 * @note	None
 */
void CodecReadByte(u32 I2C_base_addr, u8 codec_addr, u16 Address, u8 *readBuffer, u8 ByteCount) {
	u8 AddrToSend[]={Address >>8, (u8)Address};

	XIic_Send(I2C_base_addr,codec_addr,AddrToSend,ByteCount, XIIC_STOP);
	XIic_Recv(I2C_base_addr,codec_addr,readBuffer,ByteCount, XIIC_STOP);
}
