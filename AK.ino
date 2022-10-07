#include <OneWire.h>
#include <DallasTemperature.h>

OneWire ds18x20[] = { 22, 24, 26 };
const int oneWireCount = sizeof(ds18x20)/sizeof(OneWire);
DallasTemperature sensor[oneWireCount];

void setup(void) {
  // start serial port
  Serial.begin(9600);
  //Serial.println("Dallas Temperature Multiple Bus Control Library Simple Demo");
//  Serial.print("============Ready with ");
//  Serial.print(oneWireCount);
//  Serial.println(" Sensors================");
//  
  // Start up the library on all defined bus-wires
  DeviceAddress deviceAddress;
  for (int i = 0; i < oneWireCount; i++) {;
    sensor[i].setOneWire(&ds18x20[i]);
    sensor[i].begin();
    if (sensor[i].getAddress(deviceAddress, 0)) sensor[i].setResolution(deviceAddress, 12);
  }
}

void loop(void) {
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  for (int i = 0; i < oneWireCount; i++) {
    sensor[i].requestTemperatures();
  }
  //Serial.println("DONE");
  
  delay(1000);
  for (int i = 0; i < oneWireCount; i++) {
    float temperature = sensor[i].getTempCByIndex(0);
    float x=((temperature*9)/5)+32;
    Serial.print("Temperature for Patient-0");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(x);
    Serial.println(" F");
  }
  Serial.println();
}
