// https://github.com/onurrohat

#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>




int maxvalue = 750 ;
int value = A0;



#define FIREBASE_AUTH "Firebase-Auth Token" 
#define FIREBASE_HOST "Firebase URL without https"
#define WIFI_SSID "Your Wifi SSID"
#define WIFI_PASSWORD "Your Wifi Password"

String gasdetected = "gasdetected" ;
String gasabsent= "gasabsent";

FirebaseData firebaseData ;

void setup() {

  Serial.begin(115200);                  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to IP Adress: ");
  Serial.println(WiFi.localIP());
  Serial.println();
 
  //starting to connect
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //reconnection
  
  

}

void loop() {
  
   value = analogRead(A0);
   Serial.print("Sensor Value :");
   Serial.print(value);
   Serial.print("PPM");

  if(value > maxvalue){

    Serial.println("Gas detected!");
 
    delay(500);

    Firebase.setString(firebaseData,"Sensor:", "gasdetected");
    

  } else {
      
      Serial.println("Gas absent!");
      
      
      
      Firebase.setString(firebaseData,"Sensor:", "gasabsent") ;

      delay(500);
      
  

}

}








