#include <OneWire.h>
#include <DallasTemperature.h>
#include<SimpleDHT.h>
#define A 22
#define B 24
#define C 26
#define light A1
OneWire oneWire(A);
//OneWire oneWire(B);
//OneWire oneWire(C);
DallasTemperature sensors(&oneWire);
 float Celcius=0;
 float Fahrenheit=0;
//int pulsePin = A0;                 // Pulse Sensor purple wire connected to analog pin A0
//int blinkPin = 13;                  // pin to blink led at each beat
//int pinDHT11=22;
//SimpleDHT11 dht11;
//int lvl;

void setup()
{
 
  Serial.begin(9600);             // we agree to talk fast!
//  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
     sensors.begin();                                 
}


void loop()
{
 
     sensors.requestTemperatures(); 
     Celcius=sensors.getTempCByIndex(0);
     Fahrenheit=sensors.toFahrenheit(Celcius);
     Serial.print(" C  ");
     Serial.print(Celcius);
       Serial.print("Body Temperature = ");
       Serial.print(Fahrenheit);
       Serial.println(" F");
       delay(1000);
     
       delay(20); //  take a break
}



  
