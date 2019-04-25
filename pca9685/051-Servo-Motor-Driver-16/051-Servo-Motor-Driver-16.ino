#include <CmdMessenger.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

String readString, servo1, servo2;


void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void loop() 
{

if (Serial.available())
{
    delay(3);  //delay to allow buffer to fill
    if (Serial.availabwle() >0) 
    {
      readString = Serial.readStringUntil('\n');
    }
  }

  if (readString.length() >0) 
  {
      //Serial.println(readString); //see what was received
     
         
      servo1 = readString; 
      Serial.println(servo1.length()-);
      Serial.println(servo1);  
      int n1 = servo1.toInt();
    
      Serial.println("the numbers are :");
      Serial.println(n1); 
      pwm.setPWM(0,0,pulseWidth(n1));
      n1 =0;
  }
  
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
