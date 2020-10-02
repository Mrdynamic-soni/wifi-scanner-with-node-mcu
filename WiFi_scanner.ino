#include<ESP8266WiFi.h>

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
    
}

void loop()
{
  int n= WiFi.scanNetworks();
  Serial.print("Finding network");
  if(n==0)
  {
    Serial.println("NO NETWORK FOUND");
  }
  else{
  Serial.println("NETWORK FOUND");
  }


  for(int i=0;i<n;i++)
  {
    Serial.print(i+1);
    Serial.print(":");
    Serial.println(WiFi.SSID(i));

    Serial.print("Signal  Srength:");
    Serial.println(WiFi.RSSI(i));

    Serial.print("MAC");
    Serial.println(WiFi.BSSIDstr(i));

    Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" Unsecured":",Secured");

    delay(100);
  }
    delay(2000);
}
