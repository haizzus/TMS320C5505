/*
 * Experiment implementation of block FIR filter using dual-MAC - Chapter 3
 * dualMACFir.h
 *
 * Description: This is the header file for FIR filter using dual-MAC
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 * 		For the book "Real Time Digital Signal Processing:
 *                    Fundamentals, Implementation and Application, 3rd Ed"
 * 		              By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 * 		              Publisher: John Wiley and Sons, Ltd
 */

#define  NUM_TAPS   48
#define  NUM_DATA   80

void dualMacFir(Int16 *x, Int16 blkSize,
				Int16 *h, Int16 order,
				Int16 *y,
				Int16 *w, Int16 *index);
