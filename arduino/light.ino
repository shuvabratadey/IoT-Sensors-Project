void light()
{
  int sensorValue = analogRead(lig);
  double dV = sensorValue;
  double le = (dV / 1023) * 100;
  int level = le;
  level=100-level;
  lcd.clear();
  lcd.home();
  lcd.print("LIGHT LEVEL: ");
  lcd.print(level);
  lcd.print("%");
  lcd.setCursor(0, 1);

  if ((level >= 0) && (level <= 5))
  {
    lcd.print("DARK");
  }
  else if ((level > 5) && (level <= 20))
  {
    lcd.print("DIM");
  }
  else if ((level > 20) && (level <= 30))
  {
    lcd.print("LIGHT");
  }
  else if ((level > 30) && (level <= 50))
  {
    lcd.print("BRIGHT");
  }
  else
  {
    lcd.print("VERY BRIGHT");
  }

}

