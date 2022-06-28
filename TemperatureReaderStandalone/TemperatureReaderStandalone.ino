#include "NTC_3950_10k.h"
#include <math.h>

unsigned int inByte = 0;
NTC_3950_10k *tempSensor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempSensor = new NTC_3950_10k(A0);
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(tempSensor->readTemperature());
  delay(1000);
}
