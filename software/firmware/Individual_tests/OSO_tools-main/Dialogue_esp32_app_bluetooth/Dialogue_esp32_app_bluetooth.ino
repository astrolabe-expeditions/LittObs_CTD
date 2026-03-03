#include "BluetoothSerial.h"                                            // Librairie Bluetooth
#include <DS3231.h>                                                     // Librairie RTC DS3231
#include <Wire.h>                                                       // Librairie I2C

BluetoothSerial SerialBT;                                               // Objet BluetoothSerial

int test = 0;

DS3231 rtc;                                                             // Objet DS3231

void setup() {
  Serial.begin(115200);                                                 // Init communication série 
  Wire.begin();                                                         // Init communication I2C                                         

  if (!SerialBT.begin("ESP32_LAMOS_3")) {                               // Init Bluetooth
    Serial.println("Erreur init Bluetooth");                          
    return;
  } else {
    Serial.println("Bluetooth activé");  
  }
}

void loop() {                                                          

  /* ENVOI BLUETOOTH */
  test++;
  SerialBT.println("compteur : " + String(test));
  Serial.println("compteur : " + String(test));
  delay(1000);    

  /* RECEPTION BLUETOOTH */
  if (SerialBT.available()) {                                           // Si données disponibles via Bluetooth
    String receivedMessage = SerialBT.readStringUntil('\n');            // Lecture message 
    uint64_t sleepDuration = strtoull(receivedMessage.c_str(),NULL,10); // Conversion durée reçue en uint64_t
    if (sleepDuration == 0 && receivedMessage != "0") {                 // Si erreur conversion
      Serial.println("Erreur conversion durée");                        
      SerialBT.println("Erreur conversion durée");                      
      return;
    }
    SerialBT.println("Durée deep sleep (s) : " + String(sleepDuration));// Envoie bluetooth  
    Serial.println("Durée deep sleep (s) : " + String(sleepDuration));  
  }
  delay(1000);                                                           
}

