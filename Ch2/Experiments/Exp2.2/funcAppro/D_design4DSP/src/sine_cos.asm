;/*
; * sine_cos.asm
; *
; *  Created on: May 5, 2012
; *      Author: BLEE
; *
; *		Description: Description: 16-bit sine(x) and cos(x) approximation function
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

;
;    Entry:  T0 = x, in the range of [-pi=0x8000 pi=0x7fff] 
;			AR0 -> Pointer 
;    Return: None         
;       Update:
;       AR0->[0] = cos(x) = d0+d1*x+d2*x^2+d3*x^3+d4*x^4+d5*x^5
;       AR0->[1] = sin(x) =    c1*x+c2*x^2+c3*x^3+c4*x^4+c5*x^5
;
;    46 cycles
;               

    .def _sine_cos    
		
;
;   Approximation coefficients in Q12 (4096) format
;
    .data                      
coeff ; Sine appoximation coefficients
    .word 0x3240 ; c1 =  3.140625
    .word 0x0053 ; c2 =  0.02026367
    .word 0xaacc ; c3 = -5.325196
    .word 0x08b7 ; c4 =  0.54467780
    .word 0x1cce ; c5 =  1.80029300
    ; Cosine appoximation coefficients
    .word 0x1000 ; d0 =  1.0000
    .word 0xfff8 ; d1 = -0.001922133
    .word 0xb199 ; d2 = -4.90014738
    .word 0xfbc3 ; d3 = -0.2648921
    .word 0x50ba ; d4 =  5.0454103
    .word 0xe332 ; d5 = -1.800293

;
;   Function starts
;
    .text
_sine_cos
    pshboth XAR5     	   ; Save AR5              

    amov    #14,AR5
    btstp   AR5,T0         ; Test bit 15 and 14
    nop
;
;   Start cos(x)
;	
    amov    #coeff+10,XAR5 ; Pointer to the end of coefficients

    xcc     _neg_x,TC1
    neg     T0             ; Negate if bit 14 is set
_neg_x	
	
    and     #0x7fff,T0     ; Mask out sign bit

    mov     *AR5-<<#16,AC0 ; AC0 = d5
||  bset    SATD           ; Set saturation bit
	
    mov     *AR5-<<#16,AC1 ; AC1 = d4 
||  bset    FRCT           ; Set up fractional bit	

    mac     AC0,T0,AC1     ; AC1 = (d5*x+d4)  
||  mov     *AR5-<<#16,AC0 ; AC0 = d3	         

    mac     AC1,T0,AC0     ; AC0 = (d5*x^2+d4*x+d3)         
||  mov     *AR5-<<#16,AC1 ; AC1 = d2	

    mac     AC0,T0,AC1     ; AC1 = (d5*x^3+d4*x^2+d3*x+d2)
||  mov     *AR5-<<#16,AC0 ; AC0 = d1	

    mac     AC1,T0,AC0     ; AC0 = (d5*x^4+d4*x^3+d3*x^2+d2*x+d1)
||  mov     *AR5-<<#16,AC1 ; AC1 = d0
    
    macr    AC0,T0,AC1	   ; AC1 = (d5*x^4+d4*x^3+d3*x^2+d2*x+d1)*x+d0  
||  xcc     _neg_result1,TC2
    neg     AC1
_neg_result1	                  

    mov     *AR5-<<#16,AC0 ; AC0 = c5
||  xcc     _neg_result2,TC1
    neg     AC1
_neg_result2

    mov     hi(saturate(AC1<<#3)),*AR0+  ; Return cos(x) in Q15
	
;
;   Start sin(x) computation
;

    mov     *AR5-<<#16,AC1 ; AC1 = c4 

    mac     AC0,T0,AC1     ; AC1 = (c5*x+c4)  
||  mov     *AR5-<<#16,AC0 ; AC0 = c3	         

    mac     AC1,T0,AC0     ; AC0 = (c5*x^2+c4*x+c3)         
||  mov     *AR5-<<#16,AC1 ; AC1 = c2	

    mac     AC0,T0,AC1     ; AC1 = (c5*x^3+c4*x^2+c3*x+c2)
||  mov     *AR5-<<#16,AC0 ; AC0 = c1	

    mac     AC1,T0,AC0     ; AC0 = (c5*x^4+c4*x^3+c3*x^2+c2*x+c1)
    popboth XAR5           ; Restore AR5

    mpyr    T0,AC0,AC1     ; AC1 = (c5*x^4+c4*x^3+c3*x^2+c2*x+c1)*x  
||  xcc     _neg_result3,TC2
    neg     AC1
_neg_result3	            

    mov     hi(saturate(AC1<<#3)),*AR0-  ; Return sin(x) in Q15
||  bclr    FRCT           ; Reset fractional bit	

    bclr    SATD           ; Reset saturation bit
    ret
    
    .end                                       
