/*
 * audio.h
 *
 *  Created on: 24 Sep 2021
 *      Author: admin
 */

#ifndef SRC_AUDIO_H_
#define SRC_AUDIO_H_

#include "xbasic_types.h"
#include "xil_types.h"
#include "xiic.h"
#include "adau_1761.h"

#define DEBUG

void setCodecPLL(XIic *I2C, int sampling_rate);
void setVolume(output_t *HP, u8 volume);
void CodecReadByte(u32 I2C_base_addr, u8 codec_addr, u16 Address, u8 *readBuffer, u8 ByteCount);



#endif /* SRC_AUDIO_H_ */
