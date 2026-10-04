void setup() {
  Serial.begin(9600);

  // 1. Create variables.
  int score = 10;              // int: a whole number
  double temperature = 22.5;  // double: a number with a decimal part
  char grade = 'A';           // char: one character, in single quotes
  bool buttonPressed = false; // bool: true or false
  String message = "Hello";   // String: text, in double quotes

  // 2. Change a variable using assignment (=).
  // No 'int' here: score already exists.
  score = 20;

  // 3. Use the current value to calculate a new value.
  score = score + 5; // Score is now 25.
  score += 5;       // Another way to add 5. Score is now 30.

  // 4. Assigning one int to another copies its current value.
  int savedScore = score; // savedScore is now 30.
  score = 100;            // savedScore stays 30.

  // 5. const makes a value read-only after initialization.
  const int maxScore = 100;
  // maxScore = 200; // Uncommenting this causes a compiler error.

  // 6. Display values in the Serial Monitor (9600 baud).
  Serial.println(score);         // 100
  Serial.println(savedScore);    // 30
  Serial.println(temperature);   // 22.50
  Serial.println(grade);         // A
  Serial.println(buttonPressed); // 0 (false); true prints as 1
  Serial.println(message);       // Hello
  Serial.println(maxScore);      // 100
}

void loop() {
  // Empty because this example only needs to run once.
}