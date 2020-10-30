void InitProgram()
{
  if (SPIFFS.exists("/config"))
  {
    File Readfile = SPIFFS.open("/config", "r");
    if (Readfile)
    {
      for (int i = 0; i < 4; i++)
      {
        totalStr[i] = Readfile .readStringUntil('\n');
      }
      Readfile.close();
    }
    else
    {
      Error();
    }
    if (totalStr[0] == "" || totalStr[1] == "" || totalStr[2] == "" || totalStr[3] == "")
    {
      Error();
    }
  }
  else
  {
    Error();
  }
}

void Error()
{
  totalStr[0] = "Guest";
  totalStr[1] = "guest@123";
  totalStr[2] = "192.168.0.100";
  totalStr[3] = "sensor.php";
}

