/***********************************
 * Seengreat Relay HAT demo
 * cat9555 --> Raspberry Pi
 *      VCC  -->  3.3V
 *      GND  -->  GND
 *      DRV  -->  P25(wiringPi number)
 * Author(s):Andy Li from Seengreat
 * ********************************/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define  PIN_DRV  25  


int main(void)
{
    wiringPiSetup(); //init wiringpi lib
    pinMode(PIN_DRV,OUTPUT);
    while(1)
    {
        delay(1000);
        digitalWrite(PIN_DRV,0); //Relay NO state
        delay(1000);
        digitalWrite(PIN_DRV,1);//Relay NC state
    }
    
}
