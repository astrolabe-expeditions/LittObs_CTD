/* Code for testing DS18B20 sensors
Instruction : 
- Change the pin number for startpin et ledpin if needed (and comment or uncomment pin setup in void setup)
- change the pin number for serial GPS if needed in the void setup
- upload the code on device and read and send command from serial monitor
*/

// pin declaration if needed
//const int ledpin = XX;  //25 pour LO
const int startpin = 27; // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5

#include <SparkFunBQ27441.h>            // Batterie fuel gauge lipo babysister
#include <Wire.h>                       //enable I2C.

// Set BATTERY_CAPACITY to the design capacity of your battery.
const unsigned int BATTERY_CAPACITY = 3400; // e.g. 3400mAh battery


void setup() {
  // pin initialisation
  pinMode(startpin, OUTPUT);
  digitalWrite(startpin, HIGH);
  // pinMode(ledpin, OUTPUT);
  // digitalWrite(ledpin, HIGH);
  delay(1000);

  Serial.begin(115200);                        // communication PC 
  Wire.begin();                                // for I2C communication
  setupBQ27441();                              // for Lipo Babysister sparkfun lipo fuelgauge

}




void loop() {
  // Read battery stats from the BQ27441-G1A
  unsigned int soc = lipo.soc();  // Read state-of-charge (%)
  unsigned int volts = lipo.voltage(); // Read battery voltage (mV)

  Serial.print("State of charge (%) : "); 
  Serial.println(soc);

  Serial.print("Lipo Voltage (mV) :"); 
  Serial.println(volts);

  Serial.println("");


  delay(1000);

}


void setupBQ27441(void)
{
  // Use lipo.begin() to initialize the BQ27441-G1A and confirm that it's
  // connected and communicating.
  if (!lipo.begin()) // begin() will return true if communication is successful
  {
  // If communication fails, print an error message and loop forever.
    Serial.println("Error: Unable to communicate with BQ27441.");
    Serial.println("  Check wiring and try again.");
    Serial.println("  (Battery must be plugged into Battery Babysitter!)");
    while (1) ;
  }
  Serial.println("Connected to BQ27441!");
  
  // Uset lipo.setCapacity(BATTERY_CAPACITY) to set the design capacity
  // of your battery.
  lipo.setCapacity(BATTERY_CAPACITY);
}



