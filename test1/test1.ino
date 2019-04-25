
#include <Wire.h>

#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

String firstValue,secondValue,data;
int degree1,degree2,commaIndex,secondCommaIndex,xaxis,yaxis;


void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

void loop() {
 if(Serial.available()>0)
  {
    
    data = Serial.readStringUntil('\n');
    Serial.println(data);
  } 
  commaIndex = data.indexOf(',');
  secondCommaIndex = data.indexOf(',', commaIndex + 1);

  firstValue = data.substring(0, commaIndex);
  secondValue = data.substring(commaIndex + 1, secondCommaIndex);

  
  degree1 = firstValue.toInt();
  pwm.setPWM(0,0,pulseWidth(degree1));
  degree2 = secondValue.toInt();
  //pwm.setPWM(1,0,pulseWidth(degree2));

  //Serial.println(degree1);
  //Serial.println(degree2);
  

}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
