/*
 * Basic ESP8266 info and WIFI info
 * Need deeper research to get more information. Look for the ESP8266WiFi.h library 
 */
#include <ESP8266WiFi.h>
// Thong so WiFi
const char* ssid = "TP-LINK_DECE";
const char* password = "58076439";
void setup(void)
{
  Serial.begin(115200);
// Connect WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { //Kiem tra xem trang thai da ket noi chua neu chua thi in ra dau .
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("WiFi ssid");
  Serial.println(ssid);
 Serial.println("connected local IP address");
  Serial.println(WiFi.localIP());
  Serial.println();
  Serial.print("ESP8266 MAC address: ");
  Serial.println(WiFi.macAddress());
}
void loop() {
}
