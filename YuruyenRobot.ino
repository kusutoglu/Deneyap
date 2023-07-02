#include <Servo.h>
Servo frontServo;
Servo backServo;
int xPin = A0; 
int yPin = A1; 
int butonPin = 2; 
int xPozisyon;
int yPozisyon;
int butonDurum;
char forward[] = {120,180,180,180,180,120,120,120};
char forward2[] = {60,100,100,100,100,60,60,60};
void setup() {
Serial.begin(9600);
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(butonPin, INPUT_PULLUP);
frontServo.attach(5);  // Front servo, 5. pinde bağlı
backServo.attach(4);   // Back servo, 4. pinde bağlı
}
void loop() {
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
butonDurum = digitalRead(butonPin);
Serial.print("X Pozisyonu: ");
Serial.print(xPozisyon);
Serial.print(" | Y Pozisyonu: ");
Serial.print(yPozisyon);
Serial.print(" | Buton Durum: ");
Serial.println(butonDurum);
delay(1000);
  
  if(xPozisyon==0 & yPozisyon==1023)
  {
    for(int n=0;n<4;n++)
    {
    frontServo.write(forward[2*n]);
    backServo.write(forward[(2*n)+1]);
    delay(300);
    }
}
  else if(xPozisyon==0)
    for(int n=0;n<4;n++)
    {
    frontServo.write(forward[2*n]);
    delay(300);
}
  else if(yPozisyon==1023)
    for(int n=0;n<4;n++)
    {
    backServo.write(forward[(2*n)+1]);
    delay(300);
}
}