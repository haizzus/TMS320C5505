;/*
;* asmIIR.asm
;*
;*  Created on: May 25, 2012
;*      Author: BLEE
;*
;*  Description: Assembly implementation of IIR direct form-II (biquads) IIR filter
;*
;*  For the book "Real Time Digital Signal Processing:
;*                Fundamentals, Implementation and Application, 3rd Ed"
;*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
;*                Publisher: John Wiley and Sons, Ltd
;*
;*   Prototype: void asmIIR(short *, unsigned short *, short *, unsigned short, short*);
;*
;*   Entry:  arg0: AR0-filter input sample buffer pointer
;*           arg1: T0-number of samples in input buffer
;*           arg2: AR2-output sample buffer pointer
;*           arg3: AR1-IIR coefficients array pointer
;*           arg4: T1-number of biquads IIR  sections
;*           arg5: AR3-delayline pointer
;*
;*   Direct form II - IIR filter (the ith sections):
;*   d(n) = x(n) - ai1*w(n-1)-ai2*w(n-2)
;*   y(n) = bi0*w(n) + bi1*w(n-1) + bi2*w(n-2)
;*
;*   Memory arrangement and initialization: (1,2,...i,..,Ns)
;*   tempbuf[2*Ns] coefficient[5*Ns]
;*   AR3 -> w1i       AR7 -> a1i
;*          w1j              a2i
;*           :               b2i
;*          w2i              b0i
;*          w2j              b1i
;*           :                :
;*
;*   Scale: Coefficient is in Q14 format
;*   The filter result is scaled up to compensate the Q14 coefficient
;*
      .global _asmIIR
      .sect   ".text:iir_code" 
	
_asmIIR
      pshm  ST1_55                 ; Save ST1, ST2, and ST3
      pshm  ST2_55
      pshm  ST3_55
      psh   T3                     ; Save T3 	       
      pshboth XAR7                 ; Save AR7

      or    #0x340,mmap(ST1_55)    ; Set FRCT,SXMD,SATD
      bset  SMUL                   ; Set SMUL
      sub   #1,T0                  ; Number of samples - 1
      mov   T0,BRC0                ; Set up outer loop counter
      sub   #1,T1,T0               ; Number of sections -1	
      mov   T0,BRC1                ; Set up inner loop counter
	
      mov   T1,T0                  ; Set up circular buffer sizes
      sfts  T0,#1          
      mov   mmap(T0),BK03          ; BK03=2*number of sections
      sfts  T0,#1				
      add   T1,T0                                      
      mov   mmap(T0),BK47          ; BK47=5*number of sections
      mov   mmap(AR3),BSA23        ; Initial delay buffer base 
      mov   mmap(AR2),BSA67        ; Initial coefficient base 
      amov  #0,AR3                 ; Initial delay buffer entry 
      amov  #0,AR7                 ; Initial coefficient entry 
      or    #0x88,mmap(ST2_55)
      mov   #1,T0                  ; Used for shift left
||    rptblocal sample_loop-1	   ; Start IIR filter loop  
;      mov   *AR0+ <<#12,AC0        ; AC0 = x(n)/8 (i.e. Q12)
      mov   *AR0+ <<#15,AC0        ; AC0 = x(n) (i.e. Q15)
||    rptblocal filter_loop-1      ; Loop for each section
      masm  *(AR3+T1),*AR7+,AC0    ; AC0-=ai1*wi(n-1)     
      masm  T3=*AR3,*AR7+,AC0	   ; AC0-=ai2*di(n-2)
      mov   rnd(hi(AC0<<T0)),*AR3  ; wi(n-2)=wi(n) 
||    mpym  *AR7+,T3,AC0           ; AC0+=bi2*wi(n-2) 
      macm  *(AR3+T1),*AR7+,AC0    ; AC0+=bi0*wi(n-1)                 
      macm  *AR3+,*AR7+,AC0        ; AC0+=bi1*wi(n) 
filter_loop
;      mov   rnd(hi(AC0<<#4)),*AR1+ ; Store result in Q15
      mov   rnd(hi(AC0<<#1)),*AR1+ ; Store result in Q15
sample_loop

      popboth XAR7                 ; Restore AR7
      pop   T3                     ; Restore T3
      popm  ST3_55                 ; Restore ST1, ST2, and ST3
      popm  ST2_55
      popm  ST1_55
      ret
	
      .end
