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
void loop() {
  // put your main code here, to run repeatedly:

  //determine if button is pushed on/off
  pushButton = digitalRead(D5);
  int brightnessValue;
  brightnessValue = analogRead(A0);
  Serial.println("button status:"+String(pushButton));
  
 

  //send digital signal based on analog value
  // if(pushButton == 1){
  //   brightnessValue = analogRead(A0);
  //   //save value right before light is turned off
  //   brightnessValue = brightnessValueBeforeOff;
  // }
  //turn on/off LED
  digitalWrite(D4,pushButton);
  analogWrite(D4,brightnessValue);

}