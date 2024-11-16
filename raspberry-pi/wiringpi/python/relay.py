# Seengreat Relay HAT demo
# Relay HAT --> Raspberry Pi
#      VCC --> 3.3V
#      GND --> GND
#      DRV --> P25(wiringPi number)
# Author(s):Andy Li from Seengreat

import time
import wiringpi as wpi

PIN_DRV = 25  # GPIO.25 in wiringPi encode

              
wpi.wiringPiSetup()
wpi.pinMode(PIN_DRV,wpi.OUTPUT)        
while True:
    wpi.digitalWrite(PIN_DRV,wpi.LOW) # Relay NO state
    time.sleep(1)
    wpi.digitalWrite(PIN_DRV,wpi.HIGH) # Relay NC state
    time.sleep(1)        