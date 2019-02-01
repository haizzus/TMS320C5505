 /*
 * toneGenTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"
#include "i2s.h"
#include "dma.h"
#include "dmaBuff.h"

#define XMIT_BUFF_SIZE          48*2
Int16 XmitL1[XMIT_BUFF_SIZE];	// DMA uses the same buffer names, do not rename
Int16 XmitR1[XMIT_BUFF_SIZE];
Int16 XmitL2[XMIT_BUFF_SIZE];
Int16 XmitR2[XMIT_BUFF_SIZE];

Int16 RcvL1[XMIT_BUFF_SIZE];
Int16 RcvR1[XMIT_BUFF_SIZE];
Int16 RcvL2[XMIT_BUFF_SIZE];
Int16 RcvR2[XMIT_BUFF_SIZE];

void leftChannel_process(Int16 *output, Int16 size);
void rightChannel_process(Int16 *output, Int16 size);
void playAudio(void);

extern void AIC3204_init(Uint32, Int16, Int16);
extern void initTone(Uint16 f, Uint16 Fs);
extern Int16 tone(void);

#define IER0        *(volatile unsigned *)0x0000

#define SF				8000
#define DAC_GAIN		0		// 0dB range: -6dB to 29dB
#define ADC_GAIN		0		// 0dB range: 0dB to 46dB

void main(void)
{
    Int16 i;

    // Clean output buffers before running the experiment
    for (i=0; i<XMIT_BUFF_SIZE; i++)
    {
        XmitL1[i]=XmitL2[i]=XmitR1[i]=XmitR2[i]=0;
        RcvL1[i]=RcvL2[i]=RcvR1[i]=RcvR2[i]=0;
    }

    setDMA_address();		// DMA address setup for each buffer

    asm(" BCLR ST1_INTM");	// Disable all interrupts
    IER0 = 0x0110;      	// Enable DMA interrupt

    set_i2s0_slave();		// Set I2S
    AIC3204_init(SF, DAC_GAIN, (Uint16)ADC_GAIN);  // Set AIC3204
    enable_i2s0();

    enable_dma_int();		// Set up and enable DMA
    set_dma0_ch0_i2s0_Lout(XMIT_BUFF_SIZE);
    set_dma0_ch1_i2s0_Rout(XMIT_BUFF_SIZE);
    set_dma0_ch2_i2s0_Lin(XMIT_BUFF_SIZE);
    set_dma0_ch3_i2s0_Rin(XMIT_BUFF_SIZE);

    initTone(400, SF);		// Initialize tone generator

    printf("Exp --- B: tone generation experiment\n");

    printf("Play audio tone\n");
    playAudio();
    printf("Exp --- completed\n");
}

// DSP processing function
void leftChannel_process(Int16 *output, Int16 size)
{
    Int16 i;

    for(i=0; i<size; i++)
    {
    	*(output + i) = tone();	// Send tone through left channel
    }
}

void rightChannel_process(Int16 *output, Int16 size)
{
    Int16 i;

    for(i=0; i<size; i++)
    {
    	*(output + i) = 0;		// Mute right channel
    }
}

void playAudio(void)
{
	Int16 i,j;

	for(i=0; i<32000; i++)
	{
		for (j=0; j<2000; j++)
		{
			if(leftChannel == 1)
			{
				leftChannel = 0;
				if (CurrentRxL_DMAChannel == 2)
				{
					leftChannel_process(XmitL1, XMIT_BUFF_SIZE);
				}
				else
				{
					leftChannel_process(XmitL2, XMIT_BUFF_SIZE);
				}
			}
			if(rightChannel == 1)
			{
				rightChannel= 0;
				if (CurrentRxR_DMAChannel == 2)
				{
					rightChannel_process(XmitR1, XMIT_BUFF_SIZE);
				}
				else
				{
					rightChannel_process(XmitR2, XMIT_BUFF_SIZE);
				}
			}
		}
	}
}
