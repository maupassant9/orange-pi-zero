/*
 * Java interface for led wiringOP */

 public class LedController{

    private int gpio_addr;

    public native void setHigh(int gpio_addr);
    public native void setLow(int gpio_addr);
    public native void cfgOutput(int gpio_addr);

    public LedController(int gpio_addr){
        this.gpio_addr = gpio_addr;
        //load the led c module
        System.loadLibrary("LedController.so");
        //led_ctr_c = new LedCtrInC(this.gpio_addr);

        //set the gpio to output
    }

    public void high(){
        setHigh(gpio_addr);
    }

    public void low(){
        setLow(gpio_addr);
    }

    public void setAsOutput(){
        cfgOutput(gpio_addr);
    }
 }