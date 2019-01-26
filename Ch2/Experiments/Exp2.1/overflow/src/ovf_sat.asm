; /*
; * ovf_sat.asm
; *
; *  Created on: May 5, 2012
; *      Author: BLEE
; *
; *      Description: This is the experiment program file for understanding overflow
; *
; *  For the book "Real Time Digital Signal Processing:
; *                Fundamentals, Implementation and Application, 3rd Ed"
; *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
; *                Publisher: John Wiley and Sons, Ltd
; */

    .def    _ovftest      
    .def    _buff,_buff1
	
    .bss    _buff,(0x100)	
    .bss    _buff1,(0x100)		

;
;   Code start
;

_ovftest         
    bclr    SATD             ; Clear saturation bit if set  
    xcc     start,T0!=#0     ; If T0!=0, set saturation bit
    bset    SATD
	
start	        
    pshboth XAR5             ; Save XAR5 
    nop
    nop
    mov     #0,AC0	
    amov    #_buff,XAR5      ; Set buffer pointer
    rpt     #0x100-1         ; Clear buff
    mov     AC0,*AR5+

    amov    #_buff1,XAR5     ; Set buffer pointer
    rpt     #0x100-1         ; Clear buff1
    mov     AC0,*AR5+
	
    mov     #0x80-1,BRC0     ; Initialize loop counts for addition
    amov    #_buff+0x80,XAR5 ; Initialize buffer pointer
	
    rptblocal add_loop_end-1
    add     #0x140<<#16,AC0  ; Use upper AC0 as a ramp up counter
    mov     hi(AC0),*AR5+    ; Save the counter to buffer
add_loop_end 

    mov     #0x80-1,BRC0     ; Initialize loop counts for subtraction
    mov     #0,AC0           
    amov    #_buff+0x7f,XAR5 ; Initialize buffer pointer	
    rptblocal sub_loop_end-1
    sub     #0x140<<#16,AC0  ; Use upper AC0 as a ramp down counter
    mov     hi(AC0),*AR5-    ; Save the counter to buffer
sub_loop_end

    mov     #0x100-1,BRC0    ; Initialize loop counts for sinewave
    amov    #_buff1,XAR5     ; Initialize buffer pointer	
    mov     mmap(@AR0),BSA01 ; Initialize base register
    mov     #40,BK03         ; Set buffer to size 40 
    mov     #20,AR0          ; Start with offset of 20 samples
    bset    AR0LC            ; Active circular buffer

    rptblocal sine_loop_end-1
    mov     *ar0+<<#16,AC0   ; Get sine value into high AC0
    sfts    AC0,#9           ; Scale the sine value
    mov     hi(AC0),*AR5+    ; Save scaled value
sine_loop_end

    mov     #0,T0            ; Return 0 if no overflow 
    xcc	    set_ovf_flag,overflow(AC0)   	
    mov     #1,T0            ; Return 1 if overflow detected
set_ovf_flag	

    bclr    AR0LC            ; Reset circilar buffer bit
    bclr    SATD             ; Reset saturation bit	 
    popboth XAR5             ; Restore AR5
	
    ret
	
    .end

