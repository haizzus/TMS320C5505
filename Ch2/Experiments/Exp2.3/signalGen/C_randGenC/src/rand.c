 /*
 * rand.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *      Project: Real Time Random Number (Noise) Generation
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"

#define PI          0x7FFF

// Function prototype
Int16 randNumber1(void);
Int16 randNumber2(void);
void  initRand(Int32 seed);

// Variable definition
static volatile Int32 n;
static Int16 a;

void initRand(Int32 seed)
{
    n = (Int32)seed;
    a = 2045;
}

Int16 randNumber1(void)
{
	Int16 ran;

	n = a*n + 1;
	n = n - (Int32)((float)(n*0x100000)/(float)0x100000);
	ran = (n+1)/0x100001;
	return (ran);
}

Int16 randNumber2(void)
{
	Int16 ran;
    
	n = a*n;
	n = n&0xFFFFF000;
	ran = (Int16)(n>>20);
	return (ran);
}
