/**
 * DHT11 Temperature Reader
 * This sketch reads temperature data from the DHT11 sensor and prints the value to the serial port.
 * It also handles potential error states that might occur during reading.
 *
 * Author: Dhruba Saha
 * Version: 2.1.0
 * License: MIT
 */

// Include the DHT11 library for interfacing with the sensor.
#include <DHT11.h>
#include <Wire.h> // Biblioteca utilizada para fazer a comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca utilizada para fazer a comunicação com o display 20x4 

#define col 16 // Serve para definir o numero de colunas do display utilizado
#define lin  2 // Serve para definir o numero de linhas do display utilizado
#define ende  0x27 // Serve para definir o endereço do display.

LiquidCrystal_I2C lcd(ende,col,lin); // Chamada da funcação LiquidCrystal para ser usada com o I2C

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.
DHT11 dht11(5);

void setup() {
    // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
    Serial.begin(9600);

    lcd.init(); // Serve para iniciar a comunicação com o display já conectado
    lcd.backlight(); // Serve para ligar a luz do display
    lcd.clear(); // Serve para limpar a tela do display
    
    // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
    // dht11.setDelay(500); // Set this to the desired delay. Default is 500ms.
}

void loop() {
    // Attempt to read the temperature value from the DHT11 sensor.
    int temperature = dht11.readTemperature();
    int humidity = dht11.readHumidity();

    // Check the result of the reading.
    // If there's no error, print the temperature value.
    // If there's an error, print the appropriate error message.
    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
        Serial.print(" \t");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");

        lcd.setCursor(1,0); // Coloca o cursor do display na coluna 1 e linha 1
        lcd.print("Temp: "); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
        lcd.setCursor(7 ,0); //Coloca o cursor do display na coluna 1 e linha 2
        lcd.print(temperature);  // Comando de saida com a mensagem que deve aparecer na coluna 2 e linha 4
        lcd.setCursor(10,0); // Coloca o cursor do display na coluna 1 e linha 1
        lcd.print("C"); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
        lcd.setCursor(1,3); // Coloca o cursor do display na coluna 1 e linha 1
        lcd.print("Umid: "); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
        lcd.setCursor(7,3); // Coloca o cursor do display na coluna 1 e linha 1
        lcd.print(humidity); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
        lcd.setCursor(10,3); // Coloca o cursor do display na coluna 1 e linha 1
        lcd.print("%"); // Comando de saída com a mensagem que deve aparecer na coluna 2 e linha 1.
        delay(1500);  // delay de 5 segundos com todas as mensagens na tela
        lcd.clear(); // Limpa o display até o loop ser reiniciado 
    } else {
        // Print error message based on the error code.
        Serial.println(DHT11::getErrorString(temperature));
    }
}
