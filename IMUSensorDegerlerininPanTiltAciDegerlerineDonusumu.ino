#include "lsm6dsm.h"  // Deneyap Kart dahili IMU kütüphanesinin eklenmesi

LSM6DSM IMU;  // IMU için class tanımlanması

void setup() {
  Serial.begin(9600);  // Seri haberleşme başlatılması
  IMU.begin();           // Algılayıcı ile haberleşmenin başlatılması
}

void loop() {
  Serial.println("\nAkselerometre degerleri");
  Serial.print("X ekseni: ");  // X-eksen akselerometre verisi okunması
  Serial.print(IMU.readFloatAccelX());
  Serial.print("\tY ekseni: ");  // Y-eksen akselerometre verisi okunması
  Serial.print(IMU.readFloatAccelY());
  Serial.print("\tZ ekseni: ");  // Z-eksen akselerometre verisi okunması
  Serial.println(IMU.readFloatAccelZ());
  delay(500);
}