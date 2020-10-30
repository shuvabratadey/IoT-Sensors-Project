void sdcard()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SD card:");
  lcd.setCursor(0, 1);
  if (sd_inst != false)
  {
    if (c2 == 0)
    {
      lcd.print("DISABLE       ");
    }
    if (c2 == 1)
    {
      lcd.print("ENABLE       ");
    }
  }
  else
  {
    lcd.print("DISABLE       ");
  }
}

