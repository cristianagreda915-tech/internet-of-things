int LED1 = 13;
int LED2 = 11;
int LED3 = 9;
int LED4 = 7;
int LED5 = 5;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {

  for (int numero = 0; numero <= 20; numero++) {

    // AZUL (1)
    if (numero & 1)
      digitalWrite(LED1, HIGH);
    else
      digitalWrite(LED1, LOW);

    // NARANJA (2)
    if (numero & 2)
      digitalWrite(LED2, HIGH);
    else
      digitalWrite(LED2, LOW);

    // VERDE (4)
    if (numero & 4)
      digitalWrite(LED3, HIGH);
    else
      digitalWrite(LED3, LOW);

    // AMARILLO (8)
    if (numero & 8)
      digitalWrite(LED4, HIGH);
    else
      digitalWrite(LED4, LOW);

    // ROJO (16)
    if (numero & 16)
      digitalWrite(LED5, HIGH);
    else
      digitalWrite(LED5, LOW);

    delay(1000);
  }

  // Apagar todo al terminar
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);

  delay(4000);
}
