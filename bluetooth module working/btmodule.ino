#include <SoftwareSerial.h>
SoftwareSerial btSerial(D2, D3);
const int led = D0;
int value;
void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  if (btSerial.available() > 0) {
    value = btSerial.read();
  }
  if (value == 'ON') {
    digitalWrite(led, HIGH);
    Serial.println("LIGHTS ON!");
  } else {
    digitalWrite(led, LOW);
    Serial.println("LIGHTS OUT!!!!!");
  }
}