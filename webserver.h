// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

#include "index.h"

void setupWebserver(){
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/updateLight", HTTP_GET, [](AsyncWebServerRequest *request){
    if(request->hasParam("light")){switchLight();}
  });

  server.on("/getSensorData", HTTP_GET, [](AsyncWebServerRequest *request){

    // create JSON object
    DynamicJsonDocument json(1024);
    json["waterLevel"] = waterLevel;
    json["moisture"] = moisture;
    json["light"] = lightOn;

    // serialize JSON object
    String jsonStr;
    serializeJson(json, jsonStr);

    // send JSON object as response
    AsyncWebServerResponse *response = request->beginResponse(200, "application/json", jsonStr);
    response->addHeader("Access-Control-Allow-Origin", "*");
    request->send(response);
});

  // Start server
  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
}