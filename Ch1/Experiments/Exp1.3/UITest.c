/*
 * UITest.c
 *
 *  Created on: Mar 10, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"

#define SIZE 48
Int16 dataTable[SIZE];

void main()
{
	/* Pre-generated sine wave data, 16-bit signed samples */
	Int16 table[SIZE] = {
        0x0000, 0x10b4, 0x2120, 0x30fb, 0x3fff, 0x4dea, 0x5a81, 0x658b,
        0x6ed8, 0x763f, 0x7ba1, 0x7ee5, 0x7ffd, 0x7ee5, 0x7ba1, 0x76ef,
        0x6ed8, 0x658b, 0x5a81, 0x4dea, 0x3fff, 0x30fb, 0x2120, 0x10b4,
        0x0000, 0xef4c, 0xdee0, 0xcf06, 0xc002, 0xb216, 0xa57f, 0x9a75,
        0x9128, 0x89c1, 0x845f, 0x811b, 0x8002, 0x811b, 0x845f, 0x89c1,
        0x9128, 0x9a76, 0xa57f, 0xb216, 0xc002, 0xcf06, 0xdee0, 0xef4c
	};

	Int16 g,p,i,j,k,n,m;
	Uint32 sf;

	printf("Exp. 1.3 --- UI\n");

	printf("Enter an integer number for Gain between (-6 and 29)\n");
	scanf ("%d", &g);

	printf("Enter the Sampling Frequency, select one: 8000, 12000, 16000, 24000 or 48000\n");
	scanf ("%ld", &sf);

	printf("Enter the playing time duration (5 to 60)\n");
	scanf ("%i", &p);

	if ((g < -6)||(g > 29))
	{
		printf("You have entered an invalid Gain\n");
		printf("Use default gain = 0dB\n");
		g = 0;
	}
	else
	{
		printf("Gain is set to %ddB\n", g);
	}

	if ( (sf == 8000)||(sf == 12000)||(sf == 16000)||(sf == 24000)||(sf == 48000))
	{
		printf("Sampling Frequency is set to %ldHz\n", sf);
	}
	else
	{
		printf("You have entered an invalid Sampling Frequency\n");
		printf("Use default Sampling Frequency = 48000Hz\n");
		sf = 48000;
	}

	if ((p < 5)||(p > 60))
	{
		printf("You have entered an invalid playing time\n");
		printf("Use default duration = 10s\n");
		p = 10;
	}
	else
	{
		printf("Playing time is set to %ds\n", p);
	}

	for (i=0; i<SIZE; i++)
		dataTable[i] = 0;

	switch (sf)
	{
		case 8000:
			m = 6;
			break;
		case 12000:
			m = 4;
			break;
		case 16000:
			m = 3;
			break;
		case 24000:
			m = 2;
			break;
		case 48000:
		default:
			m = 1;
			break;
	}

	for (n=k=0, i=0; i<m; i++)		// Fill in the data table
	{
		for (j=k; j<SIZE; j+=m)
		{
			dataTable[n++] = table[j];
		}
		k++;
	}

	printf("\nExp --- completed\n");
}
