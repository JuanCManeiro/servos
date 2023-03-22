/*    	
         **   O programa debe ser reactivo ao potenciómetro, de maneira que se poida accionar 8 veces por segundo como moito.     **
         **   Maior frecuencia de accionamento pode reducir o tempo de vida das engranaxes internas. Comprovar se isto se cumple  **


                   Movemento dun ServoMotor a traves do movemento dun potenciometro.

      Practica para o entreno e aprendizaxe do uso da libreria <Servo.h> do ide de Arduino, na que aprendemos a utilizar
      un servomotor asociado a un potenciometro e facemos que siga o seu movemento de esquerda a dereita. 
      Utilizaremos a entrada Analoxica A5 para comunicacion entre o potenciometro e o arduino 
      Usaremos o pin 3 (PWM~) como entrada para o control do servo, a saida do arduino (coa que simularemos unha saida Analoxica)
      O servo debe ser alimentado a traves dunha bateria externa, eu optei polo uso de 4 pilas de 1,5v postas en Serie, importante para que 
        a montaxe funcione debemos conectar o negativo da bateria o GND de Arduino para que todos os negativos esten conectados, 
        debemos facer isto sempre que non alimentemos directamente dende o Arduino, que sera na maioria dos casos. 

      Autor: Juan Carlos Maneiro
      Data:  Marzo 2023

 */

#include <Servo.h>  //incluimos a librerias Servo.h xa incluida no IDE de Arduino

//Pin de control do servo
#define CTRL 3 // Definimos o control para a Saida 3 do Arduino

//Pin de lectura do potenciometro
#define POT A5 // Definimos o potenciometro en entrada Analoxica A5

     //Parece que non da problemas escribir despois da almofada ainda que non cambia de cor

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int angulo = 10; //Por que empezamos en 10?
int veloc = 500; //Tempo que tarda en recorrer o codigo e enviar a orde de movemento


void setup() {
  motor.attach(CTRL);
  Serial.begin(9600); //Activamos o monitor serie por se necesitamos sacar algunha informacion
  
}


void loop() {
  //Lectura do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180); // mapeamos o valor do angulo xa que o servo esta entre 0 e 180 e a placa arduino
                                         // danos valores entre 0 e 1023
  
  //Actualiza servo
  motor.write(angulo);
  delay(veloc); // usamos sempre variables definidas anteriormente asi en caso de modificacion non temos que vir o loop
  Serial.println(angulo);
}
