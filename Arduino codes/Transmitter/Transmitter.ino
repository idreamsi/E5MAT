/*******************************************************************************
 *
 * E5MAT: Location Tracker Using GPS and LoRa Technology
 * LoRa GPS Tracker using Grove LoRa-E5 and the possibility of real-time tracking on the map.
 * Please find more details at Hackster.io:
 * https://www.hackster.io/idreams/e5mat-location-tracker-using-gps-and-lora-technology-05f7cf
 * 
 ******************************************************************************/
#include <LoRaE5.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 0, TXPin = 1;
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial GPSserial(RXPin, TXPin);

const long interval = 10000;
unsigned long previousMillis = 0;
//-----------------------------------------------------------------------
void setup(void)
{
    SerialUSB.begin(9600);
    GPSserial.begin(9600);
    lora.init();
    lora.initP2PMode(866, SF12, BW125, 12, 15, 14);
}
//-----------------------------------------------------------------------
void loop(void)
{
    unsigned long currentMillis = millis();
    while (GPSserial.available() > 0){
  		if (gps.encode(GPSserial.read())){
  		  if (currentMillis - previousMillis >= interval) {
    			previousMillis = currentMillis;
    			if (gps.location.isValid()){
    			  String GPSData = (String(gps.location.lat(), 6)) + "," + (String(gps.location.lng(), 6));
    			  lora.transferPacketP2PMode((char *)GPSData.c_str());
    			  SerialUSB.println("[GPS data has been sent.]");
    			}
  		  }
  	   }
  }
}
//-----------------------------------------------------------------------
