/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-websocket-server-arduino/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include "src/env/env.h"
#include "src/web_socket/web_socket.h"
#include <ESP8266WiFi.h>

void setup()
{
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  initWebSocket();


  // Start server
  server.begin();
}
int period = 250;
unsigned long time_now = 0;
void loop()
{
  time_now = millis();
  ws.cleanupClients();

  while (millis() < time_now + period)
  {
    notifyClients();
  }
}
