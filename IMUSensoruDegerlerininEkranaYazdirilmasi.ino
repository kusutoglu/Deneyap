#include "lsm6dsm.h"  // Deneyap Kart dahili IMU kütüphanesinin eklenmesi

float accAngleX;
float accAngleY;

LSM6DSM IMU;  // IMU için class tanımlanması

void setup() {
  Serial.begin(9600);  // Seri haberleşme başlatılması
  IMU.begin();           // Algılayıcı ile haberleşmenin başlatılması
}

void loop() {
  accAngleX = atan(IMU.readFloatAccelX() / sqrt(pow(IMU.readFloatAccelY(), 2) + pow(IMU.readFloatAccelZ(), 2)+0.001)) * 180 / PI;
  accAngleY = atan(-1 * IMU.readFloatAccelY() / sqrt(pow(IMU.readFloatAccelX(), 2) + pow(IMU.readFloatAccelZ(), 2)+0.001)) * 180 / PI;

  Serial.print("accAngleX: ");
  Serial.println(accAngleX);
  Serial.print("accAngleY: ");
  Serial.println(accAngleY);
  delay(500);
}
