Relay HAT from seengreat:www.seengreat.com
 =======================================
# Description
![image](https://github.com/seengreat/Relay-HAT/blob/main/01.png)<br> 

Figure 1-1 Main Product Image<br> 
## 1.1 Product Overview
This product is a single-channel relay Raspberry Pi expansion board, compatible with Raspberry Pi Zero/Zero W/Zero WH/2B/3B/3B+/4B, STM32, ESP32, Arduino, and more. It features onboard optocoupler isolation and level-shifting circuits, making it compatible with 3.3V and 5V systems.<br> 
## 1.2 Product Features
Power Supply Voltage: 3.3V/5V<br> 
Relay Load Capacity: NO: 10A 250VAC/28VDC; NO/NC 5A 250VAC<br> 
Relay Operation Indicator LED: Allows easy monitoring of relay status<br> 
Optocoupler Isolation Circuit: Strong anti-interference capability, stable operation<br> 
Open-source Example Programs: Provided for Raspberry Pi and Arduino development boards<br> 
## 1.3 Product Specifications
|Dimensions	|45mm (Length) * 28mm (Width)|
|----------------------|-----------------------------------|
|Weight	|100g (Net Weight: 21g)|
|Power Supply Voltage	|3.3V/5V|
|Optocoupler	|LTV-357T-B-IN|
|Trigger Level	|Low-level Trigger|

![image](https://github.com/seengreat/Relay-HAT/blob/main/02.png)<br> 

Figure 1-2 Relay HAT Dimensions Diagram<br> 
# Usage
The relay control pin DRV is triggered by a low level. When the VCC supply voltage is 3.3V and the DRV pin's logic level is 0V and 3.3V, the VIO switch can be set to the VCC or 3V3 position. If the VCC supply voltage is 5V and the DRV pin's logic level is 0V and 3.3V, the VIO switch should also be set to the 3V3 position. However, if the logic level is 0V and 5V, the VIO switch should be set to the VCC position. The corresponding states of the switch for different VCC and DRV pin drive voltages are shown in Table 2-1 below:<br> 
|VCC Voltage	|DRV Signal Level	|VIO Switch Position|
|----------------------|-----------------------|---------------------|
|3.3V	|0～3.3V	|VCC/3V3|
|5V	|0～5V	|VCC|
|5V	|0～3.3V	|3V3|

## 2.1 Module Resources Overview
The resource overview is shown in the diagram below:<br> 

![image](https://github.com/seengreat/Relay-HAT/blob/main/03.png)<br> 

Relay HAT Resource Overview Diagram<br> 
1. Power Indicator LED<br> 
2. Relay<br> 
3. Relay Output Terminals<br> 
4. Relay Working Indicator LED: The LED is on when the relay's normally open (NO) terminal is closed and the normally closed (NC) terminal is open. The LED is off when the NO terminal is open and the NC terminal is closed.<br> 
5. Relay Control Signal Level Selection Switch: Can be set to VCC or 3V3<br> 
6. PH2.0 1x3P Connector<br> 
7. 2.54mm 1x3P Pin Header<br> 


Relay Wiring Diagram is as follows:<br> 
![image](https://github.com/seengreat/Relay-HAT/blob/main/04.png)<br>
 
Relay Wiring Diagram<br> 

## 2.2 Raspberry Pi Platform Example Program Usage
The example code is available in two versions: one for the WiringPi library and one for the Lgpio library. The Bullseye system uses the WiringPi library, while the Bookworm system uses the Lgpio library.<br>
### 2.2.1 Wiring Definition
In the Raspberry Pi mainboard, the example program for the Bookworm system uses BCM numbering for pin definitions, while the Bullseye system uses WiringPi numbering. The pin wiring definitions for the Raspberry Pi mainboard are as shown in the table below:<br>
|Expansion Board Interface	|Pin Function	|BCM numbering	|WiringPi numbering|
|----------------------------------|----------------------|----------------------|----------------------|
|VCC	|3.3V	|3.3V	|3.3V|
|GND	|GND	|GND	|GND|
|DRV	|Relay Trigger Pin	|26	|P25|
<br>
Table 2-2 Relay HAT and Raspberry Pi Interface Definitions<br>
### 2.2.2  wiringpi Library Installation
```sudo apt-get install wiringpi```<br>

```wget https://project-downloads.drogon.net/wiringpi-latest.deb ```#<br>
Upgrade Raspberry Pi 4B Version<br>
```sudo dpkg -i wiringpi-latest.deb```<br>
```gpio -v ```<br>
If version 2.52 appears, it indicates that the installation has been successful.<br>
For the Bullseye branch system, use the following command:<br>
```git clone https://github.com/WiringPi/WiringPi```<br>
```cd WiringPi```<br>
```. /build``` <br>
```gpio -v ```#<br>
Running "gpio -v" will show version 2.70. If it doesn't appear, it means there is an installation error.<br>
If an error message "ImportError: No module named 'wiringpi'" appears when running a sample program in Python version, run the following command:<br>
For Python 2.x version<br>
```pip install wiringpi```<br>
For Python 3.x version<br>
```pip3 install wiringpi```<br>
Note: If the installation fails, you can try the following compiled installation.<br>
```git clone --recursive https://github.com/WiringPi/WiringPi-Python.git```<br>
Note: The --recursive option can automatically pull submodules. Otherwise, you need to download them manually.
Enter the newly downloaded WiringPi-Python folder and use the following commands to compile and install:<br>
For Python 2.x version<br>
```sudo python setup.py install```<br>
For Python 3.x version<br>
```sudo python3 setup.py install```<br>
If the following error occurs:<br>
``Error: Building this module requires either that swig is installed``<br>
``(e.g.,'sudo apt install swig')or that wiringpi wrap.c from the``<br>
``source distribution(on pypi) is available.``<br>
In this case, enter the command ```sudo apt install swig``` to install SWIG. After completing the installation, run ```sudo python3 setup.py``` install to compile and install. If you see similar information, it indicates that the installation was successful.<br>
``ges``<br>
``Adding wiringpi 2.60.0 to easy-install.pth file``<br>
``Installed /usr/local/lib/python3.7/dist-packages/wiringpi-2.60.0-py3.7-linux-armv7``<br>
``Processing dependencies for wiringpi==2.60.0``<br>
``Finished processing dependencies for wiringpi==2.60.0``<br>


### 2.2.3 lgpio Library Installation
For the Bookworm system, the example programs use the lgpio library. The installation command for this library is:<br>
```wget https://github.com/joan2937/lg/archive/master.zip```<br>
```unzip master.zip```<br>
```cd lg-master```<br>
```make```<br>
```sudo make install```<br>
### 2.2.4 Run Example Program
Python:<br>
Enter the Python directory:<br>
```cd /home/pi/raspberry-pi/relay-lgpio/python```<br>
or<br>
```cd /home/pi/raspberry-pi/relay-wiringpi/python```<br>
Execute：<br>
```sudo python3 relay.py```<br>
C:<br>
Enter the C directory:<br>
```cd /home/pi/raspberry-pi/relay-lgpio/c```<br>
or<br>
```cd /home/pi/raspberry-pi/relay-wiringpi/c```<br>
Execute：<br>
```sudo make clean```<br>
```sudo make```<br>
```sudo ./main```<br>
## 2.3 Arduino Platform Example Program Usage
### 2.3.1 Wiring Definition
The wiring definitions for connecting the module to the Arduino UNO mainboard are shown in the table below:<br>
|Pin Interface	|Arduino UNO|
|----------------------|---------------|
|VCC	|5V|
|GND	|GND|
|DRV	|D7|<br>

Table 2-3 Module and Arduino Pin Definitions<br>
### 2.3.2 Run Example Program
After wiring according to Table 2-3, open the project file demo codes\Arduino\relay.ino using the Arduino IDE. Then, select Arduino Uno in Tools -> Board and the corresponding port in Tools -> Port. Click Verify to check for errors, and if verification is successful, upload the code to the Arduino Uno. Observe the relay status.<br>

__Thank you for choosing the products of Shengui Technology Co.,Ltd. For more details about this product, please visit:
www.seengreat.com__
