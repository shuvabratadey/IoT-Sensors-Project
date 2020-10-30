void initialise()
{
  lcd.print("Self Testing");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.clear();
  /**************************DHT11****************************/
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM:
      lcd.clear();
      lcd.print("DHT Problem");
      while (1);
    case DHTLIB_ERROR_TIMEOUT:
      lcd.clear();
      lcd.print("DHT Problem");
      while (1);
    default:
      lcd.clear();
      lcd.print("DHT Problem");
      while (1);
  }
  /*/////////////////////DHT11////////////////////////////*
    /*********************BMP10*****************************/
  if (!bmp.begin()) {
    lcd.print("BMP180 ERROR");
    while (1);
  }
  /**********************BMP180*****************************/
  /***************************SD***************************/
  if (!SD.begin(10)) {
    lcd.clear();
    lcd.print("SD not Insert!!!");
    sd_inst=false;
    delay(1000);
  }
  /*********************SD*********************************/
}

