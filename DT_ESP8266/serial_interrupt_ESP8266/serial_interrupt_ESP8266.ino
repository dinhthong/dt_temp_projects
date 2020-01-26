/*
Serial interupt and serial communication for further development with others boards. ESP <----> other boards
ESP main serial out: TXD0
ESP main serial in: RXD0
One can use a TTL to USB for testing before implementation 
Revision:
29/10/2017
*/

#include <ESP8266WiFi.h>
const char* ssid = "TP-LINK_DECE";  //Thay  ten_wifi bang ten wifi nha ban
const char* password = "58076439"; //Thay mat_khau_wifi bang mat khau cua ban
void setup() {
// Set Serial baud rate
  Serial.begin(9600);
  delay(10);
// Connect to WIFI
  Serial.println();
  Serial.println();
  Serial.print("Dang ket noi toi mang ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
  Serial.println("");
  Serial.println("Da ket noi WiFi");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
serialEvent();
 Serial.println("1 tick");
 delay(500);
}
void serialEvent() {
while (Serial.available()) {
    if (Serial.read()=='a')
    Serial.println("hello");
}
}

