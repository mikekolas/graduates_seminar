#define _soil A0 //pin for soil hygrometer sensor
//int _soil = A0; 
 
int mes; // variable for measurements
void setup()
{
  Serial.begin(9600);
  pinMode(_soil, INPUT); 
}

void loop() 
{
  mes = analogRead(_soil); //readings
  mes = constrain(mes,260,1023); //constrainment of measurements in a range
  mes = map(mes, 260, 1023, 100, 0); 
  Serial.println(mes);// print the sensor reading in percentance
}
