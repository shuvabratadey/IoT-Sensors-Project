void nextItem()
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 200) {
    if (count > 1 && count < 6)
    {
      count--;
      if (count == 1)
      {
        count = 2;
      }
    }
    if (count == 0)
    {
      //Task 1
      c1++;
      if (c1 > 2)
      {
        c1 = 0;
      }
    }
    if (count == 1)
    {
      //Task 2
      c2++;
      if (c2 > 1)
      {
        c2 = 0;
      }
    }
  }
  lastInterruptTime = interruptTime;
}

