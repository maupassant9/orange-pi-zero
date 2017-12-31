/*
 * FileName: 74HC595
 * Author: Dong Xia
 * This is source file of the driver of 74HC595
 *
 * Change Records:
 *      >> (29/Dec/2017): Creation of file
 *      >> (30/Dec/2017): Finished the driver
 *
 */
 
 /********************************************
  * Include
  ********************************************/
  #include <wiringPi.h>
  #include <unistd.h>
  #include "74HC595.h"
  

 /********************************************
  * Internal Function Declaration
  ********************************************/
  static void Hc595GpioWrite(unsigned char pin_number, unsigned char val);
  static void Hc595GpiosWriteAll(hc595_handle_t * handle, unsigned char val);
  static  void Hc595Wait(unsigned char mini_seg);

 /********************************************
  * Internal Types and Variables
  ********************************************/

 /********************************************
  * External Variables
  ********************************************/


 /********************************************
  * Functions
  ********************************************/
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
   void DrvHc595Init(hc595_handle_t *handle)
   {
       unsigned char cnt, ser = DEFAULT_VALUE;

        handle->pins_number[0] = SER_PIN;
        handle->pins_number[1] = SRCLK_PIN;
        handle->pins_number[2] = RCLK_PIN;
        handle->pins_number[3] = SRCLR_PIN;
        handle->pins_number[4] = OE_PIN;

        wiringPiSetup();
        for(cnt = 0; cnt < 5; cnt++){
            pinMode(handle->pins_number[cnt],OUTPUT);
        }
       //Reset the 74HC595 into default mode
        Hc595GpiosWriteAll(handle,0x18|ser);
        Hc595GpiosWriteAll(handle,0x18|ser);
        Hc595GpiosWriteAll(handle,0x10|ser);
        Hc595GpiosWriteAll(handle,0x0c|ser);
        #if DEFAULT_VALUE == HIGH_VOLT
        DrvHc595Write(handle,0xff);
        #endif
   }
   
    /*------------------------------------------------
    * Hc595GpiosWriteAll();
    * Write one bit to all the GPIOs
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
            Hc595GpioWrite(handle->pins_number[cnt], val&0x01);
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
       if(val == 1){
           digitalWrite(pin_number, HIGH);
       } else {
           digitalWrite(pin_number,LOW);
       }
   }
   
   
    /*------------------------------------------------
    * DrvHc595Write();
    * Write serial data (8 bits) to Hc595.
    *           Bit0: GPIO_SER
    *           Bit1: GPIO_SRCLK
    *           Bit2: GPIO_RCLK
    *           Bit3: GPIO_SRCLR
    *           Bit4: GPIO_OE
    * Check the waveform in /waveform/write.png
    * Paras:
    *  >> hc595_handle_t: a handle for 74HC595 dev
    *  >> unsigned char: a valor write to gpio
    * Return:
    *  >> 
    * Change Records:
    *  >> (29/Dec/2017): Create the function
    *----------------------------------------------*/
    void DrvHc595Write(hc595_handle_t * handle,
                             unsigned char val)
    {
        unsigned char ser, cnt;
        for(cnt = 0; cnt < 8; cnt++){
            ser = val&0x01;
            Hc595GpiosWriteAll(handle,0x08|ser);
            Hc595GpiosWriteAll(handle,0x0a|ser);
            val = val >> 1;
        }
        Hc595GpiosWriteAll(handle,0x0c);
        Hc595GpiosWriteAll(handle,0x08);        
    }   

    /*------------------------------------------------
     * Hc595Wait();
     * Wait for a while
     * Check the waveform in /waveform/write.png
     * Paras:
     *  >> unsigned char: the miniseconds that needs to
     *  wait
     * Return:
     *  >> 
     * Change Records:
     *  >> (30/Dec/2017): Create the function
     *----------------------------------------------*/
     static  void Hc595Wait(unsigned char mini_seg)
     {
     	usleep((long)mini_seg*1000);
     }