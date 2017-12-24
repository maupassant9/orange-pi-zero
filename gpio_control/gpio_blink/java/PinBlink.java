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

 
public class PinBlink {
    public static void main(String args[]) throws PlatformAlreadyAssignedException, InterruptedException {

    	PlatformManager.setPlatform(Platform.ORANGEPI);
		final GpioController gpio = GpioFactory.getInstance();

		final GpioPinDigitalOutput led = gpio.provisionDigitalOutputPin(OrangePiZeroPin.GPIO_30);
		led.setShutdownOptions(false,PinState.HIGH);

		led.blink(1000);
		while(true){
			Thread.sleep(500);
		}

    }

}
