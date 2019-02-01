/*
 * fcosTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *		Description: This experiment program using floating-point C
 *               for calculating cosine function in the range of [0, PI/2]
 *               by equation: cos(x)=1-(1/2!)x^2+(1/4!)x^4-(1/6!)x^6
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>

#define PI (double)3.1415926

// Function approximation coefficients for cosine
double fcosCoef[4]={
    1.0, 
    -(1.0/2.0), 
    (1.0/(2.0*3.0*4.0)),
    -(1.0/(2.0*3.0*4.0*5.0*6.0))
};

// Direct implementation of function approximation
double fCos1(double x)
{
    double cosine;

    cosine  = fcosCoef[0];
    cosine += fcosCoef[1]*x*x;
    cosine += fcosCoef[2]*x*x*x*x;
    cosine += fcosCoef[3]*x*x*x*x*x*x;
    return(cosine);
}

// More efficient implementation of function approximation
double fCos2(double x)
{
    double cosine,x2;

    x2 = x * x;               
    cosine = fcosCoef[3] * x2;
    cosine = (cosine+fcosCoef[2]) * x2;
    cosine = (cosine+fcosCoef[1]) * x2;
    cosine = cosine + fcosCoef[0]; 
    return(cosine);
}


void main(void)
{
    double y[5];

    printf("Exp --- A: floating-point C experiment\n");

    y[0] = fCos1(0.0);                     // Floating-point calculation
    y[1] = fCos1(PI/6.0);                  // Floating-point calculation
    y[2] = fCos1(PI/4.0);                  // Floating-point calculation
    y[3] = fCos1(PI/3.0);                  // Floating-point calculation
    y[4] = fCos1(PI/2.0);                  // Floating-point calculation
    printf("Direct implementation of function approximation in floating point\n");
    printf("cos(0) = %1.4f\n", y[0]);
    printf("cos(PI/6) = %1.4f\n", y[1]);
    printf("cos(PI/4) = %1.4f\n", y[2]);
    printf("cos(PI/3) = %1.4f\n", y[3]);
    printf("cos(PI/2) = %1.4f\n", y[4]);

    y[0] = fCos2(0.0);                      // Floating-point calculation
    y[1] = fCos2(PI/6.0);                   // Floating-point calculation
    y[2] = fCos2(PI/4.0);                   // Floating-point calculation
    y[3] = fCos2(PI/3.0);                   // Floating-point calculation
    y[4] = fCos2(PI/2.0);                   // Floating-point calculation
    printf("More efficient implementation of function approximation in floating point\n");
    printf("cos(0) = %1.4f\n", y[0]);
    printf("cos(PI/6) = %1.4f\n", y[1]);
    printf("cos(PI/4) = %1.4f\n", y[2]);
    printf("cos(PI/3) = %1.4f\n", y[3]);
    printf("cos(PI/2) = %1.4f\n", y[4]);
    printf("\nExp --- completed\n");
}


