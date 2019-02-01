 /*
 * ftone.c
 *
 *  Created on: May 6, 2012
 *      Author: BLEE
 *
 *      Description: This function generates a tone using math library cos(x)
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <math.h>
#include "tistdtypes.h"

#define UINTQ14     0x3FFF
#define PI          3.1415926

// Function prototype
void initFTone(Uint16 f, Uint16 Fs);
Int16 fTone(Uint16 Fs);

// Variable definition
static Uint16 n;
static float twoPI_f_Fs;

void initFTone(Uint16 f, Uint16 Fs)
{
    n = 0;
    twoPI_f_Fs = 2.0*PI*(float)f/(float)Fs;    // Define frequency
}

Int16 fTone(Uint16 Fs)                         // Cosine generation
{
    n++;
    if (n >= Fs)
        n=0;
    return( (Int16)(cos(twoPI_f_Fs*(float)n)*UINTQ14));
}


