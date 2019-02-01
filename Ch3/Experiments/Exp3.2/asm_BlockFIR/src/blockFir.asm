;/*
; * Experiment assembly implementation of block FIR filter - Chapter 3
; * blockFir.asm
; *
; * Description: This is the assembly language implementation of block FIR filter
; *
; *  Created on: May 13, 2012
; *      Author: BLEE
; *
; * 		For the book "Real Time Digital Signal Processing:
; *                       Fundamentals, Implementation and Application, 3rd Ed"
; * 		              By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; * 		              Publisher: John Wiley and Sons, Ltd
; */

	.mmregs 
	
	.sect	".text:fir"
	.align 4

	.def	_blockFir

;----------------------------------------------------------------------
;   void blockFir(Int16 *x,            => AR0
;                 Int16 blkSize,       => T0
;                 Int16 *h,            => AR1
;                 Int16 order,         => T1
;                 Int16 *y,            => AR2
;                 Int16 *w,            => AR3
;                 Int16 *index)        => AR4
;----------------------------------------------------------------------

_blockFir:
    pshm  ST1_55             ; Save ST1, ST2, and ST3
    pshm  ST2_55
    pshm  ST3_55
		
    or    #0x340,mmap(ST1_55); Set FRCT,SXMD,SATD
    bset  SMUL               ; Set SMUL
    mov   mmap(AR1),BSA01    ; AR1=base address for coeff 
    mov   mmap(T1),BK03	     ; Set coefficient array size (order) 
    mov   mmap(AR3),BSA23    ; AR3=base address for signal buffer
    or    #0xA,mmap(ST2_55)  ; AR1 & AR3 as circular pointers
    mov   #0,AR1             ; Coefficient start from h[0]
    mov   *AR4,AR3           ; Signal buffer start from w[index]
||  sub   #1,T0              ; T0=blkSize-1
    mov   T0,BRC0            ; Initialize outer loop to blkSize-1
    sub   #3,T1,T0           ; T0=order-3
    mov   T0,CSR             ; Initialize inner loop order-2 times
||  rptblocal sample_loop-1  ; Start the outer loop
    mov   *AR0+,*AR3         ; Put the new sample to signal buffer
    mpym  *AR3+,*AR1+,AC0    ; Do the 1st operation
||  rpt   CSR                ; Start the inner loop
    macm  *AR3+,*AR1+,AC0
    macmr *AR3,*AR1+,AC0     ; Do the last operation with rounding	
    mov   hi(AC0),*AR2+      ; Save Q15 filtered value 
sample_loop

    popm  ST3_55             ; Restore ST1, ST2, and ST3
    popm  ST2_55 
    popm  ST1_55	
    mov   AR3,*AR4           ; Update signal buffer index
    ret

    .end
