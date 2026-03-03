/* OSO : Code for testing the blue robotic sensors : Bar 30 for pressure

This code will just send pressuree value every seconds
The 5v power will be set to on
The 12v power will be set to off
Led will be lighting
Buzzer will be cut
*/

// librairies
#include <Wire.h>
#include "MS5837.h"

// declare the sensors
MS5837 sensor_bar30;

// declare the pins
//const int buzzer = 26;
const int led = 25;        //25
const int start5v = 4;   // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5

float bar30_pressure, bar30_temp, bar30_depth, bar30_alt;


void setup() {   // setup is running just one at startup
  // define pin use for command sensor's power, led and buzzer
  pinMode(led, OUTPUT);         
  pinMode(start5v, OUTPUT);

  // configure the pins
  digitalWrite(led, HIGH);          // power on led
  digitalWrite(start5v, HIGH);      // power on 5V system


  // start serial console for communication between PC and ESP32
  Serial.begin(115200);
  Serial.println("Starting");
  
  // initialize I2C protocole
  Wire.begin();

  delay(250);

  bar30_init();

}

void loop() {  // this loop will run continuously
  
  bar30_measure();

  delay(1000);
}


void bar30_init(){
  // Initialize pressure sensor
  // Returns true if initialization was successful
  // We can't continue with the rest of the program unless we can initialize the sensor
  while (!sensor_bar30.init()) {
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");
    delay(5000);
  }
  
  sensor_bar30.setModel(MS5837::MS5837_30BA);
  sensor_bar30.setFluidDensity(1029); // kg/m^3 (freshwater, 1029 for seawater)
}


void bar30_measure(){
  // Update pressure and temperature readings
  sensor_bar30.read();

  bar30_pressure = sensor_bar30.pressure();
  bar30_temp = sensor_bar30.temperature();
  bar30_depth = sensor_bar30.depth();
  bar30_alt = sensor_bar30.altitude();

  Serial.print("Pressure: "); 
  Serial.print(bar30_pressure); 
  Serial.println(" mbar");
  
  Serial.print("Temperature: "); 
  Serial.print(bar30_temp); 
  Serial.println(" deg C");
  
  Serial.print("Depth: "); 
  Serial.print(bar30_depth); 
  Serial.println(" m");
  
  Serial.print("Altitude: "); 
  Serial.print(bar30_alt); 
  Serial.println(" m above mean sea level");

}