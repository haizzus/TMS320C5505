;                                              
;  Project: Real Time Tone Generation - Chapter 3
;
;  File name: cos.asm   
;
;  Description: 16-bit cos(x) approximation function
;
;  For the book "Real Time Digital Signal Processing: 
;                Fundamentals, Implementation and Application, 3rd Ed"
;                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;                Publisher: John Wiley and Sons, Ltd
;
;    Entry:  T0 = x, in the range of [-pi=0x8000 pi=0x7fff] 
;    Return: T0 = cos(x)         
;
;    25 cycles
;               

    .def _cosine    
		
;
;   Approximation coefficients in Q12 (4096) format
;
    .data                      
coeff ; Cosine appoximation coefficients
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
_cosine
    amov    #14,AR0
||  bset    SATD           ; Set Saturate bit
    btstp   AR0,T0         ; Test bit 15 and 14
    bset    SMUL
;
;   Start cos(x)
;	
    amov    #coeff+5,XAR0  ; Pointer to the end of coefficients
    bset    FRCT           ; Set up fractional bit	
||  xcc     neg_x,TC1
    neg     T0             ; Negate if bit 14 is set
neg_x	
	
    and     #0x7fff,T0     ; Mask out sign bit
    mov     *AR0-<<#16,AC0 ; AC0 = d5
    mov     *AR0-<<#16,AC1 ; AC1 = d4 
    mac     AC0,T0,AC1     ; AC1 = (d5*x+d4)  
||  mov     *AR0-<<#16,AC0 ; AC0 = d3	         

    mac     AC1,T0,AC0     ; AC0 = (d5*x^2+d4*x+d3)         
||  mov     *AR0-<<#16,AC1 ; AC1 = d2	

    mac     AC0,T0,AC1     ; AC1 = (d5*x^3+d4*x^2+d3*x+d2)
||  mov     *AR0-<<#16,AC0 ; AC0 = d1	

    mac     AC1,T0,AC0     ; AC0 = (d5*x^4+d4*x^3+d3*x^2+d2*x+d1)
||  mov     *AR0-<<#16,AC1 ; AC1 = d0

    macr    AC0,T0,AC1	   ; AC1 = (d5*x^4+d4*x^3+d3*x^2+d2*x+d1)*x+d0  
||  xcc     neg_result1,TC2
    neg     AC1
neg_result1	                  
  
    bclr    FRCT           ; Reset fractional bit	
||  xcc     neg_result2,TC1
    neg     AC1
neg_result2

    sfts    AC1,#3
||  bclr    SMUL
    mov     HI(saturate(AC1)),mmap(T0)  ; Return cos(x) in Q15
    bclr    SATD           ; Reset saturate bit
    ret
    
    .end                                       
