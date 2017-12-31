/*
 * Java interface for led wiringOP */

 public class SevenSegController{

    public native void init7Seg();
    public native void show(int digit);
    public native void showWithDp(int digit);

    public SevenSegController(){
        //load the led c module
        //led_ctr_c = new LedCtrInC(this.gpio_addr);
        String f_route = "/home/dary/Git-Repositorio/orange-pi-zero/"+
                          "gpio_control/show_ip/java/show_ip_by_7seg/";
        System.load(f_route+"SevenSegController.so");
        //set the gpio to output
        init7Seg();
    }

    public void showDigit(int digit){
        show(digit);
    }

    public void showDigitWithDp(int digit){
        showWithDp(digit);
    }

    public void clear(){
        init7Seg();
    }
 }
