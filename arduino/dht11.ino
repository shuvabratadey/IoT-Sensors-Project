void Dht11(){
  int chk;
  chk = DHT.read(DHT11_PIN);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.createChar(1, centregrade);
  lcd.setCursor(8,0);
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(DHT.humidity, 1);
  lcd.print("%");
}
