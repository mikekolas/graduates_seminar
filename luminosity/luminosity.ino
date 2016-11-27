#define _ph A0 //pin for photoresistor
void setup()
{
  Serial.begin(9600);
  pinMode(_ph,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lum = analogRead(_ph);
  lum = constrain(lum,0,1003);
  lum = map(lum, 0, 1003, 0, 100);
  
  Serial.println(lum);
  delay(1000);
}
