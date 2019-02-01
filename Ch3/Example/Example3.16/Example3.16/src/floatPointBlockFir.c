/* 
//  Project: Example 3.16: floating-point implementation of block FIR filter 
//  File name: floatPointBlockFir.c   
//
//  Description: This is the implementation of a floating-point block FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/

#include "floatingPointFir.h"

void floatPointBlockFir(float *x, short blkSize, 
                        float *h, short order, 
                        float *y, 
                        float *w, short *index)
{
    short i,j,k;
    float sum;
    float *c;

    k = *index;
    for (j=0; j<blkSize; j++)               // Block processing
    {
        w[k] = *x++;                        // Get the current data to delay line
        c = h;
        for (sum=0, i=0; i<order; i++)      // FIR filter processing
        {
            sum += *c++ * w[k++];
            k %= order;                     // Simulate circular buffer
        }
        *y++ = sum;                         // Save filter output

        k=(order + k-1)%order;              // Update index for next time
        
    }
    *index = k;                             // Update circular buffer index
}

