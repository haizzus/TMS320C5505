/* 
//  Project: Example 3.16: floating-point implementation of block FIR filter
//  File name: floatingPointFirTest.c   
//
//  Description: This is the test file for the example of floating-point block FIR filter
//
//  For the book "Real Time Digital Signal Processing: 
//                Fundamentals, Implementation and Application, 3rd Ed"
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
//                Publisher: John Wiley and Sons, Ltd
*/

#include <stdlib.h>
#include <stdio.h>

#include "floatingPointFir.h"
#include "firCoef.h"


float w[NUM_TAPS];
float x[NUM_DATA],  // Input data
      y[NUM_DATA];  // Output data

void main()
{
    FILE  *fpIn,*fpOut;
    short i,j;
    short index;        // Delay line index
    char  temp[NUM_DATA*2];

    fpIn = fopen("..\\data\\input.pcm", "rb");
    fpOut = fopen("..\\data\\output.pcm", "wb");

    if (fpIn == NULL)
    {
        printf("Can't open input file\n");
        exit(0);
    }
    
    // Initialize for filtering process
    for (i=0; i<NUM_TAPS; i++)
    {
        w[i] = 0.0;
    }
    index = 0;

    // Begin filtering the data
    while (fread(temp, sizeof(char), NUM_DATA*2, fpIn) == NUM_DATA*2)
    {
        for (j=0, i=0; i<NUM_DATA; i++)
        {
            x[i] = (float)((temp[j]&0xff)|(temp[j+1]<<8));
            j += 2;
        }
        // Filter the data x and save output y
        floatPointBlockFir(x, NUM_DATA, firCoefFloatingPoint, NUM_TAPS,
                           y, w, &index);

        for (j=0, i=0; i<NUM_DATA; i++)
        {
            temp[j++] = (char)((short)y[i]&0xff);
            temp[j++] = (char)((short)y[i]>>8);
        }

        fwrite(temp, sizeof(char), NUM_DATA*2, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
}
