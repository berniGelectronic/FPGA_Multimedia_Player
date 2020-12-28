/*
 * VDMA_Setup.h
 *
 *  Created on: 21 Jul 2020
 *      Author: oliver
 */


#ifndef SRC_VDMA_SETUP_H_
#define SRC_VDMA_SETUP_H_

//#include "xparameters.h"

#define Horizontal_Size 480
#define Vertical_Size 800
#define FrameSize Horizontal_Size*Vertical_Size*3 // 3 because RGB each colour contains one byte of data
//#define imgHorizontalSize 480
//#define imgVerticalSize 800

//#define DMA_DEVICE_ID		XPAR_AXIVDMA_0_DEVICE_ID

int setup_VDMA(u32 Buffer_Image, XAxiVdma AxiVdma);

///*static*/ int SetupIntrSystem(XAxiVdma *AxiVdmaPtr, u16 ReadIntrId);


//unsigned char Buffer_Image[FrameSize];
//unsigned char Pre_Screen_Image[FrameSize];

#endif /* SRC_VDMA_SETUP_H_ */
