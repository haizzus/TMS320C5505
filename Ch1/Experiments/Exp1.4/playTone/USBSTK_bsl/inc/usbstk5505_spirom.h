//////////////////////////////////////////////////////////////////////////////
// * File name: usbstk5505_spirom.h
// *                                                                          
// * Description:  SPI ROM header file.
// *                                                                          
// * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
// * Copyright (C) 2010 Spectrum Digital, Incorporated
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

/* ------------------------------------------------------------------------ *
 *  SPI ROM Definitions                                                     *
 * ------------------------------------------------------------------------ */
#define spirom_SIZE               0x00008000
#define spirom_BASE               0x00000000
#define spirom_PAGESIZE           32
#define spirom_PAGEMASK           0xffffffc0

/* ------------------------------------------------------------------------ *
 *  SPI ROM Commands                                                        *
 * ------------------------------------------------------------------------ */
#define spirom_CMD_WREN           0x06
#define spirom_CMD_WRDI           0x04
#define spirom_CMD_RDSR           0x05
#define spirom_CMD_WRSR           0x01
#define spirom_CMD_READ           0x03
#define spirom_CMD_WRITE          0x02

/* ------------------------------------------------------------------------ *
 *  Prototype                                                               *
 * ------------------------------------------------------------------------ */
Int16 USBSTK5505_SPIROM_init( );
Uint16 USBSTK5505_SPIROM_status( );
Int16 USBSTK5505_SPIROM_read(  Uint16 src, Uint32 dst, Uint32 len );
Int16 USBSTK5505_SPIROM_write( Uint32 src, Uint16 dst, Uint32 len );

