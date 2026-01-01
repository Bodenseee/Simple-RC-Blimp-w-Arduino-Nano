#include <Servo.h>

int recieverPinY = 8;
int recieverPinX = 9;
const int durationMax = 2000;
const int durationMin = 900;
Servo ESC1;//creates esc object using servo library
Servo ESC2;
const int Esc1Pin = 7;
const int Esc2Pin = 6;
unsigned long pinValueY;//creates variable, unsigned long has larger range of storage
unsigned long pinValueX;
int pwm;

void setup() {
  // put your setup code here, to run once:
  pinMode(recieverPinY, INPUT);//set reciever pin as input
  pinMode(recieverPinX, INPUT);
  Serial.begin(9600);
  ESC1.attach(7,900,2000);//servo attach: pin, minPW, maxPW
  ESC2.attach(6,900,2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinValueY = pulseIn(recieverPinY, HIGH);//reads value from reciever
  pinValueX = pulseIn(recieverPinX, HIGH);
  Serial.println(pinValueY);
  Serial.println(pinValueX);
  Serial.println("Y: " + pinValueY);
  //Serial.println("X: " + pinValueX);
  /*pulseDurationY = pinValueY;
  pulseDurationX = pinValueX;*/
  pwm = map(pinValueY, 0, durationMax, 0, 180);//scales it to 180 degrees of servo
  /*analogWrite(Esc1Pin, pwm);
  analogWrite(Esc2Pin, pwm);*/
  if (pinValueX < 1200 ){
    ESC1.write(pwm);
    ESC2.write(0); 
  } else if (pinValueX > 1800) {
    ESC1.write(0);
    ESC2.write(pwm);
  } else {
    ESC1.write(pwm);//writes to servo variable
    ESC2.write(pwm);
  }
}