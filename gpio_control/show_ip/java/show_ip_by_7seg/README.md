This is an example project using JNI and WiringOP to control GPIO.
The program will read the last ipv4 address number and show the number by GPIO pin
that connects with a LED.

(*) The command used to compile java program
javac SevenSegController.java
javac ShowIpBy7Seg.java
(*) The command used to run java program
 sudo java ShowIpBy7Seg
 or simply:
 sudo java ShowIpByLed
(*) The command used to compile the c program library
gcc -shared -I /usr/lib/jvm/java-8-openjdk-armhf/include -I /usr/lib/jvm/java-8-openjdk-armhf/include/linux/ -o SevenSegController.so SevenSegController.c ../../../74HC595/74HC595.c ../../../74HC595/7seg/7seg.c -lwiringPi -pthread -fPIC

