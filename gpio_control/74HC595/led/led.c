/*
 * FileName: led.c
 * Author: Dong Xia
 * This is source file of the driver of 74HC595
 *
 * Change Records:
 *      >> (30/Dec/2017): Creation of file
 *
 */
 
 /********************************************
  * Include
  ********************************************/
  #include "../74HC595.h"
  
  
  void main()
  {
      hc595_handle_t handle; 
      DrvHc595Init(&handle);
      DrvHc595Write(&handle, 0xff);
  }