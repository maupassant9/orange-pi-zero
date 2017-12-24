#include <stdio.h>
#include <wiringPi.h>

#define LED_PIN 30

int main()
{
	printf("LED BLINK Example.\n");

	wiringPiSetup();
	pinMode(LED_PIN, OUTPUT);

	for(;;)
	{
		digitalWrite(LED_PIN,HIGH);
		delay(500);
		digitalWrite(LED_PIN,LOW);
		delay(500);
	}

	return(0);
}
