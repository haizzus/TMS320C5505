;/*
;* vector.asm
;*
;*  Created on: Mar 14, 2012
;*      Author: BLEE, modified
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*/

;//////////////////////////////////////////////////////////////////////////////
;// * File name: vector.asm
;// *                                                                          
;// * Description:  Code for playback using I2S2 and DMA1 to AIC3254.
;// *                                                                          
;// * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
;// *                                                                          
;// *                                                                          
;// *  Redistribution and use in source and binary forms, with or without      
;// *  modification, are permitted provided that the following conditions      
;// *  are met:                                                                
;// *                                                                          
;// *    Redistributions of source code must retain the above copyright        
;// *    notice, this list of conditions and the following disclaimer.         
;// *                                                                          
;// *    Redistributions in binary form must reproduce the above copyright     
;// *    notice, this list of conditions and the following disclaimer in the   
;// *    documentation and/or other materials provided with the                
;// *    distribution.                                                         
;// *                                                                          
;// *    Neither the name of Texas Instruments Incorporated nor the names of   
;// *    its contributors may be used to endorse or promote products derived   
;// *    from this software without specific prior written permission.         
;// *                                                                          
;// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     
;// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       
;// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   
;// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    
;// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   
;// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        
;// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   
;// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   
;// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     
;// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   
;// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
;// *                                                                          
;//////////////////////////////////////////////////////////////////////////////

         .mmregs
         .include "lpva200.inc"
         
         
         .C54CM_off
         .CPL_off
         .ARMS_off
   
;**********************************************************************************
;        predefined stack operation modes  
;**********************************************************************************
;        USE_RETA     : 2x16-bit fast return mode (RETA used)
;        NO_RETA      : 2x16-bit slow return mode (RETA not used)
;        C54X_STK     : 32-bit fast return mode 

;**********************************************************************************    
         .global _DMA_Isr 
         ;.global _SAR_Isr 
         ;.global _I2S0_TX_Isr
         ;.global _I2S1_RX_Isr
         .global _RTC_Isr
		 ;.global _Timer_isr
   
             
;**********************************************************************************
        .sect "vector"
        .align  256         
;**********************************************************************************

;****************************************************************************
;* Other interrupt vector definitions go here
;****************************************************************************
	.def	_RST
_RST:		.ivec    reset_isr, USE_RETA; Reset / Software Interrupt #0

NMI:		.ivec    reset_isr				; Nonmaskable Interrupt

INT0:		.ivec    dummy_isr				; External User Interrupt #0 

INT1:		.ivec    dummy_isr				; External User Interrupt #1

;TINT0:		.ivec    _Timer_isr				; Timer #0 / Software Interrupt #4
TINT0:		.ivec    dummy_isr				; Timer #0 / Software Interrupt #4

;PROG0:		.ivec    _I2S0_TX_Isr			; Programmable 0 Interrupt
PROG0:		.ivec    dummy_isr			; Programmable 0 Interrupt

UART:		.ivec    dummy_isr				; IIS #1 Receive Interrupt

PROG1:		.ivec    dummy_isr				; Programmable 1 Interrupt

DMA:		.ivec    _DMA_Isr                ; DMA Interrupt
;DMA:		.ivec    dummy_isr                ; DMA Interrupt

PROG2:		.ivec    dummy_isr			; Programmable 2 Interrupt

COPROCFFT:  .ivec    dummy_isr			; Coprocessor FFT Module Interrupt

;PROG3:		.ivec    _I2S1_RX_Isr			; Programmable 3 Interrupt
PROG3:		.ivec    dummy_isr			; Programmable 3 Interrupt

LCD:		.ivec	 dummy_isr				; LCD Interrupt

SARADC:		.ivec    dummy_isr				; SAR ADC Interrupt

XMIT2:		.ivec	 dummy_isr		    ; I2S2 Tx Interrupt

RCV2:		.ivec	 dummy_isr		    ; I2S2 Rx Interrupt

XMIT3:		.ivec	 dummy_isr		    ; I2S3 Tx Interrupt

RCV3:		.ivec	 dummy_isr		    ; I2S3 Rx Interrupt

;RTC:		.ivec    _RTC_Isr				; RTC interrupt
RTC:		.ivec    dummy_isr				; RTC interrupt

SPI:    	.ivec    dummy_isr				; SPI Receive Interrupt

USB:		.ivec    dummy_isr				; USB Transmit Interrupt

GPIO:		.ivec    dummy_isr				; GPIO Interrupt

EMIF:	    .ivec    dummy_isr			    ; EMIF Interrupt

I2C:		.ivec    dummy_isr				; IIC interrupt

BERRIV:
IV24:		.ivec	 dummy_isr   ; Bus error interrupt

;    .ref  _DLOGINT_isr 
DLOGIV:
IV25:		.ivec   dummy_isr  ; Data log (RTDX) interrupt

;	.ref _RTOSINT_isr
RTOSIV:
IV26:		.ivec dummy_isr  ; Real-time OS interrupt
IV27:		.ivec dummy_isr  ; General-purpose software-only interrupt
IV28:		.ivec dummy_isr  ; General-purpose software-only interrupt
IV29:		.ivec dummy_isr  ; General-purpose software-only interrupt
IV30:		.ivec dummy_isr  ; General-purpose software-only interrupt
IV31:		.ivec dummy_isr  ; General-purpose software-only interrupt


;****************************************************************************
;* Reset 
;****************************************************************************

		.text
		.def reset_isr
		.ref _c_int00
		
        .align 2		
reset_isr:
	;	*port(#0x1C01) = #0x0				; Clear idles
		bset #11, ST1_55			; Disable interrupts
    	mov #(_RST >> 8), mmap(@IVPD_L)
    	mov #(_RST >> 8), mmap(@IVPH_L)

        bclr #7,ST3_55
        bset #2,ST3_55
        bclr #13,ST1_55

		mov #0xffff, mmap(@#IFR0_L) ; clear all pending interrupts
        mov #0xffff, mmap(@#IFR1_L)
        
		mov #(RESERVED_ICR|IPORT_IDLE|HWA_IDLE|DPORT_IDLE), *port(#IDLE_ICR)
		idle

;**********************************************************************************
;     Reset all peripherals
;**********************************************************************************
	mov #0x1, *port(#0x1C04) 
	nop
	mov #0x00FB, *port(#0x1C05) 	; Reset all peripherals
	nop

;**********************************************************************************
;     Enalbe EMIF
;**********************************************************************************
    mov #0x0, *port(#IDLE_PCGCR)
    
    ;/* Config EMIF - System Control Regsiter */
    mov #0x0, *port(#0x1C33)

    ;// for SRAM in memory card (Async_CE1)
    ;/* Config EMIF - ASYNC Regsiters */
    mov #0x0080, *port(#0x1004)      
    mov #0x00E4, *port(#0x1005)      

	;/* Configure as 16-bit data bus */    
    ;// Async4 ==> Async_CE1 (SRAM)	
    mov #0x40AD, *port(#0x101C)    
    mov #0x0020, *port(#0x101D)      

    ;// Async3 ==> Async_CE0(Flash)
    mov #0xFFFD, *port(#0x1018)    
    mov #0x3FFF, *port(#0x1019)      


    ;// do not assign Async_CE0 and Async_CE1 for NAND
    mov #0x0003, *port(#0x1060)     
    
    ;// Turn off page mode for all Chip Selects
    mov #0xFCFC, *port(#0x1068)      
    mov #0xFCFC, *port(#0x1069)     

	b	_c_int00		
********************************************************************************
** Name     : no_isr                                                          **
**                                                                            **
** Purpose  : Spurious interrupt handler                                      **
**                                                                            **
** Author   :                                                                 **
**                                                                            **
********************************************************************************
             .text   
no_isr:      b no_isr 

dummy_isr:   reti  
    
    .end
