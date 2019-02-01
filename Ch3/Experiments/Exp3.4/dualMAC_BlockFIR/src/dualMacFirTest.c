/*
 * Experiment implementation of block FIR filter using dual-MAC - Chapter 3
 * dualMacFirTest.c
 *
 * Description: This is the test file for the block FIR filter using dual-MAC
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 * 		For the book "Real Time Digital Signal Processing:
 *                    Fundamentals, Implementation and Application, 3rd Ed"
 * 		              By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 * 		              Publisher: John Wiley and Sons, Ltd
 */

#include <stdlib.h>
#include <stdio.h>
#include "tistdtypes.h"
#include "dualMacFir.h"

/* Define DSP system memory map */
#pragma DATA_SECTION(dualMacFirCoef, ".const:fir");
#pragma DATA_SECTION(w, ".bss:fir");
#pragma DATA_SECTION(y, ".bss:fir");  
#pragma DATA_ALIGN(y,2); // Alignment is needed for dual accumulator store

#include "dualMacFirCoef.h"

Int16 y[NUM_DATA];       // output data, for using dual store, must be aligned 32 bit
Int16 w[NUM_TAPS+1];     // For using dual MAC, this must add 1 location

		  
void main()
{
    FILE  *fpIn,*fpOut;
    Int16 i,k,c,
		  index;        // Delay line index
    Int16 x[NUM_DATA];  // Input data

    Uint8 temp[NUM_DATA*2];
    Uint8 waveHeader[44];

    printf("Exp --- Dual-MAC FIR filter experiment\n");
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
    for (i=0; i<=NUM_TAPS; i++)
    {
        w[i] = 0;
    }
    index = 0;

    // Begin filtering the data
    while (fread(temp, sizeof(Uint8), NUM_DATA*2, fpIn) == (NUM_DATA*2))
    {
        for (k=0, i=0; i<NUM_DATA; i++)
        {
            x[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
            k += 2;
        }
		// Filter the data x and save output y
        dualMacFir(x, NUM_DATA, dualMacFirCoef, NUM_TAPS, y, w, &index);

        for (k=0, i=0; i<NUM_DATA; i++)
        {
            temp[k++] = (y[i]&0xFF);
            temp[k++] = (y[i]>>8)&0xFF;
        }
        fwrite(temp, sizeof(Uint8), NUM_DATA*2, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("\nExp --- completed\n");
}
