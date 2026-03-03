/* Code for testing DS18B20 sensors
Instruction : 
- Change the pin number for startpin if needed 
- upload the code on device and read and send command from serial monitor
*/

// pin declaration if needed
// led = 25 sur LO
const int startpin = 4; // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5


#include <DallasTemperature.h>          // pour capteur ds18b20

//déclaration pour capteur de température interne ds18b20
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float tempint;


void setup() {
  // pin initialisation
  pinMode(startpin, OUTPUT);
  digitalWrite(startpin, HIGH);

  delay(1000);

  Serial.begin(115200);                        // communication PC 

}



void loop() {

  mes_temp_int();

  delay(1000);

}



void mes_temp_int(){                         // température interne du boitier 
  sensors.begin();
  delay(500);
  sensors.requestTemperatures(); // Send the command to get temperatures 
  tempint = sensors.getTempCByIndex(0);
  Serial.print("Temperature : ");
  Serial.println(tempint, 3);   // We use the function ByIndex, and as an example get the temperature from the first sensor only.
    
}

