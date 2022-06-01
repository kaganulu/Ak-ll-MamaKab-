#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

LiquidCrystal_I2C mama(0x27,16,2);

Servo kap;
int buttonPin = 9;
int buttonDeger ;
int servoPin = 3;
int buzzerPin = 2;
int kirmiziLed = 4;
int yesilLed = 5;


void setup() {
  mama.init();
  mama.backlight();
  kap.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(kirmiziLed,OUTPUT);
  pinMode(yesilLed,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
 

}

void loop() {
  buttonDeger = digitalRead(buttonPin);
  Serial.print("Buton Degerim:");
  Serial.println(buttonDeger);
  if(buttonDeger==1){
   delay(1000); // 1 saniye kadar 0 derece görelim
   kap.write(0);
   digitalWrite(yesilLed,HIGH);
   mama.setCursor(1,0);
   mama.print("Mama Zamani ");
   delay(1000);
   digitalWrite(kirmiziLed,LOW);
  
  }
 
 
  else if(buttonDeger==0){
   kap.write(90);
   digitalWrite(kirmiziLed,HIGH);
   mama.setCursor(0,1);
   mama.print("Cok Yedin dinlen");
   digitalWrite(yesilLed,LOW);
   delay(200);
   
   

  }
mama.clear();
}
