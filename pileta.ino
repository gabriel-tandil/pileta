/*
  controlador de bombas y luces de pileta
*/

//definiciones de pines
const int BOMBA_1 =  13;      // the number of the LED pin
//intervalos
const long intervaloBomba1 = 300000;        // interval para conmutar la bomba milisegundos (5 minutos)


// Variables de estados
int estadoBomba1 = HIGH;             // quiero que arranque encendida


unsigned long previousMillisBomba1 = 0;    // ultimo milisegundos en que se cambio el estado


void setup() {
  // set the digital pin as output:
  pinMode(BOMBA_1, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisBomba1 >= intervaloBomba1) {
    previousMillisBomba1 = currentMillis;

    // si la bomba esta apagada la enciendo y viceversa:
    if (estadoBomba1 == LOW) {
      estadoBomba1 = HIGH;
    } else {
      estadoBomba1 = LOW;
    }
    digitalWrite(BOMBA_1, estadoBomba1);
  }
}
