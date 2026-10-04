# Button Input Tutorial

This tutorial will walk you through connecting one button to your microcontroller and detecting when it has been pressed.

## You Will Need
- 1 button
- 1 ESP32S3 microcontroller
- Data transfer cable
- 2 Jumper Wires

## Hardware Connections

1. Connect one leg of the button to any `GPIO` on your microcontroller.
2. Connect the other leg of the button to `GND` on your microcontroller.
Or, equivalently, the `GND` rail on your breadboard, if it is connected to `GND` of your microcontroller. 

## Software

1. Create a variable called `BUTTON_PIN`, with the type `const int` and value `{pin number}` (from pinout diagram). Note that the example code uses `D0` but your pin may be different.
2. Set it as an `INPUT_PULLUP` in the `setup` function.
3. In the loop function, get its `digitalRead` value and print to Serial Monitor if `LOW`.
4. Else, print nothing. 

## Code

``` cpp

const int ButtonPin =  D0; 

void setup() {
  Serial.begin(9600);
  pinMode(ButtonPin, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(Button_Pin);
  if (state == LOW){ // if button is being pressed
    Serial.println("button pressed");
  }
  else{ // if button is not being pressed
    Serial.println("button released");
  }
}

```

## Challenge: Create a Function for Button Press Action

The function should take in a button pin (type is `int`) as an argument, and print "pressed" if pressed, and "released" if not pressed. 

This is useful because it breaks up the code for readability, and also makes it easier to change. Instead of the if-else being in the main loop, we just call the buttonAction on ButtonPin once.

## Code

``` cpp
const int ButtonPin =  D0; 

void setup() {
  Serial.begin(9600);
  pinMode(ButtonPin, INPUT_PULLUP);
}

void loop() {
  buttonAction(ButtonPin);

}

void buttonAction(int button_pin){
  int state = digitalRead(button_pin);
  // if button is being pressed
  if (state == LOW){
    Serial.println("button pressed");
  }
  // if button is not being pressed
  else{
    Serial.println("button released");
  }
}
```

## Verification

To ensure your code works, upload it to your microcontroller and then open the serial monitor (`Tools` --> `Serial Monitor`). When you press the button, you should see an output.