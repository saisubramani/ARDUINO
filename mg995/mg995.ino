#include <Servo.h>

Servo mg995;

void setup() {
  mg995.attach(9,600,2300);
 
}

void loop() {
  mg995.write(0);
  delay(1000);

  mg995.write(10);
  delay(1000);

  mg995.write(20);
  delay(1000);

  mg995.write(30);
  delay(1000);

  mg995.write(40);
  delay(1000);

  mg995.write(50);
  delay(1000);


  mg995.write(60);
  delay(1000);

  mg995.write(70);
  delay(1000);
  mg995.write(80);
  delay(1000);
  mg995.write(90);
  delay(1000);

  

  
  
}
