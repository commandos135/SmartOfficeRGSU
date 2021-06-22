void infor()
{
 infoweb =    "<!DOCTYPE html>\n";
 infoweb +=   "<html lang=\"fr\" class=\"\"> <head>\n";
 infoweb +=   "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n";
 infoweb +=   "<meta name=\"viewport\" content=\"width=device-width,initial-scale=1,user-scalable=no\">\n";
 infoweb +=   "<title>Informations</title>\n";
 infoweb +=   "<style>div,fieldset,input,select{padding:5px;font-size:1em;}fieldset{background:#4f4f4f;}p{margin:0.5em 0;}input{width:100%;box-sizing:border-box;-webkit-box-sizing:border-box;-moz-box-sizing:border-box;background:#dddddd;color:#000000;}input[type=checkbox],input[type=radio]{width:1em;margin-right:6px;vertical-align:-1px;}input[type=range]{width:99%;}select{width:100%;background:#dddddd;color:#000000;}textarea{resize:vertical;width:98%;height:318px;padding:5px;overflow:auto;background:#1f1f1f;color:#65c115;}body{text-align:center;font-family:verdana,sans-serif;background:#252525;}td{padding:0px;}button{border:0;border-radius:0.3rem;background:#1fa3ec;color:#faffff;line-height:2.4rem;font-size:1.2rem;width:100%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}button:hover{background:#0e70a4;}.bred{background:#d43535;}.bred:hover{background:#931f1f;}.bgrn{background:#47c266;}.bgrn:hover{background:#5aaf6f;}a{color:#1fa3ec;text-decoration:none;}.p{float:left;text-align:left;}.q{float:right;text-align:right;}.r{border-radius:0.3em;padding:2px;margin:6px 2px;} </style></head> <body>\n";
 infoweb +=   "<div style=\"text-align:left;display:inline-block;color:#eaeaea;min-width:340px;\">\n";
 infoweb +=   "<div style=\"text-align:center;color:#eaeaea;\">\n";
 infoweb +=   "<noscript>Pour utiliser, veuillez activer JavaScript<br></noscript>\n";
 infoweb +=   "<h2>Informations</h2></div><style>td{padding:0px 5px;}</style>\n";
 infoweb +=   "<div id=\"i\" name=\"i\">\n";
 infoweb +=   "<table style=\"width:100%\"> <tbody>";

  infoweb += "<tr><th>ESP ID </th><td>: ";
  infoweb += ESP.getFlashChipId();
  infoweb += "</td></tr>";
  infoweb += "<tr><th>ESP Core Version</th><td>: ";
  infoweb += ESP.getCoreVersion();
  infoweb += "</td></tr>";
  infoweb += "<tr><th>ESP Flash Speed</th><td>: ";
  infoweb += ESP.getFlashChipSpeed()/1000000;
  infoweb += " MHz</td></tr>";
  infoweb += "<tr><th>Chip Work Speed</th><td>: ";
  infoweb += ESP.getCpuFreqMHz();
  infoweb += " MHz</td></tr>";
  infoweb += "<tr><th>Taille Flash Programme</th><td>: ";
  infoweb += ESP.getFlashChipSize()/1024;
  infoweb += " Kbit</td></tr>";
  infoweb += "<tr><th>Taille programme </th><td>: ";
  infoweb += ESP.getSketchSize()/1024;
  infoweb += " Kbit</td></tr>";  
  infoweb += "<tr><th>Espace programme libre</th><td>: ";
  infoweb += ESP.getFreeSketchSpace()/1024;
  infoweb += " Kbit</td></tr>";
  infoweb += "<tr><th>Raison du redemarrage</th><td>: ";
  infoweb += ESP.getResetReason();
  infoweb += "</td></tr>";
  infoweb += "<tr><th><hr></th><td><hr></td></tr><tr><th>Adresse IP</th><td>: ";
  infoweb += WiFi.localIP().toString() ;
  infoweb += "</td></tr>";
  infoweb += "<tr><th>Masque sous-réseau</th><td>: ";
  infoweb += WiFi.subnetMask().toString();
  infoweb += "</td></tr>";
  infoweb += "<tr><th>Passerelle</th><td>: ";
  infoweb += WiFi.gatewayIP().toString();
  infoweb += "</td></tr>";
  infoweb += "<tr><th>Serveur DNS</th><td>: ";
  infoweb += WiFi.dnsIP().toString();
  infoweb += "</td></tr>";
  infoweb += "<tr><th>MAC Adresse</th><td>";
  infoweb += WiFi.macAddress();
  infoweb += "</td></tr>";

  infoweb +=  "</tbody></table></div><div></div><p></p>\n";
  infoweb +=  "<form action=\"./\" method=\"get\"><button name=\"\">Retour</button></form><p></p>\n";
  infoweb +=  "<div style=\"text-align:center;font-size:14px;\"><hr>\n";
  infoweb +=  "<a target=\"_blank\" style=\"color:#aaa;\"><b>Par SeifEddine Achour Et Najeh Fatthallah.</b></a><br>\n";
  infoweb +=  "<a target=\"_blank\" style=\"color:#aaa;\"><b>Copyrights© 2021 - All Rights Reserved.</b></a><br>\n";
  infoweb +=  "<a target=\"_blank\" style=\"color:#aaa;\"><b>Fabriqué Avec <span style=\"color: #e25555;\">&#10084;</span> En Tunisie.</b></a><br>\n";
  infoweb +=  "</div></div></body></html>";
   server.send(200, "text/html", infoweb);
}
// Fonctions du serverWeb

void switchLedOn() {
  buttonState1 = digitalRead(pin_led1);
  buttonState2 = digitalRead(pin_led2);
  buttonState3 = digitalRead(pin_led3);
  String statue;
if (buttonState1 == HIGH) { 
  statue = "ON/";  
 }else{
  statue = "OFF/";
  } 
if (buttonState2 == HIGH) { 
  statue += "ON/";  
 }else{
  statue += "OFF/";
  } 
if (buttonState3 == HIGH) { 
  statue += "ON/";  
 }else{
  statue += "OFF/";
  }

  
  server.send(200, "text/plain", statue);
 }

  
void wifiscan()
{
 int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");

  st = "<a>";
  for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      st += "<p onclick=\"insert('";
      st += WiFi.SSID(i);
      st += "');" ;
      st += "\"";
      st += ">&nbsp;";
      st += i+1;
      st += "-";
      st += WiFi.SSID(i);
      st += "</a> <span class=\"q\">";
      st += dBmtoPercentage(WiFi.RSSI(i));//Signal strength in %  
      st += "%&nbsp;&nbsp;</span></div>";
      st += "</a>";
    }
  st += "</p>";
  delay(10);

        server.send(200, "HTTP_GET", st);
  
  }
}

int dBmtoPercentage(int dBm)
{
  int quality;
    if(dBm <= RSSI_MIN)
    {
        quality = 0;
    }
    else if(dBm >= RSSI_MAX)
    {  
        quality = 100;
    }
    else
    {
        quality = 2 * (dBm + 100);
   }

     return quality;
}//dBmtoPercentage 

void handleSettingsUpdate()
{
  String data = server.arg("plain");
  DynamicJsonBuffer jBuffer;
  JsonObject& jObject = jBuffer.parseObject(data);

  File configFile = SPIFFS.open("/config.json", "w");
  jObject.printTo(configFile);  
  configFile.close();
  
  server.send(200, "application/json", "{\"status\" : \"ok\"}");
  delay(500);
  
 // wifiConnect();
redemarrer();
}
void handleSettingsUpdate2()
{
  String data = server.arg("plain");
  DynamicJsonBuffer jBuffer;
  JsonObject& jObject = jBuffer.parseObject(data);

  File configFile = SPIFFS.open("/config2.json", "w");
  jObject.printTo(configFile);  
  configFile.close();
  
  server.send(200, "application/json", "{\"status\" : \"ok\"}");
  delay(500);
 // wifiConnect();
redemarrer();
}
void handleSettingsUpdate3()
{
  String data = server.arg("plain");
  DynamicJsonBuffer jBuffer;
  JsonObject& jObject = jBuffer.parseObject(data);

  File configFile = SPIFFS.open("/config3.json", "w");
  jObject.printTo(configFile);  
  configFile.close();
  
  server.send(200, "application/json", "{\"status\" : \"ok\"}");
  delay(500);
 // wifiConnect();
redemarrer();
}

void wifiConnect()
{
  //reset networking
  WiFi.softAPdisconnect(true);
  WiFi.disconnect();          
  delay(1000);
  //check for stored credentials
  if(SPIFFS.exists("/config.json")){
    const char * _ssid = "", *_pass = "", * _ssid2 = "", *_pass2 = "";
    File configFile = SPIFFS.open("/config.json", "r");
    if(configFile){
      size_t size = configFile.size();
      std::unique_ptr<char[]> buf(new char[size]);
      configFile.readBytes(buf.get(), size);
      configFile.close();

      DynamicJsonBuffer jsonBuffer;
      JsonObject& jObject = jsonBuffer.parseObject(buf.get());
      if(jObject.success())
      {
        _ssid = jObject["ssid"];
        _pass = jObject["password"];
        _ssid2 = jObject["ssid2"];
        _pass2 = jObject["password2"];
        fmy_ip.fromString(my_ip);
        fmy_dns.fromString(my_dns);
        fmy_passrelle.fromString(my_passrelle);
        fmy_masque.fromString(my_masque);
        WiFi.config(fmy_ip, fmy_passrelle, fmy_masque, fmy_dns);
        WiFi.mode(WIFI_STA);
        const char* MyHostname = "smart device";
        WiFi.hostname(MyHostname);
        WiFi.begin(_ssid, _pass);  

        unsigned long startTime = millis();
        while (WiFi.status() != WL_CONNECTED) 
        {
          delay(500);
          Serial.print(".");
          digitalWrite(led,!digitalRead(led));
          if ((unsigned long)(millis() - startTime) >= 15000) break;
        } 
        WiFi.begin(_ssid2, _pass2);  
  //      WiFi.config(fmy_ip, fmy_passrelle, fmy_masque, fmy_dns);
        unsigned long startTime2 = millis();
        while (WiFi.status() != WL_CONNECTED) 
        {
          delay(500);
          Serial.print(".");
          digitalWrite(led,!digitalRead(led));
          if ((unsigned long)(millis() - startTime2) >= 15000) break;
        } 
      }
    }
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(led,HIGH);
  } else 
  {
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(mySsid, password); 

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request

  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", apIP);
    digitalWrite(led,LOW);      
  }
  Serial.println("");
  WiFi.printDiag(Serial);
}

void toggleLED1()
{
  digitalWrite(pin_led1,!digitalRead(pin_led1));
  checkstatue();
  server.send(204,"");

}
void toggleLED2()
{
  digitalWrite(pin_led2,!digitalRead(pin_led2));
  checkstatue();
  server.send(204,"");
}
void toggleLED3()
{
  digitalWrite(pin_led3,!digitalRead(pin_led3));
  checkstatue();
  server.send(204,"");
}

void ConfigMqtt()
{
  //check for stored credentials
  if(SPIFFS.exists("/config2.json")){
    File configFile = SPIFFS.open("/config2.json", "r");
    if(configFile){
      size_t size = configFile.size();
      std::unique_ptr<char[]> buf(new char[size]);
      configFile.readBytes(buf.get(), size);
      configFile.close();

      DynamicJsonBuffer jsonBuffer;
      JsonObject& jObject = jsonBuffer.parseObject(buf.get());
      if(jObject.success())
      {       
        _hote = jObject["hote"];
        _port = jObject["port"];
        _user = jObject["user"];
        _passwordm = jObject["passwordm"];
        _topic = jObject["topic"];        
        
        Serial.println("mqtt config loded");
      my_hote = strdup(_hote);
      my_port = strdup(_port);
      my_user = strdup(_user);
      my_passwordm = strdup(_passwordm);
      my_topic = strdup(_topic);
      
                        // MQTT Setup & Callback
      mqttClient.setServer(my_hote, atol(my_port));
      mqttClient.setCallback(mqttCallback);

     }
   }
 }
}
void ipp()
{
  //check for stored credentials
  if(SPIFFS.exists("/config3.json")){
    File configFile = SPIFFS.open("/config3.json", "r");
    if(configFile){
      size_t size = configFile.size();
      std::unique_ptr<char[]> buf(new char[size]);
      configFile.readBytes(buf.get(), size);
      configFile.close();

      DynamicJsonBuffer jsonBuffer;
      JsonObject& jObject = jsonBuffer.parseObject(buf.get());
      if(jObject.success())
      {       
        _ip = jObject["ip"];
        _masque = jObject["masque"];
        _passrelle = jObject["passrelle"];
        _dns = jObject["dns"];       
        
        Serial.println("ip config loded");
      my_ip = strdup(_ip);
      my_masque = strdup(_masque);
      my_passrelle = strdup(_passrelle);
      my_dns = strdup(_dns);
     
      

     }
   }
 }
}

void StartMdns()
{
   if (WiFi.status() == WL_CONNECTED)   { 
   if (!MDNS.begin("esp8266")) {
   Serial.println("Error setting up MDNS responder!");
    
      delay(1000);
    
  }
  Serial.println("mDNS responder started");

  // Start TCP (HTTP) server
  //server.begin();
  Serial.println("TCP server started");

  // Add service to MDNS-SD
  MDNS.addService("http", "tcp", 80);

    }
}
void redemarrer()
{
  //reset networking
  WiFi.softAPdisconnect(true);
  WiFi.disconnect(); 
  Serial.println("reboot....");         
  delay(1000);
  ESP.restart();
  
} 
void reinit()
{
  //reset wifi et mqtt
SPIFFS.format();
redemarrer();
  
} 

void checkstatue()
{
  if (digitalRead(pin_led1) == LOW ) {
    mqttClient.publish(String(my_topic + "/fan1/status").c_str(), String("off").c_str(), true);
  }
  
  if (digitalRead(pin_led1) == HIGH ) {
    mqttClient.publish(String(my_topic + "/fan1/status").c_str(), String("on").c_str(), true);
  }
  if (digitalRead(pin_led2) == LOW ) {
    mqttClient.publish(String(my_topic + "/fan2/status").c_str(), String("off").c_str(), true);
  }
  
  if (digitalRead(pin_led2) == HIGH ) {
    mqttClient.publish(String(my_topic + "/fan2/status").c_str(), String("on").c_str(), true);
  }
  if (digitalRead(pin_led3) == LOW ) {
    mqttClient.publish(String(my_topic + "/led/status").c_str(), String("off").c_str(), true);
  }
  
  if (digitalRead(pin_led3) == HIGH ) {
    mqttClient.publish(String(my_topic + "/led/status").c_str(), String("on").c_str(), true);
  }

}
