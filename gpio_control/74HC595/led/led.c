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
  #include "unistd.h"
  
  void main()
  {
      hc595_handle_t handle; 
      DrvHc595Init(&handle);
      while(1){
      	DrvHc595Write(&handle, 0x40);
      	sleep(1);
      	DrvHc595Write(&handle, 0x00);
      	sleep(1);
      }
      
  }