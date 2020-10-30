#include<ESP8266WiFi.h>
#include <DNSServer.h>
#include<ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "FS.h"

#define ssid1 "myWiFi"
#define password1 "12345678"

char ssid[50];
char pass[50];

#define led 2

const byte DNS_PORT = 53;

DNSServer dnsServer;
ESP8266WebServer server(80);
String totalStr[4];
bool ap = false;
bool st = false;
bool state;
String s;
char c;
int C_NList = 0;
int C_PList = 0;

String Temp;
String Hum;
String Pre;

unsigned long preMillis1 = 0;
unsigned long preMillis2 = 0;

String message;

void setup() {
  SPIFFS.begin();
  InitProgram();
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  WiFi.mode(WIFI_OFF);
  Serial.begin(115200);
  while (!Serial.available() > 0);
  c = Serial.read();
  /*******************For OFF Mode******************/
  if (c == 'O')
  {
    digitalWrite(led, 0);
    for (int i = 0; i < 50; i++)
    {
      Serial.write('o');
    }
    ESP.deepSleep(2e6); //Deep_Sleep for 2x10^6 micro seconds OR 2 sec. But it will not work untll Reset WiFi.
  }
  /*******************For AP Mode******************/
  if (c == 'A')
  {
    digitalWrite(led, 1);
    for (int i = 0; i < 50; i++)
    {
      Serial.write('a');
    }
    ap = true;
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid1, password1);
    dnsServer.start(DNS_PORT, "www.sensors.com", WiFi.softAPIP());
    server.on("/", handleclient);
    server.on("/config", Upsdate);
    server.on("/SettingChange", Redirect);
    server.on("/back", handleclient);
    server.onNotFound(handleNoFound);
    server.begin();
  }
  /************************************************/
  /*******************For ST Mode******************/
  if (c == 'S')
  {
    digitalWrite(led, 1);
    for (int i = 0; i < 50; i++)
    {
      Serial.write('s');
    }

    totalStr[0].toCharArray(ssid, totalStr[0].length());  //We write here 'data.length()' but the array takes 'data.length()-1'
    totalStr[1].toCharArray(pass, totalStr[1].length());  //We write here 'data.length()' but the array takes 'data.length()-1'
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
      state = !state;
      digitalWrite(led, state);
      delay(500);
    }
    st = true;
  }
  /************************************************/
}

void loop() {
  if (ap == true)
  {
    RecvData();
    C_NList = WiFi.softAPgetStationNum();
    if (C_NList > C_PList)
    {
      sendNCon();
    }
    else if (C_NList < C_PList)
    {
      sendPCon();
    }
    dnsServer.processNextRequest();
    server.handleClient();
    yield();
  }
  if (st == true)
  {
    if (WiFi.status() != WL_CONNECTED)
    {
      if (millis() - preMillis1 >= 2000)
      {
        preMillis1 = millis();
        ConServer(false);
      }
      if (millis() - preMillis2 >= 500)
      {
        preMillis2 = millis();
        state = !state;
        digitalWrite(led, state);
      }
    }
    else if(WiFi.status() == WL_CONNECTED)
    {
      ConServer(true);
      digitalWrite(led, HIGH);
    }
    while (WiFi.status() == WL_CONNECTED) {
      RecvData();
      sendRequest();
      delay(1000);
    }
  }
}

void sendNCon()
{
  Serial.write('n');
  delay(10);
  Serial.flush();
  C_PList = C_NList;
}

void sendPCon()
{
  Serial.write('f');
  delay(10);
  Serial.flush();
  C_PList = C_NList;
}
void ConServer(bool condition)
{
  if (condition)
  {
    Serial.write('x');
    delay(10);
    Serial.flush();
  }
  else
  {
    Serial.write('y');
    delay(10);
    Serial.flush();
  }
}

void sendRequest()
{
  HTTPClient http;
  http.begin("http://" + StrToStr(totalStr[2]) + "/" + StrToStr(totalStr[3]) + "?Temp=" + Temp + "&Hum=" + Hum + "&Pre=" + Pre); //http://192.168.0.100/sensor.php?Temp=35&Hum=20&Pre=101105
  int httpCode = http.GET();
  if (httpCode == 200)
  {
    digitalWrite(led, state);
    state = !state;
  }
  else
  {
    Serial.write('e');
    delay(10);
    Serial.flush();
    digitalWrite(led, 0);
  }
  http.end();
}

void handleclient()
{
  String webpage;
  webpage += "<html>";
  webpage += "<head>";
  webpage += "<meta http-equiv=refresh content=1 />";
  webpage += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />";
  webpage += "</head>";
  webpage += "<body bgcolor='lime'>";
  webpage += "<center>";
  webpage += "<table border='2'><tr><th><h2><font color='red'>Temp:- </font></th><th>";
  webpage += Temp;
  webpage += "</th><th><font color='green'>&nbsp&nbsp*c&nbsp&nbsp&nbsp&nbsp</font></h1></th></tr><tr><th><h2><font color='green'>Humidity:- </font></th><th>";
  webpage += Hum;
  webpage += "</th><th><font color='green'>&nbsp&nbsp%&nbsp&nbsp&nbsp&nbsp</font></h1></th></tr><tr><th><h2><font color='blue'>Presure:- </font></th><th>";
  webpage += Pre;
  webpage += "</th><th><font color='green'>&nbsp&nbsppa&nbsp&nbsp&nbsp&nbsp</font></h1></th></tr></table></center></body></html>";
  server.send(200, "text/html", webpage);
}

void handleNoFound()
{
  server.send(404, "text/html", "<center><h1>404: Not Found</h1></center>");
}

void RecvData()
{
  while (Serial.available())
  {
    c = Serial.read();
    /**********Temp**********/
    if (c == 'T')
      Temp = Serial.readStringUntil('t');
    /***********************/
    c = Serial.read();
    /**********Humidity**********/
    if (c == 'H')
      Hum = Serial.readStringUntil('h');
    /***********************/
    c = Serial.read();
    /**********Presure**********/
    if (c == 'P')
      Pre = Serial.readStringUntil('p');
    /***********************/
    delay(10);
    Serial.flush();
  }
}

String StrToStr(String data)
{
  String st = "";
  for (int i = 0; i < data.length(); i++)
  {
    if (byte(data[i]) > 31)
    {
      st += data[i];
    }
  }
  return st;
}
