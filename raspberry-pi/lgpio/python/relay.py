import time
from gpiozero import *

'''define pin conection in BCM number
Relay HAT    Raspberry Pi
      VCC   --->   3.3V
      GND   --->   GND
      DRV   --->   D26
'''
PIN_DRV     = 26

if __name__ == '__main__':
    DRV = DigitalOutputDevice(PIN_DRV,active_high = True,initial_value =False)#
    while True:
        DRV.on() # NC state
        time.sleep(1)
        DRV.off() # NO state
        time.sleep(1)
            
            
            
            
            