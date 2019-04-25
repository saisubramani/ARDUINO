#include <SoftwareSerial.h>
SoftwareSerial sw(6, 7); // RX, TX
void setup() 
{
  Serial.begin(9600);
  sw.begin(9600);  

}

void loop()
{
 if (sw.available())
 {
  Serial.write(sw.read());
 }

}
