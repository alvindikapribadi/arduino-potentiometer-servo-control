/*
  Title: Arduino Potentiometer Control Servo
  Description: Control servo angle (0–180°) using a potentiometer.
  Components: Arduino, Potentiometer, Servo Motor (SG90), Jumper Wires
  Wiring:
    - Potentiometer:
        Left  -> 5V
        Right -> GND
        Middle -> A0
    - Servo:
        Red   -> 5V
        Brown/Black -> GND
        Orange/Yellow -> Pin 9
*/

#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  int potValue = analogRead(potPin);          // Read potentiometer (0–1023)
  int angle = map(potValue, 0, 1023, 0, 180); // Convert to 0–180 degrees
  
  myServo.write(angle);                       // Move servo
  delay(15);                                  // Small delay for stability
}
