/*
 * Experiment decimation using FIR filter - Chapter 3
 * coef48to24.h
 *
 * Description: This is the filter coefficient file for a 2:1 decimation FIR filter
 *
 *  Created on: May 13, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

Int16 deciFilt48to24[TAPS48to24]={
(Int16)(0.001471*32767.0),
(Int16)(-0.007929*32767.0),
(Int16)(-0.027013*32767.0),
(Int16)(-0.031867*32767.0),
(Int16)(0.017209*32767.0),
(Int16)(0.130256*32767.0),
(Int16)(0.255831*32767.0),
(Int16)(0.311233*32767.0),
(Int16)(0.255831*32767.0),
(Int16)(0.130256*32767.0),
(Int16)(0.017209*32767.0),
(Int16)(-0.031867*32767.0),
(Int16)(-0.027013*32767.0),
(Int16)(-0.007929*32767.0),
(Int16)(0.001471*32767.0)
};
