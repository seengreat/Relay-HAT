#include <stdio.h>
#include <unistd.h>
#include "sg_lgpio.h"

/****************************
Relay    Raspberry Pi
      VCC   --->   3.3V
      GND   --->   GND
      DRV   --->   D26
*****************************/
//define pin conection in BCM number
#define PIN_DRV     26

int	main(void)
{
    Lgpio_export(); 
    Lgpio_set_pinmode(PIN_DRV,LGPIO_OUTPUT);
	while(1)
	{
		Lgpio_write_pin(PIN_DRV,LGPIO_HIGH);
		delay(1000); //1s			
		Lgpio_write_pin(PIN_DRV,LGPIO_LOW);
		delay(1000); //1s	

	}
}	


