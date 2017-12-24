import java.net.NetworkInterface;
import java.net.*;
import java.lang.String;
import java.util.*;
import java.net.SocketException;
import LedController

public class ShowIpByLed {

  private int led_addr;
  private LedController led_ctr;

  public ShowIpByLed(int led_addr)
  {
    this.led_addr = led_addr;
    led_ctr = new LedController(led_addr);
    led_ctr.setAsOutput(led_addr);
  }

  public ShowIpByLed()
  {
    led_addr = 30;
    led_ctr = new LedController(30);
    led_ctr.setAsOutput(30);
  }

  public void show()
  {
    //get the ip addr
    ArrayList<Integer> ips = getIps();

    //show the led
    for (Integer addr: ips){
      ledShowNum(addr);
      Thread.sleep(2000);
    }

  }

  private void ledShowNum(int num){
    for(int i = 0; i < num; i++){
      led_ctr.high();
      Thread.sleep(500);
      led_str.low();
      Thread.sleep(500);
    }
  }

  /*
   *A private function to get ip list*/
  private static ArrayList<Integer> getIps() throws SocketException {
    //a container for ips retrieved
    ArrayList<Integer> ips = new ArrayList<>();
    
    String interfaceName = "eth0", ip;
    //get eth0 ip
    NetworkInterface networkInterface = NetworkInterface.getByName(interfaceName);
    Enumeration<InetAddress> inetAddress = networkInterface.getInetAddresses();
    InetAddress currentAddress;

    while(inetAddress.hasMoreElements())
    {
        currentAddress = inetAddress.nextElement();
        //if it is ipv4, get the ip
        if(currentAddress instanceof Inet4Address && !currentAddress.isLoopbackAddress())
        {
            ip = currentAddress.toString();
            ip = ip.substring(ip.lastIndexOf('.')+1);
            ips.add(Integer.parse(ip));
            break;
        }
        //currentAddress = inetAddress.nextElement();
    }
    return ips;
  }



}
    
