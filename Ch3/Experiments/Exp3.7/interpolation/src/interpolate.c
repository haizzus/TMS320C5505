/*
 * Experiment interpolation using FIR filter - Chapter 3
 * interpolate.c
 *
 * Description: This is the implementation of a fixed-point interpolation filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"
#include "interpolation.h"

/* Define DSP system memory map */
#pragma CODE_SECTION(interpolate, ".text:fir");


void interpolate(Int16 *x, Int16 blkSize,
                Int16 *h, Int16 order,
                Int16 *y,
                Int16 *w, Int16 *index,
                Int16 intp)
{
    Int32 sum;
    Int16 i,j,k,n,m;
    Int16 *c;

    k = *index;
    for (j=0; j<blkSize; j++)                   // Block processing
    {
        c = h;
        w[k] = *x++;                            // Get the current data to delay line
        m = k;
        for (n=0; n<intp; n++)
        {
            for (sum=0, i=0; i<order; i++)      // FIR filter processing
            {
                sum += c[i*intp] * (Int32)w[k++];
                if (k == order)                 // Simulate circular buffer
                {
                    k = 0;
                }
            }   		
            *y++ = (Int16)(sum>>14);            // Save filter output
            c++;
            k = m;
        }

        k--;
        if (k<0)                                // Update index for next time
        {
            k += order;
        }
    }
    *index = k;                                // Update circular buffer index
}

