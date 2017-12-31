import java.net.NetworkInterface;
import java.net.*;
import java.lang.String;
import java.util.*;
import java.net.SocketException;
//import LedController;

public class ShowIpBy7Seg {

  //private int led_addr;
  //private LedController led_ctr;

  // public ShowIpBy7Seg(int led_addr)
  // {
  //   //this.led_addr = led_addr;
  //   //led_ctr = new LedController(led_addr);
  //   //led_ctr.setAsOutput();
  // }

  public ShowIpBy7Seg()
  {
    //led_addr = 30;
    //led_ctr = new LedController(30);
    //led_ctr.setAsOutput();
  }

  public void show() throws SocketException, InterruptedException
  {
    //get the ip addr
    ArrayList<String> ips = getIps();

    //show the led
    for (String ip: ips){
      System.out.println("IP:"+ip);
      7segShowIp(ip);
      Thread.sleep(3000);
    }
  }


  private void 7segShowIp(String ip) throws InterruptedException{
    String[] addrs = ip.split('.');
    
    for (String addr: addrs){
      7segShowNum(Integer.parse(addr));
    }
  }

  private 7segShowNum(int num)
  {
    int n1 = num % 10;
    int n2 = (num / 10) % 10;
    int n3 = (num / 100);

    7segShowDigit(n1);
    7segShowDigit(n2);
    7segShowDigit(n3);
  }

  
  /*
   *A private function to get ip list*/
  private static ArrayList<String> getIps() throws SocketException {
    //a container for ips retrieved
    ArrayList<String> ips = new ArrayList<>();
    
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
            //ip = ip.substring(ip.lastIndexOf('.')+1);
            ips.add(ip);
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
              //ip = ip.substring(ip.lastIndexOf('.')+1);
              ips.add(ip);
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
    ShowIpBy7Seg displayer = new ShowIpBy7Seg();
    //System.load("/home/dary/Git-Repositorio/orange-pi-zero/gpio_control/show_ip/java/show_ip_by_led/LedController.so");
    displayer.show();
    //displayer.ledShowNum(25);
    //displayer.test();
  }

}
    
