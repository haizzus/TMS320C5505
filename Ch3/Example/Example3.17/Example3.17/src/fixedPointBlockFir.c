/* 
//  Project: Example 3.17: fixed-point implementation of block FIR filter 
//  File name: fixedPointFir.c   
//
//  Description: This is the implementation of a fixed-point block FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/

#include "fixedPointFir.h"

void fixedPointBlockFir(short *x, short blkSize, 
						short *h, short order, 
						short *y, 
						short *w, short *index)
{
    short i,j,k;
    long sum;
	short *c;

	k = *index;
	for (j=0; j<blkSize; j++)			// Block processing
	{
		w[k] = *x++;					// Get the current data to delay line
		c = h;
		for (sum=0, i=0; i<order; i++)	// FIR filter processing
		{
			sum += *c++ * (long)w[k++];
            if (k == order)				// Simulate circular buffer
			{
			    k = 0;
			}
		}
		*y++ = (short)(sum>>15);		// Save filter output

    	if (k-- <=0)					// Update index for next time
		{
		    k = order-1;
		}
	}
	*index = k;							// Update circular buffer index
}

