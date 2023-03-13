# servos
iniciacion a servomotores

/***
Proba

**/


#include <Servo.h>

#define CTRL 9 // DEFINIMOS o pin que usaremos para controlar o servo

Servo motor; //declaramos servo motor como un obxecto que imos usar, e de tipo servo
int veloc  = 500; //usaremolo para o delay
int veloc2 = 100; 

void setup(){
 motor.attach(CTRL); 
Serial.begin(9600); // por si necesitamos o monitor serie

}

void loop(){

  for (int i =0; i >= 180; i++){ //Move o servo entre 0º e 180º, de 5 en 5 º
    motor.write(i);
    delay(veloc);
    Serial.println("marcha _ ");

  }

delay(15*veloc); // move o servo entre 180º e 0º de 5 en 5º
 for(int i = 180; i >=0; i--){
   motor.write(i);
   delay(veloc2);
   Serial.println("retorno");

   
 }

}
