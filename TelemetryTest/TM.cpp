#include "TM.h"
#include <SD.h>
#include <string.h>


TM::TM(String filename = "") {
  // initialize clock
  #ifndef RTC_UNVAILABLE
  Wire.begin();
  #else
  Serial.println("RTC not available. I2C will not be initialized.");
  #endif

  if( filename == "" ) filename = "AC_"+getTimestamp()+"_TM.csv";
  logfilename = filename;
  // initialize SD card
  #ifndef SD_UNAVAILABLE
  SD.begin(10);
  uint8_t O_WRITE = 0X02;
  uint8_t O_APPEND = 0X04;
  
  // testing the file opening
  logfile = SD.open(logfilename, (O_APPEND | O_WRITE));
  logfile.close();
  #else
  Serial.println("Attempting SD card initialization (debug mode)");
  #endif
}

int TM::transmitTelemetry(String packet) {
  buffer = "";
  buffer.concat(getTimestamp());
  buffer.concat('\t');
  buffer.concat(clockReliability());
  buffer.concat('\t');
  buffer.concat(packet);

  #ifndef SD_UNAVAILABLE
  logfile = SD.open(logfilename, (O_APPEND | O_WRITE));
  logfile.println(buffer);
  logfile.close();
  #endif
  #ifdef DEBUG
  Serial.println(buffer);
  #endif
  Serial.println(buffer);
  return 0;
}

String TM::getTimestamp() {
  String ts = "";
  #ifndef RTC_UNAVAILABLE
  bool a = false;
  int buff = clock.getYear();
  ts.concat(buff+2000);
  ts.concat("-");
  
  buff = clock.getMonth(a);
  if(buff<10) ts.concat("0");
  ts.concat(buff);
  ts.concat("-");
  
  buff = clock.getDate();
  if(buff<10) ts.concat("0");
  ts.concat(buff);
  ts.concat("T");
  
  buff = clock.getHour(a, a);
  if(buff<10) ts.concat("0");
  ts.concat(buff);
  ts.concat(":");
  
  buff = clock.getMinute();
  if(buff<10) ts.concat("0");
  ts.concat(clock.getMinute());
  ts.concat(":");
  
  buff = clock.getSecond();
  if(buff<10) ts.concat("0");
  ts.concat(clock.getSecond());
  #else
  ts = "2022-06-28T23:56:00";
  #endif
  return ts;
}

bool TM::isClockReliable() {
  #ifndef RTC_UNAVAILABLE
  return clock.oscillatorCheck();
  #else
  return true;
  #endif
}

String TM::clockReliability() {
  if(TM::isClockReliable()) return "OK";
  else return "NOK";
}
