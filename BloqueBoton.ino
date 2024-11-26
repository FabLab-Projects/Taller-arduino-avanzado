
//-----------------------------------------------------------------------BLOQUE DE BOTON----------------------------------------------------------------------------------------------------------------------------------------------
unsigned long t1; // temporizador
boolean estado = false; // estado booleano controlado por el boton 

void setup() {
  Serial.begin(9600);//comunicacion serial
  attachInterrupt(digitalPinToInterrupt(2), interruption, RISING); // defino que si ocurre una interrupcion en el pin 2 de tipo RISING, ejecuto la funcion interruption
}

//Funcion que se ejecuta cuando se presiona el boton
void interruption(){
  //El estado pasa de true a false o de false a true dependiendo del estado anterior
  if (estado == false){
    estado = true;
  }
  else{
    estado = false;
  }
}

void loop() {
  // Printeo del estado
  if (millis()-t1 >=1000){
    Serial.println(estado);
    t1 = millis();
  } 
}
