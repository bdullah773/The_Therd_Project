#include <DHT.h>
#include <Servo.h>
#define DHTPIN1 7
int Redled= 12;
int relay= 2;
#define servo 3
#define ddd A1
float temp = 0.0;
float hum = 0.0;
#define DHTTYPE1 DHT22
DHT dht(DHTPIN1,DHTTYPE1);
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Redled, OUTPUT);
  pinMode(relay, OUTPUT);
myservo.attach(servo);

}

void loop() {
  // put your main code here, to run repeatedly:

  temp = dht.readTemperature();
 // temp = dht.readTemperature(true); //for fahrenheit
  int soil = analogRead(ddd); 
  hum =dht.readHumidity();
  if(temp>30){
    myservo.write(180);
  }else if(temp<20){
    digitalWrite(Redled, HIGH);
  }
  if(hum<50.00){
    Serial.println(hum);
  }
  else if(soil<300){
    digitalWrite(relay, HIGH);
    delay(10000);
    digitalWrite(relay, LOW);
  }
}
