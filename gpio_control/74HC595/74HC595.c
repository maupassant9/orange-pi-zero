/*
 * FileName: 74HC595
 * Author: Dong Xia
 * This is source file of the driver of 74HC595
 *
 * Change Records:
 *      >> (29/Dec/2017): Creation of file
 *
 */
 
 /********************************************
  * Include
  ********************************************/
  #include <wiringPi.h>
  
  
  /*------------------------------------------------
   * Drv595Init();
   * Initialize the 74HC595 Device.
   * Paras:
   *  >> 
   * Return:
   *  >> 
   * Change Records:
   *  >> (29/Dec/2017): Create the function
   *----------------------------------------------*/
   void Drv595Init(void)
   {
       //Set the 74HC595 into default mode
       
   }
   
   
    /*------------------------------------------------
    * Hc595GpiosWriteAll();
    * Write to all the GPIOs
    * Paras:
    *  >> unsigned char: Set all the gpios state
    *           Bit0: GPIO_SER
    *           Bit1: GPIO_SRCLK
    *           Bit2: GPIO_RCLK
    *           Bit3: GPIO_SRCLR
    *           Bit4: GPIO_OE
    * Return:
    *  >> 
    * Change Records:
    *  >> (29/Dec/2017): Create the function
    *----------------------------------------------*/
    static void Hc595GpiosWriteAll(hc595_handle_t * handle, unsigned char val)
    {
        unsigned char cnt = 0;
        for(;cnt < 5; cnt++){
            GpioWrite(handle->pins_number[cnt], val&0x01);
            val = val >> 1;
        }
        //wait for one freq
        Hc595Wait(WAIT_TIME);
    }
   
   
   /*------------------------------------------------
   * Hc595GpioWrite();
   * Write to one GPIO
   * Paras:
   *  >> unsigned char: the pin number that write to;
   *  >> unsigned char: a valor write to gpio
   * Return:
   *  >> 
   * Change Records:
   *  >> (29/Dec/2017): Create the function
   *----------------------------------------------*/
   static void Hc595GpioWrite(unsigned char pin_number,
                            unsigned char val)
   {
       
   }
   
   
    /*------------------------------------------------
    * DrvHc595Write();
    * Reset Hc595, write to the default value
    * Paras:
    *  >> unsigned char: a valor write to gpio
    
    * Return:
    *  >> 
    * Change Records:
    *  >> (29/Dec/2017): Create the function
    *----------------------------------------------*/
    static void DrvHc595Write(hc595_handle_t * handle,
                             unsigned char val)
    {
        Hc595GpiosWriteAll(handle,0x08);
        Hc595GpiosWriteAll(handle,0x28);
        Hc595GpiosWriteAll(handle,0x09);
        Hc595GpiosWriteAll(handle,0x29);
        Hc595GpioWriteAll(handle,)
        
    }   