#include <DHT.h>
#include <Wire.h>
#include "SSD1306.h"
//#include "SSDDisplayUi.h"

#define DHTPIN D3
#define DHTTYPE DHT22
DHT dht (DHTPIN,DHTTYPE);

SSD1306 display(0x3c,4,5);

int localHum = 0;
int localTem = 0;

String localTemp;
void setup() {
  display.init();
  display.flipScreenVertically();

}

void loop() {
  display.clear();
  getDHT();
  drawDHT();
  drawLM35();
  display.display();
  

}
void getDHT()
{
 localTemp = dht.readTemperature();
 localHum = dht.readHumidity();
}
void drawDHT()
{
  int x=0;
  int y=0;
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0+x,5+y,"Hum");
  
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(43+x,y,"DHT22");
  
  display.setFont(ArialMT_Plain_16);
  String humdht22 = String(localHum);
  display.drawString(0 + x , 15 + y , humdht22 + "%" );
  
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(95 + x , 5 + y , "Temp");

  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  
  display.drawString(70 + x , 15 + y , localTemp + "C°");
  
}
void drawLM35 ()
{
  int x=0;
  int y=0;

  int val = 0;

  for (int i = 0;i<10;i++)
  {
    val += analogRead(A0);
    delay(200);
  }
  
  int templm35 = val * 33 / 1023;

  String temperature(templm35);

  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(34 + x , 37 + y , "LM35 temp");
  display.setFont(ArialMT_Plain_16);
  display.drawString(46,48 , temperature + "C°" );
  
}
