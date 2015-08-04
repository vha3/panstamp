/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This code is for the TI EM430 Development board
 */

void setup() {                
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);    
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);              // wait for a second
}