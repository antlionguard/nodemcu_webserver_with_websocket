#ifndef WEB_SERVER_H
#define WEB_WERVER_H
#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

extern bool ledState;
extern const int ledPin;

extern AsyncWebServer server;
extern AsyncWebSocket ws;

void notifyClients();
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void initWebSocket();
String processor(const String &var);

#endif
