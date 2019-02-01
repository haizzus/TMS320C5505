/*
 * sineCosineTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *		Description: This function is used to test function approximation experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include <stdio.h>
#include "tistdtypes.h"

#define UNITQ15  0x7FFF
                   
extern void sine_cos(Int16, Int16 *);

const Int16 theta[16]={
    0x9556,0xa000,0xaaab,0xc000,  /* -150, -135, -120, -90 */
    0xd555,0xe000,0xeaab,0xffff,  /*  -60,  -45,  -30,  -0 */ 
    0x1555,0x2000,0x2aaa,0x4000,  /*   30,   45,   60,  90 */            
    0x5555,0x6000,0x6aaa,0x7fff}; /*  120,  135,  150, 180 */


void main()
{    
	double  result[32];
	Int16   Wn[2], i;

    printf("Exp --- D: design for DSP experiment\n");

    /* 3rd quadrant angles */  
    sine_cos(theta[0], Wn); /* -150 */
    result[0] = (double)(Wn[0])/UNITQ15;
    result[1] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[1], Wn); /* -135 */
    result[2] = (double)(Wn[0])/UNITQ15;
    result[3] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[2], Wn); /* -120 */
    result[4] = (double)(Wn[0])/UNITQ15;
    result[5] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[3], Wn); /* -90  */
    result[6] = (double)(Wn[0])/UNITQ15;
    result[7] = (double)(Wn[1])/UNITQ15;
		
    /* 4th quadrant angles */  
    sine_cos(theta[4], Wn); /* -60 */
    result[8] = (double)(Wn[0])/UNITQ15;
    result[9] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[5], Wn); /* -45 */
    result[10] = (double)(Wn[0])/UNITQ15;
    result[11] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[6], Wn); /* -30 */
    result[12] = (double)(Wn[0])/UNITQ15;
    result[13] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[7], Wn); /* -0  */
    result[14] = (double)(Wn[0])/UNITQ15;
    result[15] = (double)(Wn[1])/UNITQ15;
	
    /* 1st quadrant angles */
    sine_cos(theta[8], Wn);   /* 30 */
    result[16] = (double)(Wn[0])/UNITQ15;
    result[17] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[9], Wn);	  /* 45 */
    result[18] = (double)(Wn[0])/UNITQ15;
    result[19] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[10], Wn); /* 60 */
    result[20] = (double)(Wn[0])/UNITQ15;
    result[21] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[11], Wn); /* 90 */   
    result[22] = (double)(Wn[0])/UNITQ15;
    result[23] = (double)(Wn[1])/UNITQ15;
		
    /* 2nd quadrant angles */
    sine_cos(theta[12], Wn); /* 120 */
    result[24] = (double)(Wn[0])/UNITQ15;
    result[25] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[13], Wn); /* 135 */
    result[26] = (double)(Wn[0])/UNITQ15;
    result[27] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[14], Wn); /* 150 */
    result[28] = (double)(Wn[0])/UNITQ15;
    result[29] = (double)(Wn[1])/UNITQ15;
    sine_cos(theta[15], Wn); /* 180 */
    result[30] = (double)(Wn[0])/UNITQ15;
    result[31] = (double)(Wn[1])/UNITQ15;


    printf("1st quadrant angles: cos(x) and sin(x)\n");
    for (i=16; i<24; i+=2)
    {
        printf("cos(x)=%1.4f\t sin(x)=%1.4f\n", result[i], result[i+1]);
    }
    printf("2nd quadrant angles: cos(x) and sin(x)\n");
    for (i=24; i<32; i+=2)
    {
        printf("cos(x)=%1.4f\t sin(x)=%1.4f\n", result[i], result[i+1]);
    }
    printf("3rd quadrant angles: cos(x) and sin(x)\n");
    for (i=0; i<8; i+=2)
    {
        printf("cos(x)=%1.4f\t sin(x)=%1.4f\n", result[i], result[i+1]);
    }
    printf("4th quadrant angles: cos(x) and sin(x)\n");
    for (i=8; i<16; i+=2)
    {
        printf("cos(x)=%1.4f\t sin(x)=%1.4f\n", result[i], result[i+1]);
    }
    printf("\nExp --- completed\n");
}
