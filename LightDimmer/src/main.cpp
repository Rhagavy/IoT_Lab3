#include <Arduino.h>

void setup() {
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 

  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range - Pulse Width Modulation = PWM
  analogWriteRange(1023); 
}

int brightnessValueBeforeOff;
int pushButton;
bool buttonState = false;
void loop() {
  // put your main code here, to run repeatedly:

 int brightnessValue;
  //current value of button
  pushButton = digitalRead(D5);

  Serial.println("button status:"+String(pushButton));
  
  if(pushButton == 1){
    buttonState = true;
  }else{
    buttonState = false;
  }
  //check button state, if on then allow LED brightness to be adjustable w/ converter 
  if (buttonState == false){
    //turn off LED
    digitalWrite(D4,1);
    buttonState = true;
  }else{
    brightnessValue = analogRead(A0);
    //save brightnees of light before its turn off
    brightnessValueBeforeOff = brightnessValue;
    analogWrite(D4,brightnessValueBeforeOff);
    buttonState = false;

  }

}
