/******************************************************************
AUTOR: PETR KYNČL
VERZE: 1.00
DATUM: 11.4.2020
POPIS: Sumo-model
*****************************************************************/

#include <Servo.h>

#define trigPin 9
#define echoPin 8
#define int1 5
#define int2 4
#define int3 2
#define int4 3

Servo servo;

int senzor(void);
int pohyb(int);
int distance =0;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  
  servo.attach(10);
}

void loop() {
  distance= senzor();
  pohyb(distance);
}

    
int senzor(void){
  long duration;
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;

  return distance;
}

int pohyb(int distance){
  if(distance>=30){
    //motor A
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    //motorB
    digitalWrite(int3,LOW);
    digitalWrite(int4,HIGH);
   
   servo.write(100);
   }
   else if(distance<30){
    //motor A
    digitalWrite(int1,HIGH);
    digitalWrite(int2,LOW);
    //motorB
    digitalWrite(int3,HIGH);
    digitalWrite(int4,LOW);
    
    servo.write(10);
    }                       
}
