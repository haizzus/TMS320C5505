/*
 * tone.c
 *
 *  Created on: May 6, 2012
 *      Author: BLEE
 *
 *      Description: This function generates a tone by calling
 *                   C55x assembly routine, cosine()
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */


#include "tistdtypes.h"
#define PI          0x7FFF

// Function prototype
void  initTone(Uint16 f, Uint16 Fs);
Int16 tone(void);
extern Int16 cosine(Int16);


// Variable definition
static Uint16 n;
static Int16 twoPI_f_Fs;

void initTone(Uint16 f, Uint16 Fs)
{
    n = 0;
    twoPI_f_Fs = (Int16)((2.0*PI*(float)f/(float)Fs));
}

Int16 tone(void)
{
	Int16 theta;

    theta = (Int16)(twoPI_f_Fs * n++);
    return (cosine(theta));
}

