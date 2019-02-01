/*
 * c55xxASMTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *		Description: This experiment program is implemented for testing the
 *				assembly routine for calculating cosine function in the range
 *				of [0, PI/2] using function: cos(x)=1-(1/2!)x^2+(1/4!)x^4-(1/6!)x^6
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"

#define PI (double)3.1415926
#define UNITQ15  0x7FFF
#define UNITQ14  0x3FFF

extern Int16 cosine(Int16 T0);

void main(void)
{
    double y[5];
    Int16  x[5],z[5];

    printf("Exp --- C: assembly program experiment\n");

    x[0] = (Int16)(0);                     // Q14 format input in rad
    x[1] = (Int16)(UNITQ14*PI/6.0);        // Q14 format input in rad
    x[2] = (Int16)(UNITQ14*PI/4.0);        // Q14 format input in rad
    x[3] = (Int16)(UNITQ14*PI/3.0);        // Q14 format input in rad
    x[4] = (Int16)(UNITQ14*PI/2.0);        // Q14 format input in rad
	
    z[0] = cosine(x[0]);                   // Assembly function calculation
    z[1] = cosine(x[1]);                   // Assembly function calculation
    z[2] = cosine(x[2]);                   // Assembly function calculation
    z[3] = cosine(x[3]);                   // Assembly function calculation
    z[4] = cosine(x[4]);                   // Assembly function calculation

    y[0] = (double)z[0]/UNITQ15;
    y[1] = (double)z[1]/UNITQ15;
    y[2] = (double)z[2]/UNITQ15;
    y[3] = (double)z[3]/UNITQ15;
    y[4] = (double)z[4]/UNITQ15;                       
    printf("Assembly implementation of function approximation\n");
    printf("cos(0) = %1.4f\n", y[0]);
    printf("cos(PI/6) = %1.4f\n", y[1]);
    printf("cos(PI/4) = %1.4f\n", y[2]);
    printf("cos(PI/3) = %1.4f\n", y[3]);
    printf("cos(PI/2) = %1.4f\n", y[4]);
    printf("\nExp --- completed\n");
}


