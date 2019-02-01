;/*
; * Experiment implementation of block FIR filter using dual-MAC - Chapter 3
; * dualMacFir.asm
; *
; * Description: This is the test file for the block FIR filter using dual-MAC
; *
; *  Created on: May 13, 2012
; *      Author: BLEE
; *
; * 		For the book "Real Time Digital Signal Processing:
; *                       Fundamentals,Implementation and Application, 3rd Ed"
; * 		              By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; * 		              Publisher: John Wiley and Sons, Ltd
; */

	.mmregs 
	
	.sect	".text:fir"
	.align 4

	.def	_dualMacFir

;----------------------------------------------------------------------
;   void dualMacFir(short *x,            => AR0
;                   short blkSize,       => T0          
;                   short *h,            => AR1
;                   short order,         => T1                                  
;                   short *y,            => AR2                                             
;                   short *w,            => AR3
;                   short *index)        => AR4                                  
;----------------------------------------------------------------------

_dualMacFir:
    pshm  ST1_55             ; Save ST1, ST2, and ST3
    pshm  ST2_55
    pshm  ST3_55
    
    or    #0x340,mmap(ST1_55); Set FRCT,SXMD,SATD
    bset  SMUL               ; Set SMUL
    mov   XAR1,XCDP          ; CDP as  coefficient pointer 
    mov   mmap(AR1),BSAC     ; Set up base address for CDP
    mov   mmap(T1),BKC       ; Set the coefficient array size = order
    mov   XAR3,XAR1          ; AR1 and AR3 are signal buffer pointers
    mov   mmap(AR3),BSA01    ; Set base address for AR1    
    mov   mmap(AR3),BSA23    ; Set base address for AR3
    mov   #0,CDP             ; Start from the 1st coefficient
||  add   #1,T1    
    mov   mmap(T1),BK03      ; Set signal buffer x[] size as order+1
    mov   *AR4,AR3           ; AR3 = signal buffer index
    mov   *AR4,AR1           ; AR1 = signal buffer index	    
    or    #0x10A,mmap(ST2_55); CDP, AR1, AR3 circular pointers
    amar  *AR1+              ; AR1 delayline index+1
||  sfts  T0,#-1             ; Use half of data samples    
    sub   #1,T0              ;   as outer repeat counter
    mov   T0,BRC0            ; Outer loop couter	
    sub   #4,T1,T0
    mov   T0,CSR             ; Inner loop counter as order-2
||  rptblocal sample_loop-1
    mov   *AR0+,*AR1         ; Put new sample to signal buffer x[n]
    mov   *AR0+,*AR3         ; Put next new sample to location x[n+1]
    mpy   *AR1+,*CDP+,AC0    ; The first operation
::  mpy   *AR3+,*CDP+,AC1
||  rpt   CSR
    mac   *AR1+,*CDP+,AC0    ; The rest MAC iterations
::  mac   *AR3+,*CDP+,AC1     
    macr  *AR1,*CDP+,AC0
::  macr  *AR3,*CDP+,AC1     ; The last MAC operation 
    mov   pair(hi(AC0)),dbl(*AR2+); Store two output data (must be aligned in 32-bit!)
sample_loop
	
    popm  ST3_55             ; Restore ST1, ST2, and ST3
    popm  ST2_55
    popm  ST1_55
    mov   AR3,*AR4           ; Return signal buffer index
    ret
    .end

