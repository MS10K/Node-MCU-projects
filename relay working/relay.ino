#include <SoftwareSerial.h>
const int IRSensor = D0;
const int relay = D1;
int value, value1;
void setup() {
  Serial.begin(9600);
  pinMode(IRSensor, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  value = digitalRead(IRSensor);
  if (value == HIGH) {
    digitalWrite(relay, HIGH);
    Serial.println("RELAY ON");
    delay(1000);
  } else {
    digitalWrite(relay, LOW);
    Serial.println("RELAY OFF");
    delay(1000);
  }
}
