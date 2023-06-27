#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // create an instance of the RFID reader

void setup() {
Serial.begin(9600); // start serial communication
SPI.begin(); // start SPI communication
rfid.PCD_Init(); // initialize the RFID reader
}

void loop() {
if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) { // check if a card is present
Serial.println("Card detected!");

// get the UID (unique identifier) of the card
String uid = "";
for (byte i = 0; i < rfid.uid.size; i++) {
uid += String(rfid.uid.uidByte[i], HEX);
}

Serial.print("UID: ");
Serial.println(uid);

// write data to the card
byte data[] = {0x41, 0x42, 0x43, 0x44};
byte dataLength = sizeof(data);
MFRC522::StatusCode status = rfid.MIFARE_Write(4, data, dataLength);

if (status == MFRC522::STATUS_OK) {
Serial.println("Data written to card!");
} else {
Serial.println("Error writing data to card!");
}

// read data from the card
// byte buffer[18];
// byte bufferSize = sizeof(buffer);
// status = rfid.MIFARE_Read(4, buffer, &bufferSize);

// if (status == MFRC522::STATUS_OK) {
// Serial.print("Data read from card: ");
// for (byte i = 0; i < 16; i++) {
// Serial.write(buffer[i]);
// }
// Serial.println();
// } else {
// Serial.println("Error reading data from card!");
// }

// // halt the card and prepare for a new reading
// rfid.PICC_HaltA();
// rfid.PCD_StopCrypto1();
}
}
