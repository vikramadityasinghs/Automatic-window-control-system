#include <dht.h>
#include<Servo.h>
#define dht1_apin A1
#define dht2_apin A2
#define rainfall A4

//defining DHT sensor

dht DHT1_inside;
dht DHT2_outside;

//defining LDR pins 

const int ldr2Pin = A5;
const int ldr1Pin = A0;

Servo myservo;

int value;
int set = 900;
int windowstatus = 1;

void setup() {

   Serial.begin(9600);
   delay(500); //Delay to let system boot

   pinMode(ldr1Pin, INPUT);
   pinMode(ldr2Pin, INPUT);

   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);

   pinMode(rainfall, INPUT);
   Serial.println("AUTOMATIC WINDOW SYSTEM\n\n");
   myservo.attach(10);
   delay(1000);

}

void openWindow(){
 if(windowstatus==0){
Serial.println("KHULI");
myservo.write(2);
delay(550);
myservo.write(90);
windowstatus = 1;
delay(5000);
}  
  else{
  }
}

void closewindow(){
  if(windowstatus==1){
windowstatus=0;  
Serial.println("BAND");
myservo.write(178);
delay(550);
myservo.write(90);


delay(5000);
  }
  else{
}
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
      Serial.println("CLOSE WINDOW! value<set");
      closewindow();

   } else {

//Temp sensor code

      if (temp_inside > temp_outside) {
            Serial.println("AC is running!");
            Serial.println("CLOSE WINDOW!");
            closewindow();
         } 
         else if (temp_inside < temp_outside) {
            Serial.println("Its windy!");
            Serial.println("OPEN WINDOW! temp outside >");
            openWindow();
         } 
         else{    
//          LDR code
      if (ldr1_outside > ldr2_inside) {
         Serial.println("Sun is shining!");
         Serial.println("OPEN WINDOW! ldr outside >");
         openWindow();
         Serial.println(windowstatus);
      
         
      }
      else if (ldr1_outside < ldr2_inside) {
         Serial.println("Enough Light");
         Serial.println("CLOSE WINDOW!!!!!!!!!");
         closewindow();
         Serial.println(windowstatus);
      }
      else{}
         }
        
//Temp sensor code
       
  
//      else{
//        Serial.println("LAST Else running!");
//        }
   }
   Serial.println(ldr1Pin);
   delay(10000);

}// end loop
