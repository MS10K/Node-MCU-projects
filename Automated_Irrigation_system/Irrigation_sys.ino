#include <SoftwareSerial.h>
const int ir = D0, pir = D1, ldr = D2, rain = A0, soil = A0;
int led, buzz, value1,value2,value3,value5,value4;
float ans1;
void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(pir, INPUT);
  pinMode(ldr, INPUT);
  pinMode(rain, INPUT);
  pinMode(soil, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(buzz, LOW);
}

void loop() {
  value1 = digitalRead(ir);
  if (value1 == HIGH) {
    digitalWrite(buzz, HIGH);
    Serial.println("Close the door!YOU MORON!!");
    delay(5000);
  }
  value2 = digitalRead(pir);
  value3 = digitalRead(ldr);
  if (value2 == HIGH) {
    if (value3 == LOW) {

      digitalWrite(led, HIGH);
      delay(10000);
      Serial.println("Lights ON!!");
      delay(1000);
    } else {
      digitalWrite(led, LOW);
      Serial.println("No Need of LIGHT!");
      delay(1000);
    }
  }
  value4 = analogRead(rain);
  value5 = analogRead(soil);
  ans1=(100.00-(value5/1023.00)*100.00);  
  if (value4 > 200) {
    Serial.println("Irrigation not required");
delay(1000);    
    if (ans1 > 700) {
      Serial.println("close the shed WATER IS LOGGING!!");
      delay(1000);
    }
  } else if (ans1 < 700) {
    Serial.println("Irrigation reuired");
    delay(1000);
  }
  else{
    Serial.println("Irrigation not required");
    delay(1000);
  }
  
  
}



















































































































































































































