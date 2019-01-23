/*
 * fileIOTest.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tistdtypes.h"

Uint8 waveHeader[44]={                          // 44 bytes for WAV file header
		0x52,	0x49,	0x46,	0x46,	0x00,	0x00,	0x00,	0x00,
		0x57,	0x41,	0x56,	0x45,	0x66,	0x6D,	0x74,	0x20,
		0x10,	0x00,	0x00,	0x00,	0x01,	0x00,	0x01,	0x00,
		0x40,	0x1F,	0x00,	0x00,	0x80,	0x3E,	0x00,	0x00,
		0x02,	0x00,	0x10,	0x00,	0x64,	0x61,	0x74,	0x61,
		0x00,	0x00,	0x00,	0x00};

#define SIZE	1024
Uint8 ch[SIZE];                                 // Declare a char[1024] array for experiment

void main()
{
	FILE *fp1,*fp2;                             // File pointers
	uint32_t i;                                   // Unsigned long integer used as a counter

	printf("Exp. 1.2 --- file IO\n");
	ch[0] = 0xFF;
	memset(ch, 0x00, SIZE);

	fp1 = fopen("..\\data\\C55DSPUSBStickAudioTest.pcm", "rb");	// Open input file
	fp2 = fopen("..\\data\\C55DSPUSBStickAudioTest.wav", "wb");	// Open output file

	if (fp1 == NULL)                            // Check if the input file exists
	{
		printf("Failed to open input file 'C55DSPUSBStickAudioTest.pcm'\n");
		exit(0);
	}

	fseek(fp2, 44, 0);                          // Advance output file point 44 bytes
	i=0;
	while (fread(ch, sizeof(Uint8), SIZE, fp1) == SIZE) // Read in SIZE of input data bytes
	{
		fwrite(ch, sizeof(Uint8), SIZE, fp2);  // Write SIZE of data bytes to output file
		i += SIZE;
		printf("%ld bytes processed\n", i);    // Show the number of data is processed

	}

	waveHeader[40] = (Uint8)(i&0xff);          // Update the size parameter into WAV header
	waveHeader[41] = (Uint8)(i>>8)&0xff;
	waveHeader[42] = (Uint8)(i>>16)&0xff;
	waveHeader[43] = (Uint8)(i>>24)&0xff;
	waveHeader[4] = waveHeader[40];
	waveHeader[5] = waveHeader[41];
	waveHeader[6] = waveHeader[42];
	waveHeader[7] = waveHeader[43];

	rewind(fp2);                                // Adjust output file point to beginning
	fwrite(waveHeader, sizeof(Uint8), 44, fp2); // Write 44 bytes of WAV header to output file

	fclose(fp1);                                // Close input file
	fclose(fp2);                                // Close output file

	printf("\nExp --- completed\n");
}

