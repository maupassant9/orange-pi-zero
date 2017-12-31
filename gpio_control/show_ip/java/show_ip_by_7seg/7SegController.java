/*
 * Java interface for led wiringOP */

 public class 7SegController{

    public native void init7Seg();
    public native void show(int digit);
    public native void showWithDp(int digit);

    public 7SegController(){
        //load the led c module
        //led_ctr_c = new LedCtrInC(this.gpio_addr);
        System.load("/home/dary/Git-Repositorio/orange-pi-zero/gpio_control/show_ip/java/show_ip_by_led/7SegController.so");
        //set the gpio to output
    }

    public void showDigit(int digit){
        show(digit);
    }

    public void init(){
        init7Seg();
    }

    public void showDigitWithDp(int digit){
        showWithDp(digit);
    }
 }