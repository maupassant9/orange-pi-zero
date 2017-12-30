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
 
 #define OE_PIN
 #define SER_PIN
 #define SRCLK_PIN
 #define SRCLR_PIN
 #define RCLK_PIN
 
 //Define the default value of 74HC545 output
 #define HIGH 1
 #define LOW 0
 #define DEFAULT_VALUE HIGH
 
 
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