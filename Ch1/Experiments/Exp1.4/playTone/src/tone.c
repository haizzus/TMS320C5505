/*
 * tone.c
 *
 *  Created on: Mar 11, 2012
 *      Author: BLEE
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 */


#define AIC3204_I2C_ADDR 0x18
#include "usbstk5505.h"
#include "usbstk5505_gpio.h"
#include "usbstk5505_i2c.h"
#include "usbstk5505_i2s.h"
#include <stdio.h>

extern void aic3204_tone_headphone( );
extern void tone(Uint32, Int16, Int16, Uint16, Int16*);
extern void Init_AIC3204(Uint32 sf, Int16 gDAC, Uint16 gADC);
extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);

void tone(Uint32 sf, Int16 playtime, Int16 gDAC, Uint16 gADC, Int16 *sinetable)
{
    Int16 sec, msec;
    Int16 sample, len;

    /* Initialize BSL */
    USBSTK5505_init( );

    /* Set A20_MODE for GPIO mode */
    CSL_FINST(CSL_SYSCTRL_REGS->EBSR, SYS_EBSR_A20_MODE, MODE1); 
    
    /* Use GPIO to enable AIC3204 chip */
    USBSTK5505_GPIO_init();
    USBSTK5505_GPIO_setDirection(GPIO26, GPIO_OUT);
    USBSTK5505_GPIO_setOutput( GPIO26, 1 );    // Take AIC3204 chip out of reset
    
    /* Initialize I2C */
    USBSTK5505_I2C_init( );

    /* Initialized AIC3204 */
    Init_AIC3204(sf, gDAC, gADC);

    /* Initialize I2S */
    USBSTK5505_I2S_init();

    switch (sf)
    {
        case 8000:
            len = 8;
            break;
        case 12000:
            len = 12;
            break;
        case 16000:
            len = 16;
            break;
        case 24000:
            len = 24;
            break;
        case 48000:
        default:
            len = 48;
            break;
    }

    /* Play tone */
    for ( sec = 0 ; sec < playtime ; sec++ )
    {
        for ( msec = 0 ; msec < 1000 ; msec++ )
        {
            for ( sample = 0 ; sample < len ; sample++ )
            {
                /* Write 16-bit left channel data */
                USBSTK5505_I2S_writeLeft( sinetable[sample]);

                /* Write 16-bit right channel data */
                USBSTK5505_I2S_writeRight(sinetable[sample]);
            }
        }
    }

#if 0
    USBSTK5505_I2S_close();  // Disable I2S
    AIC3204_rset( 1, 1 );    // Reset codec

    USBSTK5505_GPIO_setOutput( GPIO26, 0 );    // Disable AIC3204
#endif
}
