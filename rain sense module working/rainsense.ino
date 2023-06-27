#include <SoftwareSerial.h>
const int rainsen = A0;
int value;
int ans;
void setup() {
  Serial.begin(9600);
  pinMode(rainsen, INPUT);
  pinMode(rainsen, LOW);
}

void loop() {
   pinMode(rainsen, LOW);
  value = analogRead(rainsen);
  ans = (100.00 - (value / 1023.00) * 100.00);
  Serial.println(ans);
  delay(1000);
}