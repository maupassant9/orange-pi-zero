/*
 * FileName: main.c
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
#include <unistd.h>
#include "../74HC595.h"
#include "7seg.h"

 /********************************************
  * Internal Function Declaration
  ********************************************/


 /********************************************
  * Internal Types and Variables
  ********************************************/

 /********************************************
  * External Variables
  ********************************************/


 /********************************************
  * Functions
  ********************************************/
  void main(void)
  {
      int i = 0;
      hc595_handle_t handle;

      Drv7SegInit(&handle);
      while(1){
          Drv7SegDisp(i);
          i = (++i)%10;
          sleep(2);
      }
  }