/*
 * Interrupt.h
 *
 *  Created on: 21 Jul 2020
 *      Author: oliver
 */

#ifndef SRC_INTERRUPT_H_
#define SRC_INTERRUPT_H_

int SetupIntrSystem(XAxiVdma *AxiVdmaPtr, u16 ReadIntrId);

void ReadCallBack(void *CallbackRef, u32 Mask);

void ReadErrorCallBack(void *CallbackRef, u32 Mask);


#endif /* SRC_INTERRUPT_H_ */
