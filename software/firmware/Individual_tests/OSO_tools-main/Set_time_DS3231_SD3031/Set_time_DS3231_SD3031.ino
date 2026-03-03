/*
Programme pour la mise à l'heure d'une horloge SD3031 ou DS3231: 
1- ouvrir dans un navigateur un serveur de temps, par exemple sur le site https://time.is
2 - charger le programme et ouvrir le moniteur serie
3 - choisir le type d'horloge quand la question est posé dans le moniteur serie
3 - Entrer la date au format YYYY-MM-DD HH:MM:SS
4 - Appuyer sur la touche entrée pour synchroniser (prévoir d'appuyer sur entrée 1s avant l'heure exacte (durée d'exécution du code)

Format date : 
Exemple : Taper 2023-06-20 15:23:45 pour mettre à la date du 20 juin 2023 à 15h23min45s"

*/



// Pour horloge RTC
#include <DS3231.h>
#include <DFRobot_SD3031.h>


// défintion pour SD3031
DFRobot_SD3031 rtc;
//char datetime[20];

int year_serial, month_serial, day_serial, hour_serial, minute_serial, second_serial;



// définiton pour DS3231

DS3231 Clock;
bool Century = false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

byte year, month, date, DoW, hour, minute, second;
//int state = 1; // 0 pour set time, 1 pour get time  

//int donnee; // données reçues sur la liaison série

String model; 

// si besoin selon les configurations des PCB
//const int led = 25;
const int en5v = 4; // 27 pour SensOcean, 4 pour Littobs <2.5, 14 pour Littobs >= 2.5


void setup() {
  Serial.begin(115200);

  // allumage led et composants 
  // pinMode(led, OUTPUT);
  // digitalWrite(led, HIGH);
  pinMode(en5v, OUTPUT);
  digitalWrite(en5v, HIGH);
  delay(1000);

  //Initilisation I2C pour rtc
  Wire.begin();

  Serial.println("--------------------------------------------- ");

  Serial.println("Pour synchroniser : entrer la date au format YYYY-MM-DD HH:MM:SS, et appuyer sur la touche entrée pour synchroniser 2s avant l'heure se synchronisation");
  Serial.println("(Exemple : Taper 2023-06-20 15:23:45 pour mettre à la date du 20 juin 2023 à 15h23min45s)");
  Serial.println("Vous trouverez l'heure exacte sur le site https://time.is, prévoir d'appuyer sur entrée 2s avant l'heure exacte (durée d'exécution du code)");
  Serial.println(" ");

  // choix du type d'horloge
  Serial.println("Quel modele d'horloge RTC est utilisé ? "); 
  Serial.println("1 - Pour les modèles de type DS3231 : taper 1 puis entrer");
  Serial.println("2 - Pour les modèles de type SD3031 : taper 2 puis entrer");

  while (!Serial.available()){
  }
  model = Serial.readStringUntil('\n');
  model.trim(); // Supprimer les espaces blancs en début et fin de la chaîne
  if (model == "1") {
    Serial.println("Modèle 1 : DS3231");
  } else if (model == "2") {
    Serial.println("Modèle 2 : SD3031");
    /*Wait for the chip to be initialized completely, and then exit*/
    while(rtc.begin() != 0){
        Serial.println("Failed to init chip, please check if the chip connection is fine. ");
        delay(1000);
    }
  } else {
    Serial.println("Modèle non reconnu");
    ESP.restart();
  }

  delay(1000);
}

void loop() {

  // si on reçoit une infos sur la liaison serie
  if (Serial.available()) {
    String userInput = Serial.readStringUntil('\n');
    
    if (userInput.length() > 0) {       // si la donné dans le buffer contient plus que le caractère entrée
      parseDateTime(userInput);         // on découpe la donnée en ces valeurs individuelles
      if (year_serial > 0 && month_serial > 0 && day_serial > 0 && hour_serial >= 0 && hour_serial < 24 && minute_serial >= 0 && minute_serial < 60 && second_serial >= 0 && second_serial < 60) {   // si le format est correct
            // Set time pour les deux cas      
            if (model == "1"){
              // Fonction de mise à l'heure de DS3231
              Serial.println("coucou on doit mettre à l'heure la DS3231 ici ");

              // set time
              Clock.setSecond(second_serial);//Set the second
              Clock.setMinute(minute_serial);//Set the minute
              Clock.setHour(hour_serial);  //Set the hour
              //Clock.setDoW(5);    //Set the day of the week
              Clock.setDate(day_serial);  //Set the date of the month
              Clock.setMonth(month_serial);  //Set the month of the year
              Clock.setYear(year_serial-2000);  //Set the year (Last two digits of the year)
              Clock.setClockMode(false); // pour avoir le format 24h
              Serial.println("Date et heure mises à jour avec succès !");

            } else if (model == "2") {
              Serial.println("toc toc mise à l'heure de SD3031");
              
              // fonction de mise à l'heure de SD3031
              if (year_serial > 0 && month_serial > 0 && day_serial > 0 && hour_serial >= 0 && hour_serial < 24 && minute_serial >= 0 && minute_serial < 60 && second_serial >= 0 && second_serial < 60) {
                rtc.setTime(year_serial, month_serial, day_serial, hour_serial, minute_serial, second_serial);
                Serial.println("Date et heure mises à jour avec succès !");
              } else {
                Serial.println("Format de date et heure invalide. Veuillez réessayer !");
              }
              

            }
            else {                             
              Serial.println("Modèle non reconnu - redémarrer le programme");
            }
          delay(500);
          
      } else {                         // si le format est incorrect
        Serial.println("Format de date et heure invalide. Veuillez réessayer !");
      }
    }
  }

  // si on recoit rien sur la liaison serie on affiche juste l'heure de l'horloge RTC toute les secondes
  else{
    if (model == "1") {
      read_time_DS3231();
    } else if (model == "2") {
      read_time_SD3031();
    } else {
      Serial.println("Modèle non reconnu");
    }
  
    delay(1000);
  }

}


void parseDateTime(String dateTimeString) {
  int parsedYear, parsedMonth, parsedDay, parsedHour, parsedMinute, parsedSecond;
  if (sscanf(dateTimeString.c_str(), "%d-%d-%d %d:%d:%d", &parsedYear, &parsedMonth, &parsedDay, &parsedHour, &parsedMinute, &parsedSecond) == 6) {
    year_serial = parsedYear;
    month_serial = parsedMonth;
    day_serial = parsedDay;
    hour_serial = parsedHour;
    minute_serial = parsedMinute;
    second_serial = parsedSecond;
  } else {
    year_serial = 0;
    month_serial = 0;
    day_serial = 0;
    hour_serial = 0;
    minute_serial = 0;
    second_serial = 0;
  }
}


void read_time_SD3031(){
    sTimeData_t sTime;
    sTime = rtc.getRTCTime();

    char datetime[20];

    sprintf(datetime, "%04d/%02d/%02d %02d:%02d:%02d", sTime.year, sTime.month, sTime.day, sTime.hour, sTime.minute, sTime.second);

    Serial.println(datetime);
}


void read_time_DS3231(){
    int second, minute, hour, date, month, year;

    // lecture de l'horloge rtc
    second = Clock.getSecond();
    minute = Clock.getMinute();
    hour = Clock.getHour(h12, PM);
    date = Clock.getDate();
    month = Clock.getMonth(Century);
    year = Clock.getYear();
    Serial.println("");
    Serial.print(year); Serial.print("/"); Serial.print(month); Serial.print("/"); Serial.print(date); Serial.print(" ");
    Serial.print(hour); Serial.print(":"); Serial.print(minute); Serial.print(":"); Serial.println(second);
    delay(1000);

}
