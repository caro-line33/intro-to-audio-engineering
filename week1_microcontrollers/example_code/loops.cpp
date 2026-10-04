// Arduino loop examples.
// Open the Serial Monitor and set the baud rate to 9600.

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 1. FOR LOOP
  // Useful when you know how many times to repeat.
  //
  // int i = 0 -> Create a counter starting at 0.
  // i < 5     -> Check this BEFORE each repetition.
  // i++       -> Add 1 AFTER each repetition.
  Serial.println("For loop:");

  for (int i = 0; i < 5; i++) {
    Serial.println(i);
    delay(500); // Wait 500 milliseconds.
  }
  // Prints: 0, 1, 2, 3, 4.

  // 2. WHILE LOOP
  // Repeats as long as the condition is true.
  Serial.println("While loop:");

  int countdown = 3;

  while (countdown > 0) {
    Serial.println(countdown);
    countdown--; // Subtract 1 each time.
    delay(500);
  }
  Serial.println("Go!");
  // Prints: 3, 2, 1, Go!
  // Without countdown--, this loop would run forever.

  // 3. DO-WHILE LOOP
  // Runs the code BEFORE checking the condition.
  // The body always runs at least once.
  Serial.println("Do-while loop:");

  int number = 10;

  do {
    Serial.println(number);
    number++;
  } while (number < 5); // Notice the semicolon.
  // Prints 10 once, then stops because 11 < 5 is false.

  // Arduino automatically runs loop() again when it reaches the end.
  Serial.println("Restarting examples in 3 seconds...");
  delay(3000);
}