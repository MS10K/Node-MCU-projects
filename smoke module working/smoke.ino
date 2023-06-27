m mṁ,,ṁṁ
  pinMode(smoke, INPUT);
  pinMode(smoke, LOW);
  pinMode(led, OUTPUT);
  pinMode(led, LOW);
}

void loop() {

  value = analogRead(smoke);
  Serial.println(value);
  if (value > 700) {

    digitalWrite(led, HIGH);
    Serial.println("led ON");
    delay(1000);

  } else {

    digitalWrite(led, LOW);
    Serial.println("led OFF");
    delay(1000);
  }
}