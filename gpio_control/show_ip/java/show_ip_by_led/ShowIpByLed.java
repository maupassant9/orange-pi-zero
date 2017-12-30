import java.net.NetworkInterface;
import java.net.*;
import java.lang.String;
import java.util.*;
import java.net.SocketException;
//import LedController;

public class ShowIpByLed {

  private int led_addr;
  private LedController led_ctr;

  public ShowIpByLed(int led_addr)
  {
    this.led_addr = led_addr;
    led_ctr = new LedController(led_addr);
    led_ctr.setAsOutput();
  }

  public ShowIpByLed()
  {
    led_addr = 30;
    led_ctr = new LedController(30);
    led_ctr.setAsOutput();
  }

  public void show() throws SocketException, InterruptedException
  {
    //get the ip addr
    ArrayList<Integer> ips = getIps();

    //show the led
    for (Integer addr: ips){
      System.out.println("IP:"+addr);
      ledShowNum(addr);
      Thread.sleep(2000);
    }
  }


  private void ledShowNum(int num) throws InterruptedException{
    for(int i = 0; i < num; i++){
      led_ctr.high();
      Thread.sleep(500);
      led_ctr.low();
      Thread.sleep(500);
    }
  }

  private void test() throws InterruptedException{
    led_ctr.high();
  }

  /*
   *A private function to get ip list*/
  private static ArrayList<Integer> getIps() throws SocketException {
    //a container for ips retrieved
    ArrayList<Integer> ips = new ArrayList<>();
    
    String interfaceName = "eth0", ip;
    //get eth0 ip
    NetworkInterface networkInterface = NetworkInterface.getByName(interfaceName);
    Enumeration<InetAddress> inetAddress;
    InetAddress currentAddress;

    try {
      inetAddress = networkInterface.getInetAddresses();
      while(inetAddress.hasMoreElements())
      {
        currentAddress = inetAddress.nextElement();
        //if it is ipv4, get the ip
        if(currentAddress instanceof Inet4Address && !currentAddress.isLoopbackAddress())
        {
            ip = currentAddress.toString();
            ip = ip.substring(ip.lastIndexOf('.')+1);
            ips.add(Integer.parseInt(ip));
            break;
        }
        //currentAddress = inetAddress.nextElement();
      }
    }catch (NullPointerException e){
      //do nothing
    }
    

    //get wlan0 ip
    interfaceName = "wlan0";
    networkInterface = NetworkInterface.getByName(interfaceName);
    try {
      inetAddress = networkInterface.getInetAddresses();
      while(inetAddress.hasMoreElements())
      {
          currentAddress = inetAddress.nextElement();
          //if it is ipv4, get the ip
          if(currentAddress instanceof Inet4Address && !currentAddress.isLoopbackAddress())
          {
              ip = currentAddress.toString();
              ip = ip.substring(ip.lastIndexOf('.')+1);
              ips.add(Integer.parseInt(ip));
              break;
          }
          //currentAddress = inetAddress.nextElement();
      }
    }catch(NullPointerException e)
    {
      //do nothning here
    }
    return ips;
  }


  //main function
  public static void main(String args[]) throws SocketException, InterruptedException{
    ShowIpByLed displayer = new ShowIpByLed();
    //System.load("/home/dary/Git-Repositorio/orange-pi-zero/gpio_control/show_ip/java/show_ip_by_led/LedController.so");
    displayer.show();
    //displayer.ledShowNum(25);
    //displayer.test();
  }

}
    
