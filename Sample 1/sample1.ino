/////////////////////////////////
// Neeraj P Praveen            //
// neerajppraveen2@gmail.com   //
// Version 1.1.0			   //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
   WiFi.begin("my-net","");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println("");

  }
  Serial.println("Connected");
  Serial.println("IP Address(This Device) :");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    if (i == "LEFT") {
      Serial.println("Robot Move Left");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LEFT");
      client.println("</html>");

      delay(1);

    }
    if (i == "RIGHT") {
      Serial.println("Robot Move RIGHT");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("RIGHT");
      client.println("</html>");

      delay(1);

    }
    if (i == "UP") {
      Serial.println("Robot Move UP");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("UP");
      client.println("</html>");

      delay(1);

    }
    if (i == "Down") {
      Serial.println("Robot Move DOWN");
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Down");
      client.println("</html>");

      delay(1);

    }

}