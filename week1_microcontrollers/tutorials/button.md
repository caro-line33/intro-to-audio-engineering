# Button Input Tutorial

This tutorial will walk you through connecting one button to your microcontroller and detecting when it is pressed.

## You Will Need

- 1 button
- 1 ESP32S3 microcontroller
- Data transfer cable
- Breadboard
- 2 jumper wires

## Hardware Connections

Disconnect your microcontroller from power before wiring.

1. Connect one terminal of the button to an input-capable `GPIO` on your microcontroller.
2. Connect the other terminal to `GND`. You can also use the breadboard’s ground rail if it is connected to the microcontroller’s `GND`.

If your button has four legs, two pairs are already connected internally. Choose terminals that become connected **when you press the button**.

## Software

1. Create a variable called `BUTTON_PIN` with the type `const int`. Assign it the pin connected to your button. The example uses `D0`, but your pin may be different—check your board’s pinout.
2. In `setup()`, start serial communication with `Serial.begin(9600)`.
3. Set the button pin as `INPUT_PULLUP` using `pinMode()`.
4. In `loop()`, use `digitalRead()` to read the button’s state.
5. If the state is `LOW`, print `"button pressed"`. Otherwise, print nothing.

**Why does `LOW` mean pressed?** With `INPUT_PULLUP`, an internal resistor holds the pin `HIGH` when the button is released. Pressing the button connects the pin to ground, making it read `LOW`.

## Code

```cpp
const int BUTTON_PIN = D0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  if (state == LOW) {
    Serial.println("button pressed");
  }
}
```

## Challenge: Create a Function for Button Press Action

Create a function called `buttonAction` that:

- Takes a button pin of type `int` as an argument.
- Prints `"button pressed"` if the button is pressed.
- Prints `"button released"` if the button is released.

Moving the button logic into a function makes `loop()` easier to read and lets you reuse the same function for other buttons.

Call `buttonAction(BUTTON_PIN)` inside `loop()`. The function runs again each time `loop()` repeats.

## Code

```cpp
const int BUTTON_PIN = D0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonAction(BUTTON_PIN);
}

void buttonAction(int button_pin) {
  int state = digitalRead(button_pin);

  if (state == LOW) {
    Serial.println("button pressed");
  } else {
    Serial.println("button released");
  }
}
```

## Verification

Upload the code to your microcontroller, then open **Tools → Serial Monitor**. Set the baud rate to **9600** to match `Serial.begin(9600)`.

- **First example:** Prints `"button pressed"` while you hold the button and prints nothing when you release it.
- **Function challenge:** Prints `"button pressed"` while you hold the button and `"button released"` when you release it.

The messages repeat because the code checks the button continuously in `loop()`.