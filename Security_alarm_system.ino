#include<LiquidCrystal.h>
// Assigning PIN Numbers
const int led = 8; 
const int sensor = 7;
const int buzzer = 6;
bool sensor_value ;
bool state = false ;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() 
{
pinMode(led,OUTPUT); //assigning led as output
pinMode(buzzer,OUTPUT); //assigning buzzer as output
pinMode(sensor,INPUT); //assigning sensor as input
}
void loop() 
{
sensor_value = digitalRead(sensor); //Reads sensor value
if(sensor_value == true) //PIR sends a signal
 {
 state = true;
 }
 if(state == true)// if Object detected
 {
 digitalWrite(led,HIGH); //LED ON
 tone(buzzer,1000); //BUZZER ON
 delay(500);
 digitalWrite(led,LOW);
 noTone(buzzer); 
 delay(500);
 lcd.begin(16, 2); 
 
 lcd.print(" Alarm Triggered"); //LCD display output
 lcd.setCursor(0, 2); 
 lcd.print(millis() / 1000);
 } 
 else //object not detected
 {
 digitalWrite(led,LOW); //LED OFF
 noTone(buzzer); //BUZZER OFF
 lcd.print(" Secured"); // print statement in LCD
 }
 lcd.setCursor(0, 1);
}
