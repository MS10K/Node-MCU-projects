#include <SoftwareSerial.h>
const int flame = A0;
const int buzz = D1;
int value;
void setup() {
  Serial.begin(9600);
  pinMode(flame, INPUT);
  //pinMode(flame, LOW);
  pinMode(buzz, OUTPUT);
  pinMode(buzz, LOW);
}

void loop() {

  value = analogRead(flame);
  Serial.println(value);
  if (value > 10) {

    digitalWrite(buzz, HIGH);
    Serial.println("Fire DETECTED!!");
    delay(1000);

  } else {

    digitalWrite(buzz, LOW);
    Serial.println("FIRE NOT DEETECTED");
    delay(1000);
  }
}