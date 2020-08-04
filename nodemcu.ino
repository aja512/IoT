

#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include<WiFiClient.h>
int dataa=0;
const char* ssid="Your SSid ";
const char* password="Your Password";
unsigned long myChannelNumber = "Your Channel number";  
const char * myWriteAPIKey = "Your Channel API key";  
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    dataa=Serial.parseInt(); ///to convert from ASCII to integer
    //i=i*10+data;
    if(dataa<1000 && dataa>0){
    Serial.println(dataa);
    //delay(5000);
    ThingSpeak.writeField(myChannelNumber, 1,dataa, myWriteAPIKey); ///write the data on thingspeak.
    delay(15000);
    }
    }
    
    
  

}
