/*****************************************************************************************
 * This is the code used for remote controlling the Arduino's LED with the use of 
 * Blynk app.
 *
 *
*******************************************************************************************/

 

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <Ethernet2.h>
#include <BlynkSimpleEthernet2.h>

int led = 7;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

byte ip[] = {192, 168, 1, 30}; //IP address
byte mac[] = {
  0x90, 0xA2, 0xDA, 0x10, 0x8A, 0x1A
  }; //MAC address toy Ethernet Shield
byte mask[] = {255, 255, 255, 0}; //μάσκα του δικτύου

BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int state = param.asInt(); 
  if(state == 1)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);
  
  pinMode(led, HIGH);
  // You can also specify server.
  // For more options, see BoardsAndShields/Arduino_Ethernet_Manual example
  //Blynk.begin(auth, "your_server.com", 8442);
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8888);
}

void loop()
{
  Blynk.run();
  //delay(15);
}

