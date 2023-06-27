#include<SoftwareSerial.h>
const int Enable = D0;
const int IN1 = D1;
const int IN2 = D2;


void setup() {
  Serial.begin(9600);
  pinMode(Enable, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite(Enable, 30);
}

void loop() {
  //clockwise
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(Enable, 30);  
  delay(5000);

  //Anti-clockwise
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(Enable, 30);
  delay(5000);

  //Stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

}
