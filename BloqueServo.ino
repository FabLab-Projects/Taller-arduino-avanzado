//---------------------------------------BLOQUE PARA GIRO DE SERVOMOTOR------------------------------------------------------------------------------------------------
// Libreria de servo
#include <Servo.h>
// Definicion de pin que se utiliza para servo
#define pinServo 7
// Declaración de objeto calse servomotor (Interfaz)
Servo servoMotor;

// variables
int angulo; // variable de angulos
unsigned long t1; // temporizador
boolean horario = false; // variable que define el sentido de giro horario o antihorario

void setup() {
  Serial.begin(9600);
  servoMotor.attach(pinServo); // conecta el servomotor al pin definido
  angulo = 0;// el angulo inicial sera 0 grados
  servoMotor.write(0);// funcion para mover el servomotor con el angulo deseado| El angulo que se da de argumento debe ser "int" de 0 a 180
  t1 = millis(); // temporizador 
  
}

void loop() {
  //------------------------------------------------------------------------Definicion del modo-------------------------------------------------------------------------------------------------------------------------------------------------
  // Condicion para pasar de antihorario a horario
  if (angulo > 180){
    horario = true; // modo en sentido horario
    angulo = 180; // para volver a un valor valido de angulo se vuelve a 180 grados
  }
  // Condicion para pasar de  horario a antihorario
  else if (angulo < 0){
    horario = false; //modo en sentido antihorario
    angulo = 0; // para volver a un valor valido se vuelve a 0 grados
    delay(5000);
  }
//------------------------------------------------------------------------Giro del servomotor-------------------------------------------------------------------------------------------------------------------------------------------------
  //Giro ANTIHORARIO
  if ((millis()-t1 >= 10)&&(horario == false)){
    servoMotor.write(angulo); // se mueve el servomotor al angulo dado
    angulo++; //aumenta en 1 el angulo
    t1 = millis(); //Reinicia temporizador

  }
  //Giro HORARIO
  else if ((millis()-t1 >= 10)&&(horario == true)){
    servoMotor.write(angulo); // se mueve el servomotor al angulo dado
    angulo--; // disminuye en 1 el angulo 
    t1 = millis(); // reinicia temporizador
  }

}
