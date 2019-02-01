/* 
//  Project: Example 3.15: floating-point implementation of FIR filter
//  File name: floatingPointFirTest.c   
//
//  Description: This is the test file for the example of floating-point FIR filter
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

void main()
{
    FILE  *fpIn,*fpOut;
    short i;
    char  temp[2];
    float x,  // Input data
          y;  // Output data
  
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

    // Begin filtering the data
    while (fread(&temp, sizeof(char), 2, fpIn) == 2)
    {
        x = (float)((temp[1]<<8)|(temp[0]&0xff));
        // Filter the data x and save output y
        floatPointFir(&x, firCoefFloatingPoint, NUM_TAPS, &y, w);

        temp[0] = (char)((short)y&0xff);
        temp[1] = (char)(((short)y>>8)&0xff);
        fwrite(&temp, sizeof(char), 2, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
}
