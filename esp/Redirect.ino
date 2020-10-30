void Redirect()
{
  if (SPIFFS.exists("/config"))
  {
    File Writefile = SPIFFS.open("/config", "w");
    if (Writefile)
    {
      Writefile.println(server.arg("WiFiName"));
      Writefile.println(server.arg("WiFiPass"));
      Writefile.println(server.arg("ServerIP"));
      Writefile.println(server.arg("ServerFile"));
      Writefile.close();
    }
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
  }
  else
  {
    Error();
  }
  handleclient();
}

