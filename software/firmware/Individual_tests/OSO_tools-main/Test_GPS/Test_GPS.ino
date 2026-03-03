/* Code for testing GPS 

Instruction : 
- Change the pin number for startpin et ledpin if needed (and comment or uncomment pin setup in void setup)
- change the pin number for serial GPS if needed in the void setup
- upload the code on device and read and send command from serial monitor
*/

// pin declaration if needed
//const int ledpin = XX; 
const int startpin = 27; // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5


#include <TinyGPS++.h>                       

TinyGPSPlus gps;                           
HardwareSerial Serial_GPS(1);                 

void setup()
{
    // pin initialisation
  pinMode(startpin, OUTPUT);
  digitalWrite(startpin, HIGH);
  // pinMode(ledpin, OUTPUT);
  // digitalWrite(ledpin, HIGH);
  delay(1000);

  Serial.begin(115200);
  Serial_GPS.begin(9600, SERIAL_8N1, 16, 17);
}

void loop()
{
  Serial.print("Latitude  : ");
  Serial.println(gps.location.lat(), 5);
  Serial.print("Longitude : ");
  Serial.println(gps.location.lng(), 4);
  Serial.print("Satellites: ");
  Serial.println(gps.satellites.value());
  Serial.print("Altitude  : ");
  Serial.print(gps.altitude.feet() / 3.2808);
  Serial.println("M");
  Serial.print("Time      : ");
  Serial.print(gps.time.hour());
  Serial.print(":");
  Serial.print(gps.time.minute());
  Serial.print(":");
  Serial.println(gps.time.second());
  Serial.println("**********************");

  smartDelay(1000);                                     

  if (millis() > 5000 && gps.charsProcessed() < 10)
    Serial.println(F("No GPS data received: check wiring"));
}

static void smartDelay(unsigned long ms)               
{
  unsigned long start = millis();
  do
  {
    while (Serial_GPS.available())
      gps.encode(Serial_GPS.read());
  } while (millis() - start < ms);
}


