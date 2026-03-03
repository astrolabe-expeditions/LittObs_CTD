// LED test pour les instruments OSO 
// Led pin = 25 pour OSO-CTD >= 2.2


const int led_info = 25;


void setup() {
  Serial.begin(115200);
  
  pinMode(led_info, OUTPUT);
  digitalWrite(led_info, LOW);

  Serial.println("Start test");

}



void loop() {

  Serial.println("Go blink led -> ");

  digitalWrite(led_info, LOW);
  delay(500);
  digitalWrite(led_info, HIGH);
  delay(1000);
}


