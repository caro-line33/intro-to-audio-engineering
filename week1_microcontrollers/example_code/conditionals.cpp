void setup() {
  Serial.begin(9600);

  // Conditionals let the program decide which code to run.

  // 1. IF
  // Runs the code only when the condition is true.
  int score = 80;

  if (score >= 60) {
    Serial.println("You passed!");
  }

  // 2. IF / ELSE
  // Chooses between two blocks of code.
  bool buttonPressed = false;

  if (buttonPressed) {
    Serial.println("Button is pressed.");
  } else {
    Serial.println("Button is not pressed.");
  }

  // 3. IF / ELSE IF / ELSE
  // Checks conditions from top to bottom.
  // Only the FIRST matching block runs.
  if (score >= 90) {
    Serial.println("Grade: A");
  } else if (score >= 80) {
    Serial.println("Grade: B");
  } else if (score >= 70) {
    Serial.println("Grade: C");
  } else {
    Serial.println("Score is below 70.");
  }
  // Prints "Grade: B" because score is 80.

  // 4. COMPARISON OPERATORS
  // ==  equal to
  // !=  not equal to
  // >   greater than
  // <   less than
  // >=  greater than or equal to
  // <=  less than or equal to
  //
  // IMPORTANT: = assigns a value; == compares values.
  int lives = 3;

  if (lives == 3) {
    Serial.println("You have all 3 lives.");
  }

  // 5. COMBINING CONDITIONS
  // && means AND: both conditions must be true.
  int temperature = 25;

  if (temperature >= 20 && temperature <= 30) {
    Serial.println("Temperature is between 20 and 30.");
  }

  // || means OR: at least one condition must be true.
  if (temperature < 0 || temperature > 40) {
    Serial.println("Temperature is outside the expected range.");
  }

  // ! means NOT: reverses true and false.
  if (!buttonPressed) {
    Serial.println("Waiting for a button press.");
  }
}

void loop() {
  // Empty because this example only needs to run once.
}