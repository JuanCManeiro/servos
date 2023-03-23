// Espazo para a Practica 25

                         Práctica 25
  Posicionamento dun servo empregando comunicación serie.

Obxectivos:

    Identificar pins E analóxicas en Arduino
    Empezar a programar en Sketch (C++ de Arduíno).
    Comprender a lectura dun valor analóxico en Arduíno.
    Instalar e usar librerías proporcionadas por fabricantes ou a comunidade.
    Usar comunicacións serie para obter informacións da placa Arduíno.
    Usar comunicacións serie para suministrar ordes á placa Arduíno.

Descrición:
Reutiliza a montaxe da práctica anterior e parte do código da mesma, para engadir reactividade á comunicación serie.
O programa debe ser, igual que na práctica anterior, reactivo ao potenciómetro, pero ademais, se existe unha orde en forma de texto na entrada serie,
débese priorizar a orde lida. É dicir, compróbase a entrada serie, se hai entrada execútase, se non existe orde en forma de texto, 
posiciónase o servo onde indique o potenciómetro. A diferenza da práctica anterior, o servo só se pode accionar un máximo de 0.25 veces por segundo.
As ordes que se poden admitir por comunicación serie son: 
   (a) 'esquerda', (b) 'diagonal esquerda', (c) 'centro', (d) 'diagonal dereita', (e) 'dereita', ou ben (f) un número enteiro entre 0 e 180.

Tarefa a realizar:
    Fai en TinkerCAD a montaxe que se indica no enunciado.
    Realiza en Sketch (C++ de Arduíno) o programa que controla a montaxe.
    Crea no proxecto 'Servos' en GitHub un arquivo 'servo_monitor_serie.ino' e sube o texto do probrama.
    Modifica o texto que subiches ao GitHub, para que na parte superior do programa apareza un único comentario que abarque varias 
    liñas (empeza en '/*' e remata en '*/'). Nese comentario debes pór (a) un título explicativo da práctica,
(b) un texto máis extenso que explique cun pouco máis de detalle o que fai, menciona os números de pin de entradas e de saídas, 
(c) unha nova liña separada do texto anterior, co nome do autor, e (d) outra liña, coa data de creación do programa.
    Engade comentarios de liña, para explicar que fai cada parte do código.
      Entrega da tarefa:
      Debes entregar e subir á aula virtual:
          Pantallazo da montaxe,
          A URL da túa simulación, 
          A URL do código subido a GitHub.
            
            
            /*
 
 */

#include <Servo.h>

//Pin de control do servo
#define CTRL 3

//Pin de lectura do potenc
#define POT A5

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int angulo = 10;
int veloc = 3000; // Tempo que tarda en facer o loop e redirixir o servo a nova posicion

String orde = "";

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop(){

if(Serial.available()){
  orde = Serial.readStringUntil('\n');                     // a \/ para un lado ou para o outro fai que as ordes de movemento do servo vaian
  if(orde.equals("esquerda")){angulo = 180; }              // polo lado do movemento que ten ou polo lado contrario, por eso se lle decimos 
  else if(orde.equals("Desquerda")){angulo = 135;} // que "centro" vai para un extremo, porque tenta ir ao centro 
  else if(orde.equals("centro")){angulo = 90;}             // do lado contrario e o servo so se move en 180º
  else if(orde.equals("Ddereita")){angulo = 45;}
  else if(orde.equals("dereita")){angulo = 0;}
  else{
  int temp = orde.toInt();
    if(temp >= 0 && temp <= 180) angulo = temp;
    else angulo = 0;
    
  }
    
 
}
  else{
    // Lectura do potenciometro
    angulo = analogRead(POT);
    angulo = map(angulo, 0, 1023, 0, 180);
  
  

}
  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
  Serial.println(angulo); 
  //delay(lectura);
  
  
}

/*/void loop() {
  //Lectura do potenciometro
  angulo = analogRead(POT);
  angulo = map(angulo, 0, 1023, 0, 180);
  //Actualiza servo
  motor.write(angulo);
  delay(veloc);
}

**/
