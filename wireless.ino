#include <SoftwareSerial.h>
SoftwareSerial espSerial(8, 7);  // RX, TX

const char* ssid = "S22";
const char* password = "rtln0000";

void setup() {
  Serial.begin(230400);
  espSerial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");
  espSerial.println("AT+RST");
  delay(2000);
  espSerial.println("AT+CWMODE=1");
  delay(1000);
  espSerial.println("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"");

  while (espSerial.available() == 0) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  String input = Serial.readString();

  if (input.length() == 2) {
    if (input.equals("s\n")) {
      Serial.println("RECEIVED");
      delay(2000);
      espSerial.println("AT+CIPMUX=1");
      delay(2000);
      espSerial.println("AT+CIFSR");
    }
    if (input.equals("p\n")) {
      delay(2000);
      espSerial.println("AT+CIPSERVER=1,1234");
    }
  }
  else if (input.length() > 2) {
    espSerial.print("AT+CIPSEND=0,");
    espSerial.println(input.length());
    delay(2000);
    espSerial.println(input);
  }
  if (espSerial.available()) {
    Serial.print(espSerial.readString());
    delay(1000);
  }
}
