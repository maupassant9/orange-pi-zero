import java.net.NetworkInterface;
import java.net.*;
import java.lang.String;
import java.util.*;
import java.net.SocketException;


public class ShowIp {

  public static void main(String args[]) throws SocketException {
    String interfaceName = "eth0", ip;
    NetworkInterface networkInterface = NetworkInterface.getByName(interfaceName);
    Enumeration<InetAddress> inetAddress = networkInterface.getInetAddresses();
    InetAddress currentAddress;

    currentAddress = inetAddress.nextElement();
    while(inetAddress.hasMoreElements())
    {
        currentAddress = inetAddress.nextElement();
        if(currentAddress instanceof Inet4Address && !currentAddress.isLoopbackAddress())
        {
            ip = currentAddress.toString();
            System.out.println(ip);
            ip = ip.substring(ip.lastIndexOf('.')+1);
            System.out.println(ip);
            break;
        }
        currentAddress = inetAddress.nextElement();
    }
  }
}
    
