//Build by Group 19 - Intro to Computer Systems and Platform Technologies (COSC2500) 
//Semester 3, 2021

#include <string.h>
#include "DHT.h" //Declare sensor DHT library
#define DHT11Pin 4 //define input DHT sensor at PIN 4
#define DHTType DHT11 //Define type of sensor (DHT11)
DHT HT(DHT11Pin, DHTType); //Declare variable HT which represents for DHT sensor
float humidity; //Declare variable humidity to store humidity value
float temperatureC; //Declare variable temperature to store temperature value


int led1 = 9; //Declare value represents for LED1 = 9
int led2 = 10;  //Declare value represents for LED2 = 10
int led3 = 11;  //Declare value represents for LED3 = 11

char val;  //Declare variable val to store the signal value which is sent from Python
void setup()

{
    Serial.begin(9600); //The serial at begin
    HT.begin(); //The DHT11 sensor at begin
    delay(1000);
   
    pinMode (led1, OUTPUT); //Declare input LED1 at PIN 9
    pinMode (led2, OUTPUT); //Declare output LED2 at PIN 10
    pinMode (led3, OUTPUT); //Declare output LED3 at PIN 11

}

void loop()
 {
 while (Serial.available() > 0) //if the bluetooth is connected, perform the while loop 
 {
  val = Serial.read(); //the value of signal which is sent from Python will be stored in variable val
    
  if (val == 't'){ //if the value of signal which is sent from Python == 't', perform the command
     delay(1000); //pause 1 second
 
     humidity = HT.readHumidity(); //Get the humidity value
     temperatureC = HT.readTemperature(); //Get the temperature value
    
     Serial.print("Humidity: "); //send the message "Humidity: " to Python
     Serial.print(humidity); //send the value of humidity to Python
     Serial.println("%RH,"); //send the message "%RH" to Python
     Serial.print(" Temperature: "); //send the message "Temperature: " to Python
     Serial.print(temperatureC); //send the value of temperature to 
     Serial.println(" degree C"); //send the message "degree C" to Python
  }

    else if (val == '1'){ //if the value of signal which is sent from Python == '1', perform the command
      delay(1000);
      digitalWrite(led1, HIGH); //the LED1 will turn on
    }
    else if (val == '2'){ //if the value of signal which is sent from Python == '2', perform the command
      delay(1000);
      digitalWrite(led1, LOW); //the LED1 will turn off
    }

    else if (val == '3'){ //if the value of signal which is sent from Python == '3', perform the command
      delay(1000);
      digitalWrite(led2, HIGH); //the LED2 will turn on
    }
    else if (val == '4'){ //if the value of signal which is sent from Python == '4', perform the command
      delay(1000);
      digitalWrite(led2, LOW); //the LED2 will turn off
    }

    else if (val == '5'){ //if the value of signal which is sent from Python == '5', perform the command
      delay(1000);
      digitalWrite(led3, HIGH); //the LED3 will turn on
    }
    else if (val == '6'){ //if the value of signal which is sent from Python == '6', perform the command
      delay(1000);
      digitalWrite(led3, LOW); //the LED3 will turn off
    }
  }
}
