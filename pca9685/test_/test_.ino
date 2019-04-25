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

  
  pwm.setPWM(1,0,pulseWidth(35)); //down
  delay(1000);
  pwm.setPWM(1,0,pulseWidth(85)); //straight
  delay(1000);
  pwm.setPWM(1,0,pulseWidth(115)); //up
  delay(1000);
  
  


 


  
 
  pwm.setPWM(0,0,pulseWidth(130)); //right
  delay(1000);
  pwm.setPWM(0,0,pulseWidth(90)); //center
  delay(1000);
  
  pwm.setPWM(0,0,pulseWidth(60)); //left
  delay(1000);
 
  
 
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
