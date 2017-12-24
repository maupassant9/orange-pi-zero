This is an example project of using JNI and WiringOP to control GPIO.
The program will read the last ipv4 address number and show the number by GPIO pin
that connects with a LED.

(*) The command used to compile java program
javac ShowIpByLed.java
(*) The command used to run java program
 sudo java -Djava.library.path=/home/dary/Git-Repositorio/orange-pi-zero/gpio_control/show_ip/java/show_ip_by_led/ ShowIpByLed
(*) The command used to compile the c program library
 gcc -shared -I /usr/lib/jvm/java-8-openjdk-armhf/include -I /usr/lib/jvm/java-8-openjdk-armhf/include/linux/ -o ./LedController.so LedController.c -lwiringPi -pthread

