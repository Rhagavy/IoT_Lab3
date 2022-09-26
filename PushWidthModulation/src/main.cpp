// Mohawk College - COMP-10184 
// 
// Pulse Width Modulation - Test Program 
// 
#include <Arduino.h> 

//ratio of on and off time is called Duty Cycle
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range - Pulse Width Modulation = PWM
  analogWriteRange(1023); 
} 

void loop() { 
  int i; 
   
  for ( i=0; i<1024; ++i) { 
    // set the PWM pulse width 
    analogWrite(D4, i); 
 
    // wait 1ms to add DRAMA! 
    delay(1); 
  } 
} 

// 10 ms on and off duration, 10% duty cycle, lick flickers for 1ms, but
// human eyes can not see the change
// void loop() { 
//   // turn the LED ON 
//   digitalWrite(D4, LOW); 
//   // wait 1ms 
//   delay(1); 
 
//   // turn the LED OFF 
//   digitalWrite(D4, HIGH); 
//   // wait 9ms 
//   delay(9); 
// } 

//50% duty cycle
// void loop() { 
//   // turn the LED ON 
//   digitalWrite(D4, LOW); 
//   // wait 1s 
//   delay(1000); 
 
//   // turn the LED OFF 
//   digitalWrite(D4, HIGH); 
//   // wait 1s 
//   delay(1000); 
// } 

//0.5% duty cycle
// void loop() { 
//   // turn the LED ON 
//   digitalWrite(D4, LOW); 
//   // wait 10ms 
//   delay(10); 
 
//   // turn the LED OFF 
//   digitalWrite(D4, HIGH); 
//   // wait 1990ms 
//   delay(1990); 
// } 

