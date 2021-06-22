// Handler for the incoming MQTT topics and payloads
   
void mqttCallback(char* incomingTopic  , byte* payload  , unsigned int length ) {
  payload[length] = '\0';
  String strTopic = String((char*)incomingTopic );
  
  String msg = String((char*)payload);

  Serial.println("----------------------");
  Serial.println(strTopic);
  Serial.println(msg);
  Serial.println("----------------------");
  my_topiccmd = my_topic + "/fan1/cmd" ;
  if (strTopic == my_topiccmd) {
     if(msg == "on") {digitalWrite(pin_led1,HIGH);}   //LED on 
     if(msg == "off") {digitalWrite(pin_led1,LOW);} //LED off
     checkstatue();

  }

  String strTopic1 = String((char*)incomingTopic );
  
  String msg1 = String((char*)payload);

  my_topiccmd = my_topic + "/fan2/cmd" ;
  if (strTopic1 == my_topiccmd) {

     if(msg == "on") {digitalWrite(pin_led2,HIGH);}   //LED on 
     if(msg == "off") {digitalWrite(pin_led2,LOW);} //LED off
     checkstatue();

  }


  
  String strTopic2 = String((char*)incomingTopic );
  
  String msg2 = String((char*)payload);

  my_topiccmd = my_topic + "/led/cmd" ;
  if (strTopic2 == my_topiccmd) {

     if(msg == "on") {digitalWrite(pin_led3,HIGH);}   //LED on 
     if(msg == "off") {digitalWrite(pin_led3,LOW);} //LED off
     checkstatue();
  }
    
  
}



// Reconnect to MQTT if the connection fails
void reconnect() {
  Serial.print("Attempting MQTT connection...");
  // Attempt to connect
  // If you do not want to use a username and password, change next line to
  // if (mqttClient.connect("ESP8266Client")) {
  if (mqttClient.connect(mac.c_str(), my_user, my_passwordm)) {
    Serial.println("connected");
    // Subscribe to our globally defined topic
  mqttClient.subscribe(String(my_topic + "/fan1/cmd").c_str());
  mqttClient.subscribe(String(my_topic + "/fan2/cmd").c_str());
  mqttClient.subscribe(String(my_topic + "/led/cmd").c_str());

    // Say Hello
    mqttClient.publish(String(my_topic + "/fan1/cmd").c_str(), String("off").c_str(), true);
    mqttClient.publish(String(my_topic + "/fan2/cmd").c_str(), String("off").c_str(), true);
    mqttClient.publish(String(my_topic + "/led/cmd").c_str(), String("off").c_str(), true);
  } else {
    Serial.print("failed, rc=");
    Serial.print(mqttClient.state());
    Serial.println(" try again in 15 seconds");
  }
}
void statusReport(String status) {
 // mqttClient.publish(String(my_topic + "/cmd").c_str(), status.c_str(), true);
}
