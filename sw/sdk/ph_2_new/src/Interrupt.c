/*
 * Interrupt.c
 *
 *  Created on: 21 Jul 2020
 *      Author: oliver
 */

#include "xbasic_types.h"
#include "xaxivdma.h"
#include "xscugic.h"
#include "Interrupt.h"

static XScuGic Intc;

// set up the interrupt system for the VDMA
int SetupIntrSystem(XAxiVdma *AxiVdmaPtr, u16 ReadIntrId)
{
	int Status;
	XScuGic *IntcInstancePtr =&Intc;

	/* Initialize the interrupt controller and connect the ISRs */
	XScuGic_Config *IntcConfig;
	IntcConfig = XScuGic_LookupConfig(XPAR_PS7_SCUGIC_0_DEVICE_ID);
	Status =  XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig, IntcConfig->CpuBaseAddress);
	if(Status != XST_SUCCESS){
		xil_printf("Interrupt controller initialization failed..");
		return XST_FAILURE;
	}

	Status = XScuGic_Connect(IntcInstancePtr,ReadIntrId,(Xil_InterruptHandler)XAxiVdma_ReadIntrHandler,(void *)AxiVdmaPtr);
	if (Status != XST_SUCCESS) {
		xil_printf("Failed read channel connect intc %d\r\n", Status);
		return XST_FAILURE;
	}

	XScuGic_Enable(IntcInstancePtr,ReadIntrId);

	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,(Xil_ExceptionHandler)XScuGic_InterruptHandler,(void *)IntcInstancePtr);
	Xil_ExceptionEnable();

	/* Register call-back functions
	 */
	XAxiVdma_SetCallBack(AxiVdmaPtr, XAXIVDMA_HANDLER_GENERAL, ReadCallBack, (void *)AxiVdmaPtr, XAXIVDMA_READ);

	XAxiVdma_SetCallBack(AxiVdmaPtr, XAXIVDMA_HANDLER_ERROR, ReadErrorCallBack, (void *)AxiVdmaPtr, XAXIVDMA_READ);

	return XST_SUCCESS;
}


/*****************************************************************************/
 /* Call back function for read channel
******************************************************************************/

void ReadCallBack(void *CallbackRef, u32 Mask)
{
	/* User can add his code in this call back function */
	//xil_printf("Read Call back function is called\r\n");
}

/*****************************************************************************/
/*
 * The user can put his code that should get executed when this
 * call back happens.
 *
*
******************************************************************************/
void ReadErrorCallBack(void *CallbackRef, u32 Mask)
{
	/* User can add his code in this call back function */
	xil_printf("Read Call back Error function is called\r\n");

}
/**********************************************************************/
