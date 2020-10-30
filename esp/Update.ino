void Upsdate()
{
  message = "<html><head>";
  message += "<style>h1{color:red;}.first{color:Darkblue;}.second{color:orangered;}.third{color:forestgreen;}.forth{color:blue;}</style>";
  message += "<script>function validateForm() {var a = document.forms['Setting']['WiFiName'].value;var b = document.forms['Setting']['WiFiPass'].value;var c = document.forms['Setting']['ServerIP'].value;var d = document.forms['Setting']['ServerFile'].value;";
  message += "if (a == '') { alert('WiFi Name must be filled out');return false;}";
  message += "else if (b == '') {alert('WiFi Password must be filled out');return false;}";
  message += "else if (c == '') {alert('Server IP must be filled out');return false;}";
  message += "else if (d == '') {alert('Server File must be filled out');return false;}}</script>";
  message += "<title>Change Settings</title>";
  message += "<meta name='viewport' content='width=device-width, initial-scale=1' /></head><body bgcolor='lime'><center><h1>Change Required Settings</h1>";
  message += "<form name='Setting' action='SettingChange' method='GET' onsubmit='return validateForm()'>";
  message += "<h2 class=first>WiFi Name: <input type='textbox' name='WiFiName' value='"+totalStr[0]+"'/></h2>";
  message += "<h2 class=second>WiFi Pass: <input type='password' name='WiFiPass' value='"+totalStr[1]+"'/></h2>";
  message += "<h2 class=third>Server IP: <input type='textbox' name='ServerIP' value='"+totalStr[2]+"'/></h2>";
  message += "<h2 class=forth>Server File: <input type='textbox' name='ServerFile' value='"+totalStr[3]+"'/></h2>";
  message += "<input type='submit'/></form>";
  message += "<a href='back'><button>back</button></a></center></body></html>";
  server.send(200, "text/html", message);
}
