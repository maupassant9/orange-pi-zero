/*
 * FileName: 7seg.c
 * Author: Dong Xia
 * This is source file of the driver of 7seg using 
 * 74HC595.
 * The connection between 74HC595 and 7seg:
 * A(P10) - QB
 * B(P9) - QC
 * C(P7) - QD
 * D(P5) - QE
 * E(P4) - QF
 * F(P2) - QG
 * G(P1) - QH
 * DP(P6) - QA
 * Change Records:
 *      >> (30/Dec/2017): Creation of file
 *      >> (30/Dec/2017): Finished the driver
 *
 */
 
 /********************************************
  * Include
  ********************************************/
#include "../74HC595.h"

 /********************************************
  * Internal Function Declaration
  ********************************************/


 /********************************************
  * Internal Types and Variables
  ********************************************/

 /********************************************
  * External Variables
  ********************************************/
extern const unsigned char codes_number[11];

 /********************************************
  * Functions
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
   void Drv7SegInit(hc595_handle_t *handle){
       DrvHc595Init(handle);
   }

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
   void Drv7SegDisp(hc595_handle_t *handle, unsigned char num){
       DrvHc595Write(handle, codes_number[num]);
   }

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
   void Drv7SegDispWithDp(hc595_handle_t *handle, unsigned char num){
       DrvHc595Write(handle, codes_number[num]&codes_number[10]);
   }
