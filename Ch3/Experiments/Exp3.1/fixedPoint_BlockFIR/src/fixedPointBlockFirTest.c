/*
 * Experiment fixed-point implementation of block FIR filter - Chapter 3
 * fixedPointFirTest.c
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

#include <stdlib.h>
#include <stdio.h>
#include "tistdtypes.h"
#include "fixedPointFir.h"

/* Define DSP system memory map */
#pragma DATA_SECTION(firCoefFixedPoint, ".data:fir");
#pragma DATA_SECTION(w, ".bss:fir");

#include "firCoef.h"

Int16 w[NUM_TAPS];
Int16 x[NUM_DATA],  	// Input data
      y[NUM_DATA];  	// Output data

void main()
{
    FILE  *fpIn,*fpOut;
    Int16 i,k,c,
          index;        // Delay line index
    Int8  temp[NUM_DATA*2];
    Uint8 waveHeader[44];

    printf("Exp --- Fixed-point_Block FIR filter experiment\n");
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\input.wav", "rb");
    	fpOut = fopen("..\\data\\output.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\input.pcm", "rb");
    	fpOut = fopen("..\\data\\output.pcm", "wb");
    }

	if (fpIn == NULL)
	{
        printf("Can't open input file\n");
		exit(0);
	}

    if (c == 2)
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }
	
    // Initialize for filtering process
    for (i=0; i<NUM_TAPS; i++)
    {
        w[i] = 0;
    }
    index = 0;

    // Begin filtering the data
    while (fread(temp, sizeof(Int8), NUM_DATA*2, fpIn) == (NUM_DATA*2))
    {
        for (k=0, i=0; i<NUM_DATA; i++)
        {
            x[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
            k += 2;
        }
        // Filter the data x and save output y
        fixedPointBlockFir(x, NUM_DATA, firCoefFixedPoint, NUM_TAPS, y, w, &index);

        for (k=0, i=0; i<NUM_DATA; i++)
        {
            temp[k++] = (y[i]&0xFF);
            temp[k++] = (y[i]>>8)&0xFF;
        }
        fwrite(temp, sizeof(Int8), NUM_DATA*2, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);

    printf("\nExp --- completed\n");
}
