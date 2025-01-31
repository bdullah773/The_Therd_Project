# The_Therd_Project

<div>
  <img src="https://github.com/bdullah773/The_Therd_Project/blob/main/imgfroProject.png">
</div>

---

ex Git:
~~~
#include <DHT.h>
#include <Servo.h>
~~~
DHT.h: This library is used to interface with the DHT22 temperature and humidity sensor.

Servo.h: This library is used to control the servo motor.

~~~
#define DHTPIN1 7
int Redled = 12;
int relay = 2;
#define servo 3
#define ddd A1
float temp = 0.0;
float hum = 0.0;
#define DHTTYPE1 DHT22
~~~
DHTPIN1: The pin where the DHT22 sensor is connected (Digital Pin 7).

Redled: The pin where the red LED is connected (Digital Pin 12).

relay: The pin where the relay is connected (Digital Pin 2).

servo: The pin where the servo motor is connected (Digital Pin 3).

ddd: The analog pin where the soil moisture sensor is connected (Analog Pin A1).

temp and hum: Variables to store temperature and humidity readings.

DHTTYPE1: Specifies the type of DHT sensor being used (DHT22).

~~~
DHT dht(DHTPIN1, DHTTYPE1);
Servo myservo;
~~~
dht: An instance of the DHT class for the DHT22 sensor.

myservo: An instance of the Servo class for the servo motor.

~~~
void setup() {
  Serial.begin(115200);
  pinMode(Redled, OUTPUT);
  pinMode(relay, OUTPUT);
  myservo.attach(servo);
}
~~~
Serial.begin(115200): Initializes serial communication at 115200 baud rate for debugging.

pinMode(Redled, OUTPUT): Sets the red LED pin as an output.

pinMode(relay, OUTPUT): Sets the relay pin as an output.

myservo.attach(servo): Attaches the servo motor to the specified pin.

~~~
void loop() {
  temp = dht.readTemperature();
  int soil = analogRead(ddd); 
  hum = dht.readHumidity();
~~~
temp = dht.readTemperature(): Reads the temperature from the DHT22 sensor.

soil = analogRead(ddd): Reads the soil moisture level from the analog pin A1.

hum = dht.readHumidity(): Reads the humidity from the DHT22 sensor.

~~~
  if(temp > 30){
    myservo.write(180);
  } else if(temp < 20){
    digitalWrite(Redled, HIGH);
  }
~~~
if(temp > 30): If the temperature is greater than 30°C, the servo motor is set to 180 degrees.

else if(temp < 20): If the temperature is less than 20°C, the red LED is turned on.

~~~
  if(hum < 50.00){
    Serial.println(hum);
  }
~~~
if(hum < 50.00): If the humidity is less than 50%, the humidity value is printed to the serial monitor.

~~~
  else if(soil < 300){
    digitalWrite(relay, HIGH);
    delay(10000);
    digitalWrite(relay, LOW);
  }
~~~
else if(soil < 300): If the soil moisture level is less than 300 (assuming lower values mean drier soil),
the relay is turned on for 10 seconds and then turned off.
This could be used to control a water pump to irrigate the soil.

---
Summary
---
The system monitors temperature, humidity, and soil moisture.

If the temperature exceeds 30°C, the servo motor moves to 180 degrees.

If the temperature drops below 20°C, a red LED is turned on.

If the humidity is below 50%, the humidity value is printed to the serial monitor.

If the soil moisture is below a certain threshold (300), a relay is activated for 10 seconds, possibly to control a water pump.

This code is a basic example of how to integrate multiple sensors and actuators to create a simple environmental control system using an Arduino.

---
This project was established by Eng. Abdullah Shamsan 
---
