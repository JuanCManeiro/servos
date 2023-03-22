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
