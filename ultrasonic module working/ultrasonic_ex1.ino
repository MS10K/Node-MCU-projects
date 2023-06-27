#include <SoftwareSerial.h>
const int trig = D1;
const int echo = D2;
const int relay = D0;
float duration;
float distance;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(relay, OUTPUT);
}

void loop() {

  digitalWrite(trig, LOW);
  delay(10);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
Serial.println(duration);
  distance = (duration * 0.034 / 2);
  Serial.println(distance);
  if (distance < 20) {
    digitalWrite(relay,HIGH);
    Serial.println("motor off");
  }

  else {
    digitalWrite(relay, LOW);
    Serial.println("motor on");
  }
  delay(2000);
}
