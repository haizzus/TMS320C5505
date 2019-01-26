 /*
 * overflowTest.c
 *
 *  Created on: May 5, 2012
 *      Author: BLEE
 *
 *      Description: This is the experiment program file for understanding overflow
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */

#include "tistdtypes.h"

#define	BUF_SIZE 40

Int16 sineTable[BUF_SIZE]={
    0x0000,0x000f,0x001e,0x002d,0x003a,0x0046,0x0050,0x0059,
    0x005f,0x0062,0x0063,0x0062,0x005f,0x0059,0x0050,0x0046,
    0x003a,0x002d,0x001e,0x000f,0x0000,0xfff1,0xffe2,0xffd3,
    0xffc6,0xffba,0xffb0,0xffa7,0xffa1,0xff9e,0xff9d,0xff9e,
    0xffa1,0xffa7,0xffb0,0xffba,0xffc6,0xffd3,0xffe2,0xfff1}; 
			
extern Int16 ovftest(short, short *);

extern Int16 buff;         // Use graphic display this buffer
extern Int16 buff1;        // Use graphic display this buffer

void main()
{
    Int16 ovrflow_flag;
    Int16 *ptr=sineTable;

    while(1)
    {	         
        ovrflow_flag=0;
        ovrflow_flag=ovftest(ovrflow_flag, ptr); 
	
        if (ovrflow_flag != 0)         // <- Set break point on this line
            ovrflow_flag=ovftest(ovrflow_flag, ptr); 
    }  	                               // <- Set break point on this line
}
