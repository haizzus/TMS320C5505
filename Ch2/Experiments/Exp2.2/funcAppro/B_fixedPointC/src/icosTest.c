 /*
 * icosTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *		Description: This experiment program using fixed-point C
 *               for calculating cosine function in the range of [0, PI/2]
 *               by equation: cos(x)=1-(1/2!)x^2+(1/4!)x^4-(1/6!)x^6
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

// Function approximation coefficients for cosine
Int16 icosCoef[4]={
	(Int16)(UNITQ15),
	(Int16)(-(UNITQ15/2.0)),
	(Int16)(UNITQ15/(2.0*3.0*4.0)),
	(Int16)(-(UNITQ15/(2.0*3.0*4.0*5.0*6.0)))
};


// Fixed-point implementation of function approximation
Int16 iCos1(Int16 x)
{
    Int32  cosine,z;
    Int16 x2;

    z = (Int32)x * x;
    x2 = (Int16)(z>>15);                       // x2 has x(Q14)*x(Q14)

    cosine = (Int32)icosCoef[3] * x2;
    cosine = cosine >> 13;                     // Scale back to Q15
    cosine = (Int16)(cosine + (Int32)icosCoef[2]) * (Int32)x2;
    cosine = cosine >> 13;                     // Scale back to Q15
    cosine = (cosine + (Int32)icosCoef[1]) * x2;
    cosine = cosine >> 13;                     // Scale back to Q15
    cosine = cosine + icosCoef[0];
    return((Int16)cosine);
}

// Simulated assembly implementation for function approximation
Int16 iCos(Int16 T0)
{
    Int32  AC0;
    Int16 *ptr;

    ptr = &icosCoef[3];
    AC0 = (Int32)T0 * T0;
    T0  = (Int16)(AC0>>15);                  // AC0 has T0(Q14)*T0(Q14)

    AC0 = (Int32)T0 * *ptr--;
    AC0 = AC0 >> 13;                         // Scale back to Q15
    AC0 = (Int16)(AC0 + *ptr--) * (Int32)T0;
    AC0 = AC0 >> 13;                         // Scale back to Q15
    AC0 = (Int16)(AC0 + *ptr--) * (Int32)T0;
    AC0 = AC0 >> 13;                         // Scale back to Q15
    AC0 = AC0 +  *ptr;
    return((Int16)AC0);
}



void main(void)
{
    static double y[5];
    Int16  x[5],z[5];

    printf("Exp --- B: fixed-point C experiment\n");

    x[0] = (Int16)(0);                     // Q14 format input in rad
    x[1] = (Int16)(UNITQ14*PI/6.0);        // Q14 format input in rad
    x[2] = (Int16)(UNITQ14*PI/4.0);        // Q14 format input in rad
    x[3] = (Int16)(UNITQ14*PI/3.0);        // Q14 format input in rad
    x[4] = (Int16)(UNITQ14*PI/2.0);        // Q14 format input in rad
	
    z[0] = iCos1(x[0]);                    // Floating-point calculation
    z[1] = iCos1(x[1]);                    // Floating-point calculation
    z[2] = iCos1(x[2]);                    // Floating-point calculation
    z[3] = iCos1(x[3]);                    // Floating-point calculation
    z[4] = iCos1(x[4]);                    // Floating-point calculation

    y[0] = (double)z[0]/UNITQ15;
    y[1] = (double)z[1]/UNITQ15;
    y[2] = (double)z[2]/UNITQ15;
    y[3] = (double)z[3]/UNITQ15;
    y[4] = (double)z[4]/UNITQ15;  
    printf("Fixed-point implementation of function approximation\n");
    printf("cos(0) = %1.4f\n", y[0]);
    printf("cos(PI/6) = %1.4f\n", y[1]);
    printf("cos(PI/4) = %1.4f\n", y[2]);
    printf("cos(PI/3) = %1.4f\n", y[3]);
    printf("cos(PI/2) = %1.4f\n", y[4]);
    
    z[0] = iCos(x[0]);                     // Floating-point calculation
    z[1] = iCos(x[1]);                     // Floating-point calculation
    z[2] = iCos(x[2]);                     // Floating-point calculation
    z[3] = iCos(x[3]);                     // Floating-point calculation
    z[4] = iCos(x[4]);                     // Floating-point calculation

    y[0] = (double)z[0]/UNITQ15;
    y[1] = (double)z[1]/UNITQ15;
    y[2] = (double)z[2]/UNITQ15;
    y[3] = (double)z[3]/UNITQ15;
    y[4] = (double)z[4]/UNITQ15;
    printf("Simulated assembly implementation for function approximation\n");
    printf("cos(0) = %1.4f\n", y[0]);
    printf("cos(PI/6) = %1.4f\n", y[1]);
    printf("cos(PI/4) = %1.4f\n", y[2]);
    printf("cos(PI/3) = %1.4f\n", y[3]);
    printf("cos(PI/2) = %1.4f\n", y[4]);
    printf("\nExp --- completed\n");
}


