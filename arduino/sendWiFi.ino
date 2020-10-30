void sendWiFi()
{
  if (WiFiEn == true)
  {
    Serial.print('T');
    Serial.print(DHT.temperature);
    Serial.print('t');
    Serial.flush();
    Serial.print('H');
    Serial.print(DHT.humidity);
    Serial.print('h');
    Serial.flush();
    Serial.print('P');
    Serial.print(bmp.readPressure());
    Serial.print('p');
    Serial.flush();
  }
}
