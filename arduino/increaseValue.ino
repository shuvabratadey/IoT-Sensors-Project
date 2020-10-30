void increaseValue()
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 200) {
    count++;
    if(count>5)
    {
      count=2;
    }
  }
  lastInterruptTime = interruptTime;
}

