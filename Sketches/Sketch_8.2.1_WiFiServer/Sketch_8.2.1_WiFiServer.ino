/**********************************************************************
  Filename    : Sketch 39.2.1_WiFi_Server
  Description : Use Control board's WiFi server feature to wait for other WiFi devices to connect.
                And communicate with them once a connection has been established.
  Auther      : www.freenove.com
  Modification: 2024/08/05
**********************************************************************/

#include "WiFiS3.h"

#define port 80
const char *ssid_Router      = "********";  //input your wifi name
const char *password_Router  = "********";  //input your wifi passwords
WiFiServer  server(port);

void setup()
{
    Serial.begin(115200);
    Serial.println("\nConnecting to ");
    Serial.println(ssid_Router);
    WiFi.disconnect();
    WiFi.begin(ssid_Router, password_Router);
    delay(1000);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());		
    Serial.println(String("IP port:") + String(port));				
    server.begin(port);								
}

void loop(){
 WiFiClient client = server.available();            // listen for incoming clients
  if (client) {                                     // if you get a client,
    Serial.println("Client connected.");
    while (client.connected()) {                    // loop while the client's connected
      if (client.available()) {                     // if there's bytes to read from the client,
        Serial.println(client.readStringUntil('\n')); // print it out the serial monitor
        while(client.read()>0);                     // clear the wifi receive area cache
      }
      if(Serial.available()){                       // if there's bytes to read from the serial monitor,
        client.print(Serial.readStringUntil('\n')); // print it out the client.
        while(Serial.read()>0);                     // clear the wifi receive area cache
      }
    }
    client.stop();                                  // stop the client connecting.
    Serial.println("Client Disconnected.");
  }
}
