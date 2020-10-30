#include <LiquidCrystal.h>
#include <dht11.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#define lig A0
#define DHT11_PIN A3
#define dist_echo 9
#define dist_trig 8
#define sd_pin 10
#define btnSet 0
#define btnSel 1

LiquidCrystal lcd(7, 6, 5, 4, A1, A2);
dht11 DHT;
File myFile;

Adafruit_BMP085 bmp;

int count = 0;
int c1 = 0;
int c2 = 0;
bool sd_en = true;
bool sd_inst = true;
bool one_time = true;
bool WiFiEn = false;
char ch;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
/************degree centegrde***************/
byte centregrade[] = {
  B11000,
  B11000,
  B00111,
  B01000,
  B01000,
  B01000,
  B01000,
  B00111
};
/***************degree centegrde***************/
byte smiley[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};
byte thumb1[8] = {B00001, B00010, B00011, B00100, B00011, B00100, B00011, B00100};
byte thumb2[8] = {B00011, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte thumb3[8] = {B11110, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
byte thumb4[8] = {B00000, B11110, B01000, B10001, B10010, B10010, B01100, B00000};
byte thumb5[8] = {B00000, B10000, B01110, B00010, B00010, B00010, B00010, B00010};
byte thumb6[8] = {B00110, B01000, B10000, B00000, B00000, B00000, B00000, B00000};

void setup()
{
  Serial.begin(115200);
  lcd.begin(16, 2);
  attachInterrupt(btnSet, increaseValue, RISING);
  attachInterrupt(btnSel, nextItem, RISING);
  pinMode(dist_trig, OUTPUT);
  pinMode(dist_echo, INPUT);
  initialise();
}
void loop()
{
  int chk;
  chk = DHT.read(DHT11_PIN);
  if (millis() - previousMillis1 >= 500)
  {
    if (count == 0)
    {
      WiFiMode();
    }
    if (count == 1)
    {
      sdcard();
    }
    if (count == 2)
    {
      OneTimeExc();
      Dht11();
    }
    if (count == 3)
    {
      Bmp180();
    }
    if (count == 4)
    {
      light();
    }
    if (count == 5)
    {
      dist();
    }
    previousMillis1 = millis();
  }
  recvWiFi();
  sendWiFi();
  if (millis() - previousMillis2 >= 2000)
  {
    storeSd();
    previousMillis2 = millis();
  }
}
