// C++ code
//

int pir1 = 2; // Primer sensor PIR conectado al pin digital 2
int pir2 = 5; // Segundo sensor PIR conectado al pin digital 5
int led = 3;  // LED conectado al pin digital 3
int zumbador = 4; // Zumbador piezoeléctrico conectado al pin digital 4

void setup() {
  pinMode(pir1, INPUT); // Configurar el primer sensor PIR como entrada
  pinMode(pir2, INPUT); // Configurar el segundo sensor PIR como entrada
  pinMode(led, OUTPUT); // Configurar el LED como salida
  pinMode(zumbador, OUTPUT); // Configurar el zumbador piezoeléctrico como salida
  Serial.begin(9600); // Iniciar la comunicación serial a 9600 bps
}

void loop() {
  if (digitalRead(pir1) == HIGH || digitalRead(pir2) == HIGH) { 
    // Si cualquiera de los dos sensores PIR detecta movimiento
    digitalWrite(led, HIGH); // Enciende el LED
    digitalWrite(zumbador, HIGH); // Enciende el zumbador piezoeléctrico
  } else {
    digitalWrite(led, LOW); // Apaga el LED
    digitalWrite(zumbador, LOW); // Apaga el zumbador piezoeléctrico
  }
}
