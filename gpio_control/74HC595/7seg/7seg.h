/*
* FileName: 7seg.h
* Author: Dong Xia
* This is source file of the driver of 7seg.h 
* using 74HC595.
* The connection between 74HC595 and 7seg:
* A(P10) - QB
* B(P9) - QC
* C(P7) - QD
* D(P5) - QE
* E(P4) - QF
* F(P2) - QG
* G(P1) - QH
* DP(P6) - QA
*
* Change Records:
*      >> (30/Dec/2017): Creation of file
*
*/

#ifndef _7SEG_H
#define _7SEG_H
/********************************************
 * Include
 ********************************************/
 #include "../74HC595.h"
 
/********************************************
 * Macro
 ********************************************/


/********************************************
 * External Variables
 ********************************************/
//The code of numbers to write to 74HC595
// codes_number[0] = number '0' code
// codes_number[1] = number '1' code
// .....
// codes_number[9] = number '9' code
// codes_number[10] = '.' code
const unsigned char codes_number[11] = {
    0x81, //'0': B,C,D,E,F,G = 0; 10000001b
    0xcf, //'1': C,D = 0; 11001111b
    0x92, //'2': B,C,E,F,H = 0; 10010010b
    0x86, //'3': B,C,D,E,H = 0; 10000110b
    0xcc, //'4': C,D,G,H = 0; 11001100b
    0xa4, //'5': B,D,E,G,H = 0; 10100100b
    0xa0, //'6': B,D,E,F,G,H = 0; 10100000b
    0x8f, //'7': B,C,D = 0; 10001111b
    0x80, //'8': B,C,D,E,F,G,H = 0; 10000000b
    0x84, //'9': B,C,D,E,G,H = 0; 10000100b
    0x7f //'.': 01111111b
};

/********************************************
 * Type definition
 ********************************************/


/********************************************
 * Function prototype
 ********************************************/
  /*------------------------------------------------
   * Drv7SegInit();
   * Initialize the 7Seg Device.
   * This function just call the init function 
   * of 74HC595.
   * Paras:
   *  >> hc595_handle_t*: a handle pointer to 74Hc595
   * Return:
   *  >> 
   * Change Records:
   *  >> (30/Dec/2017): Create the function
   *----------------------------------------------*/
   void Drv7SegInit(hc595_handle_t *handle);

  /*------------------------------------------------
   * Drv7SegDisp();
   * Display the number 
   * Paras:
   *  >> hc595_handle_t*: a handle pointer to 74Hc595
   *  >> unsigned char: the number to display, should be
   *     between 0-9.
   * Return:
   *  >> 
   * Change Records:
   *  >> (30/Dec/2017): Create the function
   *----------------------------------------------*/
   void Drv7SegDisp(hc595_handle_t *handle, unsigned char num);

  /*------------------------------------------------
   * Drv7SegDispWithDp();
   * Display the number 
   * Paras:
   *  >> hc595_handle_t*: a handle pointer to 74Hc595
   *  >> unsigned char: the number to display, should be
   *     between 0-9, and this function will also display
   *     the point.
   * Return:
   *  >> 
   * Change Records:
   *  >> (30/Dec/2017): Create the function
   *----------------------------------------------*/
   void Drv7SegDispWithDp(hc595_handle_t *handle, unsigned char num);


#endif
