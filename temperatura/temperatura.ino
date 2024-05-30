#include <DHT.h>

#define DHTPIN 5     // Pin al que está conectado el sensor DHT11
#define DHTTYPE DHT11   // Define el tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

int buzzer = 4;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); // Inicializar la comunicación serial
  dht.begin(); // Inicializar el sensor DHT11
}

void loop() {
  float temperatura = dht.readTemperature(); // Leer la temperatura en grados Celsius

  // Verificar si hubo un error al leer el sensor
  if (isnan(temperatura)) {
    Serial.println("Error al leer del sensor DHT11!");
    return;
  }

  delay(1000); // Espera de un segundo entre lecturas
  Serial.print("Temperatura : ");
  Serial.print(temperatura);
  Serial.println(" °C"); // Imprimir la temperatura en el monitor serial

  if (temperatura <= 20) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW); // Apagar el buzzer si la temperatura es mayor a 20
  }
}
