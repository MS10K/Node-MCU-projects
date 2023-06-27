

#include <SoftwareSerial.h>
const int ldr = D0;
const int led = D1;
int value;
void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  //delay(10000);
}

void loop() {
  value = digitalRead(ldr);
  if (value == 0) {
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
    delay(1000);
  } else {
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
    delay(1000);
  }
}
