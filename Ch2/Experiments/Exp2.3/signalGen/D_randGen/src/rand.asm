; /*
; * rand.asm
; *
; *  Created on: May 5, 2012
; *      Author: BLEE
; *
; *		 Description: mod-20 random number generator with 12-bit dynamic range
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;    Entry:  None 
;    Return: T0 = rand()         
;
;    15 cycles
;    
	
	.mmregs

	.bss	_n,2,0,2         ; long  n
	.bss	_a,1,0,0         ; short a

	.def	_initRand
	.def	_randNumber

	.sect	".text"	
_initRand:
    mov  AC0,dbl(*(#_n))     ; n = (long)seed; 
    mov  #2045,*(#_a)        ; a = 2045;
    ret

_randNumber:
    amov  #_n,XAR0
    mov   *(#_a),T0
    mpym  *AR0+,T0,AC0       ; n = a*n; 
    mpymu *AR0-,T0,AC1       ; (This is 32x16 integer multiply)
    sfts  AC0,#16
    add   AC1,AC0
||  mov   #0xFFFF<<#16,AC2   ; n = n&0xFFFFF000; 
    or    #0xF000,AC2 
    and   AC0,AC2 
    mov   AC2,dbl(*AR0)  
||  sfts  AC2,#-20,AC0       ; ran = (short)(n>>20); 
    mov   AC0,T0             ; Return (ran);
    ret

    .end
 
