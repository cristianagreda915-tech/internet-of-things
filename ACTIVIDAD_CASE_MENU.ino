#define BUTTON 2
#define RED 13
#define YELLOW 11
#define GREEN 9

int estado = 0;
int estadoAnterior = -1;  // ← NUEVO: para detectar cambio de estado
bool ultimoBoton = HIGH;
unsigned long tiempoAnterior = 0;
int intervalo = 500;
bool parpadeo = false;

int estadoSemaforo = 0;
unsigned long tiempoSemaforo = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  bool lectura = digitalRead(BUTTON);

  if (lectura == LOW && ultimoBoton == HIGH) {
    estado++;
    if (estado > 4) estado = 0;
    delay(200);
  }
  ultimoBoton = lectura;

  // ← NUEVO: al entrar al modo semáforo, reinicia desde ROJO
  if (estado == 4 && estadoAnterior != 4) {
    estadoSemaforo = 0;
    tiempoSemaforo = millis();
  }
  estadoAnterior = estado;

  if (millis() - tiempoAnterior > intervalo) {
    tiempoAnterior = millis();
    parpadeo = !parpadeo;
  }

  switch (estado) {
    case 0:
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, LOW);
      break;
    case 1:
      digitalWrite(GREEN, parpadeo);
      digitalWrite(YELLOW, parpadeo);
      digitalWrite(RED, parpadeo);
      break;
    case 2:
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, parpadeo);
      break;
    case 3:
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, LOW);
      break;
    case 4:
      switch (estadoSemaforo) {
        case 0: // 🔴 ROJO
          digitalWrite(RED, HIGH);
          digitalWrite(YELLOW, LOW);
          digitalWrite(GREEN, LOW);
          if (millis() - tiempoSemaforo >= 3000) {
            tiempoSemaforo = millis();
            estadoSemaforo = 1;
          }
          break;
        case 1: // 🟡 AMARILLO
          digitalWrite(RED, LOW);
          digitalWrite(YELLOW, HIGH);
          digitalWrite(GREEN, LOW);
          if (millis() - tiempoSemaforo >= 1000) {
            tiempoSemaforo = millis();
            estadoSemaforo = 2;
          }
          break;
        case 2: // 🟢 VERDE
          digitalWrite(RED, LOW);
          digitalWrite(YELLOW, LOW);
          digitalWrite(GREEN, HIGH);
          if (millis() - tiempoSemaforo >= 3000) {
            tiempoSemaforo = millis();
            estadoSemaforo = 3;
          }
          break;
        case 3: // 🟡 AMARILLO (antes de rojo)
          digitalWrite(RED, LOW);
          digitalWrite(YELLOW, HIGH);
          digitalWrite(GREEN, LOW);
          if (millis() - tiempoSemaforo >= 1000) {
            tiempoSemaforo = millis();
            estadoSemaforo = 0;
          }
          break;
      }
      break;
  }
}