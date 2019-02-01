/*
 * Experiment interpolation using FIR filter - Chapter 3
 * interpolation.h
 *
 * Description: his is the header file for fixed-point interpolation filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define  TAPS8to16         196
#define  TAPS16to48         66

#define  INT_NUM_DATA_IN    96
#define  INT_NUM_DATA2      (INT_NUM_DATA_IN*2)
#define  INT_NUM_DATA_OUT   (INT_NUM_DATA2*3)

void  interpolate(Int16 *x, Int16 blkSize,
		  Int16 *h, Int16 order,
                  Int16 *y,
                  Int16 *w, Int16 *index,
                  Int16 interp);
