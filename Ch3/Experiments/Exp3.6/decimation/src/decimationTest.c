/*
 * Experiment decimation using FIR filter - Chapter 3
 * decimationTest.c
 *
 * Description: This is the test file for the decimation FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdlib.h>
#include <stdio.h>
#include "tistdtypes.h"
#include "decimation.h"

/* Define DSP system memory map */
#pragma DATA_SECTION(deciFilt48to24, ".const:fir");
#pragma DATA_SECTION(deciFilt24to8, ".const:fir");
#pragma DATA_SECTION(temp, ".bss:fir");
#pragma DATA_SECTION(x1, ".bss:fir");
#pragma DATA_SECTION(x2, ".bss:fir");
#pragma DATA_SECTION(y, ".bss:fir");
#pragma DATA_SECTION(w1, ".bss:fir");
#pragma DATA_SECTION(w2, ".bss:fir");
#pragma DATA_ALIGN(w1, 2);       // Use dual MAC, align to 32 bits
#pragma DATA_ALIGN(w2, 2);       // Use dual MAC, align to 32 bits


#include "coef48to24.h"
#include "coef24to8.h"


Int16 w1[TAPS48to24+1];          // Use dual MAC, add one space
Int16 w2[TAPS24to8+1];           // Use dual MAC, add one space
Int16 x1[DEC_NUM_DATA_IN],       // Input data
	  x2[DEC_NUM_DATA2],         // Intermediate data
	  y[DEC_NUM_DATA_OUT];       // Output data
Int8  temp[DEC_NUM_DATA_IN*2];   // Temp buffer for file IO

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main()
{
    FILE  *fpIn,*fpOut;
    Int16 i,k,c,
		  index1,                 // Delay line w1 index
		  index2;                 // Delay line w2 index
    Uint8 waveHeader[44];
    Uint32 cnt;

    printf("Exp --- Decimation experiment\n");
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\tone1k_48000.wav", "rb");
    	fpOut = fopen("..\\data\\output1kHz8kHz.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\tone1k_48000.pcm", "rb");
    	fpOut = fopen("..\\data\\output1kHz8kHz.pcm", "wb");
    }

    if (fpIn == NULL)
    {
        printf("Can't open input file\n");
        exit(0);
    }

    if (c == 2)
    {
    	fread(waveHeader, sizeof(Int8), 44, fpIn);		// Advance to data
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);	// Advance to data
    }

    // Initialize for filtering process
    for (i=0; i<=TAPS48to24; i++)
    {
        w1[i] = 0;
    }
    for (i=0; i<=TAPS24to8; i++)
    {
        w2[i] = 0;
    }

    index1 = 0;
    index2 = 0;
    cnt = 0;

    // Begin filtering the data
    while (fread(temp, sizeof(Int8), DEC_NUM_DATA_IN*2, fpIn)
	       == (DEC_NUM_DATA_IN*2))
    {
        for (k=0, i=0; i<DEC_NUM_DATA_IN; i++)
        {
            x1[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
            k += 2;
        }

        // Filter the data x and save output y
        decimator(x1, DEC_NUM_DATA2, deciFilt48to24, TAPS48to24, x2, w1, &index1, 2);

        decimator(x2, DEC_NUM_DATA_OUT, deciFilt24to8, TAPS24to8, y, w2, &index2, 3);

        for (k=0, i=0; i<DEC_NUM_DATA_OUT; i++)
        {
            temp[k++] = (y[i]&0xFF);
            temp[k++] = (y[i]>>8)&0xFF;
            cnt += 2;
        }
        printf("%ld samples processed\n", cnt>>1);
        fwrite(temp, sizeof(Int8), (DEC_NUM_DATA_OUT*2), fpOut);
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
    	wHeader(waveHeader, 48000, 8000, cnt);
    	rewind(fpOut);
    	fwrite(waveHeader, sizeof(Int8), 44, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
    printf("\nExp --- completed\n");
}

// Create the wave file header
void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes)
{
	Int32 t;

	t = bytes;
	w[40] = (t>>0)&0xff;	// Set up output file size
	w[41] = (t>>8)&0xff;
	w[42] = (t>>16)&0xff;
	w[43] = (t>>24)&0xff;
	t += 36;
	w[4] = (t>>0)&0xff;
	w[5] = (t>>8)&0xff;
	w[6] = (t>>16)&0xff;
	w[7] = (t>>24)&0xff;
	t = w[24]|(w[25]<<8)|((Int32)w[26]<<16)|((Int32)w[27]<<24);
	t = (Int32)((float)t*f2/f1);
	w[24] = (t>>0)&0xff;	// Set up output file frequency
	w[25] = (t>>8)&0xff;
	w[26] = (t>>16)&0xff;
	w[27] = (t>>24)&0xff;
	t = w[28]|(w[29]<<8)|((Int32)w[30]<<16)|((Int32)w[31]<<24);
	t = (Int32)((float)t*f2/f1);
	w[28] = (t>>0)&0xff;	// Set up output file byte rate
	w[29] = (t>>8)&0xff;
	w[30] = (t>>16)&0xff;
	w[31] = (t>>24)&0xff;

	return;
}
