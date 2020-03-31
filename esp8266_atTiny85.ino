/*  since we were not told about the method to take input in the esp8266, by default I took as android app
 *  Submitted by Sudipta Pahar on 31.03.2020 @ 3:00 pm
 *  Comments are welcome
 */
#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
const char* ssid = "ssid"; //WiFi name
const char* password = "password"; //WiFi Password
String command = "";
int R1 = 0;// AtTiny85 pins 0,1,2
int R2 = 1;
int R3 = 2;// 3 relays
int state;
void setup(void)
{ 

  server.begin();
  Serial.begin(115200);// Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
}

void loop() 
{
  if(Serial.available()>0)
  {
    state = Serial.read();
  }
  client = server.available();
  if(!client) return;
  command = checkClient ();
  Serial.println(command);
  if(command == "R1 on")
  {
    digitalWrite(R1, HIGH);
  }
  else if(command == "R1 off")
  {
    digitalWrite(R1, LOW);
  }
  else if(command == "R2 on")
  {
    digitalWrite(R1, HIGH);
  }
  else if(command == "R2 off")
  {
    digitalWrite(R2, LOW);
  }
  else if(command == "R3 on")
  {
    digitalWrite(R1, HIGH);
  }
  else if(command == "R3 off")
  {
    digitalWrite(R3, LOW);
  }
}
String checkClient (void)
{
  while(!client.available()) delay(1);
    String request = client.readStringUntil('\r');
    request.remove(0, 5);
    request.remove(request.length() - 9,9);
    return request;  
}

void sendBackEcho(String echo)
{
  /* Since it is a dummy code, I am not writing this part
   *  if required would add afterwards!
   */
}
