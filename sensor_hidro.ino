// Sensor de humedad
byte pinSensor = A0;
int humedad;
// Fotoresistor
byte pinLDR = A1;
int luz;
// Motor 
byte pinM1 = 2;
byte pinM2 = 3;

void setup()
{
  pinMode(pinSensor, INPUT);
  pinMode(pinLDR, INPUT);
  
  pinMode(pinM1, OUTPUT);
  pinMode(pinM2, OUTPUT);

  
  Serial.begin(9600);
}

void loop()
{
  humedad = analogRead(pinSensor);
  humedad = map(humedad, 0, 1023, 0, 100);
  
  luz= analogRead(pinLDR);
  
  if (humedad < 45 && luz < 100){
   digitalWrite(pinM1, HIGH);
   digitalWrite(pinM2, LOW);
  }
  
  else {
   digitalWrite(pinM1, LOW);
   digitalWrite(pinM2, LOW);
  }
  
  Serial.print(humedad);
  Serial.print("      ");
  Serial.println(luz);
  
}