void storeSd()
{
  if (sd_inst == true && c2 == 1)
  {
    myFile = SD.open("MYFILE.txt", FILE_WRITE);
    if (myFile) {
      myFile.print("temperature is: ");
      myFile.print(DHT.temperature);
      myFile.print(" *c");
      myFile.print("      |     ");
      myFile.print("Humidity is: ");
      myFile.print(DHT.humidity);
      myFile.print(" %");
      myFile.print("      |     ");
      myFile.print("Pressure:");
      myFile.print(bmp.readPressure());
      myFile.println(" Pa");
      myFile.close();
    }
  }
}
