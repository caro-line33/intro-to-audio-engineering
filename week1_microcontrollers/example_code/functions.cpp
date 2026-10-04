// Functions are named blocks of code that perform a task.
// You can call a function whenever you want that task to run.

// 1. FUNCTION WITH NO INPUT OR RETURN VALUE
// void means the function does not return a value.
void sayHello() {
  Serial.println("Hello!");
}

// 2. FUNCTION WITH AN INPUT (PARAMETER)
// count is a variable that receives the value passed to the function.
void printCount(int count) {
  Serial.print("Count: ");
  Serial.println(count);
}

// 3. FUNCTION WITH MULTIPLE INPUTS
void printSum(int a, int b) {
  Serial.println(a + b);
}

// 4. FUNCTION THAT RETURNS A VALUE
// int means this function returns a whole number.
int add(int a, int b) {
  return a + b; // Send the result back to the code that called it.
}

void setup() {
  Serial.begin(9600);

  // Call a function by writing its name followed by parentheses.
  sayHello(); // Prints "Hello!"

  // Pass a value into a function.
  printCount(5);  // Prints "Count: 5"
  printCount(10); // Prints "Count: 10"

  // You can also pass a variable.
  int score = 20;
  printCount(score); // Prints "Count: 20"

  // Pass multiple values, separated by commas.
  printSum(3, 4); // Prints 7.

  // Store a returned value in a variable.
  int result = add(3, 4);
  Serial.println(result); // Prints 7.

  // printSum() prints the answer itself.
  // add() returns the answer so we can store it or use it later.
  int doubledResult = result * 2;
  Serial.println(doubledResult); // Prints 14.
}

void loop() {
  // Empty because this example only needs to run once.
}

// setup() and loop() are functions too!
// Arduino calls setup() once, then calls loop() repeatedly.