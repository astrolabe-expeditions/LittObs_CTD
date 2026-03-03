/* Code for testing DS18B20 sensors
Instruction : 
- Change the pin number for startpin et ledpin if needed (and comment or uncomment pin setup in void setup)
- change the pin number for serial GPS if needed in the void setup
- upload the code on device and read and send command from serial monitor
*/

// pin declaration if needed
//const int ledpin = XX; 
const int startpin = 27;  // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5


// Library

//// if epaper v1
#include <GxEPD.h>                      // Epaper Screen
//#include <GxGDEW042T2/GxGDEW042T2.h>    // Epaper Screen 4.2" b/w
#include <GxGDEH029A1/GxGDEH029A1.h>    // Epaper Screen 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.h>     // epaper sceeen
#include <GxIO/GxIO.h>                  // epaper screen

//// if epaper v2
// #include <GxEPD2_BW.h> 
// #include <GxEPD2_3C.h> 


// fonts for both epaper
#include <Fonts/FreeMonoBold9pt7b.h>    // font for epaper sreen
#include <Fonts/FreeMonoBold12pt7b.h>   // font for epaper sreen
#include <Fonts/FreeMonoBold18pt7b.h>   // font for epaper sreen
#include <Fonts/FreeMonoBold24pt7b.h>   // font for epaper sreen


//SPI pin definitions pour ecran epaper V1
GxIO_Class io(SPI, /*CS=5*/ 0, /*DC=*/ 13, /*RST=*/ 10); // arbitrary selection of 17, 16  //SS remplacé par 0
GxEPD_Class display(io, /*RST=*/ 10, /*BUSY=*/ 4); // arbitrary selection of (16), 4

// spi pin definitons pour ecran V2
// GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=5*/ 0, /*DC=*/ 13, /*RST=*/ 25, /*BUSY=*/ 4)); // GDEM029T94, Waveshare 2.9" V2 variant


// définition pour les fonts ecran
const GFXfont* f1 = &FreeMonoBold9pt7b;
const GFXfont* f2 = &FreeMonoBold12pt7b;
const GFXfont* f3 = &FreeMonoBold18pt7b;
const GFXfont* f4 = &FreeMonoBold24pt7b;



int count = 0;


void setup() {
  // pin initialisation
  pinMode(startpin, OUTPUT);
  digitalWrite(startpin, HIGH);
  // pinMode(ledpin, OUTPUT);
  // digitalWrite(ledpin, HIGH);
  delay(1000);

  Serial.begin(115200);                        // communication PC 
  display.init();                              // enable display Epaper

  delay(500); //Take some time to open up the Serial Monitor and enable all things
  
  affichageintro1();       // texte d'intro et cadre initiale
  delay(3000);

  // on efface l'écran et affiche texte
  texte();
  delay(1000);


}




void loop() {

  countmessage();

  count ++; 

  delay(2000);

}



void affichageintro1(){                     // texte intro à l'allumage
  display.setRotation(3);
  display.fillScreen(GxEPD_WHITE);
  
  //titre
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f4);
  display.setCursor(25, 55  );
  display.println("SENSOCEAN ");

  //version
  display.setFont(f1);
  display.setCursor(30, 90);
  display.print("Num Serie :");display.println("XXXXXX");
  display.setCursor(30, 110);
  display.print("Ver Soft  :");display.print("YYYYYY");
 
  display.update();        // pour ecran V1
  //display.nextPage();  //  pour ecran V2 
}


void texte(){
  // on affiche le texte
  display.setRotation(3);

  display.fillScreen(GxEPD_WHITE);

  //titre
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f3);
  display.setCursor(25, 55 );
  display.println("  COUCOU ");

  display.update();

}



void countmessage(){                    
  display.setRotation(3);

  //display.fillScreen(GxEPD_WHITE);
  // Effacez la zone où se trouvent les valeurs numériques
  display.fillRect(30, 70, 100, 22, GxEPD_WHITE);

  //Affichez la nouvelle valeur numérique
  display.setFont(f1);
  display.setCursor(30, 90);
  display.print(count);
 
  //display.update();        // pour ecran V1
  //display.nextPage();  //  pour ecran V2 
  //display.updateWindow(30,70, 100, 22);

    // Définissez la fenêtre de rafraîchissement partiel
  display.setPartialWindow(30, 70, 130, 112);

  // Effectuez un rafraîchissement partiel de cette zone uniquement
  display.displayWindow();
}


