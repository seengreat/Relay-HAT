/***************************************************************************************
 * Project  :
 * Experimental Platform :Arduino UNO + Relay HAT
 * Hardware Connection :Arduino UNO-> Relay HAT
 *      5V  --> VCC
 *      GND --> GND
 *      D7  --> DRV
 * Web Site    :www.seengreat.com
***************************************************************************************/
//IO settings
int DRV_Pin = 7; 

#define DRV_0  digitalWrite(DRV_Pin,LOW)
#define DRV_1  digitalWrite(DRV_Pin,HIGH) 
  

void setup() {
   pinMode(DRV_Pin, OUTPUT);   
}

void loop() {
    unsigned char i; 

    delay(1000);
    DRV_0; // relay NO state
    delay(1000);
    DRV_1; // relay NC state

}




//////////////////////////////////END//////////////////////////////////////////////////
