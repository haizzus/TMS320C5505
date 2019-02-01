/*
 * dma.h
 *
 *  Created on: Mar 17, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

//////////////////////////////////////////////////////////////////////////////
// * File name: dma_bypass1.h
// *                                                                          
// * Description: DMA function prototypes.
// *                                                                          
// * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
// *                                                                          
// *                                                                          
// *  Redistribution and use in source and binary forms, with or without      
// *  modification, are permitted provided that the following conditions      
// *  are met:                                                                
// *                                                                          
// *    Redistributions of source code must retain the above copyright        
// *    notice, this list of conditions and the following disclaimer.         
// *                                                                          
// *    Redistributions in binary form must reproduce the above copyright     
// *    notice, this list of conditions and the following disclaimer in the   
// *    documentation and/or other materials provided with the                
// *    distribution.                                                         
// *                                                                          
// *    Neither the name of Texas Instruments Incorporated nor the names of   
// *    its contributors may be used to endorse or promote products derived   
// *    from this software without specific prior written permission.         
// *                                                                          
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
// *                                                                          
//////////////////////////////////////////////////////////////////////////////

#ifndef _DMA_H_
#define _DMA_H_

#ifdef __CDT_PARSER__
#define interrupt
#endif

void set_dma0_ch0_i2s0_Lout(Uint16);
void set_dma0_ch1_i2s0_Rout(Uint16);
void set_dma0_ch2_i2s0_Lin(Uint16);
void set_dma0_ch3_i2s0_Rin(Uint16);

void set_dma0_ch0_stop(void);
void set_dma0_ch1_stop(void);
void set_dma0_ch2_stop(void);
void set_dma0_ch3_stop(void);

void enable_dma_int(void);
interrupt void DMA_Isr(void);
void setDMA_address(void);

extern Uint32 RxL1_DMA_address;
extern Uint32 RxL2_DMA_address;
extern Uint32 RxR1_DMA_address;
extern Uint32 RxR2_DMA_address;
extern Uint32 TxL1_DMA_address;
extern Uint32 TxL2_DMA_address;
extern Uint32 TxR1_DMA_address;
extern Uint32 TxR2_DMA_address;

extern Uint16 CurrentRxL_DMAChannel;
extern Uint16 CurrentRxR_DMAChannel;
extern Uint16 CurrentTxL_DMAChannel;
extern Uint16 CurrentTxR_DMAChannel;
extern Uint16 leftChannel;
extern Uint16 rightChannel;

extern Int16 RcvL1[];
extern Int16 RcvR1[];
extern Int16 RcvL2[];
extern Int16 RcvR2[];

extern Int16 XmitL1[];
extern Int16 XmitR1[];
extern Int16 XmitL2[];
extern Int16 XmitR2[];

#endif
