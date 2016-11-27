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

#define _soil A0 //pin for soil hygrometer sensor
#define _ph A1 //pin for photoresistor

#define _pump 12 // pin of the motor(liquid pump)
#define _pumpbr 9// pin of the motor's brake
#define _pumps 3 //pin for speed

int led = 7;
char auth[] = ""; //Blynk authorization token

byte _ip[] = { 192, 168, 30, 234}; //_ip address
byte _mac[] = {0x90, 0xA2, 0xDA, 0x10, 0x8A, 0x1A}; //_mac address toy Ethernet Shield
byte _mask[] = {255, 255, 255, 0}; //μάσκα του δικτύου

BLYNK_WRITE(V2) //Button Widget is writing to pin V2
{
  int state = param.asInt(); //αποθήκευση της κατάστασης που στέλνεται από ένα button
  if(state == 1)// αν η κατάσταση είναι 1, 
  {
    digitalWrite(led,HIGH);//τότε ανάβει το Led στην διάταξη
    digitalWrite(_pump, HIGH); //kinisi mprosta gia piestira
    //digitalWrite(9, LOW);   //bgazei to freno
    analogWrite(_pumps,255);  //taxitita motor A
  }
  else
  {
    digitalWrite(led,LOW);//διαφορετικά σβήνει η παραμένει σβηστό.
    digitalWrite(_pump, LOW); //kinisi mprosta gia piestira
    //digitalWrite(9, LOW);   //bgazei to freno
    analogWrite(_pumps, 0);  //taxitita motor A
  }
}

int moistureCalc()
{
  int mois = analogRead(_soil); // save in a variable the readings
  mois = constrain(mois,260,1023); //constrainment of measurements in a range
  mois = map(mois, 260, 1023, 100, 0); //values matching from 260-1023 to 100-0,
                                     //in order to see moisture in percentage
  return mois; //return soil hygrometer
}

int luminanceCalc() //function to calculate the luminance
{
  int lum = analogRead(_ph); // save in a variable the readings
  lum = constrain(lum,0,1003); //constrainment of measurements in a range
  lum = map(lum, 0, 1003, 0, 100);//values matching from 0-1003 to 100-0,
                                  //in order to see moisture in percentage
  return lum; //return luminosity
}

void setup()
{
  //Serial.begin(9600);
  Ethernet.begin(_mac, _ip, _mask); //
  Blynk.begin(auth); //begin connection with Blynk Server
  pinMode(led, HIGH);

  pinMode(_soil, INPUT);
  pinMode(_ph, INPUT); 
  
  pinMode(_pump, OUTPUT);
  pinMode(_pumpbr, OUTPUT);
  digitalWrite(_pumpbr, LOW);
  digitalWrite(_pump, LOW);
  // You can also specify server.
  // For more options, see BoardsAndShields/Arduino_Ethernet_Manual example
  //Blynk.begin(auth, "your_server.com", 8442);
  //Blynk.begin(auth, _ipAddress(192,168,1,100), 8888);
}

void loop()
{
  Blynk.virtualWrite(V0, moistureCalc());
  Blynk.virtualWrite(V1, luminanceCalc());
  delay(1000);
  Blynk.run(); //this is used in order to keep communication up
  //delay(15);
}

