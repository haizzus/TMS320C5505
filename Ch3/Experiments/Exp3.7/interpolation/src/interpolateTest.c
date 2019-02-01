/*
 * Experiment interpolation using FIR filter - Chapter 3
 * interpolateTest.c
 *
 * Description: This is the test file for the interpolation FIR filter
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
#include "interpolation.h"

/* Define DSP system memory map */
#if (__TMS320C55X__)
#pragma DATA_SECTION(intpFilt8to16, ".const:fir");
#pragma DATA_SECTION(intpFilt16to48, ".const:fir");
#pragma DATA_SECTION(z1, ".bss");
#pragma DATA_SECTION(z2, ".bss");
#pragma DATA_SECTION(x3, ".bss");
#pragma DATA_SECTION(x4, ".bss");
#pragma DATA_SECTION(y2, ".bss");
#pragma DATA_SECTION(temp, ".bss");
#pragma DATA_ALIGN(z1, 2);
#pragma DATA_ALIGN(z2, 2);
#endif


#include "coef8to16.h"
#include "coef16to48.h"

Int16 z1[(TAPS8to16/2)+1];
Int16 z2[(TAPS16to48/3)+1];

Int16 x3[INT_NUM_DATA_IN],       // Input data
      x4[INT_NUM_DATA2],
      y2[INT_NUM_DATA_OUT];      // Output data
Int8  temp[INT_NUM_DATA_OUT*2];

void wHeader(Uint8 *w, float f1, float f2, Uint32 bytes);

void main()
{
    FILE  *fpIn,*fpOut;
    Int16 i,k,c,
		  indx1,        // Delay line index
		  indx2;        // Delay line index
    Uint8 waveHeader[44];
    Uint32 cnt;

    printf("Exp --- Interpolation experiment\n");
    printf("Enter 1 for using PCM file, enter 2 for using WAV file\n");
    scanf ("%d", &c);;

    if (c == 2)
    {
    	fpIn = fopen("..\\data\\tone1k_8000.wav", "rb");
    	fpOut = fopen("..\\data\\output1khz48kHz.wav", "wb");
    }
    else
    {
    	fpIn = fopen("..\\data\\tone1k_8000.pcm", "rb");
    	fpOut = fopen("..\\data\\output1khz48kHz.pcm", "wb");
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
    for (i=0; i<TAPS8to16/2; i++)
    {
        z1[i] = 0;
    }
    for (i=0; i<TAPS16to48/3; i++)
    {
        z2[i] = 0;
    }
    for (i=0; i<INT_NUM_DATA_OUT*2; i++)
    {
        temp[i] = 0;
    }
    
    indx1 = 0;
    indx2 = 0;
    cnt = 0;

    // Begin filtering the data
    while (fread(temp, sizeof(Int8), INT_NUM_DATA_IN*2, fpIn) ==
		   (INT_NUM_DATA_IN*2))
    {
    for (k=0, i=0; i<INT_NUM_DATA_IN; i++)
    {
        x3[i] = (temp[k]&0xFF)|(temp[k+1]<<8);
        k += 2;
    }
    
    // Filter the data x and save output y
    interpolate(x3, INT_NUM_DATA_IN, intpFilt8to16, TAPS8to16/2, x4, z1, &indx1,2);

    interpolate(x4, INT_NUM_DATA2, intpFilt16to48, TAPS16to48/3, y2, z2, &indx2,3);

    for (k=0, i=0; i<INT_NUM_DATA_OUT; i++)
    {
        temp[k++] = (y2[i]&0xFF);
        temp[k++] = (y2[i]>>8)&0xFF;
        cnt += 2;
    }
        printf("%ld samples processed\n", cnt>>1);
        fwrite(temp, sizeof(Int8), (INT_NUM_DATA_OUT*2), fpOut);
    }

    if (c == 2)		// Based on input WAVE file to generate output
    {
    	wHeader(waveHeader, 8000, 48000, cnt);
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
