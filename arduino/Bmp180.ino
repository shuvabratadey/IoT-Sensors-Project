void Bmp180()
{
  lcd.clear();
  lcd.home();
  lcd.print("Pressure:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readPressure());
  lcd.print(" Pa");
  delay(100);
}
