//const int LED1 = 13;  
#define LED1 13
#define LED2 11
#define LED3 9


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {

  // ROJO
  digitalWrite(LED1, HIGH);   // Rojo ON
  digitalWrite(LED2, LOW);    // Amarillo OFF
  digitalWrite(LED3, LOW);    // Verde OFF
  delay(5000);                // 5 segundos

  // AMARILLO
  digitalWrite(LED1, LOW);    
  digitalWrite(LED2, HIGH);   
  digitalWrite(LED3, LOW);    
  delay(2000);                // 2 segundos

  // VERDE
  digitalWrite(LED1, LOW);    
  digitalWrite(LED2, LOW);    
  digitalWrite(LED3, HIGH);   
  delay(5000);    
  
   // AMARILLO
  digitalWrite(LED1, LOW);    
  digitalWrite(LED2, HIGH);   
  digitalWrite(LED3, LOW);    
  delay(2000);              // 5 segundos
}