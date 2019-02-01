/* 
//  Example 3.16: floating-point implementation of block FIR filter
//  File name: floatingPointFir.h
//
//  Description: This is the header file for floating-point block FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/


#define  NUM_TAPS   48
#define  NUM_DATA   80

void floatPointBlockFir(float *x, short blkSize, 
			float *h, short order, 
			float *y, 
			float *w, short *index);
