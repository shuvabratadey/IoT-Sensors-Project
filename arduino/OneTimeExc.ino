void OneTimeExc()
{
  if (one_time == true)
  {
    /******ESP8266*********/
    if (c1 == 0)
    {
      Serial.write('O');
    }
    if (c1 == 1)
    {
      Serial.write('A');
    }
    if (c1 == 2)
    {
      Serial.write('S');
    }
    for (int i = 0; i < 5000; i++) {
      if (Serial.available() > 0)
      {
        ch = Serial.read();
        Serial.flush();
      }
    }
    if (ch == 'a')
    {
      lcd.clear();
      lcd.home();
      lcd.print("AP Mode enable");
      lcd.setCursor(0, 1);
      lcd.print("enjoy");
      lcd.createChar(2, smiley);
      lcd.setCursor(6, 1);
      lcd.write(2);
      WiFiEn = true;
    }
    else if (ch == 's')
    {
      lcd.clear();
      lcd.home();
      lcd.print("STA Mode enable");
      lcd.setCursor(0, 1);
      lcd.print("enjoy");
      lcd.createChar(2, smiley);
      lcd.setCursor(6, 1);
      lcd.write(2);
      WiFiEn = true;
    }
    else if (ch == 'o')
    {
      lcd.clear();
      lcd.home();
      lcd.print("WiFi is not use");
      lcd.setCursor(0, 1);
      lcd.print("!!!!");
    }
    else
    {
      lcd.clear();
      lcd.createChar(8, thumb1);
      lcd.createChar(6, thumb2);
      lcd.createChar(7, thumb3);
      lcd.createChar(3, thumb4);
      lcd.createChar(4, thumb5);
      lcd.createChar(5, thumb6);
      lcd.setCursor(0, 0);
      lcd.print("WiFi is ");
      lcd.setCursor(0, 1);
      lcd.print("disconnect");
      lcd.setCursor(10, 0);
      lcd.write(8);
      lcd.setCursor(10, 1);
      lcd.write(6);
      lcd.setCursor(11, 0);
      lcd.write(7);
      lcd.setCursor(11, 1);
      lcd.write(3);
      lcd.setCursor(12, 0);
      lcd.write(4);
      lcd.setCursor(12, 1);
      lcd.write(5);
    }
    /******ESP8266*********/
    delay(2000);
    one_time = false;
  }
}
