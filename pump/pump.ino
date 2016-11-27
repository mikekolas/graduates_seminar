#define _pump 12 // pin of the motor(liquid pump)
#define _pumpbr 9// pin of the motor's brake
#define _pumps 3
void setup()
{
  pinMode(_pump, OUTPUT);
  pinMode(_pumpbr, OUTPUT);
  digitalWrite(_pumpbr, LOW);
  digitalWrite(_pump, LOW);
}

void loop()
{
  /*analogWrite(_pumps,255);
  delay(1000);
  analogWrite(_pumps,0);
  delay(1000);*/

  digitalWrite(12, HIGH); //kinisi mprosta gia piestira
    digitalWrite(9, LOW);   //bgazei to freno
    analogWrite(3,255);  //taxitita motor A
    delay(2000);
    digitalWrite(12, LOW); //kinisi mprosta gia piestira
    //digitalWrite(9, LOW);   //bgazei to freno
    analogWrite(3,0);  //taxitita motor A
    delay(1000);
}
