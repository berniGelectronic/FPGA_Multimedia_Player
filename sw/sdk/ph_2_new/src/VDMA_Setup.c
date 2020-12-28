/*
 * VDMA_Setup.c
 *
 *  Created on: 21 Jul 2020
 *      Author: oliver
 */

#include "xaxivdma.h"
#include "xparameters.h"
#include "VDMA_Setup.h"
#include "xil_cache.h"
#include "xil_types.h"
#include "Interrupt.h"

#define DMA_DEVICE_ID		XPAR_AXIVDMA_0_DEVICE_ID




//unsigned char Buffer_Image[FrameSize];
//unsigned char Pre_Screen_Image[FrameSize];


int setup_VDMA(u32 Buffer_Image, XAxiVdma AxiVdma){
	int Status;
	int Index;
	u32 Addr;

//	XAxiVdma AxiVdma;
	XAxiVdma_Config *Config;
	XAxiVdma_DmaSetup ReadCfg;

	/* The information of the XAxiVdma_Config comes from hardware build.
	 * The user IP should pass this information to the AXI DMA core.
	 */
	Config = XAxiVdma_LookupConfig(DMA_DEVICE_ID);
	if (!Config) {
		xil_printf("No video DMA found for ID %d\r\n", DMA_DEVICE_ID);

		return XST_FAILURE;
	}

	/* Initialize DMA engine */
	Status = XAxiVdma_CfgInitialize(&AxiVdma, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS) {

		xil_printf("Configuration Initialization failed %d\r\n", Status);

		return XST_FAILURE;
	}

	ReadCfg.VertSizeInput = Vertical_Size;
	ReadCfg.HoriSizeInput = Horizontal_Size*3;
	ReadCfg.Stride = Horizontal_Size*3;
	ReadCfg.FrameDelay = 0;
	ReadCfg.EnableCircularBuf = 1;
	ReadCfg.EnableSync = 1;
	ReadCfg.PointNum = 0;
	ReadCfg.EnableFrameCounter = 0;
	ReadCfg.FixedFrameStoreAddr = 0;

	Status = XAxiVdma_DmaConfig(&AxiVdma, XAXIVDMA_READ, &ReadCfg);
	    if (Status != XST_SUCCESS) {
	    	xil_printf("Read channel config failed %d\r\n", Status);
	    	return Status;
	    }
	//xil_printf("\r\n VDMA Setup\r\n");

	Addr = (u32)Buffer_Image;

	for(Index = 0; Index < AxiVdma.MaxNumFrames; Index++) {
			ReadCfg.FrameStoreStartAddr[Index] = Addr;
			Addr +=  FrameSize;
		}

	xil_printf("\r\n For loop complete\r\n");
	xil_printf("\r\n AxiVdma.MaxNumFrames = %u\r\n",AxiVdma.MaxNumFrames);

	Status = XAxiVdma_DmaSetBufferAddr(&AxiVdma, XAXIVDMA_READ,ReadCfg.FrameStoreStartAddr);
		if (Status != XST_SUCCESS) {
			xil_printf("Read channel set buffer address failed %d\r\n", Status);
			return XST_FAILURE;
		}
		xil_printf("\r\n DMA Setup complete\r\n");

	XAxiVdma_IntrEnable(&AxiVdma, XAXIVDMA_IXR_COMPLETION_MASK, XAXIVDMA_READ);

 //changed  vdma_1 to vdma_0
	/////commented
	SetupIntrSystem(&AxiVdma, XPAR_FABRIC_VIDEO_AXI_VDMA_0_MM2S_INTROUT_INTR);


	Xil_DCacheFlush();

	Status = XAxiVdma_DmaStart(&AxiVdma,XAXIVDMA_READ);
		if (Status != XST_SUCCESS) {
			if(Status == XST_VDMA_MISMATCH_ERROR)
				xil_printf("DMA Mismatch Error\r\n");
			return XST_FAILURE;
		}
		return XST_SUCCESS;
	}
