//----------------------------------------------------------BLOQUE DE SENSOR DE ULTRASONIDO---------------------------------------------------------------------------------------------------------------------------------------------
// Se definen los pines de trig y echo
#define trig 11
#define eco 10
// Variables temporizadores
unsigned long t0, t2;
// variables para calculo de distancia
unsigned long T;
float d, v, d_min;

void setup() {
  Serial.begin(9600); // comunicacion serial
  pinMode(trig, OUTPUT); // define el pin como salida 
  pinMode(eco, INPUT); // define el pin como entrada 
  t0 = millis(); //Temporizador de pulso 
  t2 = millis(); // Temporizador de printeo
  d_min = INFINITY; // La distancia minima sera infinito en la primera iteracion
}

void loop() {

  digitalWrite(trig, HIGH); // Activa la emision pulso de ultrasonido
  if(millis() - t0 >= 1){
    t0 = millis(); // reinicia temporizador
    digitalWrite(trig, LOW); // Apaga emision de pulso
    T = pulseIn(eco, HIGH); // recibe la señal de echo del pulso de ultrasonido y registra el tiempo en MICROSEGUNDOS
  }
  //Calculo de distancia
  v = 34.3; // Velocidad del sonido en cm/ms
  d = (v*T)/2000; // Forumla para calcular la distancia en centimetros


  if (d < d_min){
    d_min = d; // si la distancia medida es menor que que la distancia minima anterior, se guarda la nueva
  }

  // printeo de la distancia
  if(millis()-t2 >= 1000){
    Serial.println(d_ref);
    t2 = millis();
    d_min = INFINITY;
  }

}
