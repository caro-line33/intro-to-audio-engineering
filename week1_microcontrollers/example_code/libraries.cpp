// Libraries provide code written for you to reuse.
// They can help control displays, motors, sensors, and more.

// This example uses the Servo library to control a servo motor.
// If needed, install "Servo" using the Arduino IDE's Library Manager.

// 1. INCLUDE THE LIBRARY
// #include makes the library's declarations available to your sketch.
#include <Servo.h>

// 2. CREATE AN OBJECT
// Servo is a type provided by the library.
// myServo is the name we choose for our servo object.
Servo myServo;

void setup() {
  // 3. USE A LIBRARY FUNCTION
  // attach() tells the library which pin carries the servo signal.
  // Connect the servo's signal wire to pin 9.
  myServo.attach(9);
}

void loop() {
  // 4. CALL FUNCTIONS THROUGH THE OBJECT
  // Syntax: objectName.functionName(arguments);

  myServo.write(0);   // Command a standard positional servo to 0 degrees.
  delay(1000);       // Allow time for it to move.

  myServo.write(90);  // Command it to 90 degrees.
  delay(1000);

  myServo.write(180); // Command it to 180 degrees.
  delay(1000);

  // write() comes from the Servo library.
  // delay() is provided by Arduino itself.
}