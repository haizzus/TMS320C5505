 /*
 * randNoise.c
 *
 *  Created on: May 6, 2012
 *      Author: BLEE
 *
 *      Description: This function generates random numbers using math library rand()
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdlib.h>
#include "tistdtypes.h"

// Function prototype
void initRand(Uint16 seed);
Int16 randNoise(void);

void initRand(Uint16 seed)               // Random number initialization
{
    srand(seed);
}

Int16 randNoise(void)                    // Random number generation
{   
    return((rand()-RAND_MAX/2)>>1);
}


