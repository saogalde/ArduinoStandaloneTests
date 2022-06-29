#include <string.h>
#include <DS3231.h>
#include <SD.h>

class TM {
  public:
    TM(String filename = "");
    int transmitTelemetry(String);
    DS3231 clock;
    File logfile;
    String logfilename;
  private:
    String buffer;
    String getTimestamp();
    String clockReliability();
    bool isClockReliable();
};
