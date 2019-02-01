/*
 * Experiment decimation using FIR filter - Chapter 3
 * decimation.h
 *
 * Description: This is the header file for decimation FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#define  TAPS48to24   15
#define  TAPS24to8   213

#define  DEC_NUM_DATA_OUT    96
#define  DEC_NUM_DATA2      (DEC_NUM_DATA_OUT*3)
#define  DEC_NUM_DATA_IN    (DEC_NUM_DATA2*2)

void  decimator(Int16 *x, Int16 blkSize,
				Int16 *h, Int16 order,
				Int16 *y,
				Int16 *w, Int16 *index,
				Int16 dec);
