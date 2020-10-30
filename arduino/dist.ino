void dist()
{
  lcd.clear();
  long duration, distance;
  digitalWrite(dist_trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(dist_trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(dist_trig, LOW);
  duration = pulseIn(dist_echo, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 1000 || distance <= 0) {
    lcd.setCursor(0, 0);
    lcd.print("Out of range      ");
}
  else {
    lcd.setCursor(0, 0);
    lcd.print("DISTANCE= ");
    lcd.print(distance);
    lcd.print(" cm    ");
  }
}
