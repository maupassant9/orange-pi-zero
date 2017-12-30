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
 
 
/********************************************
 * Macro
 ********************************************/
 #define WAIT_TIME 0x1000000
 
 #define OE_PIN 1
 #define SER_PIN 0
 #define SRCLK_PIN 5
 #define SRCLR_PIN 6
 #define RCLK_PIN 4
 
 //Define the default value of 74HC545 output
 #define HIGH_VOLT 1
 #define LOW_VOLT 0
 #define DEFAULT_VALUE LOW_VOLT
 
 
 //74HC545 handle
 typedef struct {
     //The list of pin_number, in order:
     //*           GPIO_SER
     //*           GPIO_SRCLK
     //*           GPIO_RCLK
     //*           GPIO_SRCLR
     //*           GPIO_OE
     unsigned short pins_number[5];
     
     //Function pointers
     
     
 } hc595_handle_t;

 hc595_handle_t handle;


void DrvHc595Init(hc595_handle_t *handle);
void DrvHc595Write(hc595_handle_t * handle,unsigned char val);


