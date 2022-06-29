//#define RTC_UNVAILABLE
//#define SD_UNVAILABLE
#define DEBUG

#include "TM.h"

TM *tm;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9700);
  tm = new TM();
}

void loop() {
  // put your main code here, to run repeatedly:
  tm->transmitTelemetry("hola");
  delay(1000);
}
