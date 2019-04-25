#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial sw(6, 7); // RX, TX

#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

String data,firstValue,secondValue;

int degree1=0;
int degree2=0;
int commaIndex,secondCommaIndex;
int xaxis,yaxis;


void setup()
{
  Serial.begin(9600);
  sw.begin(9600);  
  sw.println("init");
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  //pwm.setPWM(0,0,pulseWidth(0));
  
  
}

void loop() 
{
  if(Serial.available()>0)
  {    
    data = Serial.readStringUntil('\n');
    sw.println(data); 
    //Serial.println(data);
  } 
  //deg = data.toInt();

  commaIndex = data.indexOf(',');
  secondCommaIndex = data.indexOf(',', commaIndex + 1);

  firstValue = data.substring(0, commaIndex);
  secondValue = data.substring(commaIndex + 1, secondCommaIndex);

  
  degree1 = firstValue.toInt();
  
  degree2 = secondValue.toInt();
  
  
  
  xaxis = map(degree1,45,345,50,110);
  yaxis = map(degree2,30,270,140,30);
  //sw.println(xaxis);
  //sw.println(yaxis);
  
  pwm.setPWM(0,0,pulseWidth(xaxis));
  delay(5);
  pwm.setPWM(1,0,pulseWidth(yaxis));
  delay(5);
  
  /*degree1 = data.toInt();
  xaxis = map(degree1,45,345,30,120);
  pwm.setPWM(0,0,pulseWidth(xaxis));*/
  

  
 
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
