void recvWiFi()
{
  if (WiFiEn == true)
  {
    ch = ' ';
    while (Serial.available() > 0)
    {
      ch = Serial.read();
    }
    if (ch == 'n')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("New Client");
      lcd.setCursor(0, 1);
      lcd.print("Connected");
      ch = ' ';
      delay(2000);
      lcd.clear();
    }
    if (ch == 'f')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("One Client");
      lcd.setCursor(0, 1);
      lcd.print("Disconnected");
      ch = ' ';
      delay(2000);
      lcd.clear();
    }
    if (ch == 'x')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("AP Connected");
      lcd.setCursor(0, 1);
      lcd.print("Successfully");
      ch = ' ';
      delay(2000);
      lcd.clear();
    }
    if (ch == 'y')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("AP Disconnected!");
      lcd.setCursor(0, 1);
      lcd.print("Try to Reconnect");
      ch = ' ';
      delay(2000);
      lcd.clear();
    }
    if (ch == 'e')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("HTTP Error");
      lcd.setCursor(0, 1);
      lcd.print("Can't Send Data!");
      ch = ' ';
      delay(2000);
      lcd.clear();
    }
  }
}
