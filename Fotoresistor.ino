
/*
Cayenne WiFi Example

This sketch connects to the Cayenne server using an Arduino WiFi shield
and runs the main communication loop.

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. Set the token variable to match the Arduino token from the Dashboard.
2. Set the network name and password.
3. Compile and upload this sketch.

For Cayenne Dashboard widgets using digital or analog pins this sketch will automatically
send data on those pins to the Cayenne server. If the widgets use Virtual Pins, data
should be sent to those pins using virtualWrites. Examples for sending and receiving
Virtual Pin data are under the Basics folder.
Esta é uma adaptação feita por Carlos kwiek para usar um ESP8266-12E e um fotoresitor e mostrar os recursos 
do site de IoT do Cayenne.
contato@carloskwiek.com.br.
*/

//#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266_mod.h"
#include "CayenneWiFiClient.h"

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "Tokem";
// Your network name and password.
char ssid[] = "REDE";
char password[] = "SENHA";



void setup()
{
  Serial.begin(115200);
  Cayenne.begin(token, ssid, password);

}

void loop()
{
  Cayenne.run();

}

CAYENNE_OUT(V0){

  int sensorValue = analogRead(A0);
 
  float lux = sensorValue * (3.3 / 1023.0);
 
  

  Serial.print("LUX: ");
  Serial.println(lux*100);


  Cayenne.virtualWrite(V0, lux*100);
}


 
