#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

  Serial.begin(9600);

  pinMode(D5, OUTPUT); 
  pinMode(5, OUTPUT);  // GPIO pin5=D1 
  pinMode(4, OUTPUT);  // GPIO pin4=D2 
  pinMode(0, OUTPUT);  // GPIO pin0=D3 
    WiFi.disconnect();
  delay(2000);
  Serial.println("Connecting to WIFI");
   WiFi.begin("Home","42780212");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }Serial.println("I am Connected");
  Serial.println("My Local IP is : ");
  Serial.print((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));

    client.flush();
    i.remove(0, 5);
    i.remove(i.length()-9,9);                 //Senses the signal required for movement
//    if (i == "forward") {             
//      digitalWrite(16,HIGH);
//      digitalWrite(5,LOW);
//      digitalWrite(4,HIGH);
//      digitalWrite(0,LOW);
//      client.println("HTTP/1.1 200 OK");
//      client.println("Content-Type: text/html");
//      client.println("");
//      client.println("<!DOCTYPE HTML>");
//      client.println("<html>");
//      client.println("forward");
//      client.println("</html>");
//      client.stop();
//      delay(1);
//
//    }
//    if (i == "reverse") {
//      digitalWrite(16,LOW);
//      digitalWrite(5,HIGH);
//      digitalWrite(4,LOW);
//      digitalWrite(0,HIGH);
//      client.println("HTTP/1.1 200 OK");
//      client.println("Content-Type: text/html");
//      client.println("");
//      client.println("<!DOCTYPE HTML>");
//      client.println("<html>");
//      client.println("reverse");
//      client.println("</html>");
//      client.stop();
//      delay(1);
//
//    }
//    if (i == "right") {
//      digitalWrite(16,LOW);
//      digitalWrite(5,LOW);
//      digitalWrite(4,HIGH);
//      digitalWrite(0,LOW);
//      client.println("HTTP/1.1 200 OK");
//      client.println("Content-Type: text/html");
//      client.println("");
//      client.println("<!DOCTYPE HTML>");
//      client.println("<html>");
//      client.println("right");
//      client.println("</html>");
//      client.stop();
//      delay(1);
//
//    }
//    if (i == "left") {
//      digitalWrite(16,HIGH);
//      digitalWrite(5,LOW);
//      digitalWrite(4,LOW);
//      digitalWrite(0,LOW);
//      client.println("HTTP/1.1 200 OK");
//      client.println("Content-Type: text/html");
//      client.println("");
//      client.println("<!DOCTYPE HTML>");
//      client.println("<html>");
//      client.println("left");
//      client.println("</html>");
//      client.stop();
//      delay(1);
//
//    }
//    if (i == "stop") {
//      digitalWrite(16,LOW);
//      digitalWrite(5,LOW);
//      digitalWrite(4,LOW);
//      digitalWrite(0,LOW);
//      client.println("HTTP/1.1 200 OK");
//      client.println("Content-Type: text/html");
//      client.println("");
//      client.println("<!DOCTYPE HTML>");
//      client.println("<html>");
//      client.println("stop");
//      client.println("</html>");
//      client.stop();
//      delay(1);
//
//    }
  Serial.println(i);
}
