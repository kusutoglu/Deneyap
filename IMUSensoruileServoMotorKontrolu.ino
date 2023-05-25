#include "lsm6dsm.h"
#include "ESP32Servo.h"
#define SERVOPIN D0
float angle_x=0.; //x açısı
Servo myservo;
int pos=0; //servo motor konum değişkeni
int ref_pos=0; //servo motor başlangıç konumu değişkeni
LSM6DSM IMU; //Deneyap kart üzerinde bulunan IMU sensörü modeli
void setup() {
IMU.begin();
myservo.attach(SERVOPIN);
}
void loop() {

ref_pos=90; //servo motor başlangıç konumu 90 derece olar ayarlanıyor.

//açı hesaplama denklemi (sqrt: karekök alma işlemi, pow: üs alma işlemi, PI: pi (π)sayısı)
angle_x = atan(IMU.readFloatAccelX() / sqrt(pow(IMU.readFloatAccelY(), 2) +

pow(IMU.readFloatAccelZ(), 2)+0.001)) * 180 / PI;
pos=angle_x; //servo motor konumu olarak x yönündeki açı tanımlanıyor.

myservo.write(ref_pos+pos);
delay(500);
}
