/* 
//  Example 3.17: fixed-point implementation of FIR filter 
//  File name: fixedPointFir.h   
//
//  Description: This is the header file for fixed-point FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/


#define  NUM_TAPS   48
#define  NUM_DATA   40

void fixedPointBlockFir(short *x, short blkSize, 
						short *h, short order, 
						short *y, 
						short *w, short *index);
