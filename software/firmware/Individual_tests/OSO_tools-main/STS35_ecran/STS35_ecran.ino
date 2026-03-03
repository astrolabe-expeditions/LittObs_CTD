#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "DFRobot_STS3X.h"
#include <Adafruit_BMP280.h>            // capteur de pression température atmosphérique
#include <DallasTemperature.h>          // pour capteur ds18b20

// spi pin definitons pour ecran V2
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=5*/ 0, /*DC=*/ 13, /*RST=*/ 10, /*BUSY=*/ 4)); // GDEM029T94, Waveshare 2.9" V2 variant
U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

// declaration pour STS35
DFRobot_STS3X sts(&Wire, 0x4B);
float T_air;


// déclaration pour capteur de pression (bmp280)
Adafruit_BMP280 bmp; // I2C Interface
float temp_ext;
float pres_ext;

//déclaration pour capteur de température interne ds18b20
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temp_water;



void setup()
{
  Serial.begin(1150200);
  Wire.begin();                                // for I2C communication

  // initialisation STS35
  while(sts.begin() != true){
    Serial.println("Failed to init chip, please check if the chip connection is fine. ");
    delay(1000);
  }
  sts.setFreq(sts.e10Hz);

  // initilisation ecran
  display.init();
  u8g2Fonts.begin(display); // connect u8g2 procedures to Adafruit GFX

  Serial.println("STS35 + screen = ok");
  delay(1000);
}

void loop()
{
  T_air = sts.getTemperaturePeriodC();
  mes_pressure();
  mes_temp_water();

  display.fillScreen(GxEPD_WHITE);
  displayValues();

  delay(1000);  
}


void displayValues()
{
  
  float number;
  float number2; 
  float number3;
  float number4;
  float number5; 
  float number6;
  number = T_air;
  number2 = temp_ext;
  number3 = pres_ext;
  number4 = temp_water;
  number5 = 20;
  number6 = 25;
  

  display.setRotation(1); // 0--> No rotation ,  1--> rotate 90 deg
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = GxEPD_BLACK;
  u8g2Fonts.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);            // left to right (this is default)
  u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(bg);         // apply Adafruit GFX color
  //u8g2Fonts.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here:  https://github.com/olikraus/u8g2/wiki/fntlistall

  u8g2Fonts.setFont(u8g2_font_logisoso16_tr); //u8g2_font_logisoso32_tn--->numbers only to save memory ; u8g2_font_logisoso32_tr , u8g2_font_logisoso32_tf -->numbers&letters
  
  uint16_t x = 195;
  uint16_t y = 20;
  display.setPartialWindow(0, 0, display.width(), 296); //this sets a window for the partial update, so the values can update without refreshing the entire screen.
  display.firstPage();
  do
  {
    display.fillScreen(bg);

    // Display A0 value
    u8g2Fonts.setCursor(5, y); 
    u8g2Fonts.print("AIR : Tsts35(C)   :");
    u8g2Fonts.setCursor(x, y);
    u8g2Fonts.println(number,2);
  
    // Display Voltage of A0
    u8g2Fonts.setCursor(5, y +20);
    u8g2Fonts.print("AIR : Tbmp280(C)  :");
    u8g2Fonts.setCursor(x, y + 20);
    u8g2Fonts.println(number2,2);

    // Display Pressure
    u8g2Fonts.setCursor(5, y +40);
    u8g2Fonts.print("AIR : Pbmp280(hpa):");
    u8g2Fonts.setCursor(x, y + 40);
    u8g2Fonts.println(number3,2);

    // Display water temp
    u8g2Fonts.setCursor(5, y +60);
    u8g2Fonts.print("EAU :Tds18b20(C):");
    u8g2Fonts.setCursor(x, y + 60);
    u8g2Fonts.println(number4,2);

    // Display water EC
    u8g2Fonts.setCursor(5, y +80);
    u8g2Fonts.print("EAU :value5():");
    u8g2Fonts.setCursor(x, y + 80);
    u8g2Fonts.println(number5,2);

    // Display water EC
    u8g2Fonts.setCursor(5, y +100);
    u8g2Fonts.print("EAU :value6():");
    u8g2Fonts.setCursor(x, y + 100);
    u8g2Fonts.println(number6,2);
  }
  while (display.nextPage());
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


void mes_temp_water(){                         // température interne du boitier 
  sensors.begin();
  delay(500);
  sensors.requestTemperatures(); // Send the command to get temperatures 
  temp_water= sensors.getTempCByIndex(0);
  Serial.print("Temperature : ");
  Serial.println(temp_water, 3);   // We use the function ByIndex, and as an example get the temperature from the first sensor only.
    
}
