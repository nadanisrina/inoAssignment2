//include DHT library
#include "DHTesp.h"
//define DHT
#define DHTPIN 15
DHTesp dht;
//define pin led rgb
const int rgbPins[] = { 23, 19, 21};
//function run once on first 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // inisiasi led rgb
  for( int i=0; i<3; i++)
    pinMode( rgbPins[i], OUTPUT);
  // inisiasi sensor DHT
  dht.setup(DHTPIN, DHTesp::DHT22);
}
//function run loop after setup
void loop() {
  // deklarasi objek untuk menampung data 
  // temperatur dan kelembapan dari DHT22
  TempAndHumidity data = dht.getTempAndHumidity();
  // ekstrak data temperature
  float temp = data.temperature;
  // ekstrak data humidity
  float hum = data.humidity;
  //pick resistor R(3.3-2)/0.02 , G=B(3.3-3/0.02) ,15-65 so pick 220
  // menampilkan data di serial
  Serial.println("Suhu: " + String(temp, 2) + "°C");
  if(temp < 30){
    Serial.println("temp < 30, green" );
    digitalWrite(rgbPins[2], LOW);
  }else if(temp >= 30 && temp <= 50 ){
    Serial.println("temp >= 30 && temp <= 50, blue" );
    digitalWrite(rgbPins[1], LOW);
  }else{
    Serial.println("temp > 50, red" );
    digitalWrite(rgbPins[0], LOW);
  }
  delay(500);
  
}
