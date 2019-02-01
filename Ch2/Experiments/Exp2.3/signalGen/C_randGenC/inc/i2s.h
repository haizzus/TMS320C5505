/*
 * i2s.h
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
// * File name: i2s_bypass1.h
// *                                                                          
// * Description:  i2s function prototypes.
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
#ifndef _I2S_H_
#define _I2S_H_

Uint16  i2s0_read_CR( void);
void i2s0_write_CR( Uint16  data);
Uint16  i2s0_read_SRGR( void);
void i2s0_write_SRGR( Uint16  data);
Uint16  i2s0_read_TXL_LSW( void);
void i2s0_write_TXL_LSW( Uint16  data);
Uint16  i2s0_read_TXL_MSW( void);
void i2s0_write_TXL_MSW( Uint16  data);
Uint16  i2s0_read_TXR_LSW( void);
void i2s0_write_TXR_LSW( Uint16  data);
Uint16  i2s0_read_TXR_MSW( void);
void i2s0_write_TXR_MSW( Uint16  data);
Uint16  i2s0_read_INTR( void);
Uint16  i2s0_read_INT_MASK( void);
void i2s0_write_INT_MASK( Uint16  data);
Uint16  i2s0_read_RXL_LSW( void);
void i2s0_write_RXL_LSW( Uint16  data);
Uint16  i2s0_read_RXL_MSW( void);
void i2s0_write_RXL_MSW( Uint16  data);
Uint16  i2s0_read_RXR_LSW( void);
void i2s0_write_RXR_LSW( Uint16  data);
Uint16  i2s0_read_RXR_MSW( void);
void i2s0_write_RXR_MSW( Uint16  data);
Uint16  i2s1_read_CR( void);
void i2s1_write_CR( Uint16  data);
Uint16  i2s1_read_SRGR( void);
void i2s1_write_SRGR( Uint16  data);
Uint16  i2s1_read_TXL_LSW( void);
void i2s1_write_TXL_LSW( Uint16  data);
Uint16  i2s1_read_TXL_MSW( void);
void i2s1_write_TXL_MSW( Uint16  data);
Uint16  i2s1_read_TXR_LSW( void);
void i2s1_write_TXR_LSW( Uint16  data);
Uint16  i2s1_read_TXR_MSW( void);
void i2s1_write_TXR_MSW( Uint16  data);
Uint16  i2s1_read_INTR( void);
Uint16  i2s1_read_INT_MASK( void);
void i2s1_write_INT_MASK( Uint16  data);
Uint16  i2s1_read_RXL_LSW( void);
void i2s1_write_RXL_LSW( Uint16  data);
Uint16  i2s1_read_RXL_MSW( void);
void i2s1_write_RXL_MSW( Uint16  data);
Uint16  i2s1_read_RXR_LSW( void);
void i2s1_write_RXR_LSW( Uint16  data);
Uint16  i2s1_read_RXR_MSW( void);
void i2s1_write_RXR_MSW( Uint16  data);
Uint16  i2s2_read_CR( void);
void i2s2_write_CR( Uint16  data);
Uint16  i2s2_read_SRGR( void);
void i2s2_write_SRGR( Uint16  data);
Uint16  i2s2_read_TXL_LSW( void);
void i2s2_write_TXL_LSW( Uint16  data);
Uint16  i2s2_read_TXL_MSW( void);
void i2s2_write_TXL_MSW( Uint16  data);
Uint16  i2s2_read_TXR_LSW( void);
void i2s2_write_TXR_LSW( Uint16  data);
Uint16  i2s2_read_TXR_MSW( void);
void i2s2_write_TXR_MSW( Uint16  data);
Uint16  i2s2_read_INTR( void);
Uint16  i2s2_read_INT_MASK( void);
void i2s2_write_INT_MASK( Uint16  data);
Uint16  i2s2_read_RXL_LSW( void);
void i2s2_write_RXL_LSW( Uint16  data);
Uint16  i2s2_read_RXL_MSW( void);
void i2s2_write_RXL_MSW( Uint16  data);
Uint16  i2s2_read_RXR_LSW( void);
void i2s2_write_RXR_LSW( Uint16  data);
Uint16  i2s2_read_RXR_MSW( void);
void i2s2_write_RXR_MSW( Uint16  data);
Uint16  i2s3_read_CR( void);
void i2s3_write_CR( Uint16  data);
Uint16  i2s3_read_SRGR( void);
void i2s3_write_SRGR( Uint16  data);
Uint16  i2s3_read_TXL_LSW( void);
void i2s3_write_TXL_LSW( Uint16  data);
Uint16  i2s3_read_TXL_MSW( void);
void i2s3_write_TXL_MSW( Uint16  data);
Uint16  i2s3_read_TXR_LSW( void);
void i2s3_write_TXR_LSW( Uint16  data);
Uint16  i2s3_read_TXR_MSW( void);
void i2s3_write_TXR_MSW( Uint16  data);
Uint16  i2s3_read_INTR( void);
Uint16  i2s3_read_INT_MASK( void);
void i2s3_write_INT_MASK( Uint16  data);
Uint16  i2s3_read_RXL_LSW( void);
void i2s3_write_RXL_LSW( Uint16  data);
Uint16  i2s3_read_RXL_MSW( void);
void i2s3_write_RXL_MSW( Uint16  data);
Uint16  i2s3_read_RXR_LSW( void);
void i2s3_write_RXR_LSW( Uint16  data);
Uint16  i2s3_read_RXR_MSW( void);
void i2s3_write_RXR_MSW( Uint16  data);
void enable_i2s0(void);
void enable_i2s1(void);
void enable_i2s2(void);
void enable_i2s3(void);
void disable_i2s0(void);
void disable_i2s1(void);
void disable_i2s2(void);
void disable_i2s3(void);

void set_i2s0_master(void);
void set_i2s0_slave(void);
#define USE_DMA 	1

#endif
