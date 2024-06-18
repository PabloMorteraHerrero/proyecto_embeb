#include <LiquidCrystal.h>

// Configuración de pines del LCD
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pir1 = 7;  // pin para el primer sensor PIR
int pir2 = 8;  // pin para el segundo sensor PIR
int zumbador = 6;  // pin para el zumbador (buzzer)
int led = 10;  //  pin para el LED

void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
  
  // Inicializar el LCD con 16 columnas y 2 filas
  lcd.begin(16, 2);
  
  // Inicializar los pines de los sensores PIR como entradas
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  
  // Inicializar el pin del zumbador y el LED como salidas
  pinMode(zumbador, OUTPUT);
  pinMode(led, OUTPUT);
  
  // Mensaje de inicio por serial
  Serial.println("Inicialización completa.");
}

void loop() {
  // Verificar estado de los sensores PIR
  if (digitalRead(pir1) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Movimiento en");
    lcd.setCursor(0, 1);
    lcd.print("Sensor 1");
    digitalWrite(zumbador, HIGH); // Encender el zumbador
    digitalWrite(led, HIGH); // Encender el LED
  } else if (digitalRead(pir2) == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Movimiento en");
    lcd.setCursor(0, 1);
    lcd.print("Sensor 2");
    digitalWrite(zumbador, HIGH); // Encender el zumbador
    digitalWrite(led, HIGH); // Encender el LED
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sin movimiento");
    digitalWrite(zumbador, LOW); // Apagar el zumbador
    digitalWrite(led, LOW); // Apagar el LED
  }
  
  delay(500); // Pequeña pausa para la legibilidad
  
  // Mostrar estado de los sensores por serial
  Serial.print("Estado PIR1: ");
  Serial.print(digitalRead(pir1));
  Serial.print(", Estado PIR2: ");
  Serial.println(digitalRead(pir2));
}
