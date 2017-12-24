///package organgepi;

import java.lang.String;
import java.util.*;
import com.pi4j.io.gpio.*;
import com.pi4j.io.gpio.event.GpioPinDigitalStateChangeEvent;
import com.pi4j.io.gpio.event.GpioPinListenerDigital;
import com.pi4j.platform.Platform;
import com.pi4j.platform.PlatformAlreadyAssignedException;
import com.pi4j.platform.PlatformManager;
import com.pi4j.util.CommandArgumentParser;
import com.pi4j.util.Console;
import com.pi4j.util.ConsoleColor;

/**
 * Simple Java program to find IP Address of localhost. This program uses
 * InetAddress from java.net package to find IP address. 
 *
 * @author Javin Paul
 */

 
public class PinPrint {
    public static void main(String args[]) throws PlatformAlreadyAssignedException {

    	PlatformManager.setPlatform(Platform.ORANGEPI);
		final GpioController gpio = GpioFactory.getInstance();
		
		for (Pin pin:OrangePiPin.allPins())
		{
			System.out.println(pin.getName()+":"+pin.getAddress());
		}
    }

}


