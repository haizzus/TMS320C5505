/* 
//  Project: Example 3.15: floating-point implementation of FIR filter 
//  File name: floatPointFir.c   
//
//  Description: This is the implementation of a floating-point FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/

#include "floatingPointFir.h"

void floatPointFir(float *x, float *h, short order, float *y, float *w)
{
    short i;
    float sum;

	w[0] = *x++;                        // Get the current data to delay line
	for (sum=0, i=0; i<order; i++)      // FIR filter processing
	{
		sum += h[i] * w[i];
	}
	*y++ = sum;                         // Save filter output

	for (i=order-1; i>0; i--)           // Update data delay line
	{
		w[i] = w[i-1] ;
	}

}

