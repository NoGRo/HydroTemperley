#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <SoftTimer.h>

void timeUpdate(Task* me);
Task update(15 * 60 * 1000, timeUpdate);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ar.pool.ntp.org", -10800, 60000);

void setuptime(){
  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
  }
  timeClient.begin();
  SoftTimer.add(&update);

}

void timeUpdate(Task* me) {
  if(WiFi.status() == WL_CONNECTED)
  {
    timeClient.update();
  }
}



void setChronosTimeFromNTP() 

{ 
    time_t rawtime = timeClient.getEpochTime();
   struct tm * ti;
   ti = localtime (&rawtime);

   uint16_t year = ti->tm_year + 1900;
   uint8_t month = ti->tm_mon + 1;
   uint8_t day = ti->tm_mday;
   uint8_t hours = ti->tm_hour;
   uint8_t minutes = ti->tm_min;
   uint8_t seconds = ti->tm_sec;
   
}

String getTimeStampString() {
   time_t rawtime = timeClient.getEpochTime();
   struct tm * ti;
   ti = localtime (&rawtime);

   uint16_t year = ti->tm_year + 1900;
   String yearStr = String(year);

   uint8_t month = ti->tm_mon + 1;
   String monthStr = month < 10 ? "0" + String(month) : String(month);

   uint8_t day = ti->tm_mday;
   String dayStr = day < 10 ? "0" + String(day) : String(day);

   uint8_t hours = ti->tm_hour;
   String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

   uint8_t minutes = ti->tm_min;
   String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);

   uint8_t seconds = ti->tm_sec;
   String secondStr = seconds < 10 ? "0" + String(seconds) : String(seconds);

   return yearStr + "-" + monthStr + "-" + dayStr + " " +
          hoursStr + ":" + minuteStr + ":" + secondStr;
}