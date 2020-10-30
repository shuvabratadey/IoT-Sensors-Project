void WiFiMode()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Mode:");
  lcd.setCursor(0, 1);
  if (c1 == 0)
  {
    lcd.print("OFF         ");
  }
  if (c1 == 1)
  {
    lcd.print("Access Point");
  }
  if (c1 == 2)
  {
    lcd.print("Station        ");
  }
}

