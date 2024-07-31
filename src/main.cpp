/*
   Exemplo simples demonstrando as funções básicas de medição de temperatura, pressão e umidade
*/
#include <Arduino.h>     // Incluindo a biblioteca
#include <GyverBME280.h> // Incluindo a biblioteca
GyverBME280 bme;         // Criando o objeto bme

float calculateAltitude(float nivelsolo)
{
  float pressaoatual = bme.readPressure() / 100.0F;
  float altitude = 44330.0 * (1.0 - pow(pressaoatual / nivelsolo, 0.1903)); // Calculation for altitude in meters
  return altitude;
}

void setup()
{
  Serial.begin(115200); // Iniciando a porta serial
  // bme.begin();          // Se configurações adicionais não são necessárias - inicializamos o sensor
  bme.begin(0x76); // Se configurações adicionais não são necessárias - inicializamos o sensor
  // bme.begin(0x77);          // Se configurações adicionais não são necessárias - inicializamos o sensor
}

void loop()
{
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature()); // Mostrando a temperatura em [*C]
  Serial.println(" *C");

  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity()); // Mostrando a umidade em [%]
  Serial.println(" %");

  float pressure = bme.readPressure(); // Lendo a pressão em [Pa]
  Serial.print("Pressure: ");
  Serial.print(pressure / 100.0F); // Mostrando a pressão em [hPa]
  Serial.print(" hPa , ");
  Serial.print(pressureToMmHg(pressure)); // Mostrando a pressão em [mm Hg]
  Serial.println(" mm Hg");
  Serial.print(calculateAltitude(1013.25F)); // Mostrando a altitude em relacao ao nivel do mar
  Serial.println(" Meters");

  delay(1000);
}
