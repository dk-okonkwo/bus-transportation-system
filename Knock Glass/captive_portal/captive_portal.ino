#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <map>

const byte DNS_PORT = 53;
int name = 40;
IPAddress apIP(172, 217, 28, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);
int Ip[100];
char Location[100][25];

// Dicitinary to store user info

String responseHTML = ""
                      "<!DOCTYPE html><html lang='en'><head>"
                      "<meta name='viewport' content='width=device-width'>"
                      "<title>CaptivePortal</title>"
                      "<style>"
                      "body {"
                        "display: flex;"
                        "flex-direction: column;"
                        "min-height: 100vh;" /* Ensure that the body takes up at least the full viewport height */
                        "margin: 0;"
                        "padding: 0;"
                      "}"
                      "header {"
                        "background-color: white;"
                        "height: 70px;"
                        "width: 100%;"
                      "}"
                      "main {"
                        "flex: 1;" /* Allow the main content to grow and fill available space */
                        "padding: 20px;"
                      "}"
                      "footer {"
                        "background-color: white;"
                        "height: 60px;"
                        "width: 100%;"
                      "}"
                      "footer p {"
                        "text-align: center;"
                        "align-items: center;"
                      "}"
                      "</style>"
                      "</head><body>"
                      "<header></header>"
                      "<main>"
                      "<h1>Hello World!</h1><p>This is a captive portal example."
                      " All requests will be redirected here.</p>"
                      "<form action='/trigger' method='get'>"
                      "<button>"
                      "Click function"
                      "</button>"
                      "</form>"
                      "</main>"
                      "<footer></footer>"
                      "</body></html>";

void myFunction() {
  Serial.println("Yes this works!");
}

void IpResponse() {
  for (int i = 0; )

}

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("Captive Portal");

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);

  //serial monitor
  Serial.begin(9600);

  // replay to all requests with same HTML
  webServer.onNotFound([]() {
    webServer.send(200, "text/html", responseHTML);
  });
  webServer.begin();

}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
  webServer.on("/trigger", []() {
    myFunction();
  });
  // GET SERVERS IPADD
  Serial.println((WiFi.localIP()));
  // GET NUM OF CONNECTED STATIONS(CLIENTS)
  Serial.println("connected stations:");
  Serial.println((WiFi.softAPgetStationNum()));
  delay(500);

}