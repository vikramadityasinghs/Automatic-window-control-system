#include <dht.h>
#include<Servo.h>
#define dht1_apin A1
#define dht2_apin A2
#define rainfall A4
Servo myservo;
//defining DHT sensor

dht DHT1_inside;
dht DHT2_outside;

//defining LDR pins 

const int ldr2Pin = A5;
const int ldr1Pin = A0;

int value;
int set = 900;


void open(){
 
  }

void setup() {

   Serial.begin(9600);
   delay(500); //Delay to let system boot

   pinMode(ldr1Pin, INPUT);
   pinMode(ldr2Pin, INPUT);

   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);

   pinMode(rainfall, INPUT);
   Serial.println("AUTOMATIC WINDOW SYSTEM\n\n");
   delay(1000);

}

void loop() {
   //Start of Program 

   value = analogRead(rainfall);
   int ldr1_outside = analogRead(ldr1Pin);
   int ldr2_inside = analogRead(ldr2Pin);
   DHT1_inside.read11(dht1_apin);
   DHT2_outside.read11(dht2_apin);
   float temp_inside = DHT1_inside.temperature;
   float temp_outside = DHT2_outside.temperature;
 

     Serial.println(value);
     Serial.println(temp_outside);
     Serial.println(temp_inside);
     Serial.println(ldr1_outside);
     Serial.println(ldr2_inside);
   
   if (value <= set) {
      Serial.println("rain detected");
      Serial.println("CLOSE WINDOW!!!!!!!!!");

   } else {
      if (ldr1_outside > ldr2_inside) {
         Serial.println("Sun is shining!");
         Serial.println("OPEN WINDOW!!!!!!!!!");
//Temp sensor code
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
         if (temp_inside > temp_outside) {
            Serial.println("AC is running!");
            Serial.println("CLOSE WINDOW!!!!!!!!!");
         } else if (temp_inside < temp_outside) {
            Serial.println("Its windy!");
            Serial.println("OPEN WINDOW!!!!!!!!!");
         } else {
            Serial.println("Code error!");
         }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------         
      } else if (ldr1_outside < ldr2_inside) {
         Serial.println("Enough Light");
         Serial.println("CLOSE WINDOW!!!!!!!!!");
//Temp sensor code
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                  
         if (temp_inside > temp_outside) {
            Serial.println("AC is running!");
            Serial.println("CLOSE WINDOW!!!!!!!!!");
         } else if (temp_inside < temp_outside) {
            Serial.println("Its windy!");
            Serial.println("OPEN WINDOW!!!!!!!!!");
         } else {
            Serial.println("CLOSE WINDOW!!!!!!!!!");
         }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
      }
      else{
        Serial.println("LAST Else running!");
        }
   }
   delay(7000);

}// end loop
