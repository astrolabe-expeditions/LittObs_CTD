#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#include <U8g2_for_Adafruit_GFX.h>

// #if defined(__AVR)
// #define MAX_DISPLAY_BUFFER_SIZE 800 
// #define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))
// GxEPD2_BW<GxEPD2_290, MAX_HEIGHT(GxEPD2_290)> display(GxEPD2_290(/*CS=10*/ 0, /*DC=*/ 13, /*RST=*/ 10, /*BUSY=*/ 4));
// #endif
int i=0;

// spi pin definitons pour ecran V2
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=5*/ 0, /*DC=*/ 13, /*RST=*/ 10, /*BUSY=*/ 4)); // GDEM029T94, Waveshare 2.9" V2 variant

U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

void setup()
{
  display.init();
  u8g2Fonts.begin(display); // connect u8g2 procedures to Adafruit GFX
  delay(1000);
}

void loop()
{
  display.fillScreen(GxEPD_WHITE);
  displayValues();
  i=i+1;
  delay(1000);  
}


void displayValues()
{
  
  float number; //A0 Value
  float number2; // A0 Value converted to voltage
  number = i;
  number2 = number/2* 5;
  

  display.setRotation(1); // 0--> No rotation ,  1--> rotate 90 deg
  uint16_t bg = GxEPD_WHITE;
  uint16_t fg = GxEPD_BLACK;
  u8g2Fonts.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2Fonts.setFontDirection(0);            // left to right (this is default)
  u8g2Fonts.setForegroundColor(fg);         // apply Adafruit GFX color
  u8g2Fonts.setBackgroundColor(bg);         // apply Adafruit GFX color
  //u8g2Fonts.setFont(u8g2_font_helvR14_tf);  // select u8g2 font from here:  https://github.com/olikraus/u8g2/wiki/fntlistall

  u8g2Fonts.setFont(u8g2_font_logisoso32_tr); //u8g2_font_logisoso32_tn--->numbers only to save memory ; u8g2_font_logisoso32_tr , u8g2_font_logisoso32_tf -->numbers&letters
  
  uint16_t x = 150;
  uint16_t y = 50;
  display.setPartialWindow(0, 0, display.width(), 296); //this sets a window for the partial update, so the values can update without refreshing the entire screen.
  display.firstPage();
  do
  {
    display.fillScreen(bg);

    // Display A0 value
    u8g2Fonts.setCursor(90, y); 
    u8g2Fonts.print("A0:");
    u8g2Fonts.setCursor(x, y);
    u8g2Fonts.println(number,1);
  
   // Display Voltage of A0
   u8g2Fonts.setCursor(50, y +40);
    u8g2Fonts.print("Volts:");
   u8g2Fonts.setCursor(x, y + 40);
   u8g2Fonts.println(number2,1);
  }
  while (display.nextPage());
}