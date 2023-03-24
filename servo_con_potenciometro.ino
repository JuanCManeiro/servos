/*                                        Práctica 25
                     
           Posicionamento dun servo empregando comunicación serie ou potenciometro.
           
  Nesta practica volvemos a empregar a libreria <Servo.h> do ide de Arduino, reutilizando a practica 24 engadiremos "orde = Serial.readStringUntil('\n');" 
  para podermonos comunicar co programa a traves do monitor serie co que lle daremos unha orde e servo se movera como lle digamos. O servo 
  moverase como lle digamos no monitor e durante o tempo que lle teñamos asignado o delay permanecera nesa posicion, unha vez lido o delay,volvera a posicion
  do potenciometro.
   Utilizaremos a entrada Analoxica A5 para comunicacion entre o potenciometro e o arduino 
      Usaremos o pin 3 (PWM~) como entrada para o control do servo, a saida do arduino (coa que simularemos unha saida Analoxica)
      O servo debe ser alimentado a traves dunha bateria externa, neste caso optei polo uso dunha placa fotovoltaica, importante para que 
      a montaxe funcione debemos conectar o negativo da bateria ao GND de Arduino para que todos os negativos esten conectados nun punto comun, 
      debemos facer isto sempre que non alimentemos directamente dende o Arduino, que sera na maioria dos casos.
       
       Empregaremos as seguintes ordes pola comunicación serie son: 
           (a) 'esquerda', (b) 'diagonal esquerda' = Desquerda, (c) 'centro', (d) 'diagonal dereita' = Ddereita, (e) 'dereita'
           (f) un número enteiro entre 0 e 180.
     
      Autor: Juan Carlos Maneiro
      Data:  Marzo 2023
            
                                        ************ */

#include <Servo.h> //incluimos a librerias Servo.h xa incluida no IDE de Arduino

//Pin de control do servo
#define CTRL 3 // Definimos o control para a Saida 3 do Arduino

//Pin de lectura do potenciometro
#define POT A5 // Definimos o potenciometro en entrada Analoxica A5

     //Parece que non da problemas escribir despois da almofada ainda que non cambia de cor

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int angulo = 10;
int veloc = 3000; // Tempo que tarda en facer o loop e redirixir o servo a nova posicion

String orde = "";

void setup() {
  motor.attach(CTRL); // definicion do ide para o control de servos segundo a biblioteca "obxecto".attach(pin)
  Serial.begin(9600); // activamos o monitor serie para poder comunicarnos e saber a posicion do servo en cada momento
}

void loop(){

if(Serial.available()){
  orde = Serial.readStringUntil('\n');                     // a \/ para un lado ou para o outro fai que as ordes de movemento do servo vaian
  if(orde.equals("esquerda")){angulo = 180; }              // polo lado do movemento que ten ou polo lado contrario, por eso se lle decimos 
  else if(orde.equals("Desquerda")){angulo = 135;}         // que "centro" vai para un extremo, porque tenta ir ao centro 
  else if(orde.equals("centro")){angulo = 90;}             // do lado contrario e o servo so se move en 180º
  else if(orde.equals("Ddereita")){angulo = 45;}
  else if(orde.equals("dereita")){angulo = 0;}
  else{
  int temp = orde.toInt();                      //cambio temp por tmp en 4 sitios_ sen cambios... xa descubrin porque non o facia, temp esta definido aqui
    if(temp >= 0 && temp <= 180) angulo = temp; // o modificalo en todos os sitios no afecta o resultado, si afecta si o movo nun so sitio
                                                // cando necesitamos definir unha variable dun so uso podemos facelo en calquera sitio
                                                // ainda que por norma mellor sempre as definicions sempre o inicio para mais claridade
                                                // na lectura do codigo
    else angulo = 0; 
    
  } 
}
  else{
    // Lectura do potenciometro
    angulo = analogRead(POT);
    angulo = map(angulo, 0, 1023, 0, 180);// mapeamos o valor do angulo xa que o servo esta entre 0 e 180 e a placa arduino
                                         // danos valores entre 0 e 1023
  
}
  //Actualiza servo
  motor.write(angulo);
  delay(veloc); // usamos sempre variables definidas anteriormente asi en caso de modificacion non temos que vir o loop
  Serial.println(angulo); 
  //delay(lectura);
    
}

