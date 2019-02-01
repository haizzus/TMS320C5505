/*
 * iirFilter.c
 *
 *  Created on: May 26, 2012
 *      Author: BLEE
 *
 *  Description: Initialization and control for IIR direct form-II (biquads) IIR filter
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */
#include <stdio.h>
#include "tistdtypes.h"
#include "dma.h"
#include "dmaBuff.h"

void iirFilter_init(void);
void iirFilter(void);

/* Define DSP system memory map */
#pragma DATA_ALIGN(XmitL1,2);	// Alignment is needed for dual accumulator store
#pragma DATA_ALIGN(XmitL2,2);
#pragma DATA_ALIGN(XmitR1,2);
#pragma DATA_ALIGN(XmitR2,2);

Int16 XmitL1[XMIT_BUFF_SIZE];
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

// IIR filter related variables
#include "asmIIR.h"
#include "iir_lp_2khz_48khz.h"		// Lowpass filter of 48kHz sampling rate and 2kHz cutoff frequency

#define SECTIONS       ((MWSPT_NSEC-1)/2)     // Number of 2nd order sections
Int16   C[SECTIONS*5]; // Filter coefficients obtained from example 5.14 MATLAB FDATool
                       // C[]=A[i][1], A[i][2], B[i][2], B[i][0], B[i][1]...
Int16   w1[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...
Int16   w2[SECTIONS*2]; // Filter delay line
                       // w[]=w[i][n-1],w[i+1][n-1],...,w[i][n-2],w[i+1][n-2],...



void iirFilter_init(void)
{
    Int32 temp32;
    Int16 gainNUM,gainDEN;
    Int16 i,k,n;

    // Initialize IIR filter delay line
    for (i=0; i<SECTIONS*2;i++)
	{
        w1[i] = 0;
        w2[i] = 0;
	}

	// Get coefficients from DEN[][] and NUM[][]
	for(k=0, n=0, i=0; i<SECTIONS; i++)
	{
            gainDEN = DEN[k][0];
            gainNUM = NUM[k++][0];

            temp32 = (Int32)gainDEN * DEN[k][1];
            C[n++] = (Int16)(temp32>>14);
            temp32 = (Int32)gainDEN * DEN[k][2];
            C[n++] = (Int16)(temp32>>14);
            
            temp32 = (Int32)gainNUM * NUM[k][2];
            C[n++] = (Int16)(temp32>>14);
            temp32 = (Int32)gainNUM * NUM[k][0];
            C[n++] = (Int16)(temp32>>14);
            temp32 = (Int32)gainNUM * NUM[k++][1];
            C[n++] = (Int16)(temp32>>14);
	}
}


void iirFilter(void)
{
    Int32 n=0;
    Int16 i,j=0;

    printf("Filter status:\n");
    printf("off\n");
    while (1)			// Forever loop for the demo if status is set
    {
    	if (n++ == (0x4000000))
    	{
            n = 0;
            j++;
            if (j &= 1)
                printf("on\n");
            else
                printf("off\n");
    	}

        if(leftChannel == 1)
        {
            leftChannel = 0;
            if (CurrentRxL_DMAChannel == 2)
            {
            	if (j) // Filter the input audio data and send to output
            	{
            	    asmIIR(RcvL1,XMIT_BUFF_SIZE,XmitL1,C,SECTIONS,w1);
            	}
            	else  // Without filter, pass through the audio
            	{
                    for(i=0; i<XMIT_BUFF_SIZE; i++)
                    {
                        XmitL1[i] = RcvL1[i]>>1;
                    }
            	}
            }
            else
            {
            	if (j) // Filter the input audio data and send to output
            	{
            	    asmIIR(RcvL2,XMIT_BUFF_SIZE,XmitL2,C,SECTIONS,w1);
            	}
            	else  // Without filter, pass through the audio
            	{
                    for(i=0; i<XMIT_BUFF_SIZE; i++)
                    {
                        XmitL2[i] = RcvL2[i]>>1;
                    }
            	}
             }
        }
        if(rightChannel == 1)
        {
            rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	if (j) // Filter the input audio data and send to output
            	{
            	    asmIIR(RcvR1,XMIT_BUFF_SIZE,XmitR1,C,SECTIONS,w2);
            	}
            	else  // Without filter, pass through the audio
            	{
                    for(i=0; i<XMIT_BUFF_SIZE; i++)
                    {
                        XmitR1[i] = RcvR1[i]>>1;
                    }
            	}
            }
            else
            {
            	if (j) // Filter the input audio data and send to output
            	{
            	    asmIIR(RcvR2,XMIT_BUFF_SIZE,XmitR2,C,SECTIONS,w2);
            	}
            	else  // Without filter, pass through the audio
            	{
                    for(i=0; i<XMIT_BUFF_SIZE; i++)
                    {
                        XmitR2[i] = RcvR2[i]>>1;
                    }
            	}
            }
        }
    }
}
