/*
 * firFilter.c
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
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
#include "dualMacFir.h"

extern void firFilter_init(void);
extern void firFilter(void);

/* Define DSP system memory map */
#pragma DATA_SECTION(dualMacFirCoef, ".const:fir");
#pragma DATA_SECTION(w1, ".bss:fir");
#pragma DATA_SECTION(w2, ".bss:fir");
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

Int16 w1[NUM_TAPS+1];     		// For using dual MAC, this must add 1 location
Int16 w2[NUM_TAPS+1];
Int16 index1, index2;

#include "dualMacFirCoef.h"


void firFilter_init(void)
{
	Int16 i;

	// Initialize for filtering process
	for (i=0; i<=NUM_TAPS; i++)
	{
        w1[i] = 0;
        w2[i] = 0;
	}
	index1 = 0;
	index2 = 0;
}
void firFilter(void)
{
	Int32 n=0;
	Int16 i,j=0;

	printf("Filter status:\n");
	printf("off\n");
    while (1)			// Forever loop for the demo
    {
    	if (n++ == (0x1000000))
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
            	if (j) // Lowpass filter the input audio data and send to output
            	{
            		dualMacFir(RcvL1, XMIT_BUFF_SIZE, dualMacFirCoef, NUM_TAPS, XmitL1, w1, &index1);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL1[i] = RcvL1[i];
            		}
            	}
            }
            else
            {
            	if (j) // Lowpass filter the input audio data and send to output
            	{
            		dualMacFir(RcvL2, XMIT_BUFF_SIZE, dualMacFirCoef, NUM_TAPS, XmitL2, w1, &index1);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitL2[i] = RcvL2[i];
            		}
            	}
             }
        }
        if(rightChannel == 1)
        {
        	rightChannel= 0;
            if (CurrentRxR_DMAChannel == 2)
            {
            	if (j) // Lowpass filter the input audio data and send to output
            	{
            		dualMacFir(RcvR1, XMIT_BUFF_SIZE, dualMacFirCoef, NUM_TAPS, XmitR1, w2, &index2);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR1[i] = RcvR1[i];
            		}
            	}
            }
            else
            {
            	if (j) // Lowpass filter the input audio data and send to output
            	{
            		dualMacFir(RcvR2, XMIT_BUFF_SIZE, dualMacFirCoef, NUM_TAPS, XmitR2, w2, &index2);
            	}
            	else  // Without filter, pass through the audio
            	{
            		for(i=0; i<XMIT_BUFF_SIZE; i++)
            		{
            			XmitR2[i] = RcvR2[i];
            		}
            	}
            }
        }
    }
}
