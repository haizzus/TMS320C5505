/*
 * Experiment implementation of block FIR filter - Chapter 3
 * fixedPointFir.c
 *
 * Description: This is the test file for the fixed-point block FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 * 		For the book "Real Time Digital Signal Processing:
 *              Fundamentals, Implementation and Application, 3rd Ed"
 * 		By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 * 		Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "fixedPointFir.h"

/* Define DSP system memory map */
#pragma CODE_SECTION(fixedPointBlockFir, ".text:fir");

void fixedPointBlockFir(Int16 *x, Int16 blkSize,
                        Int16 *h, Int16 order,
                        Int16 *y,
                        Int16 *w, Int16 *index)
{
    Int16 i,j,k;
    Int32 sum;
    Int16 *c;

    k = *index;
    for (j=0; j<blkSize; j++)               // Block processing
    {
        w[k] = *x++;                        // Get the current data to delay line
        c = h;
        for (sum=0, i=0; i<order; i++)      // FIR filter processing
        {
            sum += *c++ * (Int32)w[k++];
            if (k == NUM_TAPS)              // Simulate circular buffer
            {
                k = 0;
            }
        }    
        sum += 0x4000;                      // Rounding
        *y++ = (Int16)(sum>>15);            // Save filter output

    	if (k-- <=0)                        // Update index for next time
        {
            k = NUM_TAPS-1;
        }
    }
    *index = k;                             // Update circular buffer index
}

