#include "DHT.h"
DHT dht;

int smokeA0 = A0;

int PulseSensorPin1=A6;
int PulseSensorPin2=A7;
int PulseSensorPin3=A5;

#include <OneWire.h>
#include <DallasTemperature.h>
OneWire ds18x20[] = { 22, 24, 42 };
const int oneWireCount = sizeof(ds18x20)/sizeof(OneWire);
DallasTemperature sensor[oneWireCount];


void setup()
{
  Serial.begin(9600);
  dht.setup(2); // data pin 2

  pinMode(smokeA0, INPUT);

  //B.temp
  DeviceAddress deviceAddress;
  for (int i = 0; i < oneWireCount; i++) {;
    sensor[i].setOneWire(&ds18x20[i]);
    sensor[i].begin();
    if (sensor[i].getAddress(deviceAddress, 0)) sensor[i].setResolution(deviceAddress, 12);
  }
  
}

void loop()
{
  //delay(dht.getMinimumSamplingPeriod());
  delay(1000);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  //Serial.print(dht.getStatusString());
  //Serial.print("\t");
  Serial.print("Humidity : ");
  Serial.print(humidity, 1);
  Serial.println(" %");
  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println(" C");
//  Serial.println(dht.toFahrenheit(temperature), 1);
//  Serial.print("temp:  ");
  
 //Smoke Sensor
 int analogSensor = analogRead(smokeA0);
 Serial.print("Smoke Volume: ");
 Serial.print(analogSensor);
 Serial.println(" PPM");

  //Pulse Sensor 
  int Signal1=analogRead(PulseSensorPin1)/8;
  Serial.print("Pulse rate of Patient-01 :  ");
  Serial.print(Signal1);
  Serial.println(" BPM");

  int Signal2=analogRead(PulseSensorPin2)/8;
  Serial.print("Pulse rate of Patient-02 :  ");
  Serial.print(Signal2);
  Serial.println(" BPM");

  int Signal3=analogRead(PulseSensorPin3)/8;
  Serial.print("Pulse rate of Patient-03 :  ");
  Serial.print(Signal3);
  Serial.println(" BPM");

  //B. Temp
   for (int i = 0; i < oneWireCount; i++) {
    sensor[i].requestTemperatures();
  }
    for (int i = 0; i < oneWireCount; i++) {
    float temperature = sensor[i].getTempCByIndex(0);
    float x=((temperature*9)/5)+32;
    Serial.print("Temperature of Patient-0");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(x);
    Serial.println(" F");
  }
  
  
  delay(7000);

  Serial.println();
}
