/*******************************************************************************
 *
 * E5MAT: Location Tracker Using GPS and LoRa Technology
 * LoRa GPS Tracker using Grove LoRa-E5 and the possibility of real-time tracking on the map.
 * Please find more details at Hackster.io:
 * https://www.hackster.io/idreams/e5mat-location-tracker-using-gps-and-lora-technology-05f7cf
 * 
 ******************************************************************************/
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "index.h"
#include <LoRaE5.h>

unsigned char buffer[128] = {0, };
String incomingString;

//Grove Port >> GND/5V/G13/G4
#define GROVE_TX 13
#define GROVE_RX 4

WebServer server(80);

//Enter your SSID and PASSWORD
const char* ssid = "idreams";
const char* password = "98765432";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_PAGE_IDREAMS;
 server.send(200, "text/html", s);
}

void handleGPS() {
 server.send(200, "text/plane", incomingString);
}
//===============================================================
// Setup
//===============================================================
void setup(void){
  Serial.begin(115200);

  lora.init();.    //lora.init(GROVE_RX, GROVE_TX);
  delay(2000);
  lora.initP2PMode(866, SF12, BW125, 12, 15, 14);

//ESP32 connects to your wifi
  WiFi.mode(WIFI_STA);          //Connect to your wifi
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
   }
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to: ");
  Serial.print(ssid);
  Serial.println("");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());  //IP address assigned to your ESP
  Serial.println("");
//----------------------------------------------------------------
  server.on("/", handleRoot);
  server.on("/gpsDATA", handleGPS);
  server.begin();
  Serial.println("HTTP server started");
}
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
  delay(1);
//--------------------------------
  short length = 0;
  short rssi = 0;
  memset(buffer, 0, 128);
  length = lora.receivePacketP2PMode(buffer, 128,  &rssi, 1);
  if(length){
    incomingString = String((char*)buffer);
    String Data = incomingString + "|";
    Serial.print(Data);
	//Serial.flush();
  }
//--------------------------------    
}
