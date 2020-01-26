/*
 * This program send a web request EVENT to ITFFF webhook server.
 * Xem bai viet tren nguyendinhthong.com de hieu ro
 */
#include <ESP8266WiFi.h>
// actually it's ust declaring character array.
const char* ssid = "TP-LINK_DECE";
const char* password = "58076439";
char input;
char server[] = "maker.ifttt.com";    // name address for Google (using DNS)
WiFiClient client;
int trigger=0;

void setup() {
  Serial.begin(115200);
  delay(10);
// Ket noi voi mang wifi
  Serial.println();
  Serial.println();
  Serial.print("Ket noi toi mang wifi ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi da ket noi");
  Serial.println("Dia chi IP: ");
  Serial.println(WiFi.localIP()); //In ra dia chi IP
  pinMode(5, INPUT_PULLUP);
  attachInterrupt(5,sendRequest,LOW); // Interrupt is fired whenever button is pressed
  Serial.println("Push the button!");
}

void loop() {

  String IFTTT_KEY = "bZX19sei2Nz7tKF3vKuBwv3pOYcI1SCdbPDP3bRwf3L";
  String IFTTT_EVENT = "button_p"; // IFTTT Maker Event Name here
  input=Serial.read();
  if(input == '1'){
    ifttt_trigger(IFTTT_KEY, IFTTT_EVENT); 
    Serial.println("Push the button!");
    input='0';
  }
  }

//******************************************************************************************
// This method makes a HTTP connection to the server & does a GET request for user name
// Simply pass in the badge ID to query as a String.
// Returns string:
//   - Returns "<NAME>"if badge ID is registered
//   - Returns "NULL" if badge ID is not registered
//   - Returns "FAIL" if REST API failed
//******************************************************************************************
String ifttt_trigger(String KEY, String EVENT) {
  String name = "";
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    
    // This is optional. You can send additional data to IFTTT along with your HTTP POST that triggers the action
    String PostData = "{\"value1\" : \"testValue\", \"value2\" : \"Hello\", \"value3\" : \"Worlddd!\" }";
    
    Serial.println("connected to server... Getting name...");
    // send the HTTP PUT request:
    String request = "POST /trigger/";
    request += EVENT;
    request += "/with/key/";
    request += KEY;
    request += " HTTP/1.1";
    
    Serial.println(request);    
    client.println(request);
    client.println("Host: maker.ifttt.com");
    client.println("User-Agent: Energia/1.1");
    client.println("Connection: close");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(PostData.length());
    client.println();
    client.println(PostData);
    client.println();

  }
  else {
    // if you couldn't make a connection:
    Serial.println("Connection failed");
    return "FAIL"; // rest API failed...
  }
  
  // Capture response from the server. (10 second timeout)
  long timeOut = 4000;
  long lastTime = millis();
  
  while((millis()-lastTime) < timeOut){  // Wait for incoming response from server
    while (client.available()) {         // Characters incoming from the server
      char c = client.read();            // Read characters
      Serial.write(c);
    }
    
  }
  Serial.println();
  Serial.println("Request Complete!");
  //return name; // Return the complete name received from server
  return "SUCCESS";
}

void sendRequest(){
  if(trigger == 0){
    trigger = 1;
  }
}

