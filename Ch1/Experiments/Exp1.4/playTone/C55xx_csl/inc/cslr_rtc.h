/********************************************************************
* Copyright (C) 2003-2008 Texas Instruments Incorporated.
* All Rights Reserved
*********************************************************************
* file: cslr_rtc.h
*
* Brief: This file contains the Register Description for rtc
*
*********************************************************************/
#ifndef _CSLR_RTC_H_
#define _CSLR_RTC_H_

#include <cslr.h>

#include <tistdtypes.h>
#include <csl_general.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 RTCINTEN;
    volatile Uint16 RTCUPDATE;
    volatile Uint16 RSVD0[2];
    volatile Uint16 RTCMIL;
    volatile Uint16 RTCMILA;
    volatile Uint16 RSVD1[2];
    volatile Uint16 RTCSEC;
    volatile Uint16 RTCSECA;
    volatile Uint16 RSVD2[2];
    volatile Uint16 RTCMIN;
    volatile Uint16 RTCMINA;
    volatile Uint16 RSVD3[2];
    volatile Uint16 RTCHOUR;
    volatile Uint16 RTCHOURA;
    volatile Uint16 RSVD4[2];
    volatile Uint16 RTCDAY;
    volatile Uint16 RTCDAYA;
    volatile Uint16 RSVD5[2];
    volatile Uint16 RTCMONTH;
    volatile Uint16 RTCMONTHA;
    volatile Uint16 RSVD6[2];
    volatile Uint16 RTCYEAR;
    volatile Uint16 RTCYEARA;
    volatile Uint16 RSVD7[2];
    volatile Uint16 RTCINTFL;
    volatile Uint16 RTCNOPWR;
    volatile Uint16 RSVD8[2];
    volatile Uint16 RTCINTREG;
    volatile Uint16 RSVD9[3];
    volatile Uint16 RTCDRIFT;
    volatile Uint16 RSVD10[3];
    volatile Uint16 RTCOSC;
    volatile Uint16 RSVD11[3];
    volatile Uint16 RTCPMGT;
    volatile Uint16 RSVD12[47];
    volatile Uint16 RTCSCR1;
    volatile Uint16 RTCSCR2;
    volatile Uint16 RSVD13[2];
    volatile Uint16 RTCSCR3;
    volatile Uint16 RTCSCR4;
} CSL_RtcRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* RTCINTEN */


#define CSL_RTC_RTCINTEN_RTCINTEN_MASK   (0x0001u)
#define CSL_RTC_RTCINTEN_RTCINTEN_SHIFT  (0x0000u)
#define CSL_RTC_RTCINTEN_RTCINTEN_RESETVAL (0x0000u)
/*----RTCINTEN Tokens----*/
#define CSL_RTC_RTCINTEN_RTCINTEN_DISABLED (0x0000u)
#define CSL_RTC_RTCINTEN_RTCINTEN_ENABLED (0x0001u)

#define CSL_RTC_RTCINTEN_RESETVAL        (0x0000u)

/* RTCUPDATE */

#define CSL_RTC_RTCUPDATE_TIMEUPDT_MASK  (0x8000u)
#define CSL_RTC_RTCUPDATE_TIMEUPDT_SHIFT (0x000Fu)
#define CSL_RTC_RTCUPDATE_TIMEUPDT_RESETVAL (0x0000u)
/*----TIMEUPDT Tokens----*/
#define CSL_RTC_RTCUPDATE_TIMEUPDT_CLEAR (0x0000u)
#define CSL_RTC_RTCUPDATE_TIMEUPDT_SET   (0x0001u)

#define CSL_RTC_RTCUPDATE_ALARMUPDT_MASK (0x4000u)
#define CSL_RTC_RTCUPDATE_ALARMUPDT_SHIFT (0x000Eu)
#define CSL_RTC_RTCUPDATE_ALARMUPDT_RESETVAL (0x0000u)
/*----ALARMUPDT Tokens----*/
#define CSL_RTC_RTCUPDATE_ALARMUPDT_CLEAR (0x0000u)
#define CSL_RTC_RTCUPDATE_ALARMUPDT_SET  (0x0001u)


#define CSL_RTC_RTCUPDATE_RESETVAL       (0x0000u)

/* RTCMIL */


#define CSL_RTC_RTCMIL_MS3_MASK          (0x1000u)
#define CSL_RTC_RTCMIL_MS3_SHIFT         (0x000Cu)
#define CSL_RTC_RTCMIL_MS3_RESETVAL      (0x0000u)
/*----MS3 Tokens----*/
#define CSL_RTC_RTCMIL_MS3_ZERO          (0x0000u)
#define CSL_RTC_RTCMIL_MS3_ONE           (0x0001u)

#define CSL_RTC_RTCMIL_MS2_MASK          (0x0F00u)
#define CSL_RTC_RTCMIL_MS2_SHIFT         (0x0008u)
#define CSL_RTC_RTCMIL_MS2_RESETVAL      (0x0000u)

#define CSL_RTC_RTCMIL_MS1_MASK          (0x00F0u)
#define CSL_RTC_RTCMIL_MS1_SHIFT         (0x0004u)
#define CSL_RTC_RTCMIL_MS1_RESETVAL      (0x0000u)

#define CSL_RTC_RTCMIL_MS0_MASK          (0x000Fu)
#define CSL_RTC_RTCMIL_MS0_SHIFT         (0x0000u)
#define CSL_RTC_RTCMIL_MS0_RESETVAL      (0x0000u)

#define CSL_RTC_RTCMIL_RESETVAL          (0x0000u)

/* RTCMILA */


#define CSL_RTC_RTCMILA_MSA3_MASK        (0x1000u)
#define CSL_RTC_RTCMILA_MSA3_SHIFT       (0x000Cu)
#define CSL_RTC_RTCMILA_MSA3_RESETVAL    (0x0000u)
/*----MSA3 Tokens----*/
#define CSL_RTC_RTCMILA_MSA3_ZERO        (0x0000u)
#define CSL_RTC_RTCMILA_MSA3_ONE         (0x0001u)

#define CSL_RTC_RTCMILA_MSA2_MASK        (0x0F00u)
#define CSL_RTC_RTCMILA_MSA2_SHIFT       (0x0008u)
#define CSL_RTC_RTCMILA_MSA2_RESETVAL    (0x0000u)

#define CSL_RTC_RTCMILA_MSA1_MASK        (0x00F0u)
#define CSL_RTC_RTCMILA_MSA1_SHIFT       (0x0004u)
#define CSL_RTC_RTCMILA_MSA1_RESETVAL    (0x0000u)

#define CSL_RTC_RTCMILA_MSA0_MASK        (0x000Fu)
#define CSL_RTC_RTCMILA_MSA0_SHIFT       (0x0000u)
#define CSL_RTC_RTCMILA_MSA0_RESETVAL    (0x0000u)

#define CSL_RTC_RTCMILA_RESETVAL         (0x0000u)

/* RTCSEC */


#define CSL_RTC_RTCSEC_SEC1_MASK         (0x0070u)
#define CSL_RTC_RTCSEC_SEC1_SHIFT        (0x0004u)
#define CSL_RTC_RTCSEC_SEC1_RESETVAL     (0x0000u)

#define CSL_RTC_RTCSEC_SEC0_MASK         (0x000Fu)
#define CSL_RTC_RTCSEC_SEC0_SHIFT        (0x0000u)
#define CSL_RTC_RTCSEC_SEC0_RESETVAL     (0x0000u)

#define CSL_RTC_RTCSEC_RESETVAL          (0x0000u)

/* RTCSECA */


#define CSL_RTC_RTCSECA_SECA1_MASK       (0x0070u)
#define CSL_RTC_RTCSECA_SECA1_SHIFT      (0x0004u)
#define CSL_RTC_RTCSECA_SECA1_RESETVAL   (0x0000u)

#define CSL_RTC_RTCSECA_SECA0_MASK       (0x000Fu)
#define CSL_RTC_RTCSECA_SECA0_SHIFT      (0x0000u)
#define CSL_RTC_RTCSECA_SECA0_RESETVAL   (0x0000u)

#define CSL_RTC_RTCSECA_RESETVAL         (0x0000u)

/* RTCMIN */


#define CSL_RTC_RTCMIN_MIN1_MASK         (0x0070u)
#define CSL_RTC_RTCMIN_MIN1_SHIFT        (0x0004u)
#define CSL_RTC_RTCMIN_MIN1_RESETVAL     (0x0000u)

#define CSL_RTC_RTCMIN_MIN0_MASK         (0x000Fu)
#define CSL_RTC_RTCMIN_MIN0_SHIFT        (0x0000u)
#define CSL_RTC_RTCMIN_MIN0_RESETVAL     (0x0000u)

#define CSL_RTC_RTCMIN_RESETVAL          (0x0000u)

/* RTCMINA */


#define CSL_RTC_RTCMINA_MINA1_MASK       (0x0070u)
#define CSL_RTC_RTCMINA_MINA1_SHIFT      (0x0004u)
#define CSL_RTC_RTCMINA_MINA1_RESETVAL   (0x0000u)

#define CSL_RTC_RTCMINA_MINA0_MASK       (0x000Fu)
#define CSL_RTC_RTCMINA_MINA0_SHIFT      (0x0000u)
#define CSL_RTC_RTCMINA_MINA0_RESETVAL   (0x0000u)

#define CSL_RTC_RTCMINA_RESETVAL         (0x0000u)

/* RTCHOUR */


#define CSL_RTC_RTCHOUR_HOUR1_MASK       (0x0030u)
#define CSL_RTC_RTCHOUR_HOUR1_SHIFT      (0x0004u)
#define CSL_RTC_RTCHOUR_HOUR1_RESETVAL   (0x0000u)

#define CSL_RTC_RTCHOUR_HOUR0_MASK       (0x000Fu)
#define CSL_RTC_RTCHOUR_HOUR0_SHIFT      (0x0000u)
#define CSL_RTC_RTCHOUR_HOUR0_RESETVAL   (0x0000u)

#define CSL_RTC_RTCHOUR_RESETVAL         (0x0000u)

/* RTCHOURA */


#define CSL_RTC_RTCHOURA_HOURA1_MASK     (0x0030u)
#define CSL_RTC_RTCHOURA_HOURA1_SHIFT    (0x0004u)
#define CSL_RTC_RTCHOURA_HOURA1_RESETVAL (0x0000u)

#define CSL_RTC_RTCHOURA_HOURA0_MASK     (0x000Fu)
#define CSL_RTC_RTCHOURA_HOURA0_SHIFT    (0x0000u)
#define CSL_RTC_RTCHOURA_HOURA0_RESETVAL (0x0000u)

#define CSL_RTC_RTCHOURA_RESETVAL        (0x0000u)

/* RTCDAY */


#define CSL_RTC_RTCDAY_DAY1_MASK         (0x0030u)
#define CSL_RTC_RTCDAY_DAY1_SHIFT        (0x0004u)
#define CSL_RTC_RTCDAY_DAY1_RESETVAL     (0x0000u)

#define CSL_RTC_RTCDAY_DAY0_MASK         (0x000Fu)
#define CSL_RTC_RTCDAY_DAY0_SHIFT        (0x0000u)
#define CSL_RTC_RTCDAY_DAY0_RESETVAL     (0x0000u)

#define CSL_RTC_RTCDAY_RESETVAL          (0x0000u)

/* RTCDAYA */


#define CSL_RTC_RTCDAYA_DAYA1_MASK       (0x0030u)
#define CSL_RTC_RTCDAYA_DAYA1_SHIFT      (0x0004u)
#define CSL_RTC_RTCDAYA_DAYA1_RESETVAL   (0x0000u)

#define CSL_RTC_RTCDAYA_DAYA0_MASK       (0x000Fu)
#define CSL_RTC_RTCDAYA_DAYA0_SHIFT      (0x0000u)
#define CSL_RTC_RTCDAYA_DAYA0_RESETVAL   (0x0000u)

#define CSL_RTC_RTCDAYA_RESETVAL         (0x0000u)

/* RTCMONTH */


#define CSL_RTC_RTCMONTH_MONTH1_MASK     (0x0010u)
#define CSL_RTC_RTCMONTH_MONTH1_SHIFT    (0x0004u)
#define CSL_RTC_RTCMONTH_MONTH1_RESETVAL (0x0000u)

#define CSL_RTC_RTCMONTH_MONTH0_MASK     (0x000Fu)
#define CSL_RTC_RTCMONTH_MONTH0_SHIFT    (0x0000u)
#define CSL_RTC_RTCMONTH_MONTH0_RESETVAL (0x0000u)

#define CSL_RTC_RTCMONTH_RESETVAL        (0x0000u)

/* RTCMONTHA */


#define CSL_RTC_RTCMONTHA_MONTHA1_MASK   (0x0010u)
#define CSL_RTC_RTCMONTHA_MONTHA1_SHIFT  (0x0004u)
#define CSL_RTC_RTCMONTHA_MONTHA1_RESETVAL (0x0000u)

#define CSL_RTC_RTCMONTHA_MONTHA0_MASK   (0x000Fu)
#define CSL_RTC_RTCMONTHA_MONTHA0_SHIFT  (0x0000u)
#define CSL_RTC_RTCMONTHA_MONTHA0_RESETVAL (0x0000u)

#define CSL_RTC_RTCMONTHA_RESETVAL       (0x0000u)

/* RTCYEAR */


#define CSL_RTC_RTCYEAR_YEAR1_MASK       (0x00F0u)
#define CSL_RTC_RTCYEAR_YEAR1_SHIFT      (0x0004u)
#define CSL_RTC_RTCYEAR_YEAR1_RESETVAL   (0x0000u)

#define CSL_RTC_RTCYEAR_YEAR0_MASK       (0x000Fu)
#define CSL_RTC_RTCYEAR_YEAR0_SHIFT      (0x0000u)
#define CSL_RTC_RTCYEAR_YEAR0_RESETVAL   (0x0000u)

#define CSL_RTC_RTCYEAR_RESETVAL         (0x0000u)

/* RTCYEARA */


#define CSL_RTC_RTCYEARA_YEARA1_MASK     (0x00F0u)
#define CSL_RTC_RTCYEARA_YEARA1_SHIFT    (0x0004u)
#define CSL_RTC_RTCYEARA_YEARA1_RESETVAL (0x0000u)

#define CSL_RTC_RTCYEARA_YEARA0_MASK     (0x000Fu)
#define CSL_RTC_RTCYEARA_YEARA0_SHIFT    (0x0000u)
#define CSL_RTC_RTCYEARA_YEARA0_RESETVAL (0x0000u)

#define CSL_RTC_RTCYEARA_RESETVAL        (0x0000u)

/* RTCINTFL */

#define CSL_RTC_RTCINTFL_ALARMFL_MASK    (0x8000u)
#define CSL_RTC_RTCINTFL_ALARMFL_SHIFT   (0x000Fu)
#define CSL_RTC_RTCINTFL_ALARMFL_RESETVAL (0x0000u)
/*----ALARMFL Tokens----*/
#define CSL_RTC_RTCINTFL_ALARMFL_CLEAR   (0x0000u)
#define CSL_RTC_RTCINTFL_ALARMFL_SET     (0x0001u)


#define CSL_RTC_RTCINTFL_EXTFL_MASK      (0x0020u)
#define CSL_RTC_RTCINTFL_EXTFL_SHIFT     (0x0005u)
#define CSL_RTC_RTCINTFL_EXTFL_RESETVAL  (0x0000u)
/*----EXTFL Tokens----*/
#define CSL_RTC_RTCINTFL_EXTFL_CLEAR     (0x0000u)
#define CSL_RTC_RTCINTFL_EXTFL_SET       (0x0001u)

#define CSL_RTC_RTCINTFL_DAYFL_MASK      (0x0010u)
#define CSL_RTC_RTCINTFL_DAYFL_SHIFT     (0x0004u)
#define CSL_RTC_RTCINTFL_DAYFL_RESETVAL  (0x0000u)
/*----DAYFL Tokens----*/
#define CSL_RTC_RTCINTFL_DAYFL_CLEAR     (0x0000u)
#define CSL_RTC_RTCINTFL_DAYFL_SET       (0x0001u)

#define CSL_RTC_RTCINTFL_HOURFL_MASK     (0x0008u)
#define CSL_RTC_RTCINTFL_HOURFL_SHIFT    (0x0003u)
#define CSL_RTC_RTCINTFL_HOURFL_RESETVAL (0x0000u)
/*----HOURFL Tokens----*/
#define CSL_RTC_RTCINTFL_HOURFL_CLEAR    (0x0000u)
#define CSL_RTC_RTCINTFL_HOURFL_SET      (0x0001u)

#define CSL_RTC_RTCINTFL_MINFL_MASK      (0x0004u)
#define CSL_RTC_RTCINTFL_MINFL_SHIFT     (0x0002u)
#define CSL_RTC_RTCINTFL_MINFL_RESETVAL  (0x0000u)
/*----MINFL Tokens----*/
#define CSL_RTC_RTCINTFL_MINFL_CLEAR     (0x0000u)
#define CSL_RTC_RTCINTFL_MINFL_SET       (0x0001u)

#define CSL_RTC_RTCINTFL_SECFL_MASK      (0x0002u)
#define CSL_RTC_RTCINTFL_SECFL_SHIFT     (0x0001u)
#define CSL_RTC_RTCINTFL_SECFL_RESETVAL  (0x0000u)
/*----SECFL Tokens----*/
#define CSL_RTC_RTCINTFL_SECFL_CLEAR     (0x0000u)
#define CSL_RTC_RTCINTFL_SECFL_SET       (0x0001u)

#define CSL_RTC_RTCINTFL_MSFL_MASK       (0x0001u)
#define CSL_RTC_RTCINTFL_MSFL_SHIFT      (0x0000u)
#define CSL_RTC_RTCINTFL_MSFL_RESETVAL   (0x0000u)
/*----MSFL Tokens----*/
#define CSL_RTC_RTCINTFL_MSFL_CLEAR      (0x0000u)
#define CSL_RTC_RTCINTFL_MSFL_SET        (0x0001u)

#define CSL_RTC_RTCINTFL_RESETVAL        (0x0000u)

/* RTCNOPWR */


#define CSL_RTC_RTCNOPWR_PWRUP_MASK      (0x0001u)
#define CSL_RTC_RTCNOPWR_PWRUP_SHIFT     (0x0000u)
#define CSL_RTC_RTCNOPWR_PWRUP_RESETVAL  (0x0001u)
/*----PWRUP Tokens----*/
#define CSL_RTC_RTCNOPWR_PWRUP_CLEAR     (0x0000u)
#define CSL_RTC_RTCNOPWR_PWRUP_SET       (0x0001u)

#define CSL_RTC_RTCNOPWR_RESETVAL        (0x0001u)

/* RTCINTREG */

#define CSL_RTC_RTCINTREG_ALARMINTEN_MASK (0x8000u)
#define CSL_RTC_RTCINTREG_ALARMINTEN_SHIFT (0x000Fu)
#define CSL_RTC_RTCINTREG_ALARMINTEN_RESETVAL (0x0000u)
/*----ALARMINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_ALARMINTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_ALARMINTEN_SET (0x0001u)


#define CSL_RTC_RTCINTREG_EXTINTEN_MASK  (0x0020u)
#define CSL_RTC_RTCINTREG_EXTINTEN_SHIFT (0x0005u)
#define CSL_RTC_RTCINTREG_EXTINTEN_RESETVAL (0x0000u)
/*----EXTINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_EXTINTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_EXTINTEN_SET   (0x0001u)

#define CSL_RTC_RTCINTREG_DAYINTEN_MASK  (0x0010u)
#define CSL_RTC_RTCINTREG_DAYINTEN_SHIFT (0x0004u)
#define CSL_RTC_RTCINTREG_DAYINTEN_RESETVAL (0x0000u)
/*----DAYINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_DAYINTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_DAYINTEN_SET   (0x0001u)

#define CSL_RTC_RTCINTREG_HOURINTEN_MASK (0x0008u)
#define CSL_RTC_RTCINTREG_HOURINTEN_SHIFT (0x0003u)
#define CSL_RTC_RTCINTREG_HOURINTEN_RESETVAL (0x0000u)
/*----HOURINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_HOURINTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_HOURINTEN_SET  (0x0001u)

#define CSL_RTC_RTCINTREG_MININTEN_MASK  (0x0004u)
#define CSL_RTC_RTCINTREG_MININTEN_SHIFT (0x0002u)
#define CSL_RTC_RTCINTREG_MININTEN_RESETVAL (0x0000u)
/*----MININTEN Tokens----*/
#define CSL_RTC_RTCINTREG_MININTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_MININTEN_SET   (0x0001u)

#define CSL_RTC_RTCINTREG_SECINTEN_MASK  (0x0002u)
#define CSL_RTC_RTCINTREG_SECINTEN_SHIFT (0x0001u)
#define CSL_RTC_RTCINTREG_SECINTEN_RESETVAL (0x0000u)
/*----SECINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_SECINTEN_CLEAR (0x0000u)
#define CSL_RTC_RTCINTREG_SECINTEN_SET   (0x0001u)

#define CSL_RTC_RTCINTREG_MSINTEN_MASK   (0x0001u)
#define CSL_RTC_RTCINTREG_MSINTEN_SHIFT  (0x0000u)
#define CSL_RTC_RTCINTREG_MSINTEN_RESETVAL (0x0000u)
/*----MSINTEN Tokens----*/
#define CSL_RTC_RTCINTREG_MSINTEN_CLEAR  (0x0000u)
#define CSL_RTC_RTCINTREG_MSINTEN_SET    (0x0001u)

#define CSL_RTC_RTCINTREG_RESETVAL       (0x0000u)

/* RTCDRIFT */

#define CSL_RTC_RTCDRIFT_DRIFT_MASK      (0x8000u)
#define CSL_RTC_RTCDRIFT_DRIFT_SHIFT     (0x000Fu)
#define CSL_RTC_RTCDRIFT_DRIFT_RESETVAL  (0x0000u)
/*----DRIFT Tokens----*/
#define CSL_RTC_RTCDRIFT_DRIFT_NEG       (0x0000u)
#define CSL_RTC_RTCDRIFT_DRIFT_POS       (0x0001u)


#define CSL_RTC_RTCDRIFT_COMP3_MASK      (0x1000u)
#define CSL_RTC_RTCDRIFT_COMP3_SHIFT     (0x000Cu)
#define CSL_RTC_RTCDRIFT_COMP3_RESETVAL  (0x0000u)
/*----COMP3 Tokens----*/
#define CSL_RTC_RTCDRIFT_COMP3_ZERO      (0x0000u)
#define CSL_RTC_RTCDRIFT_COMP3_ONE       (0x0001u)

#define CSL_RTC_RTCDRIFT_COMP2_MASK      (0x0F00u)
#define CSL_RTC_RTCDRIFT_COMP2_SHIFT     (0x0008u)
#define CSL_RTC_RTCDRIFT_COMP2_RESETVAL  (0x0000u)

#define CSL_RTC_RTCDRIFT_COMP1_MASK      (0x00F0u)
#define CSL_RTC_RTCDRIFT_COMP1_SHIFT     (0x0004u)
#define CSL_RTC_RTCDRIFT_COMP1_RESETVAL  (0x0000u)

#define CSL_RTC_RTCDRIFT_COMP0_MASK      (0x000Fu)
#define CSL_RTC_RTCDRIFT_COMP0_SHIFT     (0x0000u)
#define CSL_RTC_RTCDRIFT_COMP0_RESETVAL  (0x0000u)

#define CSL_RTC_RTCDRIFT_RESETVAL        (0x0000u)

/* RTCOSC */

#define CSL_RTC_RTCOSC_RTCRESET_MASK     (0x8000u)
#define CSL_RTC_RTCOSC_RTCRESET_SHIFT    (0x000Fu)
#define CSL_RTC_RTCOSC_RTCRESET_RESETVAL (0x0000u)
/*----RTCRESET Tokens----*/
#define CSL_RTC_RTCOSC_RTCRESET_CLEAR    (0x0000u)
#define CSL_RTC_RTCOSC_RTCRESET_SET      (0x0001u)


#define CSL_RTC_RTCOSC_OSC32KPWD_MASK    (0x0010u)
#define CSL_RTC_RTCOSC_OSC32KPWD_SHIFT   (0x0004u)
#define CSL_RTC_RTCOSC_OSC32KPWD_RESETVAL (0x0000u)
/*----OSC32KPWD Tokens----*/
#define CSL_RTC_RTCOSC_OSC32KPWD_CLEAR   (0x0000u)
#define CSL_RTC_RTCOSC_OSC32KPWD_SET     (0x0001u)

#define CSL_RTC_RTCOSC_OSCRES_MASK       (0x000Fu)
#define CSL_RTC_RTCOSC_OSCRES_SHIFT      (0x0000u)
#define CSL_RTC_RTCOSC_OSCRES_RESETVAL   (0x0008u)

#define CSL_RTC_RTCOSC_RESETVAL          (0x0008u)

/* RTCPMGT */


#define CSL_RTC_RTCPMGT_WU_DOUT_MASK     (0x0010u)
#define CSL_RTC_RTCPMGT_WU_DOUT_SHIFT    (0x0004u)
#define CSL_RTC_RTCPMGT_WU_DOUT_RESETVAL (0x0000u)
/*----WU_DOUT Tokens----*/
#define CSL_RTC_RTCPMGT_WU_DOUT_LOW      (0x0000u)
#define CSL_RTC_RTCPMGT_WU_DOUT_HIGH     (0x0001u)

#define CSL_RTC_RTCPMGT_WU_DIR_MASK      (0x0008u)
#define CSL_RTC_RTCPMGT_WU_DIR_SHIFT     (0x0003u)
#define CSL_RTC_RTCPMGT_WU_DIR_RESETVAL  (0x0000u)
/*----WU_DIR Tokens----*/
#define CSL_RTC_RTCPMGT_WU_DIR_IN        (0x0000u)
#define CSL_RTC_RTCPMGT_WU_DIR_OUT       (0x0001u)

#define CSL_RTC_RTCPMGT_BG_PD_MASK       (0x0004u)
#define CSL_RTC_RTCPMGT_BG_PD_SHIFT      (0x0002u)
#define CSL_RTC_RTCPMGT_BG_PD_RESETVAL   (0x0000u)
/*----BG_PD Tokens----*/
#define CSL_RTC_RTCPMGT_BG_PD_CLEAR      (0x0000u)
#define CSL_RTC_RTCPMGT_BG_PD_SET        (0x0001u)

#define CSL_RTC_RTCPMGT_LDO_PD_MASK      (0x0002u)
#define CSL_RTC_RTCPMGT_LDO_PD_SHIFT     (0x0001u)
#define CSL_RTC_RTCPMGT_LDO_PD_RESETVAL  (0x0000u)
/*----LDO_PD Tokens----*/
#define CSL_RTC_RTCPMGT_LDO_PD_CLEAR     (0x0000u)
#define CSL_RTC_RTCPMGT_LDO_PD_SET       (0x0001u)

#define CSL_RTC_RTCPMGT_RTCCLKOUTEN_MASK (0x0001u)
#define CSL_RTC_RTCPMGT_RTCCLKOUTEN_SHIFT (0x0000u)
#define CSL_RTC_RTCPMGT_RTCCLKOUTEN_RESETVAL (0x0000u)
/*----RTCCLKOUTEN Tokens----*/
#define CSL_RTC_RTCPMGT_RTCCLKOUTEN_DISABLE (0x0000u)
#define CSL_RTC_RTCPMGT_RTCCLKOUTEN_ENABLE (0x0001u)

#define CSL_RTC_RTCPMGT_RESETVAL         (0x0000u)

/* RTCSCR1 */

#define CSL_RTC_RTCSCR1_SCRATCH0_MASK    (0xFFFFu)
#define CSL_RTC_RTCSCR1_SCRATCH0_SHIFT   (0x0000u)
#define CSL_RTC_RTCSCR1_SCRATCH0_RESETVAL (0x0000u)

#define CSL_RTC_RTCSCR1_RESETVAL         (0x0000u)

/* RTCSCR2 */

#define CSL_RTC_RTCSCR2_SCRATCH2_MASK    (0xFFFFu)
#define CSL_RTC_RTCSCR2_SCRATCH2_SHIFT   (0x0000u)
#define CSL_RTC_RTCSCR2_SCRATCH2_RESETVAL (0x0000u)

#define CSL_RTC_RTCSCR2_RESETVAL         (0x0000u)

/* RTCSCR3 */

#define CSL_RTC_RTCSCR3_SCRATCH3_MASK    (0xFFFFu)
#define CSL_RTC_RTCSCR3_SCRATCH3_SHIFT   (0x0000u)
#define CSL_RTC_RTCSCR3_SCRATCH3_RESETVAL (0x0000u)

#define CSL_RTC_RTCSCR3_RESETVAL         (0x0000u)

/* RTCSCR4 */

#define CSL_RTC_RTCSCR4_SCRATCH4_MASK    (0xFFFFu)
#define CSL_RTC_RTCSCR4_SCRATCH4_SHIFT   (0x0000u)
#define CSL_RTC_RTCSCR4_SCRATCH4_RESETVAL (0x0000u)

#define CSL_RTC_RTCSCR4_RESETVAL         (0x0000u)

#endif

