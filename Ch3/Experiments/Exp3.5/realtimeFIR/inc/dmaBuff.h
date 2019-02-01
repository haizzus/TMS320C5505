/*
 * dmaBuff.h
 *
 *  Created on: Mar 17, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#ifndef DMABUFF_H_
#define DMABUFF_H_

#define XMIT_BUFF_SIZE          48*2

extern Int16  XmitL1[];
extern Int16  XmitR1[];
extern Int16  XmitL2[];
extern Int16  XmitR2[];

extern Int16  RcvL1[];
extern Int16  RcvR1[];
extern Int16  RcvL2[];
extern Int16  RcvR2[];

#endif /* DMABUFF_H_ */
