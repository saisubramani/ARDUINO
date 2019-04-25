#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2350
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50

// Change these settings to your own setup and preferences.
 //int horServoPin = 22;
 int horMaxLeft = 60; // Maximum servo position Left
 int horMid = 90; // Middle servo position horizontal
 int horMaxRight = 120; // Maximum servo position Right
 int horStep = 1; // Step size for position horizontal

//int verServoPin = 24;
 int verMaxUp = 45; // Maximum servo position Up
 int verMid = 65; // Middle servo position vertical
 int verMaxDown = 95; // Maximum servo position Down
 int verStep = 1; // Step size for position vertical

int delaySpeed = 500; // time between the movement
 int pos = 0; // variable to store the servo position
 int positionwait = 5; // variable to wait for the servo to reach the position

void setup()
 {
 //horServo.attach(22); // attaches the servo on horzontal pin
 //verServo.attach(24); // attaches the servo on vertical pin
pwm.setPWM(0,0,pulseWidth(horMid));
pwm.setPWM(0,0,pulseWidth(verMid));
pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
//horServo.write(horMid); // Put horizontal servo in neutral position
 //verServo.write(verMid); // Put vertical servo in neutral position
 }

void loop()
 {

// Look right
 for(pos = horMid; pos <= horMaxRight; pos += horStep)
 {
 pwm.setPWM(0,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);

// Look left
 for(pos = horMaxRight; pos>=horMaxLeft; pos-=horStep)
 {
 pwm.setPWM(0,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);

/* Look neutral
 for(pos = horMaxLeft; pos<=horMid; pos+=horStep)
 {
 pwm.setPWM(0,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);

Look Up
 for(pos = verMid; pos <= verMaxDown; pos += verStep)
 {
 pwm.setPWM(1,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);

// Look down
 for(pos = verMaxDown; pos>=verMaxUp; pos-=verStep)
 {
 pwm.setPWM(1,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);

//Look neutral
 for(pos = verMaxUp; pos <= verMid; pos += verStep)
 {
 pwm.setPWM(1,0,pulseWidth(pos));
 delay(positionwait);
 }
 delay(delaySpeed);*/
 }


int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}
