/*
 * C5505.cmd
 *
 *  Created on: Jul 20, 2012
 *      Author: BLEE, modified 
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
/*
 * File name: C5505.cmd
 *                                                                          
 * Description: This file provides memory map and section map.
 *                                                                          
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/ 
 *                                                                          
 *                                                                          
 *  Redistribution and use in source and binary forms, with or without      
 *  modification, are permitted provided that the following conditions      
 *  are met:                                                                
 *                                                                          
 *    Redistributions of source code must retain the above copyright        
 *    notice, this list of conditions and the following disclaimer.         
 *                                                                          
 *    Redistributions in binary form must reproduce the above copyright     
 *    notice, this list of conditions and the following disclaimer in the   
 *    documentation and/or other materials provided with the                
 *    distribution.                                                         
 *                                                                          
 *    Neither the name of Texas Instruments Incorporated nor the names of   
 *    its contributors may be used to endorse or promote products derived   
 *    from this software without specific prior written permission.         
 *                                                                          
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
 *                                                                          
*/


/******************************************************************************/
/* C5505.cmd - COMMAND FILE FOR LINKING C PROGRAMS IN LARGE/HUGE MEMORY MODEL  */
/******************************************************************************/

/**********************************************************/
/*                                                        */
/*         LINKER command file for LEAD3 memory map       */
/*                                                        */
/**********************************************************/


-stack 0x200
-heap 0x2000
-sysstack 0x100
 
MEMORY
{
    PAGE 0:

        MMR     : origin = 0000000h, length = 00000c0h 
        DARAM0  : origin = 00002c0h, length = 0003d40h
        DARAM1  : origin = 0004000h, length = 0002000h
        DARAM2  : origin = 0006000h, length = 0002000h
        DARAM3  : origin = 0008000h, length = 0008000h

        SARAM0  : origin = 0010000h, length = 0010000h
        SARAM1  : origin = 0020000h, length = 0010000h
        SARAM2  : origin = 0030000h, length = 0010000h
        SARAM3  : origin = 0040000h, length = 0010000h
      
        CE01     : origin = 0100000h, length = 0020000h 
        CE02	 : origin = 0120000h, length = 0020000h
        CE03	 : origin = 0140000h, length = 0020000h
        CE1     : origin = 0400000h, length = 0100000h
        CE2     : origin = 0800000h, length = 0400000h
        CE3     : origin = 0c00000h, length = 03f8000h

        PDROM   : origin = 0ff8000h, length = 07f00h
        VECS    : origin = 0c0h, length = 00200h  /* Reset vector */
}	

 
SECTIONS
{
        vectors  (NOLOAD)                         /* Interrupt vector table, rts55x.lib */
        vector   : {} > DARAM1 PAGE 0 align 256   /* Interrupt vector table, vector.asm */
        .cinit   : {} > SARAM3 PAGE 0
        .text    : {} > SARAM3 PAGE 0
        .cio 	 : {} > SARAM3 PAGE 0 align 2
        .switch	 : {} > SARAM3 PAGE 0 
        .usect   : {} > SARAM3 PAGE 0 align 2
           
        .stack   : {} > DARAM0 PAGE 0
        .sysstack: {} > DARAM0 PAGE 0
        .sysmem  : {} > DARAM0 PAGE 0
        .data    : {} > DARAM0 PAGE 0
        .bss     : {} > DARAM3 PAGE 0
        .const   : {} > SARAM3 PAGE 0 
         
}
