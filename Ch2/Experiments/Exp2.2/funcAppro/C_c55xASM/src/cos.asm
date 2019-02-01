;/*
; * cos.asm
; *
; *  Created on: Feb 16, 2013
; *      Author: BLEE
; *
; *		Description: cos(x) approximation function
; *				using function: cos(x)=1-(1/2!)x^2+(1/4!)x^4-(1/6!)x^6
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;
;    Entry:  T0 = x, in the range of [0 pi/2] in Q14 format 
;    Return: T0 = cos(x) in Q15 format         
;
;    19 cycles
;               

	.mmregs

	.data
_icosCoef   ;[1 (-1/2!) (1/4!) (-1/6!)]
	.word  	32767,-16383,1365,-45

	.sect	".text"
	.def	_cosine

_cosine:
    amov #(_icosCoef+3),XAR3 ; ptr = &icosCoef[3];
    amov #0x11,XAR2          ; Set AR2 as the ptr pointing to AR1 (AR1 addr = 0x11)
    mov  T0, HI(AC0)		 ; T0 = x passed in by calling function
    sqr  AC0                 ; AC0 = (long)T0 * T0;  this computes x*x
    sfts AC0,#-15            ; T0  = (short)(AC0>>15); 
    mov  AC0,T0              ; T0 = x*x and will be used later 3 times
    mpym *AR3-,T0,AC0        ; AC0 = (long)T0 * *ptr--;
    sfts AC0,#-13            ; AC0 = AC0 >> 13; 
    add  *AR3-,AC0,AR1       ; AC0 = (short)(AC0 + *ptr--) * (long)T0; 
    mpym *AR2,T0,AC0
    sfts AC0,#-13            ; AC0 = AC0 >> 13;
    add  *AR3-,AC0,AR1       ; AC0 = (short)(AC0 + *ptr--) * (long)T0; 
    mpym *AR2,T0,AC0
    sfts AC0,#-13            ; AC0 = AC0 >> 13; 
||  mov  *AR3,T0
    add  AC0,T0              ; AC0 = AC0 + *ptr; 
    ret                      ; The computed cos(x) is returned via T0, see C calling convention
           
	.end
