#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> // library LCD
#include <NewPing.h> // library sensor ultrasonic
#include <Servo.h>  // library motor servo

#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define MAX_DISTANCE 120

#define TRIGGER_PIN1 8
#define ECHO_PIN1 7
#define MAX_DISTANCE1 22
const int ledMerah=1;
const int ledHijau=2;
const int pinbuzz=3;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1); // NewPing setup of pins and maximum distance.

void setup () {
  myservo.attach(6);
  lcd.begin(2, 16);
  pinMode(ledMerah,OUTPUT);
  pinMode(ledHijau,OUTPUT);
  pinMode(pinbuzz,OUTPUT);
 
}

void loop () {
  delay(50);
  int jarak = sonar.ping_cm(); // Send out the ping, get the results in centimeters.
  Serial.println(jarak);
  int kapasitas = sonar1.ping_cm(); // Send out the ping, get the results in centimeters.

if ((jarak>0)&&(jarak<=30)){
    delay(50);  
    myservo.write(30); 
    delay (1500);  
    }
    else {
    myservo.write(120);
    delay (1500);
    }
  
  if ((kapasitas > 15) && (kapasitas < 19))
  {
    lcd.setCursor(0, 0);
    lcd.print("Kapasitas Sampah");
    lcd.setCursor(5, 1);
    lcd.print("25%   ");
    digitalWrite (ledMerah, LOW);
    digitalWrite (ledHijau, HIGH);
    digitalWrite (pinbuzz, LOW);
  }
  else if ((kapasitas > 10) && (kapasitas < 16))
  {
    lcd.setCursor(0, 0);
    lcd.print("Kapasitas Sampah");
    lcd.setCursor(5, 1);
    lcd.print("50%  ");
    digitalWrite (ledMerah, LOW);
    digitalWrite (ledHijau, HIGH);
    digitalWrite (pinbuzz, LOW);
       
  }
  else if ((kapasitas > 5) && (kapasitas < 11))
  {
    lcd.setCursor(0, 0);
    lcd.print("Kapasitas Sampah");
    lcd.setCursor(5, 1);
    lcd.print("75%            ");
    digitalWrite (ledMerah, LOW);
    digitalWrite (ledHijau, HIGH);
    digitalWrite (pinbuzz, LOW);
   }
  else if ((kapasitas > 1) && (kapasitas <= 5))
  {
    lcd.setCursor(0, 0);
    lcd.print("Kapasitas Sampah");
    lcd.setCursor(5, 1);
    lcd.print("100%(FULL) ");
    digitalWrite (ledMerah, HIGH);
    digitalWrite (ledHijau, LOW);
    digitalWrite (pinbuzz, HIGH);
      
     
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Kapasitas Sampah");
    lcd.setCursor(5, 1);
    lcd.print("0%             ");
    digitalWrite (ledMerah, LOW);
    digitalWrite (ledHijau, HIGH);
    digitalWrite (pinbuzz, LOW);
     
  }
}
