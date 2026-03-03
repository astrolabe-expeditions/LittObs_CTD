/* Code for testing BME280 sensors
Instruction : 
- Change the pin number for startpin et ledpin if needed (and comment or uncomment pin setup in void setup)
- change the pin number for serial GPS if needed in the void setup
- upload the code on device and read and send command from serial monitor
*/

// pin declaration if needed
//const int ledpin = 25; 
const int startpin = 27;  // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5



#include <Adafruit_BMP280.h>            // capteur de pression température atmosphérique

// déclaration pour capteur de pression (bmp280)
Adafruit_BMP280 bmp; // I2C Interface
float temp_ext;
float pres_ext;





void setup() {
  // pin initialisation
  pinMode(startpin, OUTPUT);
  digitalWrite(startpin, LOW);
  // pinMode(ledpin, OUTPUT);
  // digitalWrite(ledpin, HIGH);
  delay(1000);

  Serial.begin(115200);                        // communication PC 
  Wire.begin();                                // for I2C communication
}




void loop() {

  mes_pressure();

  Serial.print("Air temperature (°C): "); 
  Serial.println(temp_ext);

  Serial.print("Air presure (Hpa): "); 
  Serial.println(pres_ext);

  Serial.println(" ");
  
  delay(1000);

}





void mes_pressure(){                         // capteur meteo, température et pression de l'air
  // init sensor
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
  }
  
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
 delay(600);

 temp_ext = bmp.readTemperature(); 
 pres_ext = bmp.readPressure()/100 ; // pressure in Hpa

}