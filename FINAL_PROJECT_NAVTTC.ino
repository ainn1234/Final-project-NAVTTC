#define RELAY //RELAY
#include <DHT.h> //DHT11
#include <DHT_U.h>
#include <LiquidCrystal.h> //LCD
DHT dht(A0, DHT11);
LiquidCrystal lcd(2,3,4,5,6,7);
int sensor = A0;
int trigger_pin = 2;  //ULTRASONIC
int echo_pin = 3;
int buzzer_pin = 10; 
int time;
int distance;

int sensor_pin = 8;  //AUTOMATIC DOOR
int relay_pin = 9;
int output;

void setup() {
Serial.begin (9600);  //RELAY
pinMode(REALY, OUTPUT);  
lcd.begin(16,2);
dht.begin();

pinMode(pir,INPUT);  //PIR
Serial.begin(9600);

pinMode(A0,INPUT);   //LDR
Serial.begin(9600);

Serial.begin (9600);  //ULTRASONIC
pinMode (trigger_pin, OUTPUT);  
pinMode (echo_pin, INPUT);
pinMode (buzzer_pin, OUTPUT);

Serial.begin(9600);  //AUTOMATIC DOOR
pinMode(sensor_pin, INPUT);   
pinMode(relay_pin, OUTPUT);  

}

void loop() {
  digitalWrite(REKAY, 0);
  Serial.println("LIGHTS ON");
  delay(2000);
  digitalWrite(RELAY, 1);
  Serial.println("LIGHTS OFF");
   delay(2000);
 
 float chk = dht.readTemperature(true);                                                                                                               
 lcd.setCursor(0,0);
 lcd.print("temp:");
 lcd.print(chk);
 delay(1000);
  float var = dht.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(var);
  delay(1000);

  int var = digitalWrite(pir);
 Serial.println(var);
 if (var == 1){
 digitalWrite(pir,HIGH);
 }
 else if (var == 0){
  digitalWrite(pir,LOW);
 } 

 int var = analogWrite(A0);
 Serial.println(var);
 if (var == 1){
 digitalWrite(A0,HIGH);
 }
 else if (var == 0){
  digitalWrite(A0,LOW);
 } 
 } 

 digitalWrite (trigger_pin, HIGH);
 delay(10);
 digitalWrite (trigger_pin, LOW);
 time = pulseIn (echo_pin, HIGH);

output = digitalRead(sensor_pin);
Serial.println(output);
if(output == 1){
 digitalWrite(relay_pin,LOW);
 Serial.println("OFF");
 delay(500);
  }
  
  
  else if(output == 0){
    digitalWrite(relay_pin, HIGH);
    Serial.println("ON");
    delay(500);
  }
 }
 distance = (time * 0.034) / 2;
